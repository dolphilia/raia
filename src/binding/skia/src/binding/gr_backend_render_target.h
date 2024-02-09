//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_GR_BACKEND_RENDER_TARGET_H
#define RAIA_SKIA_GR_BACKEND_RENDER_TARGET_H

#include "include/gpu/GrBackendSurface.h"
#include "../static/static_gr_backend_format.h"

extern "C" {
// GrBackendRenderTarget & 	operator= (const GrBackendRenderTarget &)
GrBackendRenderTarget *GrBackendRenderTarget_new();
GrBackendRenderTarget *GrBackendRenderTarget_new_2(int width, int height, int sampleCnt, int stencilBits, const GrMockRenderTargetInfo *mockInfo);
GrBackendRenderTarget *GrBackendRenderTarget_new_3(const GrBackendRenderTarget *that);
void GrBackendRenderTarget_delete(GrBackendRenderTarget *backend_render_target);
SkISize GrBackendRenderTarget_dimensions(GrBackendRenderTarget *backend_render_target);
int GrBackendRenderTarget_width(GrBackendRenderTarget *backend_render_target);
int GrBackendRenderTarget_height(GrBackendRenderTarget *backend_render_target);
int GrBackendRenderTarget_sampleCnt(GrBackendRenderTarget *backend_render_target);
int GrBackendRenderTarget_stencilBits(GrBackendRenderTarget *backend_render_target);
GrBackendApi GrBackendRenderTarget_backend(GrBackendRenderTarget *backend_render_target);
bool GrBackendRenderTarget_isFramebufferOnly(GrBackendRenderTarget *backend_render_target);
gr_backend_format_t GrBackendRenderTarget_getBackendFormat(GrBackendRenderTarget *backend_render_target);
bool GrBackendRenderTarget_getMockRenderTargetInfo(GrBackendRenderTarget *backend_render_target, GrMockRenderTargetInfo *info);
void GrBackendRenderTarget_setMutableState(GrBackendRenderTarget *backend_render_target, const skgpu::MutableTextureState *state);
bool GrBackendRenderTarget_isProtected(GrBackendRenderTarget *backend_render_target);
bool GrBackendRenderTarget_isValid(GrBackendRenderTarget *backend_render_target);
}

#endif //RAIA_SKIA_GR_BACKEND_RENDER_TARGET_H
