//
// Created by dolphilia on 2024/01/10.
//

#include "static_sk_runtime_effect_child_ptr.h"

static std::map<std::string, SkSpan<const SkRuntimeEffect::ChildPtr>> static_const_sk_runtime_effect_child_ptr;

// const

void static_const_sk_runtime_effect_child_ptr_delete(const char *key) {
    static_const_sk_runtime_effect_child_ptr.erase(key);
}

SkSpan<const SkRuntimeEffect::ChildPtr> static_const_sk_runtime_effect_child_ptr_get(const char *key) {
    return static_const_sk_runtime_effect_child_ptr[key];
}

void static_const_sk_runtime_effect_child_ptr_set(const char *key, SkSpan<const SkRuntimeEffect::ChildPtr> value) {
    static_const_sk_runtime_effect_child_ptr[key] = value;
}