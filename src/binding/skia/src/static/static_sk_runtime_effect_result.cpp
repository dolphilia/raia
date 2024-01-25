//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_runtime_effect_result.h"

#include <utility>

static std::map<int , SkRuntimeEffect::Result> static_sk_runtime_effect_result;
static int static_sk_runtime_effect_result_index = 0;

int static_sk_runtime_effect_result_make(SkRuntimeEffect::Result value) {
    static_sk_runtime_effect_result[static_sk_runtime_effect_result_index] = std::move(value);
    static_sk_runtime_effect_result_index++;
    return static_sk_runtime_effect_result_index - 1;
}

// const

void static_sk_runtime_effect_result_delete(int key) {
    static_sk_runtime_effect_result.erase(key);
}

SkRuntimeEffect::Result static_sk_runtime_effect_result_get(int key) {
    return static_sk_runtime_effect_result[key];
}

void static_sk_runtime_effect_result_set(int key, SkRuntimeEffect::Result value) {
    static_sk_runtime_effect_result[key] = std::move(value);
}