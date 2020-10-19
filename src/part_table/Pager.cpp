//
// Created by 马子杰 on 2020/9/18.
//
#include <fcntl.h>
#include <cstdlib>
#include <zconf.h>
#include "Pager.h"
#include "iostream"

Pager* Pager::pager_open(const char *filename) {
    int fd = open(filename, O_RDWR | O_CREAT | S_IWUSR | S_IRUSR);
    if (fd == -1) {
        std::cout << "Unable to open file.\n";
        exit(EXIT_FAILURE);
    }
    int file_length = lseek(fd, 0, SEEK_END);

    Pager* pager = new Pager();
    pager->file_descriptor = fd;
    pager->file_length = file_length;
    pager->num_pages = (file_length / PAGE_SIZE);

    if (file_length % PAGE_SIZE) {
        std::cout << "Db file is not a whole number of pages. Corrupt file!\n" << std::endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < TABLE_MAX_PAGES; i ++ ) {
        pager->pages[i] = nullptr;
    }
    return pager;

}

int Pager::get_file_length() {return this->file_length;}

int Pager::get_file_descriptor() {return this->file_descriptor;}

int Pager::get_num_pages() {return this->num_pages;}

void* Pager::get_page(int page_num) {
    if (page_num >= TABLE_MAX_PAGES) {
        printf("Tried to fetch page number out of bounds. %d > %d\n", page_num, TABLE_MAX_PAGES);
        exit(EXIT_FAILURE);
    }

    if (this->pages[page_num] == nullptr) {
        void* page = malloc(PAGE_SIZE);
        int num_pages = this->file_length / PAGE_SIZE;
        if (this->file_length % PAGE_SIZE) {
            num_pages = num_pages + 1;
        }

        if (page_num <= num_pages) {
            lseek(this->file_descriptor, page_num * PAGE_SIZE, SEEK_SET);
            int bytes_read = read(this->file_descriptor, page, PAGE_SIZE);
            if (bytes_read == -1) {
                printf("Error reading file: %d\n", errno);
                exit(EXIT_FAILURE);
            }
        }
        this->pages[page_num] = page;
        if (page_num >= this->num_pages) {
            this->num_pages = page_num + 1;
        }
    }
    return this->pages[page_num];
}

Pager::~Pager() {
    for (int i = 0; i < TABLE_MAX_PAGES; i ++ ) {
        void* page = this->pages[i];
        if (page != nullptr) {
            free(page);
            this->pages[i] = nullptr;
        }
    }
}

void Pager::pager_flush(int num_page) {
    if (this->pages[num_page] == nullptr) {
        printf("Tried to flush null page.\n");
        exit(EXIT_FAILURE);
    }
    int offset = lseek(this->file_descriptor, num_page * PAGE_SIZE, SEEK_SET);
    if (offset == -1) {
        printf("Error seeking: %d.\n", errno);
        exit(EXIT_FAILURE);
    }
    int bytes_written = write(this->file_descriptor, this->pages[num_page], PAGE_SIZE);
    if (bytes_written == -1) {
        printf("Error Writing: %d.\n", errno);
        exit(EXIT_FAILURE);
    }
}

int Pager::get_unused_page_num() {
    return this->get_num_pages();
}