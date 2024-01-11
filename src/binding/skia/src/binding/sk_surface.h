//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_SURFACE_H
#define RAIA_SKIA_SK_SURFACE_H

#include "include/core/SkSurface.h"
#include "include/core/SkColorSpace.h"
#include "include/core/SkCapabilities.h"
#include "../static/static_sk_image_info.h"
#include "../static/static_sk_capabilities.h"
#include "../static/static_sk_surface.h"
#include "../static/static_sk_image.h"

extern "C" {
bool SkSurface_isCompatible(SkSurface *surface, const GrSurfaceCharacterization &characterization);
int SkSurface_width(SkSurface *surface);
int SkSurface_height(SkSurface *surface);
void SkSurface_imageInfo(const char *sk_image_info_key_out, SkSurface *surface);
uint32_t SkSurface_generationID(SkSurface *surface);
void SkSurface_notifyContentWillChange(SkSurface *surface, SkSurface::ContentChangeMode mode);
GrRecordingContext * SkSurface_recordingContext(SkSurface *surface);
skgpu::graphite::Recorder * SkSurface_recorder(SkSurface *surface);
bool SkSurface_replaceBackendTexture(SkSurface *surface, const GrBackendTexture &backendTexture, GrSurfaceOrigin origin, SkSurface::ContentChangeMode mode, SkSurface::TextureReleaseProc proc, SkSurface::ReleaseContext context);
SkCanvas * SkSurface_getCanvas(SkSurface *surface);
void SkSurface_capabilities(const char *sk_capabilities_key_out, SkSurface *surface);
void SkSurface_makeSurface(const char *sk_surface_key_out, SkSurface *surface, const SkImageInfo &imageInfo);
void SkSurface_makeSurface_2(const char *sk_surface_key_out, SkSurface *surface, int width, int height);
void SkSurface_makeImageSnapshot(const char *sk_image_key_out, SkSurface *surface);
void SkSurface_makeImageSnapshot_2(const char *sk_image_key_out, SkSurface *surface, const SkIRect &bounds);
void SkSurface_draw(SkSurface *surface, SkCanvas *canvas, SkScalar x, SkScalar y, const SkSamplingOptions &sampling, const SkPaint *paint);
void SkSurface_draw_2(SkSurface *surface, SkCanvas *canvas, SkScalar x, SkScalar y, const SkPaint *paint);
bool SkSurface_peekPixels(SkSurface *surface, SkPixmap *pixmap);
bool SkSurface_readPixels(SkSurface *surface, const SkPixmap &dst, int srcX, int srcY);
bool SkSurface_readPixels_2(SkSurface *surface, const SkImageInfo &dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY);
bool SkSurface_readPixels_3(SkSurface *surface, const SkBitmap &dst, int srcX, int srcY);
void SkSurface_asyncRescaleAndReadPixels(SkSurface *surface, const SkImageInfo &info, const SkIRect &srcRect, SkSurface::RescaleGamma rescaleGamma, SkSurface::RescaleMode rescaleMode, SkSurface::ReadPixelsCallback callback, SkSurface::ReadPixelsContext context);
void SkSurface_asyncRescaleAndReadPixelsYUV420(SkSurface *surface, SkYUVColorSpace yuvColorSpace, sk_sp<SkColorSpace> dstColorSpace, const SkIRect &srcRect, const SkISize &dstSize, SkSurface::RescaleGamma rescaleGamma, SkSurface::RescaleMode rescaleMode, SkSurface::ReadPixelsCallback callback, SkSurface::ReadPixelsContext context);
void SkSurface_asyncRescaleAndReadPixelsYUVA420(SkSurface *surface, SkYUVColorSpace yuvColorSpace, sk_sp<SkColorSpace> dstColorSpace, const SkIRect &srcRect, const SkISize &dstSize, SkSurface::RescaleGamma rescaleGamma, SkSurface::RescaleMode rescaleMode, SkSurface::ReadPixelsCallback callback, SkSurface::ReadPixelsContext context);
void SkSurface_writePixels(SkSurface *surface, const SkPixmap &src, int dstX, int dstY);
void SkSurface_writePixels_2(SkSurface *surface, const SkBitmap &src, int dstX, int dstY);
const SkSurfaceProps * SkSurface_props(SkSurface *surface);
bool SkSurface_wait(SkSurface *surface, int numSemaphores, const GrBackendSemaphore *waitSemaphores, bool deleteSemaphoresAfterWait);
bool SkSurface_characterize(SkSurface *surface, GrSurfaceCharacterization *characterization);
bool SkSurface_unique(SkSurface *surface);
void SkSurface_ref(SkSurface *surface);
void SkSurface_unref(SkSurface *surface);
}

#endif //RAIA_SKIA_SK_SURFACE_H
