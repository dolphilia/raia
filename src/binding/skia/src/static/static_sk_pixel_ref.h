//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_PIXEL_REF_H
#define RAIA_SKIA_STATIC_SK_PIXEL_REF_H

#include <string>
#include <map>
#include "include/core/SkPixelRef.h"

void static_sk_pixel_ref_delete(const char *key);
SkPixelRef *static_sk_pixel_ref_get(const char *key);
void static_sk_pixel_ref_set(const char *key, sk_sp<SkPixelRef> value);
sk_sp<SkPixelRef> static_sk_pixel_ref_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_PIXEL_REF_H
