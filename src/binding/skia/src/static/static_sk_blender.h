//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_BLENDER_H
#define RAIA_SKIA_STATIC_SK_BLENDER_H

#include <string>
#include <map>
#include "include/core/SkBlender.h"

void static_sk_blender_delete(const char *key);
SkBlender *static_sk_blender_get(const char *key);
void static_sk_blender_set(const char *key, sk_sp<SkBlender> value);
sk_sp<SkBlender> static_sk_blender_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_BLENDER_H
