//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_GR_BACKEND_DRAWABLE_INFO_H
#define RAIA_SKIA_GR_BACKEND_DRAWABLE_INFO_H

#include "include/gpu/GrBackendDrawableInfo.h"

extern "C" {
GrBackendDrawableInfo *GrBackendDrawableInfo_new();
GrBackendDrawableInfo *GrBackendDrawableInfo_new_2(const GrVkDrawableInfo *info);
void GrBackendDrawableInfo_delete(GrBackendDrawableInfo *backend_drawable_info);
bool GrBackendDrawableInfo_isValid(GrBackendDrawableInfo *backend_drawable_info);
GrBackendApi GrBackendDrawableInfo_backend(GrBackendDrawableInfo *backend_drawable_info);
bool GrBackendDrawableInfo_getVkDrawableInfo(GrBackendDrawableInfo *backend_drawable_info, GrVkDrawableInfo *outInfo);
}

#endif //RAIA_SKIA_GR_BACKEND_DRAWABLE_INFO_H
