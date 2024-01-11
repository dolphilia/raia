//
// Created by dolphilia on 2024/01/09.
//

#include "static_sk_blend_mode.h"

static std::map<std::string, std::optional<SkBlendMode>> static_optional_sk_blend_mode;

void static_optional_sk_blend_mode_delete(const char *key) {
    static_optional_sk_blend_mode[key].reset();
    static_optional_sk_blend_mode.erase(key);
}

SkBlendMode static_optional_sk_blend_mode_get(const char *key) {
    return *static_optional_sk_blend_mode[key];
}

void static_optional_sk_blend_mode_set(const char *key, std::optional<SkBlendMode> value) {
    static_optional_sk_blend_mode[key] = value;
}

std::optional<SkBlendMode> static_optional_sk_blend_mode_move(const char *key) {
    return static_optional_sk_blend_mode[key];
}