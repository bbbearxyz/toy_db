//
// Created by 马子杰 on 2020/9/16.
//

#ifndef TINY_DB_ROW_H
#define TINY_DB_ROW_H

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255
#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

class Row {
public:
    void print_row();
    static void serialize_row(Row* source, void* destination);
    static void deserialize_row(void* source, Row* destination);
    int id;
    char username[COLUMN_USERNAME_SIZE + 1];
    char email[COLUMN_EMAIL_SIZE + 1];
};

const int ID_SIZE = size_of_attribute(Row, id);
const int USERNAME_SIZE = size_of_attribute(Row, username);
const int EMAIL_SIZE = size_of_attribute(Row, email);
const int ID_OFFSET = 0;
const int USERNAME_OFFSET = ID_SIZE;
const int EMAIL_OFFSET = ID_SIZE + USERNAME_SIZE;
const int ROW_SIZE = ID_SIZE + USERNAME_SIZE + EMAIL_SIZE;


#endif //TINY_DB_ROW_H
