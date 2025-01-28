#ifndef STATIC_SK_BLENDER_INTERNAL_H
#define STATIC_SK_BLENDER_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkBlender.h"
int static_sk_blender_make(sk_sp<SkBlender> value);
void static_sk_blender_set(int key, sk_sp<SkBlender> value);
sk_sp<SkBlender> static_sk_blender_move(int key);
#endif // STATIC_SK_BLENDER_INTERNAL_H
