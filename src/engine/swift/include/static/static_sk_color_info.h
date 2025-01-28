//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_STATIC_SK_COLOR_INFO_H
#define RAIA_SKIA_STATIC_SK_COLOR_INFO_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_color_info_t;
void static_sk_color_info_delete(int key);
void * static_sk_color_info_get_ptr(int key); // -> SkColorInfo *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_COLOR_INFO_H
