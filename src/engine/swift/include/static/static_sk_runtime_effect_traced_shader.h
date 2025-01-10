//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_TRACED_SHADER_H
#define RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_TRACED_SHADER_H

#include <set>
#include <string>
#include <map>
#include "include/effects/SkRuntimeEffect.h"

typedef int sk_runtime_effect_traced_shader_t;

// const
int static_sk_runtime_effect_traced_shader_make(SkRuntimeEffect::TracedShader value);
extern "C" void static_sk_runtime_effect_traced_shader_delete(int key);
SkRuntimeEffect::TracedShader static_sk_runtime_effect_traced_shader_get(int key);
void static_sk_runtime_effect_traced_shader_set(int key, SkRuntimeEffect::TracedShader value);

#endif //RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_TRACED_SHADER_H
