//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_STATIC_GR_BACKEND_TEXTURE_H
#define RAIA_SKIA_STATIC_GR_BACKEND_TEXTURE_H

#include <string>
#include <map>
#include "include/gpu/GrBackendSurface.h"

int static_gr_backend_texture_make(GrBackendTexture value);
void static_gr_backend_texture_delete(int key);
GrBackendTexture static_gr_backend_texture_get(int key);
void static_gr_backend_texture_set(int key, GrBackendTexture value);

#endif //RAIA_SKIA_STATIC_GR_BACKEND_TEXTURE_H
