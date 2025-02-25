#ifndef STATIC_SK_COLOR_SPACE_INTERNAL_H
#define STATIC_SK_COLOR_SPACE_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkColorSpace.h"
int static_sk_color_space_make(sk_sp<SkColorSpace> value);
void static_sk_color_space_set(int key, sk_sp<SkColorSpace> value);
sk_sp<SkColorSpace> static_sk_color_space_get_entity(int key);
#endif // STATIC_SK_COLOR_SPACE_INTERNAL_H
