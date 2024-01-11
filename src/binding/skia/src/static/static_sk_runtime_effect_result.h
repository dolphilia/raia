//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_RESULT_H
#define RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_RESULT_H

#include <string>
#include <map>
#include <utility>
#include "include/effects/SkRuntimeEffect.h"

// const
void static_sk_runtime_effect_result_delete(const char *key);
SkRuntimeEffect::Result static_sk_runtime_effect_result_get(const char *key);
void static_sk_runtime_effect_result_set(const char *key, SkRuntimeEffect::Result value);

#endif //RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_RESULT_H
