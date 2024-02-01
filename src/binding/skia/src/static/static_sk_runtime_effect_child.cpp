//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_runtime_effect_child.h"

static std::set<int> static_const_sk_runtime_effect_child_available_keys;
static std::map<int , SkSpan<const SkRuntimeEffect::Child>> static_const_sk_runtime_effect_child;
static int static_const_sk_runtime_effect_child_index = 0;

// const

int static_const_sk_runtime_effect_child_make(SkSpan<const SkRuntimeEffect::Child> value) {
    int key;
    if (!static_const_sk_runtime_effect_child_available_keys.empty()) {
        auto it = static_const_sk_runtime_effect_child_available_keys.begin();
        key = *it;
        static_const_sk_runtime_effect_child_available_keys.erase(it);
    } else {
        key = static_const_sk_runtime_effect_child_index++;
    }
    static_const_sk_runtime_effect_child[key] = value;
    return key;
}

void static_const_sk_runtime_effect_child_delete(int key) {
    static_const_sk_runtime_effect_child.erase(key);
    static_const_sk_runtime_effect_child_available_keys.insert(key);
}

SkSpan<const SkRuntimeEffect::Child> static_const_sk_runtime_effect_child_get(int key) {
    return static_const_sk_runtime_effect_child[key];
}

void static_const_sk_runtime_effect_child_set(int key, SkSpan<const SkRuntimeEffect::Child> value) {
    static_const_sk_runtime_effect_child[key] = value;
}