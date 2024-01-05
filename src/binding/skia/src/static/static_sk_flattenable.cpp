//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_flattenable.h"

static std::map<std::string, sk_sp<SkFlattenable>> static_sk_flattenable;

void static_sk_flattenable_delete(const char *key) {
    static_sk_flattenable[key].reset();
    static_sk_flattenable.erase(key);
}

SkFlattenable *static_sk_flattenable_get(const char *key) {
    return static_sk_flattenable[key].get();
}

void static_sk_flattenable_set(const char *key, sk_sp<SkFlattenable> value) {
    static_sk_flattenable[key] = std::move(value);
}

sk_sp<SkFlattenable> static_sk_flattenable_move(const char *key) {
    return std::move(static_sk_flattenable[key]);
}