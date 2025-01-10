//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_PIXEL_REF_H
#define RAIA_SKIA_STATIC_SK_PIXEL_REF_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkPixelRef.h"

typedef int sk_pixel_ref_t;

int static_sk_pixel_ref_make(sk_sp<SkPixelRef> value);
extern "C" void static_sk_pixel_ref_delete(int key);
extern "C" SkPixelRef *static_sk_pixel_ref_get(int key);
void static_sk_pixel_ref_set(int key, sk_sp<SkPixelRef> value);
sk_sp<SkPixelRef> static_sk_pixel_ref_move(int key);

#endif //RAIA_SKIA_STATIC_SK_PIXEL_REF_H
