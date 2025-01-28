//
// Created by dolphilia on 2024/01/12.
//

#include "static_std_string_view.h"

#include <map>
#include "static_std_string_view-internal.h"

static std::set<int> static_string_view_available_keys;
static std::map<int , std::string_view> static_string_view;
static int static_string_view_index = 0;

int static_string_view_make(std::string_view value) {
    int key;
    if (!static_string_view_available_keys.empty()) {
        auto it = static_string_view_available_keys.begin();
        key = *it;
        static_string_view_available_keys.erase(it);
    } else {
        key = static_string_view_index++;
    }
    static_string_view[key] = value;
    return key;
}

void static_string_view_delete(int key) {
    static_string_view.erase(key);
    static_string_view_available_keys.insert(key);
}

std::string_view static_string_view_get(int key) {
    return static_string_view[key];
}

void static_string_view_set(int key, std::string_view value) {
    static_string_view[key] = value;
}
