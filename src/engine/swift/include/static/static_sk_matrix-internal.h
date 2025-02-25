#ifndef STATIC_SK_MATRIX_INTERNAL_H
#define STATIC_SK_MATRIX_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkMatrix.h"
int static_sk_matrix_make(SkMatrix value);
SkMatrix static_sk_matrix_get_entity(int key);
void static_sk_matrix_set(int key, SkMatrix value);
#endif // STATIC_SK_MATRIX_INTERNAL_H
