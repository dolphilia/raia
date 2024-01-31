//
// Created by dolphilia on 2024/01/12.
//

#include "gr_backend_drawable_info.h"

extern "C" {

GrBackendDrawableInfo *GrBackendDrawableInfo_new() {
    return new GrBackendDrawableInfo();
}

GrBackendDrawableInfo *GrBackendDrawableInfo_new_2(const GrVkDrawableInfo *info) {
    return new GrBackendDrawableInfo(*info);
}

void GrBackendDrawableInfo_delete(GrBackendDrawableInfo *backend_drawable_info) {
    delete backend_drawable_info;
}

bool GrBackendDrawableInfo_isValid(GrBackendDrawableInfo *backend_drawable_info) {
    return backend_drawable_info->isValid();
}

GrBackendApi GrBackendDrawableInfo_backend(GrBackendDrawableInfo *backend_drawable_info) {
    return backend_drawable_info->backend();
}

bool GrBackendDrawableInfo_getVkDrawableInfo(GrBackendDrawableInfo *backend_drawable_info, GrVkDrawableInfo *outInfo) {
    return backend_drawable_info->getVkDrawableInfo(outInfo);
}

}