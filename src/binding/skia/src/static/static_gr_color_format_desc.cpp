//
// Created by dolphilia on 2024/01/12.
//

#include "static_gr_color_format_desc.h"

static std::set<int> static_gr_color_format_desc_available_keys;
static std::map<int, GrColorFormatDesc> static_gr_color_format_desc;
static int static_gr_color_format_desc_index = 0;

int static_gr_color_format_desc_make(GrColorFormatDesc value) {
    int key;
    if (!static_gr_color_format_desc_available_keys.empty()) {
        auto it = static_gr_color_format_desc_available_keys.begin();
        key = *it;
        static_gr_color_format_desc_available_keys.erase(it);
    } else {
        key = static_gr_color_format_desc_index++;
    }
    static_gr_color_format_desc.at(key) = value;
    return key;
}

void static_gr_color_format_desc_delete(int key) {
    static_gr_color_format_desc.erase(key);
    static_gr_color_format_desc_available_keys.insert(key);
}

GrColorFormatDesc static_gr_color_format_desc_get(int key) {
    return static_gr_color_format_desc.at(key);
}

void static_gr_color_format_desc_set(int key, GrColorFormatDesc value) {
    static_gr_color_format_desc.at(key) = value;
}