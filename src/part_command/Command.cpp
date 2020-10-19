//
// Created by 马子杰 on 2020/9/16.
//

#include <iostream>
#include "Command.h"
#include "../part_process/Process.h"
#include "../part_cursor/Cursor.h"
#include "../part_tree/Node.h"

Command::Command(CommandType _type) : type(_type) {}

Command::Command(CommandType _type, Row *_row_to_insert) : type(_type), row_to_insert(_row_to_insert) {}
bool Command::execute_command(Table *table) {
    if (this->type == INSERT) {
        print_result(execute_insert(table));
    }
    if (this->type == SELECT) {
        print_result(execute_select(table));
    }
    if (this->type == EXIT) {
        table->db_close();
        exit(EXIT_SUCCESS);
    }
    if (this->type == TYPE_STRING_LONG) {
        print_result(RESULT_STRING_LONG);
    }
    if (this->type == TYPE_SYNTAX_ERROR) {
        print_result(RESULT_SYNTAX_ERROR);
    }
    if (this->type == TYPE_UNRECOGNIZED) {
        print_result(RESULT_UNRECOGNIZED);
    }
    if (this->type == TYPE_CONSTANT) {
        print_result(RESULT_CONSTANT);
    }
    if (this->type == TYPE_PRINT_TREE) {
        print_result(execute_print_tree(table));
    }
    return true;
}

CommandResult Command::execute_insert(Table *table) {

    void* node_pos = table->pager->get_page(table->root_page_num);
    Node* node = new Node(node_pos);
    int num_cells = *node->leaf_node_num_cells();

    if (this->row_to_insert->id <= 0) {
        return RESULT_ID_NEGATIVE;
    }
    Row *row_to_insert = this->row_to_insert;
    int key_to_insert = row_to_insert->id;
    Cursor* cursor = Cursor::table_find(table, key_to_insert);
    if (cursor->get_cell_num() < num_cells) {
        int key = *(node->leaf_node_key(cursor->get_cell_num()));
        if (key == key_to_insert) {
            return RESULT_DUPLICATE_KEY;
        }
    }
    cursor->leaf_node_insert(row_to_insert->id, row_to_insert);
    delete node;
    delete cursor;
    return EXECUTED;
}

CommandResult Command::execute_select(Table *table) {
    Row* row = new Row();
    Cursor *cursor = Cursor::table_start(table);
    while (!cursor->is_end_of_table()) {
        Row::deserialize_row(cursor->cursor_value(), row);
        row->print_row();
        cursor->cursor_advance();
    }
    free(row);
    return EXECUTED;
}

CommandResult Command::execute_print_tree(Table *table) {
    Process::print_tree(table->pager, 0, 0);
    return RESULT_PRINT_TREE;
}

void Command::print_result(CommandResult result) {
    if (result == EXECUTED) {
        Process::print_success();
    }
    if (result == TABLE_FULL) {
        Process::print_table_full();
    }
    if (result == RESULT_STRING_LONG) {
        Process::print_string_long();
    }
    if (result == RESULT_SYNTAX_ERROR) {
        Process::print_syntax_error();
    }
    if (result == RESULT_UNRECOGNIZED) {
        Process::print_unrecognized();
    }
    if (result == RESULT_ID_NEGATIVE) {
        Process::print_id_negative();
    }
    if (result == RESULT_CONSTANT) {
        Process::print_constant();
    }
    if (result == RESULT_PRINT_TREE) {
        // do nothing
    }
    if (result == RESULT_DUPLICATE_KEY) {
        Process::print_duplicate_key();
    }
}