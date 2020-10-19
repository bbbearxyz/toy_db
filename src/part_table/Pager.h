//
// Created by 马子杰 on 2020/9/18.
//
#include "Row.h"
#ifndef TINY_DB_PAGER_H
#define TINY_DB_PAGER_H
#define TABLE_MAX_PAGES 100
const int PAGE_SIZE = 4096;

class Pager {
public:
    static Pager* pager_open(const char* filename);
    int get_file_descriptor();
    int get_file_length();
    int get_num_pages();
    int get_unused_page_num();
    void* get_page(int page_num);
    void pager_flush(int num_page);
    void* pages[TABLE_MAX_PAGES];
    ~Pager();
private:
    int file_descriptor;
    int file_length;
    int num_pages;

};
#endif //TINY_DB_PAGER_H
