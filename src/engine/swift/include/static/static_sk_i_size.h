//
// Created by dolphilia on 2024/03/30.
//

#ifndef RAIA_SKIA_STATIC_SK_I_SIZE_H
#define RAIA_SKIA_STATIC_SK_I_SIZE_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_i_size_t;
void static_sk_i_size_delete(int key);
void * static_sk_i_size_get_ptr(int key); // -> SkISize *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_I_SIZE_H
