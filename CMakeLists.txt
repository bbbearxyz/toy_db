cmake_minimum_required(VERSION 3.17)
project(tiny_db)

set(CMAKE_CXX_STANDARD 14)

add_executable(tiny_db main.cpp src/part_input/InputBuffer.h src/part_input/InputBuffer.cpp src/part_process/Process.h src/part_process/Process.cpp src/part_command/Command.h src/part_command/Command.cpp src/part_table/Table.h src/part_table/Table.cpp src/part_table/Row.h src/part_table/Row.cpp src/part_table/Pager.h src/part_table/Pager.cpp src/part_cursor/Cursor.h src/part_cursor/Cursor.cpp src/part_tree/Node.h src/part_tree/Node.cpp)