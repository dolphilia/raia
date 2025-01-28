//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_YUVA_PIXMAPS_H
#define RAIA_SKIA_STATIC_SK_YUVA_PIXMAPS_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_yuva_pixmaps_t;
void static_sk_yuva_pixmaps_delete(int key);
void * static_sk_yuva_pixmaps_get_ptr(int key); // -> SkYUVAPixmaps *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_YUVA_PIXMAPS_H
