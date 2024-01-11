//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_STATIC_SK_COLOR_MATRIX_H
#define RAIA_SKIA_STATIC_SK_COLOR_MATRIX_H

#include <string>
#include <map>
#include "include/effects/SkColorMatrix.h"

void static_sk_color_matrix_delete(const char *key);
SkColorMatrix static_sk_color_matrix_get(const char *key);
void static_sk_color_matrix_set(const char *key, SkColorMatrix value);

#endif //RAIA_SKIA_STATIC_SK_COLOR_MATRIX_H
