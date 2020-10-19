#include <iostream>
#include "src/part_input/InputBuffer.h"
#include "src/part_process/Process.h"

int main(int argc, char* argv[]) {
    InputBuffer* inputBuffer = new InputBuffer();
    char* filename = argv[1];
    if (filename == nullptr) {
        filename = "default.txt";
    }
    Table* table = Table::db_open(filename);
    while (true) {
        inputBuffer->read_input();
        Command* command = inputBuffer->input_parse();
        command->execute_command(table);
        delete command;
    }
}
