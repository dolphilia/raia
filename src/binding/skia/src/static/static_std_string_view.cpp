//
// Created by dolphilia on 2024/01/12.
//

#include "static_std_string_view.h"

#include <string>
#include <map>

static std::map<std::string, std::string_view> static_string_view;

void static_string_view_delete(const char *key) {
    static_string_view.erase(key);
}

std::string_view static_string_view_get(const char *key) {
    return static_string_view[key];
}

void static_string_view_set(const char *key, std::string_view value) {
    static_string_view[key] = value;
}