//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_CHILD_H
#define RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_CHILD_H

#include <set>
#include <string>
#include <map>
#include "include/effects/SkRuntimeEffect.h"
#include "export_api.h"

typedef int const_sk_runtime_effect_child_t;

extern "C" {
RAIA_API void static_const_sk_runtime_effect_child_delete(int key);
RAIA_API const SkRuntimeEffect::Child * static_const_sk_runtime_effect_child_get_ptr(int key, int index);
}

// const
int static_const_sk_runtime_effect_child_make(SkSpan<const SkRuntimeEffect::Child> value);
SkSpan<const SkRuntimeEffect::Child> static_const_sk_runtime_effect_child_get(int key);
void static_const_sk_runtime_effect_child_set(int key, SkSpan<const SkRuntimeEffect::Child> value);

#endif //RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_CHILD_H
