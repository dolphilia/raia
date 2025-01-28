//
// Created by dolphilia on 2024/03/30.
//

#ifndef RAIA_SKIA_STATIC_SK_POINT_H
#define RAIA_SKIA_STATIC_SK_POINT_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_point_t;
void static_sk_point_delete(int key);
void * static_sk_point_get_ptr(int key); // -> SkPoint *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_POINT_H
