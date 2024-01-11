//
// Created by dolphilia on 2024/01/04.
//

#ifndef RAIA_SKIA_STATIC_SK_RECT_H
#define RAIA_SKIA_STATIC_SK_RECT_H

#include <string>
#include <map>
#include "include/core/SkRect.h"

void static_sk_rect_delete(const char *key);
SkRect static_sk_rect_get(const char *key);
void static_sk_rect_set(const char *key, SkRect value);

#endif //RAIA_SKIA_STATIC_SK_RECT_H
