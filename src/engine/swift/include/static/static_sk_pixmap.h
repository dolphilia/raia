//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_PIXMAP_H
#define RAIA_SKIA_STATIC_SK_PIXMAP_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_pixmap_t;
void static_sk_pixmap_delete(int key);
void * static_sk_pixmap_get_ptr(int key); // -> SkPixmap *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_PIXMAP_H
