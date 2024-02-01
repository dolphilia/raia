//
// Created by dolphilia on 2024/01/13.
//

#include "static_gr_backend_texture.h"

static std::set<int> static_gr_backend_texture_available_keys;
static std::map<int, GrBackendTexture> static_gr_backend_texture;
static int static_gr_backend_texture_index = 0;

int static_gr_backend_texture_make(GrBackendTexture value) {
    int key;
    if (!static_gr_backend_texture_available_keys.empty()) {
        auto it = static_gr_backend_texture_available_keys.begin();
        key = *it;
        static_gr_backend_texture_available_keys.erase(it);
    } else {
        key = static_gr_backend_texture_index++;
    }
    static_gr_backend_texture[key] = value;
    return key;
}

void static_gr_backend_texture_delete(int key) {
    static_gr_backend_texture.erase(key);
    static_gr_backend_texture_available_keys.insert(key);
}

GrBackendTexture static_gr_backend_texture_get(int key) {
    return static_gr_backend_texture[key];
}

void static_gr_backend_texture_set(int key, GrBackendTexture value) {
    static_gr_backend_texture[key] = value;
}