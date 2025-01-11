//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_CHILD_PTR_H
#define RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_CHILD_PTR_H

#include <set>
#include <string>
#include <map>
#include "include/effects/SkRuntimeEffect.h"
#include "export_api.h"

typedef int const_sk_runtime_effect_child_ptr_t;

extern "C" {
RAIA_API void static_const_sk_runtime_effect_child_ptr_delete(int key);
RAIA_API const SkRuntimeEffect::ChildPtr * static_const_sk_runtime_effect_child_ptr_get_ptr(int key, int index);
}

// const
int static_const_sk_runtime_effect_child_ptr_make(SkSpan<const SkRuntimeEffect::ChildPtr> value);
SkSpan<const SkRuntimeEffect::ChildPtr> static_const_sk_runtime_effect_child_ptr_get(int key);
void static_const_sk_runtime_effect_child_ptr_set(int key, SkSpan<const SkRuntimeEffect::ChildPtr> value);

#endif //RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_CHILD_PTR_H
