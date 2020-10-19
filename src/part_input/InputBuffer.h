//
// Created by 马子杰 on 2020/9/16.
//

#ifndef TINY_DB_INPUTBUFFER_H
#define TINY_DB_INPUTBUFFER_H


#include <cstdio>
#include "../part_command/Command.h"

class InputBuffer{
public:
    InputBuffer();
    ~InputBuffer();
    void read_input();
    Command* input_parse();
    Command* insert_parse();
private:
    char* buffer;
    size_t input_length;
    size_t buffer_length;
};
#endif //TINY_DB_INPUTBUFFER_H
