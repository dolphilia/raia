//
// Created by dolphilia on 2024/01/04.
//

#ifndef RAIA_SKIA_STATIC_SK_RECT_H
#define RAIA_SKIA_STATIC_SK_RECT_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkRect.h"
#include "export_api.h"

typedef int sk_rect_t;

extern "C" {
RAIA_API void static_sk_rect_delete(int key);
RAIA_API SkRect *static_sk_rect_get_ptr(int key);
}

int static_sk_rect_make(SkRect value);
SkRect static_sk_rect_get(int key);
void static_sk_rect_set(int key, SkRect value);

#endif //RAIA_SKIA_STATIC_SK_RECT_H
