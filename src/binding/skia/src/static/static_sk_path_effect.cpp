//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_path_effect.h"

#include <utility>

static std::set<int> static_sk_path_effect_available_keys;
static std::map<int , sk_sp<SkPathEffect>> static_sk_path_effect;
static int static_sk_path_effect_index = 0;

int static_sk_path_effect_make(sk_sp<SkPathEffect> value) {
    int key;
    if (!static_sk_path_effect_available_keys.empty()) {
        auto it = static_sk_path_effect_available_keys.begin();
        key = *it;
        static_sk_path_effect_available_keys.erase(it);
    } else {
        key = static_sk_path_effect_index++;
    }
    static_sk_path_effect[key] = std::move(value);
    return key;
}

void static_sk_path_effect_delete(int key) {
    static_sk_path_effect[key].reset();
    static_sk_path_effect.erase(key);
    static_sk_path_effect_available_keys.insert(key);
}

SkPathEffect *static_sk_path_effect_get(int key) {
    return static_sk_path_effect[key].get();
}

void static_sk_path_effect_set(int key, sk_sp<SkPathEffect> value) {
    static_sk_path_effect[key] = std::move(value);
}

sk_sp<SkPathEffect> static_sk_path_effect_move(int key) {
    return std::move(static_sk_path_effect[key]);
}