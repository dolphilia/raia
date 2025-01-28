#ifndef STATIC_SK_PIXEL_REF_INTERNAL_H
#define STATIC_SK_PIXEL_REF_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkPixelRef.h"
int static_sk_pixel_ref_make(sk_sp<SkPixelRef> value);
void static_sk_pixel_ref_set(int key, sk_sp<SkPixelRef> value);
sk_sp<SkPixelRef> static_sk_pixel_ref_move(int key);
#endif // STATIC_SK_PIXEL_REF_INTERNAL_H
