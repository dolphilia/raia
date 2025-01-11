//
// Created by dolphilia on 2024/01/06.
//

#ifndef RAIA_SKIA_STATIC_SK_SURFACE_PROPS_H
#define RAIA_SKIA_STATIC_SK_SURFACE_PROPS_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkSurfaceProps.h"
#include "export_api.h"

typedef int sk_surface_props_t;

extern "C" {
RAIA_API void static_sk_surface_props_delete(int key);
RAIA_API SkSurfaceProps * static_sk_surface_props_get_ptr(int key);
}

int static_sk_surface_props_make(SkSurfaceProps value);
SkSurfaceProps static_sk_surface_props_get(int key);
void static_sk_surface_props_set(int key, SkSurfaceProps value);

#endif //RAIA_SKIA_STATIC_SK_SURFACE_PROPS_H
