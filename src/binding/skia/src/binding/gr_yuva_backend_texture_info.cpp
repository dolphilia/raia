//
// Created by dolphilia on 2024/01/13.
//

#include "gr_yuva_backend_texture_info.h"

extern "C" {

//GrYUVABackendTextureInfo & operator= (const GrYUVABackendTextureInfo &)=default
//bool operator== (const GrYUVABackendTextureInfo &) const
//bool operator!= (const GrYUVABackendTextureInfo &that) const

GrYUVABackendTextureInfo *GrYUVABackendTextureInfo_new() {
    return new GrYUVABackendTextureInfo();
}

GrYUVABackendTextureInfo *GrYUVABackendTextureInfo_new_2(const SkYUVAInfo *yuvaInfo, const GrBackendFormat backendFormat[GrYUVABackendTextureInfo::kMaxPlanes], skgpu::Mipmapped mipmapped, GrSurfaceOrigin surfaceOrigin) {
    return new GrYUVABackendTextureInfo(*yuvaInfo, backendFormat, mipmapped, surfaceOrigin);
}

GrYUVABackendTextureInfo *GrYUVABackendTextureInfo_new_3(const GrYUVABackendTextureInfo *yuvaBackendTextureInfo) {
    return new GrYUVABackendTextureInfo(*yuvaBackendTextureInfo);
}

void GrYUVABackendTextureInfo_delete(GrYUVABackendTextureInfo *yuvaBackendTextureInfo) {
    delete yuvaBackendTextureInfo;
}

const SkYUVAInfo * GrYUVABackendTextureInfo_yuvaInfo(GrYUVABackendTextureInfo *yuvaBackendTextureInfo) {
    return &yuvaBackendTextureInfo->yuvaInfo();
}

SkYUVColorSpace GrYUVABackendTextureInfo_yuvColorSpace(GrYUVABackendTextureInfo *yuvaBackendTextureInfo) {
    return yuvaBackendTextureInfo->yuvColorSpace();
}

skgpu::Mipmapped GrYUVABackendTextureInfo_mipmapped(GrYUVABackendTextureInfo *yuvaBackendTextureInfo) {
    return yuvaBackendTextureInfo->mipmapped();
}

GrSurfaceOrigin GrYUVABackendTextureInfo_textureOrigin(GrYUVABackendTextureInfo *yuvaBackendTextureInfo) {
    return yuvaBackendTextureInfo->textureOrigin();
}

int GrYUVABackendTextureInfo_numPlanes(GrYUVABackendTextureInfo *yuvaBackendTextureInfo) {
    return yuvaBackendTextureInfo->numPlanes();
}

const GrBackendFormat * GrYUVABackendTextureInfo_planeFormat(GrYUVABackendTextureInfo *yuvaBackendTextureInfo, int i) {
    return &yuvaBackendTextureInfo->planeFormat(i);
}

bool GrYUVABackendTextureInfo_isValid(GrYUVABackendTextureInfo *yuvaBackendTextureInfo) {
    return yuvaBackendTextureInfo->isValid();
}

//SkYUVAInfo::YUVALocations GrYUVABackendTextureInfo_toYUVALocations(GrYUVABackendTextureInfo *yuvaBackendTextureInfo) {
//    return yuvaBackendTextureInfo->toYUVALocations();
//}

}