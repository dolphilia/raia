//
// Created by dolphilia on 2024/04/08.
//

#include "static_sk_runtime_effect_builder_builder_child.h"

static std::set<int> static_sk_runtime_effect_builder_builder_child_available_keys;
static std::map<int , SkRuntimeEffectBuilder::BuilderChild> static_sk_runtime_effect_builder_builder_child;
static int static_sk_runtime_effect_builder_builder_child_index = 0;

int static_sk_runtime_effect_builder_builder_child_make(SkRuntimeEffectBuilder::BuilderChild value) {
    int key;
    if (!static_sk_runtime_effect_builder_builder_child_available_keys.empty()) {
        auto it = static_sk_runtime_effect_builder_builder_child_available_keys.begin();
        key = *it;
        static_sk_runtime_effect_builder_builder_child_available_keys.erase(it);
    } else {
        key = static_sk_runtime_effect_builder_builder_child_index++;
    }
    static_sk_runtime_effect_builder_builder_child[key] = value;
    return key;
}

void static_sk_runtime_effect_builder_builder_child_delete(int key) {
    static_sk_runtime_effect_builder_builder_child.erase(key);
    static_sk_runtime_effect_builder_builder_child_available_keys.insert(key);
}

SkRuntimeEffectBuilder::BuilderChild static_sk_runtime_effect_builder_builder_child_get(int key) {
    return static_sk_runtime_effect_builder_builder_child[key];
}

void static_sk_runtime_effect_builder_builder_child_set(int key, SkRuntimeEffectBuilder::BuilderChild value) {
    static_sk_runtime_effect_builder_builder_child[key] = value;
}