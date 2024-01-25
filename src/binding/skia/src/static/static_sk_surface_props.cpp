//
// Created by dolphilia on 2024/01/06.
//

#include "static_sk_surface_props.h"

static std::map<int , SkSurfaceProps> static_sk_surface_props;
static int static_sk_surface_props_index = 0;

int static_sk_surface_props_make(SkSurfaceProps value) {
    static_sk_surface_props[static_sk_surface_props_index] = value;
    static_sk_surface_props_index++;
    return static_sk_surface_props_index - 1;
}

void static_sk_surface_props_delete(int key) {
    static_sk_surface_props.erase(key);
}

SkSurfaceProps static_sk_surface_props_get(int key) {
    return static_sk_surface_props[key];
}

void static_sk_surface_props_set(int key, SkSurfaceProps value) {
    static_sk_surface_props[key] = value;
}