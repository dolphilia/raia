//
// Created by dolphilia on 2024/01/06.
//

#include "static_sk_matrix.h"

static std::map<std::string, SkMatrix> static_sk_matrix;

void static_sk_matrix_delete(const char *key) {
    static_sk_matrix.erase(key);
}

SkMatrix static_sk_matrix_get(const char *key) {
    return static_sk_matrix[key];
}

void static_sk_matrix_set(const char *key, SkMatrix value) {
    static_sk_matrix[key] = value;
}