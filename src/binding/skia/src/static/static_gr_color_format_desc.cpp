//
// Created by dolphilia on 2024/01/12.
//

#include "static_gr_color_format_desc.h"

static std::map<int, GrColorFormatDesc> static_gr_color_format_desc;
static int static_gr_color_format_desc_index = 0;

int static_gr_color_format_desc_make(GrColorFormatDesc value) {
    static_gr_color_format_desc.at(static_gr_color_format_desc_index) = value;
    static_gr_color_format_desc_index++;
    return static_gr_color_format_desc_index - 1;
}

void static_gr_color_format_desc_delete(int key) {
    static_gr_color_format_desc.erase(key);
}

GrColorFormatDesc static_gr_color_format_desc_get(int key) {
    return static_gr_color_format_desc.at(key);
}

void static_gr_color_format_desc_set(int key, GrColorFormatDesc value) {
    static_gr_color_format_desc.at(key) = value;
}