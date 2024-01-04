//
// Created by dolphilia on 2024/01/04.
//

#ifndef RAIA_SKIA_STATIC_SK_RECT_H
#define RAIA_SKIA_STATIC_SK_RECT_H

#include <string>
#include <map>
#include "include/core/SkRect.h"

void static_sk_rect_delete(const char *sk_rect_key);
SkRect static_sk_rect_get(const char *sk_rect_key);
void static_sk_rect_set(const char *sk_rect_key, SkRect rect);

#endif //RAIA_SKIA_STATIC_SK_RECT_H
