//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_flattenable.h"

#include <utility>

static std::set<int> static_sk_flattenable_available_keys;
static std::map<int , sk_sp<SkFlattenable>> static_sk_flattenable;
static int static_sk_flattenable_index = 0;

int static_sk_flattenable_make(sk_sp<SkFlattenable> value) {
    int key;
    if (!static_sk_flattenable_available_keys.empty()) {
        auto it = static_sk_flattenable_available_keys.begin();
        key = *it;
        static_sk_flattenable_available_keys.erase(it);
    } else {
        key = static_sk_flattenable_index++;
    }
    static_sk_flattenable[key] = std::move(value);
    return key;
}

void static_sk_flattenable_delete(int key) {
    static_sk_flattenable[key].reset();
    static_sk_flattenable.erase(key);
    static_sk_flattenable_available_keys.insert(key);
}

SkFlattenable *static_sk_flattenable_get(int key) {
    return static_sk_flattenable[key].get();
}

void static_sk_flattenable_set(int key, sk_sp<SkFlattenable> value) {
    static_sk_flattenable[key] = std::move(value);
}

sk_sp<SkFlattenable> static_sk_flattenable_move(int key) {
    return std::move(static_sk_flattenable[key]);
}