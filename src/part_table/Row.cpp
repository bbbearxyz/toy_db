//
// Created by 马子杰 on 2020/9/16.
//

#include <cstring>
#include <cstdio>
#include "Row.h"
#include "../part_process/Process.h"

void Row::serialize_row(Row *source, void *destination) {
    memcpy((char*)destination + ID_OFFSET, &(source->id), ID_SIZE);
    memcpy((char*)destination + USERNAME_OFFSET, &(source->username), USERNAME_SIZE);
    memcpy((char*)destination + EMAIL_OFFSET, &(source->email), EMAIL_SIZE);
}

void Row::deserialize_row(void *source, Row *destination) {
    memcpy(&(destination->id), source, ID_SIZE);
    memcpy(&(destination->username), (char *) source + USERNAME_OFFSET, USERNAME_SIZE);
    memcpy(&(destination->email), (char *) source + EMAIL_OFFSET, EMAIL_SIZE);
}

void Row::print_row() {
    printf("(%d, %s, %s)\n", this->id, this->username, this->email);
}