//
// Created by 马子杰 on 2020/9/16.
//

#include "InputBuffer.h"
#include "../part_process/Process.h"
#include <iostream>

InputBuffer::InputBuffer() {
    this->buffer = nullptr;
    this->buffer_length = 0;
    this->input_length = 0;
}

InputBuffer::~InputBuffer() {
    free(this-> buffer);
}

void InputBuffer::read_input() {
    Process::print_prompt();
    size_t bytes_read = getline(&(this->buffer), &(this->buffer_length), stdin);

    if (bytes_read <= 0) {
        std::cout << "nothing in the line, please rewrite something" << std::endl;
    }

    this->input_length = bytes_read - 1;
    this->buffer[this->input_length] = 0;
}

Command* InputBuffer::input_parse() {
    if (strncmp(this->buffer, ".exit", 5) == 0) {
        return new Command(EXIT);
    }
    if (strncmp(this->buffer, "select", 3) == 0) {
        return new Command(SELECT);
    }
    if (strncmp(this->buffer, "insert", 6) == 0) {
        return insert_parse();
    }
    if (strncmp(this->buffer, ".constants", 10) == 0) {
        return new Command(TYPE_CONSTANT);
    }
    if (strncmp(this->buffer, ".btree", 5) == 0) {
        return new Command(TYPE_PRINT_TREE);
    }
    return new Command(TYPE_UNRECOGNIZED);
}

Command* InputBuffer::insert_parse() {
    char* keyword = strtok(this->buffer, " ");
    char* id_string = strtok(nullptr, " ");
    char* username = strtok(nullptr, " ");
    char* email = strtok(nullptr, " ");

    if (id_string == nullptr || username == nullptr || email == nullptr) {
        return new Command(TYPE_SYNTAX_ERROR);
    }
    int id = atoi(id_string);

    if (strlen(username) > COLUMN_USERNAME_SIZE) {
        return new Command(TYPE_STRING_LONG);
    }
    if (strlen(email) > COLUMN_EMAIL_SIZE) {
        return new Command(TYPE_STRING_LONG);
    }
    Row* row = new Row();
    row->id = id;
    memcpy(row->username, username, strlen(username));
    memcpy(row->email, email, strlen(email));
    return new Command(INSERT, row);

}


