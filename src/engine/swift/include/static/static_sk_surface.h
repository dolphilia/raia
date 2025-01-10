//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_SURFACE_H
#define RAIA_SKIA_STATIC_SK_SURFACE_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkSurface.h"

typedef int sk_surface_t;

int static_sk_surface_make(sk_sp<SkSurface> value);
extern "C" void static_sk_surface_delete(int key);
extern "C" SkSurface *static_sk_surface_get(int key);
void static_sk_surface_set(int key, sk_sp<SkSurface> value);
sk_sp<SkSurface> static_sk_surface_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SURFACE_H
