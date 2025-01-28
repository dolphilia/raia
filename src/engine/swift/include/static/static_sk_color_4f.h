//
// Created by dolphilia on 2024/03/30.
//

#ifndef RAIA_SKIA_STATIC_SK_COLOR_4F_H
#define RAIA_SKIA_STATIC_SK_COLOR_4F_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_color_4f_t;
void static_sk_color_4f_delete(int key);
void * static_sk_color_4f_get_ptr(int key); // -> SkColor4f *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_COLOR_4F_H
