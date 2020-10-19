//
// Created by 马子杰 on 2020/9/20.
//

#include <iostream>
#include "Node.h"

void * Node::leaf_node_cell(int cell_num) {
    return (char*)this->nodePos + LEAF_NODE_HEADER_SIZE + cell_num * LEAF_NODE_CELL_SIZE;
}

int * Node::leaf_node_key(int cell_num) {return (int*)leaf_node_cell(cell_num);}

int * Node::leaf_node_num_cells() {
    return (int*)((char*)this->nodePos + LEAF_NODE_NUM_CELLS_OFFSET);
}

void * Node::leaf_node_value(int cell_num) {
    return (char*)leaf_node_cell(cell_num) + LEAF_NODE_VALUE_OFFSET;
}

int * Node::leaf_node_next_leaf() {
    return (int*)((char*)this->nodePos + LEAF_NODE_NEXT_LEAF_OFFSET);
}

NodeType Node::get_node_type() {
    return *((NodeType*)((char*)this->nodePos + NODE_TYPE_OFFSET));
}

void Node::set_node_type(NodeType type) {
    *((NodeType*)((char*)this->nodePos + NODE_TYPE_OFFSET)) = type;
}

void Node::leaf_node_init() {
    *(this->leaf_node_num_cells()) = 0;
    this->set_node_type(NODE_LEAF);
    this->set_root_node(false);
    *this->leaf_node_next_leaf() = 0;
}

void Node::internal_node_init() {
    *(this->internal_node_num_keys()) = 0;
    this->set_node_type(NODE_INTERNAL);
    this->set_root_node(false);
}

Node::Node(void *nodePos) {
    this->nodePos = nodePos;
}

void Node::set_root_node(bool is_root_node) {
    *((int *)((char*)this->nodePos + IS_ROOT_OFFSET)) = is_root_node;
}

bool Node::is_root_node() {
    return *((int *)((char*)this->nodePos + IS_ROOT_OFFSET)) == 1;
}

int * Node::internal_node_cell(int cell_num) {
    return (int*)(char*)this->nodePos + INTERNAL_NODE_HEADER_SIZE + cell_num * INTERNAL_NODE_CELL_SIZE;
}

int * Node::internal_node_child(int child_num) {
    int num_keys = *this->internal_node_num_keys();
    if (child_num > num_keys) {
        std::cout << "Tried to access child_num " << child_num << " > num_keys " << num_keys << std::endl;
        exit(EXIT_FAILURE);
    } else if (child_num == num_keys) {
        return internal_node_right_child();
    } else {
        return internal_node_cell(child_num);
    }
}

int * Node::internal_node_key(int key_num) {
    return (int*)((char*)this->nodePos + key_num * INTERNAL_NODE_CELL_SIZE + INTERNAL_NODE_HEADER_SIZE + INTERNAL_NODE_CHILD_SIZE);
}

int * Node::internal_node_num_keys() {
    return (int*)((char*)this->nodePos + INTERNAL_NODE_NUM_KEYS_OFFSET);
}

int * Node::internal_node_right_child() {
    return (int*)((char*)this->nodePos + INTERNAL_NODE_RIGHT_CHILD_OFFSET);
}

int Node::get_node_max_key() {
    if (get_node_type() == NODE_LEAF) {
        return *leaf_node_key(*leaf_node_num_cells() - 1);
    }
    if (get_node_type() == NODE_INTERNAL) {
        return *internal_node_key(*internal_node_num_keys() - 1);
    }
}

int * Node::node_parent() {
    return (int*)((char*)this->nodePos + PARENT_POINTER_OFFSET);
}

void Node::update_internal_node_key(int old_max, int new_max) {
    int old_child_index = this->internal_node_find_child(old_max);
    if (old_child_index != *this->internal_node_num_keys()) {
        *this->internal_node_key(old_child_index) = new_max;
    }
}

int Node::internal_node_find_child(int old_key) {
    int num_keys = *this->internal_node_num_keys();

    int min_index = 0, max_index = num_keys;

    while (min_index < max_index) {
        int mid_index = (min_index + max_index) / 2;
        int mid_key = *this->internal_node_key(mid_index);
        if (mid_key >= old_key) {
            max_index = mid_index;
        } else {
            min_index = mid_index + 1;
        }
    }

    return min_index;
}