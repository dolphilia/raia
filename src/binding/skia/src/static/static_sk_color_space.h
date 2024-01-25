//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_COLOR_SPACE_H
#define RAIA_SKIA_STATIC_SK_COLOR_SPACE_H

#include <string>
#include <map>
#include "include/core/SkColorSpace.h"

void static_sk_color_space_delete(int key);
SkColorSpace *static_sk_color_space_get(int key);
void static_sk_color_space_set(int key, sk_sp<SkColorSpace> value);
sk_sp<SkColorSpace> static_sk_color_space_move(int key);

#endif //RAIA_SKIA_STATIC_SK_COLOR_SPACE_H
