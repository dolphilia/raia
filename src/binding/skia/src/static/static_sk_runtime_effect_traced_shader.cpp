//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_runtime_effect_traced_shader.h"

#include <utility>

static std::map<int , SkRuntimeEffect::TracedShader> static_sk_runtime_effect_traced_shader;
static int static_sk_runtime_effect_traced_shader_index = 0;

int static_sk_runtime_effect_traced_shader_make(SkRuntimeEffect::TracedShader value) {
    static_sk_runtime_effect_traced_shader[static_sk_runtime_effect_traced_shader_index] = std::move(value);
    static_sk_runtime_effect_traced_shader_index++;
    return static_sk_runtime_effect_traced_shader_index - 1;
}

// const

void static_sk_runtime_effect_traced_shader_delete(int key) {
    static_sk_runtime_effect_traced_shader.erase(key);
}

SkRuntimeEffect::TracedShader static_sk_runtime_effect_traced_shader_get(int key) {
    return static_sk_runtime_effect_traced_shader[key];
}

void static_sk_runtime_effect_traced_shader_set(int key, SkRuntimeEffect::TracedShader value) {
    static_sk_runtime_effect_traced_shader[key] = std::move(value);
}