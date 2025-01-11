//
// Created by dolphilia on 2024/04/08.
//

#ifndef RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_BUILDER_BUILDER_UNIFORM_H
#define RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_BUILDER_BUILDER_UNIFORM_H

#include <set>
#include <map>
#include "include/effects/SkRuntimeEffect.h"
#include "export_api.h"

typedef int sk_runtime_effect_builder_builder_uniform_t;

extern "C" {
RAIA_API void static_sk_runtime_effect_builder_builder_uniform_delete(int key);
RAIA_API SkRuntimeEffectBuilder::BuilderUniform * static_sk_runtime_effect_builder_builder_uniform_get_ptr(int key);
}

int static_sk_runtime_effect_builder_builder_uniform_make(SkRuntimeEffectBuilder::BuilderUniform value);
SkRuntimeEffectBuilder::BuilderUniform static_sk_runtime_effect_builder_builder_uniform_get(int key);
void static_sk_runtime_effect_builder_builder_uniform_set(int key, SkRuntimeEffectBuilder::BuilderUniform value);

#endif //RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_BUILDER_BUILDER_UNIFORM_H
