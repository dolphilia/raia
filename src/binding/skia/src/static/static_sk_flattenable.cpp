//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_flattenable.h"

#include <utility>

static std::map<int , sk_sp<SkFlattenable>> static_sk_flattenable;
static int static_sk_flattenable_index = 0;

int static_sk_flattenable_make(sk_sp<SkFlattenable> value) {
    static_sk_flattenable[static_sk_flattenable_index] = std::move(value);
    static_sk_flattenable_index++;
    return static_sk_flattenable_index - 1;
}

void static_sk_flattenable_delete(int key) {
    static_sk_flattenable[key].reset();
    static_sk_flattenable.erase(key);
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