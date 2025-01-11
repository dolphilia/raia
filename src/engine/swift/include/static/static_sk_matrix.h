//
// Created by dolphilia on 2024/01/06.
//

#ifndef RAIA_SKIA_STATIC_SK_MATRIX_H
#define RAIA_SKIA_STATIC_SK_MATRIX_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkMatrix.h"
#include "export_api.h"

typedef int sk_matrix_t;

extern "C" {
RAIA_API void static_sk_matrix_delete(int key);
RAIA_API SkMatrix * static_sk_matrix_get_ptr(int key);
}

int static_sk_matrix_make(SkMatrix value);
SkMatrix static_sk_matrix_get(int key);
void static_sk_matrix_set(int key, SkMatrix value);

#endif //RAIA_SKIA_STATIC_SK_MATRIX_H
