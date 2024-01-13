//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_GR_YUVA_BACKEND_TEXTURE_INFO_H
#define RAIA_SKIA_GR_YUVA_BACKEND_TEXTURE_INFO_H

#include "include/core/SkYUVAInfo.h"
#include "include/gpu/GrYUVABackendTextures.h"

extern "C" {
//GrYUVABackendTextureInfo & operator= (const GrYUVABackendTextureInfo &)=default
//bool operator== (const GrYUVABackendTextureInfo &) const
//bool operator!= (const GrYUVABackendTextureInfo &that) const
GrYUVABackendTextureInfo *GrYUVABackendTextureInfo_new();
GrYUVABackendTextureInfo *GrYUVABackendTextureInfo_new_2(const SkYUVAInfo *yuvaInfo, const GrBackendFormat backendFormat[GrYUVABackendTextureInfo::kMaxPlanes], skgpu::Mipmapped mipmapped, GrSurfaceOrigin surfaceOrigin);
GrYUVABackendTextureInfo *GrYUVABackendTextureInfo_new_3(const GrYUVABackendTextureInfo *yuvaBackendTextureInfo);
const SkYUVAInfo * GrYUVABackendTextureInfo_yuvaInfo(GrYUVABackendTextureInfo *yuvaBackendTextureInfo);
SkYUVColorSpace GrYUVABackendTextureInfo_yuvColorSpace(GrYUVABackendTextureInfo *yuvaBackendTextureInfo);
skgpu::Mipmapped GrYUVABackendTextureInfo_mipmapped(GrYUVABackendTextureInfo *yuvaBackendTextureInfo);
GrSurfaceOrigin GrYUVABackendTextureInfo_textureOrigin(GrYUVABackendTextureInfo *yuvaBackendTextureInfo);
int GrYUVABackendTextureInfo_numPlanes(GrYUVABackendTextureInfo *yuvaBackendTextureInfo);
const GrBackendFormat * GrYUVABackendTextureInfo_planeFormat(GrYUVABackendTextureInfo *yuvaBackendTextureInfo, int i);
bool GrYUVABackendTextureInfo_isValid(GrYUVABackendTextureInfo *yuvaBackendTextureInfo);
//SkYUVAInfo::YUVALocations GrYUVABackendTextureInfo_toYUVALocations(GrYUVABackendTextureInfo *yuvaBackendTextureInfo);
}

#endif //RAIA_SKIA_GR_YUVA_BACKEND_TEXTURE_INFO_H
