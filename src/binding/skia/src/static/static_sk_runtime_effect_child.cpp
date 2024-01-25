//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_runtime_effect_child.h"

static std::map<int , SkSpan<const SkRuntimeEffect::Child>> static_const_sk_runtime_effect_child;

// const

void static_const_sk_runtime_effect_child_delete(int key) {
    static_const_sk_runtime_effect_child.erase(key);
}

SkSpan<const SkRuntimeEffect::Child> static_const_sk_runtime_effect_child_get(int key) {
    return static_const_sk_runtime_effect_child[key];
}

void static_const_sk_runtime_effect_child_set(int key, SkSpan<const SkRuntimeEffect::Child> value) {
    static_const_sk_runtime_effect_child[key] = value;
}