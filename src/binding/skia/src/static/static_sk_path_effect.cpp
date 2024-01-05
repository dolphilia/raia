//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_path_effect.h"

static std::map<std::string, sk_sp<SkPathEffect>> static_sk_path_effect;

void static_sk_path_effect_delete(const char *key) {
    static_sk_path_effect[key].reset();
    static_sk_path_effect.erase(key);
}

SkPathEffect *static_sk_path_effect_get(const char *key) {
    return static_sk_path_effect[key].get();
}

void static_sk_path_effect_set(const char *key, sk_sp<SkPathEffect> value) {
    static_sk_path_effect[key] = std::move(value);
}

sk_sp<SkPathEffect> static_sk_path_effect_move(const char *key) {
    return std::move(static_sk_path_effect[key]);
}