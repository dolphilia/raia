//
// Created by dolphilia on 2024/01/12.
//

#include "static_std_string_view.h"

#include <string>
#include <map>

static std::map<int , std::string_view> static_string_view;

void static_string_view_delete(int key) {
    static_string_view.erase(key);
}

std::string_view static_string_view_get(int key) {
    return static_string_view[key];
}

void static_string_view_set(int key, std::string_view value) {
    static_string_view[key] = value;
}