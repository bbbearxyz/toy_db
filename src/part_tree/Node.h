//
// Created by 马子杰 on 2020/9/20.
//

#ifndef TINY_DB_NODE_H
#define TINY_DB_NODE_H

#include "../part_table/Row.h"
#include "../part_table/Pager.h"

enum NodeType {
    NODE_INTERNAL,
    NODE_LEAF,
};

/*
 * Common node header layout
 */
const int NODE_TYPE_SIZE = sizeof(NodeType);
const int NODE_TYPE_OFFSET = 0;
const int IS_ROOT_SIZE = sizeof(int);
const int IS_ROOT_OFFSET = NODE_TYPE_SIZE + NODE_TYPE_OFFSET;
const int PARENT_POINTER_SIZE = sizeof(int);
const int PARENT_POINTER_OFFSET = IS_ROOT_SIZE + IS_ROOT_OFFSET;
const int COMMON_NODE_HEADER_SIZE = NODE_TYPE_SIZE + IS_ROOT_SIZE + PARENT_POINTER_SIZE;

/*
 * Leaf node header layout
 */
const int LEAF_NODE_NUM_CELLS_SIZE = sizeof(int);
const int LEAF_NODE_NUM_CELLS_OFFSET = COMMON_NODE_HEADER_SIZE;
const int LEAF_NODE_NEXT_LEAF_SIZE = sizeof(int);
const int LEAF_NODE_NEXT_LEAF_OFFSET = LEAF_NODE_NUM_CELLS_SIZE + LEAF_NODE_NUM_CELLS_OFFSET;
const int LEAF_NODE_HEADER_SIZE = LEAF_NODE_NUM_CELLS_SIZE +
                                  COMMON_NODE_HEADER_SIZE +
                                  LEAF_NODE_NEXT_LEAF_SIZE;

/*
 * Leaf node body layout
 */
const int LEAF_NODE_KEY_SIZE = sizeof(int);
const int LEAF_NODE_KEY_OFFSET = 0;
const int LEAF_NODE_VALUE_SIZE = ROW_SIZE;
const int LEAF_NODE_VALUE_OFFSET = LEAF_NODE_KEY_SIZE + LEAF_NODE_KEY_OFFSET;
const int LEAF_NODE_CELL_SIZE = LEAF_NODE_KEY_SIZE + LEAF_NODE_VALUE_SIZE;
const int LEAF_NODE_SPACE_FOR_CELLS = PAGE_SIZE - LEAF_NODE_HEADER_SIZE;
const int LEAF_NODE_MAX_CELLS = LEAF_NODE_SPACE_FOR_CELLS / LEAF_NODE_CELL_SIZE;

/*
 * Leaf split
 */
const int LEAF_NODE_RIGHT_SPLIT_COUNT = (LEAF_NODE_MAX_CELLS + 1) / 2;
const int LEAF_NODE_LEFT_SPLIT_COUNT = LEAF_NODE_MAX_CELLS + 1 - LEAF_NODE_RIGHT_SPLIT_COUNT;

/*
 * Internal node header layout
 */
const int INTERNAL_NODE_NUM_KEYS_SIZE = sizeof(int);
const int INTERNAL_NODE_NUM_KEYS_OFFSET = COMMON_NODE_HEADER_SIZE;
const int INTERNAL_NODE_RIGHT_CHILD_SIZE = sizeof(int);
const int INTERNAL_NODE_RIGHT_CHILD_OFFSET = INTERNAL_NODE_NUM_KEYS_SIZE + INTERNAL_NODE_NUM_KEYS_OFFSET;
const int INTERNAL_NODE_HEADER_SIZE = COMMON_NODE_HEADER_SIZE +
                                        INTERNAL_NODE_NUM_KEYS_SIZE +
                                        INTERNAL_NODE_RIGHT_CHILD_SIZE;

/*
 * Internal node body layout
 */
const int INTERNAL_NODE_KEY_SIZE = sizeof(int);
const int INTERNAL_NODE_CHILD_SIZE = sizeof(int);
const int INTERNAL_NODE_CELL_SIZE = INTERNAL_NODE_KEY_SIZE + INTERNAL_NODE_RIGHT_CHILD_SIZE;

/*
 * Internal node max cells
 */
const int INTERNAL_NODE_MAX_CELLS = 3;

class Node {
public:
    int* leaf_node_num_cells();
    void* leaf_node_cell(int cell_num);
    int* leaf_node_key(int cell_num);
    void* leaf_node_value(int cell_num);
    void leaf_node_init();
    int* leaf_node_next_leaf();
    NodeType get_node_type();
    void set_node_type(NodeType type);
    bool is_root_node();
    void set_root_node(bool is_root_node);
    Node(void* nodePos);

    int* internal_node_num_keys();
    int* internal_node_right_child();
    int* internal_node_cell(int cell_num);
    int* internal_node_child(int child_num);
    int* internal_node_key(int key_num);
    void internal_node_init();

    int get_node_max_key();

    int* node_parent();

    void update_internal_node_key(int old_max, int new_max);
    int internal_node_find_child(int old_key);
private:
    void* nodePos;
};

#endif //TINY_DB_NODE_H
