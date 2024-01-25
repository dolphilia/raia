//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_runtime_effect_uniform.h"

static std::map<int , SkSpan<const SkRuntimeEffect::Uniform>> static_const_sk_runtime_effect_uniform;
static int static_const_sk_runtime_effect_uniform_index = 0;

int static_const_sk_runtime_effect_uniform_make(SkSpan<const SkRuntimeEffect::Uniform> value) {
    static_const_sk_runtime_effect_uniform[static_const_sk_runtime_effect_uniform_index] = value;
    static_const_sk_runtime_effect_uniform_index++;
    return static_const_sk_runtime_effect_uniform_index - 1;
}

// const

void static_const_sk_runtime_effect_uniform_delete(int key) {
    static_const_sk_runtime_effect_uniform.erase(key);
}

SkSpan<const SkRuntimeEffect::Uniform> static_const_sk_runtime_effect_uniform_get(int key) {
    return static_const_sk_runtime_effect_uniform[key];
}

void static_const_sk_runtime_effect_uniform_set(int key, SkSpan<const SkRuntimeEffect::Uniform> value) {
    static_const_sk_runtime_effect_uniform[key] = value;
}