//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_CHILD_PTR_H
#define RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_CHILD_PTR_H

#include <set>
#include <string>
#include <map>
#include "include/effects/SkRuntimeEffect.h"

typedef int const_sk_runtime_effect_child_ptr_t;

// const
int static_const_sk_runtime_effect_child_ptr_make(SkSpan<const SkRuntimeEffect::ChildPtr> value);
extern "C" void static_const_sk_runtime_effect_child_ptr_delete(int key);
SkSpan<const SkRuntimeEffect::ChildPtr> static_const_sk_runtime_effect_child_ptr_get(int key);
void static_const_sk_runtime_effect_child_ptr_set(int key, SkSpan<const SkRuntimeEffect::ChildPtr> value);

#endif //RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_CHILD_PTR_H
