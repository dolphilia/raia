//
// Created by dolphilia on 2024/01/12.
//

#include "static_sk_runtime_effect.h"

static std::map<std::string, sk_sp<SkRuntimeEffect>> static_sk_runtime_effect;

void static_sk_runtime_effect_delete(const char *key) {
    static_sk_runtime_effect[key].reset();
    static_sk_runtime_effect.erase(key);
}

SkRuntimeEffect *static_sk_runtime_effect_get(const char *key) {
    return static_sk_runtime_effect[key].get();
}

void static_sk_runtime_effect_set(const char *key, sk_sp<SkRuntimeEffect> value) {
    static_sk_runtime_effect[key] = std::move(value);
}

sk_sp<SkRuntimeEffect> static_sk_runtime_effect_move(const char *key) {
    return std::move(static_sk_runtime_effect[key]);
}