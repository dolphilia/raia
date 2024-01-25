//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_H
#define RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_H

#include <string>
#include <map>
#include "include/effects/SkRuntimeEffect.h"

void static_sk_runtime_effect_delete(int key);
SkRuntimeEffect *static_sk_runtime_effect_get(int key);
void static_sk_runtime_effect_set(int key, sk_sp<SkRuntimeEffect> value);
sk_sp<SkRuntimeEffect> static_sk_runtime_effect_move(int key);

#endif //RAIA_SKIA_STATIC_SK_RUNTIME_EFFECT_H
