//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_I_RECT_H
#define RAIA_SKIA_STATIC_SK_I_RECT_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_i_rect_t;
void static_sk_i_rect_delete(int key);
void * static_sk_i_rect_get_ptr(int key); // -> SkIRect *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_I_RECT_H
