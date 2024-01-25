//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_UNIFORM_H
#define RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_UNIFORM_H

#include <string>
#include <map>
#include "include/effects/SkRuntimeEffect.h"

// const

void static_const_sk_runtime_effect_uniform_delete(int key);
SkSpan<const SkRuntimeEffect::Uniform> static_const_sk_runtime_effect_uniform_get(int key);
void static_const_sk_runtime_effect_uniform_set(int key, SkSpan<const SkRuntimeEffect::Uniform> value);

#endif //RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_UNIFORM_H
