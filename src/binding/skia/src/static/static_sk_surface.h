//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_SURFACE_H
#define RAIA_SKIA_STATIC_SK_SURFACE_H

#include <string>
#include <map>
#include "include/core/SkSurface.h"

void static_sk_surface_delete(const char *key);
SkSurface *static_sk_surface_get(const char *key);
void static_sk_surface_set(const char *key, sk_sp<SkSurface> value);
sk_sp<SkSurface> static_sk_surface_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_SURFACE_H
