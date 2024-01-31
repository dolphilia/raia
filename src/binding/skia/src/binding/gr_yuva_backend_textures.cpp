//
// Created by dolphilia on 2024/01/13.
//

#include "gr_yuva_backend_textures.h"

extern "C" {

//GrYUVABackendTextures & operator= (const GrYUVABackendTextures &)=delete
//GrYUVABackendTextures & operator= (GrYUVABackendTextures &&)=default

GrYUVABackendTextures *GrYUVABackendTextures_new() {
    return new GrYUVABackendTextures();
}

GrYUVABackendTextures *GrYUVABackendTextures_new_2(const SkYUVAInfo *yuvaInfo, const GrBackendTexture backendTexture[SkYUVAInfo::kMaxPlanes], GrSurfaceOrigin textureOrigin) {
    return new GrYUVABackendTextures(*yuvaInfo, backendTexture, textureOrigin);
}

void GrYUVABackendTextures_delete(GrYUVABackendTextures *yuvaBackendTextures) {
    delete yuvaBackendTextures;
}

const std::array< GrBackendTexture, SkYUVAInfo::kMaxPlanes > * GrYUVABackendTextures_textures(GrYUVABackendTextures *yuvaBackendTextures) {
    return &yuvaBackendTextures->textures();
}

int GrYUVABackendTextures_texture(GrYUVABackendTextures *yuvaBackendTextures, int i) {
    return static_gr_backend_texture_make(yuvaBackendTextures->texture(i));
}

const SkYUVAInfo * GrYUVABackendTextures_yuvaInfo(GrYUVABackendTextures *yuvaBackendTextures) {
    return &yuvaBackendTextures->yuvaInfo();
}

int GrYUVABackendTextures_numPlanes(GrYUVABackendTextures *yuvaBackendTextures) {
    return yuvaBackendTextures->numPlanes();
}

GrSurfaceOrigin GrYUVABackendTextures_textureOrigin(GrYUVABackendTextures *yuvaBackendTextures) {
    return yuvaBackendTextures->textureOrigin();
}

bool GrYUVABackendTextures_isValid(GrYUVABackendTextures *yuvaBackendTextures) {
    return yuvaBackendTextures->isValid();
}

//SkYUVAInfo::YUVALocations GrYUVABackendTextures_toYUVALocations(GrYUVABackendTextures *yuvaBackendTextures) {
//    return yuvaBackendTextures->toYUVALocations();
//}

}