#ifndef STATIC_SK_SURFACE_PROPS_INTERNAL_H
#define STATIC_SK_SURFACE_PROPS_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkSurfaceProps.h"
int static_sk_surface_props_make(SkSurfaceProps value);
SkSurfaceProps static_sk_surface_props_get_entity(int key);
void static_sk_surface_props_set(int key, SkSurfaceProps value);
#endif // STATIC_SK_SURFACE_PROPS_INTERNAL_H
