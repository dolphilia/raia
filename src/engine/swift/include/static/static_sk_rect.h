//
// Created by dolphilia on 2024/01/04.
//

#ifndef RAIA_SKIA_STATIC_SK_RECT_H
#define RAIA_SKIA_STATIC_SK_RECT_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_rect_t;
void static_sk_rect_delete(int key);
void *static_sk_rect_get_ptr(int key); // -> SkRect *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_RECT_H
