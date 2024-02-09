//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_BLENDER_H
#define RAIA_SKIA_STATIC_SK_BLENDER_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkBlender.h"

typedef int sk_blender_t;

int static_sk_blender_make(sk_sp<SkBlender> value);
extern "C" void static_sk_blender_delete(int key);
extern "C" SkBlender *static_sk_blender_get(int key);
void static_sk_blender_set(int key, sk_sp<SkBlender> value);
sk_sp<SkBlender> static_sk_blender_move(int key);

#endif //RAIA_SKIA_STATIC_SK_BLENDER_H
