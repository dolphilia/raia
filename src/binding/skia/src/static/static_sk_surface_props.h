//
// Created by dolphilia on 2024/01/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SURFACE_PROPS_H
#define RAIA_SKIA_STATIC_SK_SURFACE_PROPS_H

#include <string>
#include <map>
#include "include/core/SkSurfaceProps.h"

int static_sk_surface_props_make(SkSurfaceProps value);
void static_sk_surface_props_delete(int key);
SkSurfaceProps static_sk_surface_props_get(int key);
void static_sk_surface_props_set(int key, SkSurfaceProps value);

#endif //RAIA_SKIA_STATIC_SK_SURFACE_PROPS_H
