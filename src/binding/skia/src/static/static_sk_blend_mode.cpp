//
// Created by dolphilia on 2024/01/09.
//

#include "static_sk_blend_mode.h"

static std::map<int, std::optional<SkBlendMode>> static_optional_sk_blend_mode;

void static_optional_sk_blend_mode_delete(int key) {
    static_optional_sk_blend_mode[key].reset();
    static_optional_sk_blend_mode.erase(key);
}

SkBlendMode static_optional_sk_blend_mode_get(int key) {
    return *static_optional_sk_blend_mode[key];
}

void static_optional_sk_blend_mode_set(int key, std::optional<SkBlendMode> value) {
    static_optional_sk_blend_mode[key] = value;
}

std::optional<SkBlendMode> static_optional_sk_blend_mode_move(int key) {
    return static_optional_sk_blend_mode[key];
}