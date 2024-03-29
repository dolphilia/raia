//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_STATIC_GR_BACKEND_TEXTURE_H
#define RAIA_SKIA_STATIC_GR_BACKEND_TEXTURE_H

#include <set>
#include <string>
#include <map>
#include "include/gpu/GrBackendSurface.h"

typedef int gr_backend_texture_t;

int static_gr_backend_texture_make(GrBackendTexture value);
extern "C" void static_gr_backend_texture_delete(int key);
GrBackendTexture static_gr_backend_texture_get(int key);
void static_gr_backend_texture_set(int key, GrBackendTexture value);

#endif //RAIA_SKIA_STATIC_GR_BACKEND_TEXTURE_H
