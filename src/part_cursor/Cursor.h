//
// Created by 马子杰 on 2020/9/20.
//

#ifndef TINY_DB_CURSOR_H
#define TINY_DB_CURSOR_H

#include "../part_table/Table.h"

class Cursor{
public:
    static Cursor* table_start(Table* table);
    static Cursor* table_find(Table* table, int key_to_insert);
    static Cursor* table_find_leaf(Table* table, int root_page_num, int key_to_insert);
    static Cursor* table_find_internal(Table* table, int page_num, int key_to_insert);
    void* cursor_value();
    void cursor_advance();
    bool is_end_of_table();
    void leaf_node_insert(int key, Row* value);
    void leaf_node_split_and_insert(int key, Row* value);
    int get_page_num();
    int get_cell_num();
    Table* get_table();

    void internal_node_insert(int parent_page_num, int child_page_num);


private:
    int page_num;
    int cell_num;
    Table* table;
    bool end_of_table;
};
#endif //TINY_DB_CURSOR_H
