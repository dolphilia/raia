//
// Created by dolphilia on 2024/01/08.
//

#include "static_sk_color_matrix.h"

static std::map<std::string, SkColorMatrix> static_sk_color_matrix;

void static_sk_color_matrix_delete(const char *key) {
    static_sk_color_matrix.erase(key);
}

SkColorMatrix static_sk_color_matrix_get(const char *key) {
    return static_sk_color_matrix[key];
}

void static_sk_color_matrix_set(const char *key, SkColorMatrix value) {
    static_sk_color_matrix[key] = value;
}