//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_I_RECT_H
#define RAIA_SKIA_STATIC_SK_I_RECT_H

#include <string>
#include <map>
#include "include/core/SkRect.h"

void static_sk_i_rect_delete(const char *key);
SkIRect static_sk_i_rect_get(const char *key);
void static_sk_i_rect_set(const char *key, SkIRect value);

#endif //RAIA_SKIA_STATIC_SK_I_RECT_H
