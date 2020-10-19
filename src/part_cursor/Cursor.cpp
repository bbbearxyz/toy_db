//
// Created by 马子杰 on 2020/9/20.
//
#include <iostream>
#include "Cursor.h"
#include "../part_tree/Node.h"

Cursor* Cursor::table_start(Table *table) {
    Cursor* cursor = table_find(table, 0);

    void* node_pos = table->pager->get_page(cursor->page_num);
    Node* node = new Node(node_pos);
    int num_cells = *node->leaf_node_num_cells();
    cursor->end_of_table = (num_cells == 0);

    delete node;
    return cursor;
}


void* Cursor::cursor_value() {
    int page_num = this->page_num;
    void* page = this->table->pager->get_page(page_num);
    Node* node = new Node(page);
    void* res = node->leaf_node_value(this->cell_num);
    delete node;
    return res;

}

void Cursor::cursor_advance() {
    int page_num = this->page_num;
    void* page = this->table->pager->get_page(page_num);
    Node* node = new Node(page);
    this->cell_num += 1;
    if (this->cell_num >= *node->leaf_node_num_cells()) {
        int next_page_num = *node->leaf_node_next_leaf();
        if (next_page_num == 0) {
            this->end_of_table = true;
        } else {
            this->page_num = next_page_num;
            this->cell_num = 0;
        }
    }
    delete node;
}

Cursor * Cursor::table_find(Table *table, int key_to_insert) {
    int root_page_num = table->root_page_num;
    Node* root_node = new Node(table->pager->get_page(root_page_num));

    if (root_node->get_node_type() == NODE_LEAF) {
        return table_find_leaf(table, root_page_num,key_to_insert);
    } else {
        return table_find_internal(table, root_page_num, key_to_insert);
    }

}

Cursor * Cursor::table_find_leaf(Table *table, int root_page_num, int key_to_insert) {
    Cursor* cursor = new Cursor();
    cursor->table = table;
    cursor->page_num = root_page_num;

    void* root_page_pos = table->pager->get_page(root_page_num);
    Node* node = new Node(root_page_pos);

    int minIndex = 0;
    int maxIndex = *node->leaf_node_num_cells();
    while (minIndex != maxIndex) {
        int find_index = (minIndex + maxIndex) / 2;
        int index_key = *node->leaf_node_key(find_index);
        if (index_key == key_to_insert) {
            cursor->cell_num = find_index;
            return cursor;
        }
        if (index_key < key_to_insert) {
            minIndex = find_index + 1;
        } else {
            maxIndex = find_index;
        }
    }
    cursor->cell_num = minIndex;
    return cursor;


}

Cursor * Cursor::table_find_internal(Table *table, int page_num, int key_to_insert) {
    void* node_pos = table->pager->get_page(page_num);
    Node* node = new Node(node_pos);
    int num_keys = *node->internal_node_num_keys();
    int min_index = 0, max_index = num_keys;
    while (min_index != max_index) {
        int index = (min_index + max_index) / 2;
        int key = *node->internal_node_key(index);
        if (key >= key_to_insert) {
            max_index = index;
        } else {
            min_index = index + 1;
        }
    }
    int child_num;
    void* child_pos;
    Node* child_node;
    if (min_index < num_keys) {
        child_num = *node->internal_node_child(min_index);
        child_pos = table->pager->get_page(child_num);
        child_node = new Node(child_pos);
    } else if (min_index == num_keys) {
        child_num = *node->internal_node_right_child();
        child_pos = table->pager->get_page(child_num);
        child_node = new Node(child_pos);
    }
    if (child_node->get_node_type() == NODE_LEAF) {
        return table_find_leaf(table, child_num, key_to_insert);
    } else {
        return table_find_internal(table, child_num, key_to_insert);
    }


}

bool Cursor::is_end_of_table() {return this->end_of_table;}

void Cursor::leaf_node_insert(int key, Row *value) {
    void* node_pos = this->table->pager->get_page(this->page_num);
    Node* node = new Node(node_pos);
    int num_cells = *node->leaf_node_num_cells();
    if (num_cells >= LEAF_NODE_MAX_CELLS) {
        leaf_node_split_and_insert(key, value);
        return;
    }

    if (this->cell_num < num_cells) {
        for (int i = num_cells; i > this->cell_num; i -- ) {
            memcpy(node->leaf_node_cell(i), node->leaf_node_cell(i - 1), LEAF_NODE_CELL_SIZE);
        }
    }
    *node->leaf_node_num_cells() += 1;

    *(node->leaf_node_key(this->cell_num)) = key;
    Row::serialize_row(value, node->leaf_node_value(this->cell_num));
    delete node;

}

