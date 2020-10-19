//
// Created by 马子杰 on 2020/9/16.
//

#ifndef TINY_DB_PROCESS_H
#define TINY_DB_PROCESS_H

#include "../part_tree/Node.h"

class Process{
public:
    static void print_prompt();

    static void print_success();

    static void print_table_full();

    static void print_syntax_error();

    static void print_string_long();

    static void print_unrecognized();

    static void print_id_negative();

    static void print_constant();

    static void print_tree(Pager* pager, int page_num, int indentation_level);

    static void print_indent(int level);

    static void print_duplicate_key();
};
#endif //TINY_DB_PROCESS_H
