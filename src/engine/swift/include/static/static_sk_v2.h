//
// Created by dolphilia on 2024/04/04.
//

#ifndef RAIA_SKIA_STATIC_SK_V2_H
#define RAIA_SKIA_STATIC_SK_V2_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_v2_t;
void static_sk_v2_delete(int key);
void * static_sk_v2_get_ptr(int key); // -> SkV2 *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_V2_H
