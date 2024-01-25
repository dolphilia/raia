//
// Created by dolphilia on 2024/01/06.
//

#include "static_sk_matrix.h"

static std::map<int , SkMatrix> static_sk_matrix;
static int static_sk_matrix_index = 0;

int static_sk_matrix_make(SkMatrix value) {
    static_sk_matrix[static_sk_matrix_index] = value;
    static_sk_matrix_index++;
    return static_sk_matrix_index - 1;
}

void static_sk_matrix_delete(int key) {
    static_sk_matrix.erase(key);
}

SkMatrix static_sk_matrix_get(int key) {
    return static_sk_matrix[key];
}

void static_sk_matrix_set(int key, SkMatrix value) {
    static_sk_matrix[key] = value;
}