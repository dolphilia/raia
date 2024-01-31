//
// Created by dolphilia on 2024/01/12.
//

#include "static_sk_runtime_effect.h"

#include <utility>

static std::map<int , sk_sp<SkRuntimeEffect>> static_sk_runtime_effect;
static int static_sk_runtime_effect_index = 0;

int static_sk_runtime_effect_make(sk_sp<SkRuntimeEffect> value) {
    static_sk_runtime_effect[static_sk_runtime_effect_index] = std::move(value);
    static_sk_runtime_effect_index++;
    return static_sk_runtime_effect_index - 1;
}

void static_sk_runtime_effect_delete(int key) {
    static_sk_runtime_effect[key].reset();
    static_sk_runtime_effect.erase(key);
}

SkRuntimeEffect *static_sk_runtime_effect_get(int key) {
    return static_sk_runtime_effect[key].get();
}

void static_sk_runtime_effect_set(int key, sk_sp<SkRuntimeEffect> value) {
    static_sk_runtime_effect[key] = std::move(value);
}

sk_sp<SkRuntimeEffect> static_sk_runtime_effect_move(int key) {
    return std::move(static_sk_runtime_effect[key]);
}