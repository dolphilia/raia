//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_color_table.h"

static std::map<int , sk_sp<SkColorTable>> static_sk_color_table;

void static_sk_color_table_delete(int key) {
    static_sk_color_table[key].reset();
    static_sk_color_table.erase(key);
}

SkColorTable *static_sk_color_table_get(int key) {
    return static_sk_color_table[key].get();
}

void static_sk_color_table_set(int key, sk_sp<SkColorTable> value) {
    static_sk_color_table[key] = std::move(value);
}

sk_sp<SkColorTable> static_sk_color_table_move(int key) {
    return std::move(static_sk_color_table[key]);
}