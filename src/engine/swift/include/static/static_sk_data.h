//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_DATA_H
#define RAIA_SKIA_STATIC_SK_DATA_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_data_t;
typedef int const_sk_data_t;
void static_sk_data_delete(int key);
void *static_sk_data_get_ptr(int key); // -> SkData *
// const
void static_const_sk_data_delete(int key);
const void *static_const_sk_data_get_ptr(int key); // -> const SkData *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_DATA_H
