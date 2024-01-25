//
// Created by dolphilia on 2024/01/08.
//

#include "static_sk_color_matrix.h"

static std::map<int , SkColorMatrix> static_sk_color_matrix;
static int static_sk_color_matrix_index = 0;

int static_sk_color_matrix_make(SkColorMatrix value) {
    static_sk_color_matrix[static_sk_color_matrix_index] = value;
    static_sk_color_matrix_index++;
    return static_sk_color_matrix_index - 1;
}

void static_sk_color_matrix_delete(int key) {
    static_sk_color_matrix.erase(key);
}

SkColorMatrix static_sk_color_matrix_get(int key) {
    return static_sk_color_matrix[key];
}

void static_sk_color_matrix_set(int key, SkColorMatrix value) {
    static_sk_color_matrix[key] = value;
}