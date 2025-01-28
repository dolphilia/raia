//
// Created by dolphilia on 2024/04/04.
//

#ifndef RAIA_SKIA_STATIC_SK_V4_H
#define RAIA_SKIA_STATIC_SK_V4_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_v4_t;
void static_sk_v4_delete(int key);
void * static_sk_v4_get_ptr(int key); // -> SkV4 *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_V4_H