void Cursor::leaf_node_split_and_insert(int key, Row *value) {
    void* old_node_pos = this->table->pager->get_page(this->page_num);
    Node* old_node = new Node(old_node_pos);
    int old_max = old_node->get_node_max_key();
    int new_page_num = this->table->pager->get_unused_page_num();
    void* new_node_pos = this->table->pager->get_page(new_page_num);
    Node* new_node = new Node(new_node_pos);
    *new_node->node_parent() = *old_node->node_parent();
    new_node->leaf_node_init();
    *(new_node->leaf_node_next_leaf()) = *(old_node->leaf_node_next_leaf());
    *(old_node->leaf_node_next_leaf()) = new_page_num;

    for (int i = LEAF_NODE_MAX_CELLS; i >= 0; i -- ) {
        Node* destination_node;
        if (i >= LEAF_NODE_LEFT_SPLIT_COUNT) {
            destination_node = new Node(new_node_pos);
        } else {
            destination_node = new Node(old_node_pos);
        }
        int index_in_node = i % LEAF_NODE_LEFT_SPLIT_COUNT;
        void* destination = destination_node->leaf_node_cell(index_in_node);
        if (i == this->cell_num) {
            Row::serialize_row(value, destination_node->leaf_node_value(index_in_node));
            *destination_node->leaf_node_key(index_in_node) = key;
        } else if (i > this->cell_num) {
            memcpy(destination, old_node->leaf_node_cell(i - 1), LEAF_NODE_CELL_SIZE);
        } else {
            memcpy(destination, old_node->leaf_node_cell(i), LEAF_NODE_CELL_SIZE);
        }
    }
    *(old_node->leaf_node_num_cells()) = LEAF_NODE_LEFT_SPLIT_COUNT;
    *(new_node->leaf_node_num_cells()) = LEAF_NODE_RIGHT_SPLIT_COUNT;

    if (old_node->is_root_node()) {
        this->table->create_new_root(new_page_num);
    } else {
        int parent_page_num = *old_node->node_parent();
        int new_max = old_node->get_node_max_key();
        void* parent_node_pos = this->table->pager->get_page(parent_page_num);
        Node* parent_node = new Node(parent_node_pos);
        parent_node->update_internal_node_key(old_max, new_max);
        this->internal_node_insert(parent_page_num, new_page_num);
    }

    delete old_node;
    delete new_node;

}

int Cursor::get_cell_num() {return this->cell_num;}

int Cursor::get_page_num() {return this->page_num;}

Table * Cursor::get_table() {return this->table;}

void Cursor::internal_node_insert(int parent_page_num, int child_page_num) {

    void* parent_pos = this->table->pager->get_page(parent_page_num);
    void* child_pos = this->table->pager->get_page(child_page_num);

    Node* parent_node = new Node(parent_pos);
    Node* child_node = new Node(child_pos);
    int child_max_key = child_node->get_node_max_key();
    int index = parent_node->internal_node_find_child(child_max_key);
    int original_num_keys = *parent_node->internal_node_num_keys();
    *(parent_node->internal_node_num_keys()) = original_num_keys + 1;

    if (original_num_keys >= INTERNAL_NODE_MAX_CELLS) {
        std::cout << "Need to implement splitting internal node.\n" << std::endl;
        exit(EXIT_FAILURE);
    }


    int right_child_page_num = *parent_node->internal_node_right_child();
    void* right_child_pos = this->table->pager->get_page(right_child_page_num);
    Node* right_child_node = new Node(right_child_pos);

    if (child_max_key > right_child_node->get_node_max_key()) {
        *parent_node->internal_node_child(original_num_keys) = right_child_page_num;
        *parent_node->internal_node_key(original_num_keys) = right_child_node->get_node_max_key();
        *parent_node->internal_node_right_child() = child_page_num;
    } else {

        for (int i = original_num_keys; i > index; i -- ) {
            void* destination = parent_node->internal_node_cell(i);
            void* source = parent_node->internal_node_cell(i - 1);
            memcpy(destination, source, INTERNAL_NODE_CELL_SIZE);
        }
        *parent_node->internal_node_key(index) = child_node->get_node_max_key();
        *parent_node->internal_node_child(index) = child_page_num;

    }

    delete parent_node;
    delete child_node;
    delete right_child_node;
}