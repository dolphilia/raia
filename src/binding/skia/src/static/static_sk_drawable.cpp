//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_drawable.h"

static std::map<int , sk_sp<SkDrawable>> static_sk_drawable;

void static_sk_drawable_delete(int key) {
    static_sk_drawable[key].reset();
    static_sk_drawable.erase(key);
}

SkDrawable *static_sk_drawable_get(int key) {
    return static_sk_drawable[key].get();
}

void static_sk_drawable_set(int key, sk_sp<SkDrawable> value) {
    static_sk_drawable[key] = std::move(value);
}

sk_sp<SkDrawable> static_sk_drawable_move(int key) {
    return std::move(static_sk_drawable[key]);
}