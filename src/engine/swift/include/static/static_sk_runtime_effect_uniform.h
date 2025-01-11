//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_UNIFORM_H
#define RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_UNIFORM_H

#include <set>
#include <string>
#include <map>
#include "include/effects/SkRuntimeEffect.h"
#include "export_api.h"

typedef int const_sk_runtime_effect_uniform_t;

extern "C" {
RAIA_API void static_const_sk_runtime_effect_uniform_delete(int key);
RAIA_API const SkRuntimeEffect::Uniform * static_const_sk_runtime_effect_uniform_get(int key, int index);
}

// const
int static_const_sk_runtime_effect_uniform_make(SkSpan<const SkRuntimeEffect::Uniform> value);
SkSpan<const SkRuntimeEffect::Uniform> static_const_sk_runtime_effect_uniform_get(int key);
void static_const_sk_runtime_effect_uniform_set(int key, SkSpan<const SkRuntimeEffect::Uniform> value);

#endif //RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_UNIFORM_H
