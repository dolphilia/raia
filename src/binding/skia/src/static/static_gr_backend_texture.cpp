//
// Created by dolphilia on 2024/01/13.
//

#include "static_gr_backend_texture.h"

static std::map<std::string, GrBackendTexture> static_gr_backend_texture;

void static_gr_backend_texture_delete(const char *key) {
    static_gr_backend_texture.erase(key);
}

GrBackendTexture static_gr_backend_texture_get(const char *key) {
    return static_gr_backend_texture[key];
}

void static_gr_backend_texture_set(const char *key, GrBackendTexture value) {
    static_gr_backend_texture[key] = value;
}