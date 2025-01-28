//
// Created by dolphilia on 2024/04/08.
//

#include "static_sk_runtime_effect_builder_builder_uniform.h"
#include "static_sk_runtime_effect_builder_builder_uniform-internal.h"

static std::set<int> static_sk_runtime_effect_builder_builder_uniform_available_keys;
static std::map<int , SkRuntimeEffectBuilder::BuilderUniform> static_sk_runtime_effect_builder_builder_uniform;
static int static_sk_runtime_effect_builder_builder_uniform_index = 0;

int static_sk_runtime_effect_builder_builder_uniform_make(SkRuntimeEffectBuilder::BuilderUniform value) {
    int key;
    if (!static_sk_runtime_effect_builder_builder_uniform_available_keys.empty()) {
        auto it = static_sk_runtime_effect_builder_builder_uniform_available_keys.begin();
        key = *it;
        static_sk_runtime_effect_builder_builder_uniform_available_keys.erase(it);
    } else {
        key = static_sk_runtime_effect_builder_builder_uniform_index++;
    }
    static_sk_runtime_effect_builder_builder_uniform[key] = value;
    return key;
}

void static_sk_runtime_effect_builder_builder_uniform_delete(int key) {
    static_sk_runtime_effect_builder_builder_uniform.erase(key);
    static_sk_runtime_effect_builder_builder_uniform_available_keys.insert(key);
}

SkRuntimeEffectBuilder::BuilderUniform static_sk_runtime_effect_builder_builder_uniform_get(int key) {
    return static_sk_runtime_effect_builder_builder_uniform[key];
}

void * static_sk_runtime_effect_builder_builder_uniform_get_ptr(int key) { // -> SkRuntimeEffectBuilder::BuilderUniform *
    return &static_sk_runtime_effect_builder_builder_uniform[key];
}

void static_sk_runtime_effect_builder_builder_uniform_set(int key, SkRuntimeEffectBuilder::BuilderUniform value) {
    static_sk_runtime_effect_builder_builder_uniform[key] = value;
}
