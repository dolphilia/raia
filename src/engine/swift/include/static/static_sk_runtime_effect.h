//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_H
#define RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_H

#include <set>
#include <string>
#include <map>
#include "include/effects/SkRuntimeEffect.h"
#include "export_api.h"

typedef int sk_runtime_effect_t;

extern "C" {
RAIA_API void static_sk_runtime_effect_delete(int key);
RAIA_API SkRuntimeEffect *static_sk_runtime_effect_get(int key);
}

int static_sk_runtime_effect_make(sk_sp<SkRuntimeEffect> value);
void static_sk_runtime_effect_set(int key, sk_sp<SkRuntimeEffect> value);
sk_sp<SkRuntimeEffect> static_sk_runtime_effect_move(int key);

#endif //RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_H
