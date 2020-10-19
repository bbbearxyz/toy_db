//
// Created by 马子杰 on 2020/9/16.
//

#include <cstdlib>
#include <cstdio>
#include <zconf.h>
#include <cstring>
#include <iostream>
#include "Table.h"
#include "../part_tree/Node.h"

Table * Table::db_open(const char *filename) {
    Pager* pager = Pager::pager_open(filename);
    Table* table = new Table();
    table->pager = pager;
    table->root_page_num = 0;

    if (pager->get_num_pages() == 0) {
        void* root_node_pos = pager->get_page(0);
        Node* root_node = new Node(root_node_pos);
        root_node->leaf_node_init();
        root_node->set_root_node(true);

        delete root_node;
    }
    return table;

}

void Table::db_close() {
    Pager* pager = this->pager;

    for (int i = 0; i < this->pager->get_num_pages() ; i ++ ) {
        if (pager->pages[i] == nullptr) {
            continue;
        }
        pager->pager_flush(i);
        free(pager->pages[i]);
        pager->pages[i] = nullptr;
    }

    int result = close(pager->get_file_descriptor());
    if (result == -1) {
        printf("Error closing db file.\n");
        exit(EXIT_FAILURE);
    }
    delete pager;
}

void Table::create_new_root(int right_child_page_num) {
    void* root_pos = this->pager->get_page(root_page_num);
    void* right_child_pos = this->pager->get_page(right_child_page_num);
    int left_child_page_num = this->pager->get_unused_page_num();
    void* left_child_pos = this->pager->get_page(left_child_page_num);

    memcpy(left_child_pos, root_pos, PAGE_SIZE);

    Node* left_child_node = new Node(left_child_pos);
    left_child_node->set_root_node(false);
    *left_child_node->node_parent() = this->root_page_num;

    Node* right_child_node = new Node(right_child_pos);
    *right_child_node->node_parent() = this->root_page_num;

    Node* root_node = new Node(root_pos);
    root_node->internal_node_init();
    root_node->set_root_node(true);
    *(root_node->internal_node_num_keys()) = 1;

    *(root_node->internal_node_child(0)) = left_child_page_num;
    int left_child_max_key = left_child_node->get_node_max_key();
    *(root_node->internal_node_key(0)) = left_child_max_key;
    *(root_node->internal_node_right_child()) = right_child_page_num;

    delete left_child_node;
    delete root_node;
}