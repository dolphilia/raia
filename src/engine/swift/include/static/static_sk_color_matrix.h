//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_STATIC_SK_COLOR_MATRIX_H
#define RAIA_SKIA_STATIC_SK_COLOR_MATRIX_H

#include <set>
#include <string>
#include <map>
#include "include/effects/SkColorMatrix.h"
#include "export_api.h"

typedef int sk_color_matrix_t;

extern "C" {
RAIA_API void static_sk_color_matrix_delete(int key);
RAIA_API SkColorMatrix * static_sk_color_matrix_get_ptr(int key);
}

int static_sk_color_matrix_make(SkColorMatrix value);
SkColorMatrix static_sk_color_matrix_get(int key);
void static_sk_color_matrix_set(int key, SkColorMatrix value);

#endif //RAIA_SKIA_STATIC_SK_COLOR_MATRIX_H
