//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_I_RECT_H
#define RAIA_SKIA_STATIC_SK_I_RECT_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkRect.h"
#include "export_api.h"

typedef int sk_i_rect_t;

extern "C" {
RAIA_API void static_sk_i_rect_delete(int key);
RAIA_API SkIRect * static_sk_i_rect_get_ptr(int key);
}

int static_sk_i_rect_make(SkIRect value);
SkIRect static_sk_i_rect_get(int key);
void static_sk_i_rect_set(int key, SkIRect value);

#endif //RAIA_SKIA_STATIC_SK_I_RECT_H
