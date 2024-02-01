//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_STATIC_STD_VECTOR_SK_SCALAR_H
#define RAIA_SKIA_STATIC_STD_VECTOR_SK_SCALAR_H

#include <set>
#include <string>
#include <map>
#include <vector>
#include "include/core/SkScalar.h"

int static_vector_sk_scalar_make(std::vector<SkScalar> value);
extern "C" void static_vector_sk_scalar_delete(int key);
extern "C" SkScalar static_vector_sk_scalar_get(int key, int index);
void static_vector_sk_scalar_set(int key, std::vector<SkScalar> value);
extern "C" void static_vector_sk_scalar_push_back(int key, SkScalar value);
extern "C" void static_vector_sk_scalar_insert(int key, int index, SkScalar value);
extern "C" void static_vector_sk_scalar_pop_back(int key);
extern "C" void static_vector_sk_scalar_erase(int key, int index);

#endif //RAIA_SKIA_STATIC_STD_VECTOR_SK_SCALAR_H
