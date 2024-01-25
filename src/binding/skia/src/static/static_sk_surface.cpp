//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_surface.h"

#include <utility>

static std::map<int , sk_sp<SkSurface>> static_sk_surface;
static int static_sk_surface_index = 0;

int static_sk_surface_make(sk_sp<SkSurface> value) {
    static_sk_surface[static_sk_surface_index] = std::move(value);
    static_sk_surface_index++;
    return static_sk_surface_index - 1;
}

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