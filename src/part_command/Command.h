//
// Created by 马子杰 on 2020/9/16.
//

#ifndef TINY_DB_COMMAND_H
#define TINY_DB_COMMAND_H

#include "../part_table/Row.h"
#include "../part_table/Table.h"

enum CommandType {
    EXIT,
    INSERT,
    SELECT,
    TYPE_STRING_LONG,
    TYPE_SYNTAX_ERROR,
    TYPE_UNRECOGNIZED,
    TYPE_CONSTANT,
    TYPE_PRINT_TREE,
};

enum CommandResult {
    EXECUTED,
    TABLE_FULL,
    RESULT_STRING_LONG,
    RESULT_SYNTAX_ERROR,
    RESULT_UNRECOGNIZED,
    RESULT_ID_NEGATIVE,
    RESULT_CONSTANT,
    RESULT_PRINT_TREE,
    RESULT_DUPLICATE_KEY,
};
class Command{
public:
    Command(CommandType _type);
    Command(CommandType _type, Row* row_to_insert);
    bool execute_command(Table* table);

private:
    void print_result(CommandResult result);
    CommandResult execute_insert(Table* table);
    CommandResult execute_select(Table* table);
    CommandResult execute_print_tree(Table* table);
    CommandType type;
    Row* row_to_insert;
};

#endif //TINY_DB_COMMAND_H
