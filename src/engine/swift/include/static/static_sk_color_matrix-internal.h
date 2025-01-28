#ifndef STATIC_SK_COLOR_MATRIX_INTERNAL_H
#define STATIC_SK_COLOR_MATRIX_INTERNAL_H
#include <set>
#include <map>
#include "include/effects/SkColorMatrix.h"
int static_sk_color_matrix_make(SkColorMatrix value);
SkColorMatrix static_sk_color_matrix_get(int key);
void static_sk_color_matrix_set(int key, SkColorMatrix value);
#endif // STATIC_SK_COLOR_MATRIX_INTERNAL_H
