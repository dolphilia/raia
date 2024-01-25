//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_data_table.h"

static std::map<int , sk_sp<SkDataTable>> static_sk_data_table;

void static_sk_data_table_delete(int key) {
    static_sk_data_table[key].reset();
    static_sk_data_table.erase(key);
}

SkDataTable *static_sk_data_table_get(int key) {
    return static_sk_data_table[key].get();
}

void static_sk_data_table_set(int key, sk_sp<SkDataTable> value) {
    static_sk_data_table[key] = std::move(value);
}

sk_sp<SkDataTable> static_sk_data_table_move(int key) {
    return std::move(static_sk_data_table[key]);
}