//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_runtime_effect_uniform.h"

static std::map<std::string, SkSpan<const SkRuntimeEffect::Uniform>> static_const_sk_runtime_effect_uniform;

// const

void static_const_sk_runtime_effect_uniform_delete(const char *key) {
    static_const_sk_runtime_effect_uniform.erase(key);
}

SkSpan<const SkRuntimeEffect::Uniform> static_const_sk_runtime_effect_uniform_get(const char *key) {
    return static_const_sk_runtime_effect_uniform[key];
}

void static_const_sk_runtime_effect_uniform_set(const char *key, SkSpan<const SkRuntimeEffect::Uniform> value) {
    static_const_sk_runtime_effect_uniform[key] = value;
}