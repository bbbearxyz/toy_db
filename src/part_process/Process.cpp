//
// Created by 马子杰 on 2020/9/16.
//

#include "Process.h"
#include "../part_tree/Node.h"
#include <iostream>

void Process::print_prompt() {
    std::cout << "db > ";
}

void Process::print_success() {
    std::cout << "Executed.\n";
}

void Process::print_table_full() {
    std::cout << "Error: Table full.\n";
}

void Process::print_syntax_error() {
    std::cout << "Syntax error. Could not parse statement.\n";
}

void Process::print_string_long() {
    std::cout << "String is too long.\n";
}

void Process::print_unrecognized() {
    std::cout << "Error: Unrecognized.\n";
}

void Process::print_id_negative() {
    std::cout << "ID must be positive.\n";
}

void Process::print_constant() {
    printf("ROW_SIZE: %d\n", ROW_SIZE);
    printf("COMMON_NODE_HEADER_SIZE: %d\n", COMMON_NODE_HEADER_SIZE);
    printf("LEAF_NODE_HEADER_SIZE: %d\n", LEAF_NODE_HEADER_SIZE);
    printf("LEAF_NODE_CELL_SIZE: %d\n", LEAF_NODE_CELL_SIZE);
    printf("LEAF_NODE_SPACE_FOR_CELLS: %d\n", LEAF_NODE_SPACE_FOR_CELLS);
    printf("LEAF_NODE_MAX_CELLS: %d\n", LEAF_NODE_MAX_CELLS);
}

void Process::print_duplicate_key() {
    std::cout << "the key is already in the db file.\n" << std::endl;
}

void Process::print_indent(int level) {
    for (int i = 0; i < level; i ++ ) {
        std::cout << " ";
    }
}

void Process::print_tree(Pager *pager, int page_num, int indentation_level) {
    void* node_pos = pager->get_page(page_num);
    Node* node = new Node(node_pos);
    int num_keys, child;
    if (node->get_node_type() == NODE_LEAF) {
        num_keys = *node->leaf_node_num_cells();
        print_indent(indentation_level);
        printf("- leaf (size %d)\n", num_keys);
        for (int i = 0; i < num_keys; i ++ ) {
            print_indent(indentation_level);
            printf("- %d\n", *node->leaf_node_key(i));
        }
    } else if (node->get_node_type() == NODE_INTERNAL) {
        num_keys = *node->internal_node_num_keys();
        print_indent(indentation_level);
        printf("- internal (size %d)\n", num_keys);
        for (int i = 0; i < num_keys; i ++ ) {
            child = *node->internal_node_child(i);
            print_tree(pager, child, indentation_level + 1);
            printf("- key %d\n", *node->internal_node_key(i));
        }
        child = *node->internal_node_right_child();
        print_tree(pager, child, indentation_level + 1);
    }

    delete node;

}