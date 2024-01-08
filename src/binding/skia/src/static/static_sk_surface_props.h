//
// Created by dolphilia on 2024/01/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SURFACE_PROPS_H
#define RAIA_SKIA_STATIC_SK_SURFACE_PROPS_H

#include <string>
#include <map>
#include "include/core/SkSurfaceProps.h"

void static_sk_surface_props_delete(const char *key);
SkSurfaceProps static_sk_surface_props_get(const char *key);
void static_sk_surface_props_set(const char *key, SkSurfaceProps value);

#endif //RAIA_SKIA_STATIC_SK_SURFACE_PROPS_H
