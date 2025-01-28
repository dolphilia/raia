//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_runtime_effect_traced_shader.h"

#include <utility>
#include "static_sk_runtime_effect_traced_shader-internal.h"

static std::set<int> static_sk_runtime_effect_traced_shader_available_keys;
static std::map<int , SkRuntimeEffect::TracedShader> static_sk_runtime_effect_traced_shader;
static int static_sk_runtime_effect_traced_shader_index = 0;

int static_sk_runtime_effect_traced_shader_make(SkRuntimeEffect::TracedShader value) {
    int key;
    if (!static_sk_runtime_effect_traced_shader_available_keys.empty()) {
        auto it = static_sk_runtime_effect_traced_shader_available_keys.begin();
        key = *it;
        static_sk_runtime_effect_traced_shader_available_keys.erase(it);
    } else {
        key = static_sk_runtime_effect_traced_shader_index++;
    }
    static_sk_runtime_effect_traced_shader[key] = std::move(value);
    return key;
}

// const

void static_sk_runtime_effect_traced_shader_delete(int key) {
    static_sk_runtime_effect_traced_shader.erase(key);
    static_sk_runtime_effect_traced_shader_available_keys.insert(key);
}

SkRuntimeEffect::TracedShader static_sk_runtime_effect_traced_shader_get(int key) {
    return static_sk_runtime_effect_traced_shader[key];
}

void * static_sk_runtime_effect_traced_shader_get_ptr(int key) { // -> SkRuntimeEffect::TracedShader *
    return &static_sk_runtime_effect_traced_shader[key];
}

void static_sk_runtime_effect_traced_shader_set(int key, SkRuntimeEffect::TracedShader value) {
    static_sk_runtime_effect_traced_shader[key] = std::move(value);
}
