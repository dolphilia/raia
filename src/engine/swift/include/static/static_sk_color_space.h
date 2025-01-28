//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_COLOR_SPACE_H
#define RAIA_SKIA_STATIC_SK_COLOR_SPACE_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_color_space_t;
void static_sk_color_space_delete(int key);
void *static_sk_color_space_get(int key); // -> SkColorSpace *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_COLOR_SPACE_H
