//
// Created by dolphilia on 2024/01/08.
//

#include "static_std_vector_sk_scalar.h"

#include <utility>

static std::set<int> static_vector_float_available_keys;
static std::map<int , std::vector<SkScalar>> static_vector_float;
static int static_vector_float_index = 0;

int static_vector_sk_scalar_make(std::vector<SkScalar> value) {
    int key;
    if (!static_vector_float_available_keys.empty()) {
        auto it = static_vector_float_available_keys.begin();
        key = *it;
        static_vector_float_available_keys.erase(it);
    } else {
        key = static_vector_float_index++;
    }
    static_vector_float[key] = std::move(value);
    return key;
}

void static_vector_sk_scalar_delete(int key) {
    static_vector_float.erase(key);
    static_vector_float_available_keys.insert(key);
}

SkScalar static_vector_sk_scalar_get(int key, int index) {
    return static_vector_float[key][index];
}

void static_vector_sk_scalar_set(int key, std::vector<SkScalar> value) {
    static_vector_float[key] = std::move(value);
}

void static_vector_sk_scalar_push_back(int key, SkScalar value) {
    static_vector_float[key].push_back(value);
}

void static_vector_sk_scalar_insert(int key, int index, SkScalar value) {
    static_vector_float[key].insert(static_vector_float[key].begin() + index, value);
}

void static_vector_sk_scalar_pop_back(int key) {
    static_vector_float[key].pop_back();
}

void static_vector_sk_scalar_erase(int key, int index) {
    static_vector_float[key].erase(static_vector_float[key].begin() + index);
}