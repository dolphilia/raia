//
// Created by dolphilia on 2024/04/08.
//

#ifndef RAIA_SKIA_STATIC_SK_SIZE_T_H
#define RAIA_SKIA_STATIC_SK_SIZE_T_H

#ifdef __cplusplus
extern "C" {
#endif

typedef int sk_size_t;

void static_sk_size_delete(int key);
void * static_sk_size_get_ptr(int key); // -> SkSize *

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_SIZE_T_H
