//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_RESULT_H
#define RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_RESULT_H

#include <set>
#include <string>
#include <map>
#include <utility>
#include "include/effects/SkRuntimeEffect.h"
#include "export_api.h"

typedef int sk_runtime_effect_result_t;

extern "C" {
RAIA_API void static_sk_runtime_effect_result_delete(int key);
RAIA_API SkRuntimeEffect::Result * static_sk_runtime_effect_result_get_ptr(int key);
}

// const
int static_sk_runtime_effect_result_make(SkRuntimeEffect::Result value);
SkRuntimeEffect::Result static_sk_runtime_effect_result_get(int key);
void static_sk_runtime_effect_result_set(int key, SkRuntimeEffect::Result value);

#endif //RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_RESULT_H
