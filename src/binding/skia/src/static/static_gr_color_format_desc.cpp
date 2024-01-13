//
// Created by dolphilia on 2024/01/12.
//

#include "static_gr_color_format_desc.h"

static std::map<std::string, GrColorFormatDesc> static_gr_color_format_desc;

void static_gr_color_format_desc_delete(const char *key) {
    static_gr_color_format_desc.erase(key);
}

GrColorFormatDesc static_gr_color_format_desc_get(const char *key) {
    return static_gr_color_format_desc.at(key);
}

void static_gr_color_format_desc_set(const char *key, GrColorFormatDesc value) {
    static_gr_color_format_desc.at(key) = value;
}