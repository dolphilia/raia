//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_runtime_effect_traced_shader.h"

static std::map<std::string, SkRuntimeEffect::TracedShader> static_sk_runtime_effect_traced_shader;

// const

void static_sk_runtime_effect_traced_shader_delete(const char *key) {
    static_sk_runtime_effect_traced_shader.erase(key);
}

SkRuntimeEffect::TracedShader static_sk_runtime_effect_traced_shader_get(const char *key) {
    return static_sk_runtime_effect_traced_shader[key];
}

void static_sk_runtime_effect_traced_shader_set(const char *key, SkRuntimeEffect::TracedShader value) {
    static_sk_runtime_effect_traced_shader[key] = std::move(value);
}