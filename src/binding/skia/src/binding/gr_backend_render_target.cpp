//
// Created by dolphilia on 2024/01/12.
//

#include "gr_backend_render_target.h"

extern "C" {

// GrBackendRenderTarget & 	operator= (const GrBackendRenderTarget &)

GrBackendRenderTarget *GrBackendRenderTarget_new() {
    return new GrBackendRenderTarget();
}

GrBackendRenderTarget *GrBackendRenderTarget_new_2(int width, int height, int sampleCnt, int stencilBits, const GrMockRenderTargetInfo *mockInfo) {
    return new GrBackendRenderTarget(width, height, sampleCnt, stencilBits, *mockInfo);
}

GrBackendRenderTarget *GrBackendRenderTarget_new_3(const GrBackendRenderTarget *that) {
    return new GrBackendRenderTarget(*that);
}

void GrBackendRenderTarget_delete(GrBackendRenderTarget *backend_render_target) {
    delete backend_render_target;
}

SkISize GrBackendRenderTarget_dimensions(GrBackendRenderTarget *backend_render_target) {
    return backend_render_target->dimensions();
}

int GrBackendRenderTarget_width(GrBackendRenderTarget *backend_render_target) {
    return backend_render_target->width();
}

int GrBackendRenderTarget_height(GrBackendRenderTarget *backend_render_target) {
    return backend_render_target->height();
}

int GrBackendRenderTarget_sampleCnt(GrBackendRenderTarget *backend_render_target) {
    return backend_render_target->sampleCnt();
}

int GrBackendRenderTarget_stencilBits(GrBackendRenderTarget *backend_render_target) {
    return backend_render_target->stencilBits();
}

GrBackendApi GrBackendRenderTarget_backend(GrBackendRenderTarget *backend_render_target) {
    return backend_render_target->backend();
}

bool GrBackendRenderTarget_isFramebufferOnly(GrBackendRenderTarget *backend_render_target) {
    return backend_render_target->isFramebufferOnly();
}

int GrBackendRenderTarget_getBackendFormat(GrBackendRenderTarget *backend_render_target) {
    return static_gr_backend_format_make(backend_render_target->getBackendFormat());
}

bool GrBackendRenderTarget_getMockRenderTargetInfo(GrBackendRenderTarget *backend_render_target, GrMockRenderTargetInfo *info) {
    return backend_render_target->getMockRenderTargetInfo(info);
}

void GrBackendRenderTarget_setMutableState(GrBackendRenderTarget *backend_render_target, const skgpu::MutableTextureState *state) {
    return backend_render_target->setMutableState(*state);
}

bool GrBackendRenderTarget_isProtected(GrBackendRenderTarget *backend_render_target) {
    return backend_render_target->isProtected();
}

bool GrBackendRenderTarget_isValid(GrBackendRenderTarget *backend_render_target) {
    return backend_render_target->isValid();
}

}