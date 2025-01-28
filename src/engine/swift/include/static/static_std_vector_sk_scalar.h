//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_STATIC_STD_VECTOR_SK_SCALAR_H
#define RAIA_SKIA_STATIC_STD_VECTOR_SK_SCALAR_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int vector_sk_scalar_t;
void static_vector_sk_scalar_delete(int key);
float static_vector_sk_scalar_get(int key, int index); // -> SkScalar
void static_vector_sk_scalar_push_back(int key, float value); // SkScalar value
void static_vector_sk_scalar_insert(int key, int index, float value); // SkScalar value
void static_vector_sk_scalar_pop_back(int key);
void static_vector_sk_scalar_erase(int key, int index);
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_STD_VECTOR_SK_SCALAR_H
