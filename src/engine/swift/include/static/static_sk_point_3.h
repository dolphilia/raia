//
// Created by dolphilia on 2024/04/05.
//

#ifndef RAIA_SKIA_STATIC_SK_POINT_3_H
#define RAIA_SKIA_STATIC_SK_POINT_3_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_point_3_t;
void static_sk_point_3_delete(int key);
void * static_sk_point_3_get_ptr(int key); // -> SkPoint3 *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_POINT_3_H
