//
// Created by dolphilia on 2024/01/06.
//

#ifndef RAIA_SKIA_STATIC_SK_MATRIX_H
#define RAIA_SKIA_STATIC_SK_MATRIX_H

#include <string>
#include <map>
#include "include/core/SkMatrix.h"

void static_sk_matrix_delete(int key);
SkMatrix static_sk_matrix_get(int key);
void static_sk_matrix_set(int key, SkMatrix value);

#endif //RAIA_SKIA_STATIC_SK_MATRIX_H
