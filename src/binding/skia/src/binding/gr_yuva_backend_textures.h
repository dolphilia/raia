//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_GR_YUVA_BACKEND_TEXTURES_H
#define RAIA_SKIA_GR_YUVA_BACKEND_TEXTURES_H

#include "include/gpu/GrYUVABackendTextures.h"
#include "../static/static_gr_backend_texture.h"

extern "C" {
//GrYUVABackendTextures & operator= (const GrYUVABackendTextures &)=delete
//GrYUVABackendTextures & operator= (GrYUVABackendTextures &&)=default
GrYUVABackendTextures *GrYUVABackendTextures_new();
GrYUVABackendTextures *GrYUVABackendTextures_new_2(const SkYUVAInfo *yuvaInfo, const GrBackendTexture backendTexture[SkYUVAInfo::kMaxPlanes], GrSurfaceOrigin textureOrigin);
const std::array< GrBackendTexture, SkYUVAInfo::kMaxPlanes > * GrYUVABackendTextures_textures(GrYUVABackendTextures *yuvaBackendTextures);
void GrYUVABackendTextures_texture(const char *gr_backend_textur_key_out, GrYUVABackendTextures *yuvaBackendTextures, int i);
const SkYUVAInfo * GrYUVABackendTextures_yuvaInfo(GrYUVABackendTextures *yuvaBackendTextures);
int GrYUVABackendTextures_numPlanes(GrYUVABackendTextures *yuvaBackendTextures);
GrSurfaceOrigin GrYUVABackendTextures_textureOrigin(GrYUVABackendTextures *yuvaBackendTextures);
bool GrYUVABackendTextures_isValid(GrYUVABackendTextures *yuvaBackendTextures);
//SkYUVAInfo::YUVALocations GrYUVABackendTextures_toYUVALocations(GrYUVABackendTextures *yuvaBackendTextures);
}

#endif //RAIA_SKIA_GR_YUVA_BACKEND_TEXTURES_H
