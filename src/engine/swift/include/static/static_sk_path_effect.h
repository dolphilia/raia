//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_PATH_EFFECT_H
#define RAIA_SKIA_STATIC_SK_PATH_EFFECT_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkPathEffect.h"
#include "export_api.h"

typedef int sk_path_effect_t;

extern "C" {
RAIA_API void static_sk_path_effect_delete(int key);
RAIA_API SkPathEffect *static_sk_path_effect_get(int key);
}

int static_sk_path_effect_make(sk_sp<SkPathEffect> value);
void static_sk_path_effect_set(int key, sk_sp<SkPathEffect> value);
sk_sp<SkPathEffect> static_sk_path_effect_move(int key);

#endif //RAIA_SKIA_STATIC_SK_PATH_EFFECT_H
