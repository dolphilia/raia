//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_blender.h"

static std::map<int, sk_sp<SkBlender>> static_sk_blender;
static int static_sk_blender_index = 0;

int static_sk_blender_make(sk_sp<SkBlender> value) {
    static_sk_blender[static_sk_blender_index] = std::move(value);
    static_sk_blender_index++;
    return static_sk_blender_index - 1;
}

void static_sk_blender_delete(int key) {
    static_sk_blender[key].reset();
    static_sk_blender.erase(key);
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