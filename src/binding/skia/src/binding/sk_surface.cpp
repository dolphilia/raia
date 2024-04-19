//
// Created by dolphilia on 2024/01/11.
//

#include "sk_surface.h"
#include "../static/static_sk_color_space.h"

extern "C" {

void SkSurface_delete(SkSurface *surface) {
    delete surface;
}

bool SkSurface_isCompatible(SkSurface *surface, const GrSurfaceCharacterization *characterization) {
    return surface->isCompatible(*characterization);
}

int SkSurface_width(SkSurface *surface) {
    return surface->width();
}

int SkSurface_height(SkSurface *surface) {
    return surface->height();
}

sk_image_info_t SkSurface_imageInfo(SkSurface *surface) {
    return static_sk_image_info_make(surface->imageInfo());
}

uint32_t SkSurface_generationID(SkSurface *surface) {
    return surface->generationID();
}

void SkSurface_notifyContentWillChange(SkSurface *surface, SkSurface::ContentChangeMode mode) {
    surface->notifyContentWillChange(mode);
}

GrRecordingContext * SkSurface_recordingContext(SkSurface *surface) {
    return surface->recordingContext();
}

skgpu::graphite::Recorder * SkSurface_recorder(SkSurface *surface) {
    return surface->recorder();
}

bool SkSurface_replaceBackendTexture(SkSurface *surface, const GrBackendTexture *backendTexture, GrSurfaceOrigin origin, SkSurface::ContentChangeMode mode, SkSurface::TextureReleaseProc proc, SkSurface::ReleaseContext context) {
    return surface->replaceBackendTexture(*backendTexture, origin, mode, proc, context);
}

SkCanvas * SkSurface_getCanvas(SkSurface *surface) {
    return surface->getCanvas();
}

const_sk_capabilities_t SkSurface_capabilities(SkSurface *surface) {
    return static_const_sk_capabilities_make(surface->capabilities());
}

sk_surface_t SkSurface_makeSurface(SkSurface *surface, const SkImageInfo *imageInfo) {
    return static_sk_surface_make(surface->makeSurface(*imageInfo));
}

sk_surface_t SkSurface_makeSurface_2(SkSurface *surface, int width, int height) {
    return static_sk_surface_make(surface->makeSurface(width, height));
}

sk_image_t SkSurface_makeImageSnapshot(SkSurface *surface) {
    return static_sk_image_make(surface->makeImageSnapshot());
}

sk_image_t SkSurface_makeImageSnapshot_2(SkSurface *surface, const SkIRect *bounds) {
    return static_sk_image_make(surface->makeImageSnapshot(*bounds));
}

void SkSurface_draw(SkSurface *surface, SkCanvas *canvas, SkScalar x, SkScalar y, const SkSamplingOptions *sampling, const SkPaint *paint) {
    surface->draw(canvas, x, y, *sampling, paint);
}

void SkSurface_draw_2(SkSurface *surface, SkCanvas *canvas, SkScalar x, SkScalar y, const SkPaint *paint) {
    surface->draw(canvas, x, y, paint);
}

bool SkSurface_peekPixels(SkSurface *surface, SkPixmap *pixmap) {
    return surface->peekPixels(pixmap);
}

bool SkSurface_readPixels(SkSurface *surface, const SkPixmap *dst, int srcX, int srcY) {
    return surface->readPixels(*dst, srcX, srcY);
}

bool SkSurface_readPixels_2(SkSurface *surface, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY) {
    return surface->readPixels(*dstInfo, dstPixels, dstRowBytes, srcX, srcY);
}

bool SkSurface_readPixels_3(SkSurface *surface, const SkBitmap *dst, int srcX, int srcY) {
    return surface->readPixels(*dst, srcX, srcY);
}

void SkSurface_asyncRescaleAndReadPixels(SkSurface *surface, const SkImageInfo *info, const SkIRect *srcRect, SkSurface::RescaleGamma rescaleGamma, SkSurface::RescaleMode rescaleMode, SkSurface::ReadPixelsCallback callback, SkSurface::ReadPixelsContext context) {
    surface->asyncRescaleAndReadPixels(*info, *srcRect, rescaleGamma, rescaleMode, callback, context);
}

void SkSurface_asyncRescaleAndReadPixelsYUV420(SkSurface *surface, sk_color_space_t dstColorSpace, SkYUVColorSpace yuvColorSpace, const SkIRect *srcRect, const SkISize *dstSize, SkSurface::RescaleGamma rescaleGamma, SkSurface::RescaleMode rescaleMode, SkSurface::ReadPixelsCallback callback, SkSurface::ReadPixelsContext context) {
    surface->asyncRescaleAndReadPixelsYUV420(yuvColorSpace, static_sk_color_space_move(dstColorSpace), *srcRect, *dstSize, rescaleGamma, rescaleMode, callback, context);
}

void SkSurface_asyncRescaleAndReadPixelsYUVA420(SkSurface *surface, sk_color_space_t dstColorSpace, SkYUVColorSpace yuvColorSpace, const SkIRect *srcRect, const SkISize *dstSize, SkSurface::RescaleGamma rescaleGamma, SkSurface::RescaleMode rescaleMode, SkSurface::ReadPixelsCallback callback, SkSurface::ReadPixelsContext context) {
    surface->asyncRescaleAndReadPixelsYUVA420(yuvColorSpace, static_sk_color_space_move(dstColorSpace), *srcRect, *dstSize, rescaleGamma, rescaleMode, callback, context);
}

void SkSurface_writePixels(SkSurface *surface, const SkPixmap *src, int dstX, int dstY) {
    surface->writePixels(*src, dstX, dstY);
}

void SkSurface_writePixels_2(SkSurface *surface, const SkBitmap *src, int dstX, int dstY) {
    surface->writePixels(*src, dstX, dstY);
}

const SkSurfaceProps * SkSurface_props(SkSurface *surface) {
    return &surface->props();
}

bool SkSurface_wait(SkSurface *surface, int numSemaphores, const GrBackendSemaphore *waitSemaphores, bool deleteSemaphoresAfterWait) {
    return surface->wait(numSemaphores, waitSemaphores, deleteSemaphoresAfterWait);
}

bool SkSurface_characterize(SkSurface *surface, GrSurfaceCharacterization *characterization) {
    return surface->characterize(characterization);
}

bool SkSurface_unique(SkSurface *surface) {
    return surface->unique();
}

void SkSurface_ref(SkSurface *surface) {
    surface->ref();
}

void SkSurface_unref(SkSurface *surface) {
    surface->unref();
}

}