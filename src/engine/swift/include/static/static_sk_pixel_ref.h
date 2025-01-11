//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_PIXEL_REF_H
#define RAIA_SKIA_STATIC_SK_PIXEL_REF_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkPixelRef.h"
#include "export_api.h"

typedef int sk_pixel_ref_t;

extern "C" {
RAIA_API void static_sk_pixel_ref_delete(int key);
RAIA_API SkPixelRef *static_sk_pixel_ref_get(int key);
}

int static_sk_pixel_ref_make(sk_sp<SkPixelRef> value);
void static_sk_pixel_ref_set(int key, sk_sp<SkPixelRef> value);
sk_sp<SkPixelRef> static_sk_pixel_ref_move(int key);

#endif //RAIA_SKIA_STATIC_SK_PIXEL_REF_H
