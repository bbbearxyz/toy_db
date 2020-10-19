//
// Created by 马子杰 on 2020/9/16.
//

#include "Row.h"
#include "Pager.h"

#ifndef TINY_DB_TABLE_H
#define TINY_DB_TABLE_H

class Table {
public:
    int root_page_num;
    Pager* pager;
    static Table* db_open(const char* filename);
    void db_close();
    void create_new_root(int right_child_page_num);
private:

};
#endif //TINY_DB_TABLE_H
