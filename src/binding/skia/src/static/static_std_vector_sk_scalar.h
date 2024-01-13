//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_STATIC_STD_VECTOR_SK_SCALAR_H
#define RAIA_SKIA_STATIC_STD_VECTOR_SK_SCALAR_H

#include <string>
#include <map>
#include <vector>
#include "include/core/SkScalar.h"

void static_vector_sk_scalar_delete(const char *key);
SkScalar static_vector_sk_scalar_get(const char *key, int index);
void static_vector_sk_scalar_set(const char *key, std::vector<SkScalar> value);
void static_vector_sk_scalar_push_back(const char *key, SkScalar value);
void static_vector_sk_scalar_insert(const char *key, int index, SkScalar value);
void static_vector_sk_scalar_pop_back(const char *key);
void static_vector_sk_scalar_erase(const char *key, int index);

#endif //RAIA_SKIA_STATIC_STD_VECTOR_SK_SCALAR_H
