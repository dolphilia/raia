//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_color_table.h"

#include <utility>
#include "static_sk_color_table-internal.h"

static std::set<int> static_sk_color_table_available_keys;
static std::map<int , sk_sp<SkColorTable>> static_sk_color_table;
static int static_sk_color_table_index = 0;

int static_sk_color_table_make(sk_sp<SkColorTable> value) {
    int key;
    if (!static_sk_color_table_available_keys.empty()) {
        auto it = static_sk_color_table_available_keys.begin();
        key = *it;
        static_sk_color_table_available_keys.erase(it);
    } else {
        key = static_sk_color_table_index++;
    }
    static_sk_color_table[key] = std::move(value);
    return key;
}

void static_sk_color_table_delete(int key) {
    static_sk_color_table[key].reset();
    static_sk_color_table.erase(key);
    static_sk_color_table_available_keys.insert(key);
}

void *static_sk_color_table_get(int key) { // -> SkColorTable *
    return static_sk_color_table[key].get();
}

void static_sk_color_table_set(int key, sk_sp<SkColorTable> value) {
    static_sk_color_table[key] = std::move(value);
}

sk_sp<SkColorTable> static_sk_color_table_move(int key) {
    return std::move(static_sk_color_table[key]);
}
