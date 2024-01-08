//
// Created by dolphilia on 2024/01/06.
//

#include "static_sk_surface_props.h"

static std::map<std::string, SkSurfaceProps> static_sk_surface_props;

void static_sk_surface_props_delete(const char *key) {
    static_sk_surface_props.erase(key);
}

SkSurfaceProps static_sk_surface_props_get(const char *key) {
    return static_sk_surface_props[key];
}

void static_sk_surface_props_set(const char *key, SkSurfaceProps value) {
    static_sk_surface_props[key] = value;
}