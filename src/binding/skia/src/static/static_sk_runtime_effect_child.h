//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_CHILD_H
#define RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_CHILD_H

#include <string>
#include <map>
#include "include/effects/SkRuntimeEffect.h"

// const
void static_const_sk_runtime_effect_child_delete(const char *key);
SkSpan<const SkRuntimeEffect::Child> static_const_sk_runtime_effect_child_get(const char *key);
void static_const_sk_runtime_effect_child_set(const char *key, SkSpan<const SkRuntimeEffect::Child> value);

#endif //RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_CHILD_H
