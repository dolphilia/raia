//
// Created by dolphilia on 2024/03/30.
//

#ifndef RAIA_SKIA_STATIC_SK_I_POINT_H
#define RAIA_SKIA_STATIC_SK_I_POINT_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_i_point_t;
void static_sk_i_point_delete(int key);
void * static_sk_i_point_get_ptr(int key); // -> SkIPoint *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_I_POINT_H
