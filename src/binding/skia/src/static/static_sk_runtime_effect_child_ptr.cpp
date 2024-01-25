//
// Created by dolphilia on 2024/01/10.
//

#include "static_sk_runtime_effect_child_ptr.h"

static std::map<int , SkSpan<const SkRuntimeEffect::ChildPtr>> static_const_sk_runtime_effect_child_ptr;

// const

void static_const_sk_runtime_effect_child_ptr_delete(int key) {
    static_const_sk_runtime_effect_child_ptr.erase(key);
}

SkSpan<const SkRuntimeEffect::ChildPtr> static_const_sk_runtime_effect_child_ptr_get(int key) {
    return static_const_sk_runtime_effect_child_ptr[key];
}

void static_const_sk_runtime_effect_child_ptr_set(int key, SkSpan<const SkRuntimeEffect::ChildPtr> value) {
    static_const_sk_runtime_effect_child_ptr[key] = value;
}