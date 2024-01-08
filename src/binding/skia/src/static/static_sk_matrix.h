//
// Created by dolphilia on 2024/01/06.
//

#ifndef RAIA_SKIA_STATIC_SK_MATRIX_H
#define RAIA_SKIA_STATIC_SK_MATRIX_H

#include <string>
#include <map>
#include "include/core/SkMatrix.h"

void static_sk_matrix_delete(const char *key);
SkMatrix static_sk_matrix_get(const char *key);
void static_sk_matrix_set(const char *key, SkMatrix value);

#endif //RAIA_SKIA_STATIC_SK_MATRIX_H
