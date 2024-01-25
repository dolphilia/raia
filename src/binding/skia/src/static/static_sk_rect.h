//
// Created by dolphilia on 2024/01/04.
//

#ifndef RAIA_SKIA_STATIC_SK_RECT_H
#define RAIA_SKIA_STATIC_SK_RECT_H

#include <string>
#include <map>
#include "include/core/SkRect.h"

int static_sk_rect_make(SkRect value);
void static_sk_rect_delete(int key);
SkRect static_sk_rect_get(int key);
void static_sk_rect_set(int key, SkRect value);

#endif //RAIA_SKIA_STATIC_SK_RECT_H
