#ifndef STATIC_SK_I_SIZE_INTERNAL_H
#define STATIC_SK_I_SIZE_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkRect.h"
int static_sk_i_size_make(SkISize value);
SkISize static_sk_i_size_get(int key);
void static_sk_i_size_set(int key, SkISize value);
#endif // STATIC_SK_I_SIZE_INTERNAL_H
