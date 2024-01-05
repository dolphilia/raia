//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_blender.h"

static std::map<std::string, sk_sp<SkBlender>> static_sk_blender;

void static_sk_blender_delete(const char *key) {
    static_sk_blender[key].reset();
    static_sk_blender.erase(key);
}

SkBlender *static_sk_blender_get(const char *key) {
    return static_sk_blender[key].get();
}

void static_sk_blender_set(const char *key, sk_sp<SkBlender> value) {
    static_sk_blender[key] = std::move(value);
}

sk_sp<SkBlender> static_sk_blender_move(const char *key) {
    return std::move(static_sk_blender[key]);
}