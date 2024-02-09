//
// Created by dolphilia on 2024/02/05.
//

#include "static_std_vector_sk_svg_length.h"

static std::set<int> static_vector_sk_svg_length_available_keys;
static std::map<int , std::vector<SkSVGLength>> static_vector_sk_svg_length;
static int static_vector_sk_svg_length_index = 0;

int static_vector_sk_svg_length_make(std::vector<SkSVGLength> value) {
    int key;
    if (!static_vector_sk_svg_length_available_keys.empty()) {
        auto it = static_vector_sk_svg_length_available_keys.begin();
        key = *it;
        static_vector_sk_svg_length_available_keys.erase(it);
    } else {
        key = static_vector_sk_svg_length_index++;
    }
    static_vector_sk_svg_length[key] = std::move(value);
    return key;
}

void static_vector_sk_svg_length_delete(int key) {
    static_vector_sk_svg_length.erase(key);
    static_vector_sk_svg_length_available_keys.insert(key);
}

SkSVGLength static_vector_sk_svg_length_get(int key, int index) {
    return static_vector_sk_svg_length[key][index];
}

void static_vector_sk_svg_length_set(int key, std::vector<SkSVGLength> value) {
    static_vector_sk_svg_length[key] = std::move(value);
}

void static_vector_sk_svg_length_push_back(int key, SkSVGLength value) {
    static_vector_sk_svg_length[key].push_back(value);
}

void static_vector_sk_svg_length_insert(int key, int index, SkSVGLength value) {
    static_vector_sk_svg_length[key].insert(static_vector_sk_svg_length[key].begin() + index, value);
}

void static_vector_sk_svg_length_pop_back(int key) {
    static_vector_sk_svg_length[key].pop_back();
}

void static_vector_sk_svg_length_erase(int key, int index) {
    static_vector_sk_svg_length[key].erase(static_vector_sk_svg_length[key].begin() + index);
}