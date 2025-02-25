//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_PIXEL_REF_H
#define RAIA_SKIA_STATIC_SK_PIXEL_REF_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_pixel_ref_t;
void static_sk_pixel_ref_delete(int key);
void *static_sk_pixel_ref_get_ptr(int key); // -> SkPixelRef *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_PIXEL_REF_H
