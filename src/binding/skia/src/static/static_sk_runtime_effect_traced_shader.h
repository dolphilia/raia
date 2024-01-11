//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_TRACED_SHADER_H
#define RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_TRACED_SHADER_H

#include <string>
#include <map>
#include "include/effects/SkRuntimeEffect.h"

// const
void static_sk_runtime_effect_traced_shader_delete(const char *key);
SkRuntimeEffect::TracedShader static_sk_runtime_effect_traced_shader_get(const char *key);
void static_sk_runtime_effect_traced_shader_set(const char *key, SkRuntimeEffect::TracedShader value);

#endif //RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_TRACED_SHADER_H