//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_runtime_effect_result.h"

static std::map<std::string, SkRuntimeEffect::Result> static_sk_runtime_effect_result;

// const

void static_sk_runtime_effect_result_delete(const char *key) {
    static_sk_runtime_effect_result.erase(key);
}

SkRuntimeEffect::Result static_sk_runtime_effect_result_get(const char *key) {
    return static_sk_runtime_effect_result[key];
}

void static_sk_runtime_effect_result_set(const char *key, SkRuntimeEffect::Result value) {
    static_sk_runtime_effect_result[key] = std::move(value);
}