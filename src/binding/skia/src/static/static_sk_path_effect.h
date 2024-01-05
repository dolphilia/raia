//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_PATH_EFFECT_H
#define RAIA_SKIA_STATIC_SK_PATH_EFFECT_H

#include <string>
#include <map>
#include "include/core/SkPathEffect.h"

void static_sk_path_effect_delete(const char *key);
SkPathEffect *static_sk_path_effect_get(const char *key);
void static_sk_path_effect_set(const char *key, sk_sp<SkPathEffect> value);
sk_sp<SkPathEffect> static_sk_path_effect_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_PATH_EFFECT_H
