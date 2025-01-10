//
// Created by dolphilia on 2024/04/08.
//

#ifndef RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_BUILDER_BUILDER_CHILD_H
#define RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_BUILDER_BUILDER_CHILD_H

#include <set>
#include <map>
#include "include/effects/SkRuntimeEffect.h"

typedef int sk_runtime_effect_builder_builder_child_t;

int static_sk_runtime_effect_builder_builder_child_make(SkRuntimeEffectBuilder::BuilderChild value);
extern "C" void static_sk_runtime_effect_builder_builder_child_delete(int key);
SkRuntimeEffectBuilder::BuilderChild static_sk_runtime_effect_builder_builder_child_get(int key);
void static_sk_runtime_effect_builder_builder_child_set(int key, SkRuntimeEffectBuilder::BuilderChild value);

#endif //RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_BUILDER_BUILDER_CHILD_H
