//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_blender.h"

static std::set<int> static_sk_blender_available_keys;
static std::map<int, sk_sp<SkBlender>> static_sk_blender;
static int static_sk_blender_index = 0;

int static_sk_blender_make(sk_sp<SkBlender> value) {
    int key;
    if (!static_sk_blender_available_keys.empty()) {
        auto it = static_sk_blender_available_keys.begin();
        key = *it;
        static_sk_blender_available_keys.erase(it);
    } else {
        key = static_sk_blender_index++;
    }
    static_sk_blender[key] = std::move(value);
    return key;
}

void static_sk_blender_delete(int key) {
    static_sk_blender[key].reset();
    static_sk_blender.erase(key);
    static_sk_blender_available_keys.insert(key);
}

SkBlender *static_sk_blender_get(int key) {
    return static_sk_blender[key].get();
}

void static_sk_blender_set(int key, sk_sp<SkBlender> value) {
    static_sk_blender[key] = std::move(value);
}

sk_sp<SkBlender> static_sk_blender_move(int key) {
    return std::move(static_sk_blender[key]);
}