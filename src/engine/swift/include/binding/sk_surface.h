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
#include "../static/static_sk_color_space.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkSurface_delete(SkSurface *surface);
RAIA_API bool SkSurface_isCompatible(SkSurface *surface, const GrSurfaceCharacterization *characterization);
RAIA_API int SkSurface_width(SkSurface *surface);
RAIA_API int SkSurface_height(SkSurface *surface);
RAIA_API sk_image_info_t SkSurface_imageInfo(SkSurface *surface);
RAIA_API uint32_t SkSurface_generationID(SkSurface *surface);
RAIA_API void SkSurface_notifyContentWillChange(SkSurface *surface, SkSurface::ContentChangeMode mode);
RAIA_API GrRecordingContext * SkSurface_recordingContext(SkSurface *surface);
RAIA_API skgpu::graphite::Recorder * SkSurface_recorder(SkSurface *surface);
RAIA_API bool SkSurface_replaceBackendTexture(SkSurface *surface, const GrBackendTexture *backendTexture, GrSurfaceOrigin origin, SkSurface::ContentChangeMode mode, SkSurface::TextureReleaseProc proc, SkSurface::ReleaseContext context);
RAIA_API SkCanvas * SkSurface_getCanvas(SkSurface *surface);
RAIA_API const_sk_capabilities_t SkSurface_capabilities(SkSurface *surface);
RAIA_API sk_surface_t SkSurface_makeSurface(SkSurface *surface, const SkImageInfo *imageInfo);
RAIA_API sk_surface_t SkSurface_makeSurface_2(SkSurface *surface, int width, int height);
RAIA_API sk_image_t SkSurface_makeImageSnapshot(SkSurface *surface);
RAIA_API sk_image_t SkSurface_makeImageSnapshot_2(SkSurface *surface, const SkIRect *bounds);
RAIA_API void SkSurface_draw(SkSurface *surface, SkCanvas *canvas, SkScalar x, SkScalar y, const SkSamplingOptions *sampling, const SkPaint *paint);
RAIA_API void SkSurface_draw_2(SkSurface *surface, SkCanvas *canvas, SkScalar x, SkScalar y, const SkPaint *paint);
RAIA_API bool SkSurface_peekPixels(SkSurface *surface, SkPixmap *pixmap);
RAIA_API bool SkSurface_readPixels(SkSurface *surface, const SkPixmap *dst, int srcX, int srcY);
RAIA_API bool SkSurface_readPixels_2(SkSurface *surface, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY);
RAIA_API bool SkSurface_readPixels_3(SkSurface *surface, const SkBitmap *dst, int srcX, int srcY);
RAIA_API void SkSurface_asyncRescaleAndReadPixels(SkSurface *surface, const SkImageInfo *info, const SkIRect *srcRect, SkSurface::RescaleGamma rescaleGamma, SkSurface::RescaleMode rescaleMode, SkSurface::ReadPixelsCallback callback, SkSurface::ReadPixelsContext context);
RAIA_API void SkSurface_asyncRescaleAndReadPixelsYUV420(SkSurface *surface, sk_color_space_t dstColorSpace, SkYUVColorSpace yuvColorSpace, const SkIRect *srcRect, const SkISize *dstSize, SkSurface::RescaleGamma rescaleGamma, SkSurface::RescaleMode rescaleMode, SkSurface::ReadPixelsCallback callback, SkSurface::ReadPixelsContext context);
RAIA_API void SkSurface_asyncRescaleAndReadPixelsYUVA420(SkSurface *surface, sk_color_space_t dstColorSpace, SkYUVColorSpace yuvColorSpace, const SkIRect *srcRect, const SkISize *dstSize, SkSurface::RescaleGamma rescaleGamma, SkSurface::RescaleMode rescaleMode, SkSurface::ReadPixelsCallback callback, SkSurface::ReadPixelsContext context);
RAIA_API void SkSurface_writePixels(SkSurface *surface, const SkPixmap *src, int dstX, int dstY);
RAIA_API void SkSurface_writePixels_2(SkSurface *surface, const SkBitmap *src, int dstX, int dstY);
RAIA_API const SkSurfaceProps * SkSurface_props(SkSurface *surface);
RAIA_API bool SkSurface_wait(SkSurface *surface, int numSemaphores, const GrBackendSemaphore *waitSemaphores, bool deleteSemaphoresAfterWait);
RAIA_API bool SkSurface_characterize(SkSurface *surface, GrSurfaceCharacterization *characterization);
RAIA_API bool SkSurface_unique(SkSurface *surface);
RAIA_API void SkSurface_ref(SkSurface *surface);
RAIA_API void SkSurface_unref(SkSurface *surface);
}

#endif //RAIA_SKIA_SK_SURFACE_H
