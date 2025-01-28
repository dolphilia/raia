//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_STATIC_SK_R_RECT_H
#define RAIA_SKIA_STATIC_SK_R_RECT_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_r_rect_t;
void static_sk_r_rect_delete(int key);
void * static_sk_r_rect_get_ptr(int key); // -> SkRRect *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_R_RECT_H
