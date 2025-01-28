#ifndef STATIC_SK_SURFACE_INTERNAL_H
#define STATIC_SK_SURFACE_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkSurface.h"
int static_sk_surface_make(sk_sp<SkSurface> value);
void static_sk_surface_set(int key, sk_sp<SkSurface> value);
sk_sp<SkSurface> static_sk_surface_move(int key);
#endif // STATIC_SK_SURFACE_INTERNAL_H
