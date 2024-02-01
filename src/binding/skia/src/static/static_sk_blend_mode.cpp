//
// Created by dolphilia on 2024/01/09.
//

#include "static_sk_blend_mode.h"

static std::set<int> static_optional_sk_blend_mode_available_keys;
static std::map<int, std::optional<SkBlendMode>> static_optional_sk_blend_mode;
static int static_optional_sk_blend_mode_index = 0;

int static_optional_sk_blend_mode_make(std::optional<SkBlendMode> value) {
    int key;
    if (!static_optional_sk_blend_mode_available_keys.empty()) {
        auto it = static_optional_sk_blend_mode_available_keys.begin();
        key = *it;
        static_optional_sk_blend_mode_available_keys.erase(it);
    } else {
        key = static_optional_sk_blend_mode_index++;
    }
    static_optional_sk_blend_mode[key] = value;
}

void static_optional_sk_blend_mode_delete(int key) {
    static_optional_sk_blend_mode[key].reset();
    static_optional_sk_blend_mode.erase(key);
    static_optional_sk_blend_mode_available_keys.insert(key);
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