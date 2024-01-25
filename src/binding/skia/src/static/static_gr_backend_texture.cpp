//
// Created by dolphilia on 2024/01/13.
//

#include "static_gr_backend_texture.h"

static std::map<int, GrBackendTexture> static_gr_backend_texture;
static int static_gr_backend_texture_index = 0;

int static_gr_backend_texture_make(GrBackendTexture value) {
    static_gr_backend_texture[static_gr_backend_texture_index] = value;
    static_gr_backend_texture_index++;
    return static_gr_backend_texture_index - 1;
}

void static_gr_backend_texture_delete(int key) {
    static_gr_backend_texture.erase(key);
}

GrBackendTexture static_gr_backend_texture_get(int key) {
    return static_gr_backend_texture[key];
}

void static_gr_backend_texture_set(int key, GrBackendTexture value) {
    static_gr_backend_texture[key] = value;
}