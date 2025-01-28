#ifndef STATIC_SK_PATH_EFFECT_INTERNAL_H
#define STATIC_SK_PATH_EFFECT_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkPathEffect.h"
int static_sk_path_effect_make(sk_sp<SkPathEffect> value);
void static_sk_path_effect_set(int key, sk_sp<SkPathEffect> value);
sk_sp<SkPathEffect> static_sk_path_effect_move(int key);
#endif // STATIC_SK_PATH_EFFECT_INTERNAL_H
