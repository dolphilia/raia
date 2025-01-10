//
// Created by dolphilia on 2024/01/06.
//

#ifndef RAIA_SKIA_STATIC_SK_MATRIX_H
#define RAIA_SKIA_STATIC_SK_MATRIX_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkMatrix.h"

typedef int sk_matrix_t;

int static_sk_matrix_make(SkMatrix value);
extern "C" void static_sk_matrix_delete(int key);
SkMatrix static_sk_matrix_get(int key);
void static_sk_matrix_set(int key, SkMatrix value);

#endif //RAIA_SKIA_STATIC_SK_MATRIX_H
