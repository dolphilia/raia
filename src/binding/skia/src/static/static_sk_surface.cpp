//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_surface.h"

static std::map<std::string, sk_sp<SkSurface>> static_sk_surface;

void static_sk_surface_delete(const char *key) {
    static_sk_surface[key].reset();
    static_sk_surface.erase(key);
}

SkSurface *static_sk_surface_get(const char *key) {
    return static_sk_surface[key].get();
}

void static_sk_surface_set(const char *key, sk_sp<SkSurface> value) {
    static_sk_surface[key] = std::move(value);
}

sk_sp<SkSurface> static_sk_surface_move(const char *key) {
    return std::move(static_sk_surface[key]);
}