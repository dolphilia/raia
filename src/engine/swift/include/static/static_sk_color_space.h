//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_COLOR_SPACE_H
#define RAIA_SKIA_STATIC_SK_COLOR_SPACE_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkColorSpace.h"
#include "export_api.h"

typedef int sk_color_space_t;

extern "C" {
RAIA_API void static_sk_color_space_delete(int key);
RAIA_API SkColorSpace *static_sk_color_space_get(int key);
}

int static_sk_color_space_make(sk_sp<SkColorSpace> value);
void static_sk_color_space_set(int key, sk_sp<SkColorSpace> value);
sk_sp<SkColorSpace> static_sk_color_space_move(int key);

#endif //RAIA_SKIA_STATIC_SK_COLOR_SPACE_H
