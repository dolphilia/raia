//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_STATIC_GR_BACKEND_TEXTURE_H
#define RAIA_SKIA_STATIC_GR_BACKEND_TEXTURE_H

#include <string>
#include <map>
#include "include/gpu/GrBackendSurface.h"

void static_gr_backend_texture_delete(const char *key);
GrBackendTexture static_gr_backend_texture_get(const char *key);
void static_gr_backend_texture_set(const char *key, GrBackendTexture value);

#endif //RAIA_SKIA_STATIC_GR_BACKEND_TEXTURE_H
