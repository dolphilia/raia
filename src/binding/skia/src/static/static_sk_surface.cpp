//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_surface.h"

static std::map<int , sk_sp<SkSurface>> static_sk_surface;

void static_sk_surface_delete(int key) {
    static_sk_surface[key].reset();
    static_sk_surface.erase(key);
}

SkSurface *static_sk_surface_get(int key) {
    return static_sk_surface[key].get();
}

void static_sk_surface_set(int key, sk_sp<SkSurface> value) {
    static_sk_surface[key] = std::move(value);
}

sk_sp<SkSurface> static_sk_surface_move(int key) {
    return std::move(static_sk_surface[key]);
}