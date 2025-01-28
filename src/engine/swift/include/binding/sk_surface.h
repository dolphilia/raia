//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_SURFACE_H
#define RAIA_SKIA_SK_SURFACE_H

#ifdef __cplusplus
extern "C" {
#endif

void SkSurface_delete(void *surface); // (SkSurface *surface)
bool SkSurface_isCompatible(void *surface, const void *characterization); // (SkSurface *surface, const GrSurfaceCharacterization *characterization) -> bool
int SkSurface_width(void *surface); // (SkSurface *surface) -> int
int SkSurface_height(void *surface); // (SkSurface *surface) -> int
int SkSurface_imageInfo(void *surface); // (SkSurface *surface) -> sk_image_info_t
unsigned int SkSurface_generationID(void *surface); // (SkSurface *surface) -> uint32_t
void SkSurface_notifyContentWillChange(void *surface, int mode); // (SkSurface *surface, SkSurface::ContentChangeMode mode)
void * SkSurface_recordingContext(void *surface); // (SkSurface *surface) -> GrRecordingContext *
void * SkSurface_recorder(void *surface); // (SkSurface *surface) -> skgpu::graphite::Recorder *
bool SkSurface_replaceBackendTexture(void *surface, const void *backendTexture, int origin, int mode, void(* proc)(void *), void * context); // (SkSurface *surface, const GrBackendTexture *backendTexture, GrSurfaceOrigin origin, SkSurface::ContentChangeMode mode, SkSurface::TextureReleaseProc proc, SkSurface::ReleaseContext context) -> bool
void * SkSurface_getCanvas(void *surface); // (SkSurface *surface) -> SkCanvas *
int SkSurface_capabilities(void *surface); // (SkSurface *surface) -> const_sk_capabilities_t
int SkSurface_makeSurface(void *surface, const void *imageInfo); // (SkSurface *surface, const SkImageInfo *imageInfo) -> sk_surface_t
int SkSurface_makeSurface_2(void *surface, int width, int height); // (SkSurface *surface, int width, int height) -> sk_surface_t
int SkSurface_makeImageSnapshot(void *surface); // (SkSurface *surface) -> sk_image_t
int SkSurface_makeImageSnapshot_2(void *surface, const void *bounds); // (SkSurface *surface, const SkIRect *bounds) -> sk_image_t
void SkSurface_draw(void *surface, void *canvas, float x, float y, const void *sampling, const void *paint); // (SkSurface *surface, SkCanvas *canvas, SkScalar x, SkScalar y, const SkSamplingOptions *sampling, const SkPaint *paint)
void SkSurface_draw_2(void *surface, void *canvas, float x, float y, const void *paint); // (SkSurface *surface, SkCanvas *canvas, SkScalar x, SkScalar y, const SkPaint *paint)
bool SkSurface_peekPixels(void *surface, void *pixmap); // (SkSurface *surface, SkPixmap *pixmap) -> bool
bool SkSurface_readPixels(void *surface, const void *dst, int srcX, int srcY); // (SkSurface *surface, const SkPixmap *dst, int srcX, int srcY) -> bool
bool SkSurface_readPixels_2(void *surface, const void *dstInfo, void *dstPixels, unsigned long dstRowBytes, int srcX, int srcY); // (SkSurface *surface, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY) -> bool
bool SkSurface_readPixels_3(void *surface, const void *dst, int srcX, int srcY); // (SkSurface *surface, const SkBitmap *dst, int srcX, int srcY) -> bool

// TODO
// void SkSurface_asyncRescaleAndReadPixels(void *surface, const void *info, const void *srcRect, int rescaleGamma, int rescaleMode, SkSurface::ReadPixelsCallback callback, void * context); // (SkSurface *surface, const SkImageInfo *info, const SkIRect *srcRect, SkSurface::RescaleGamma rescaleGamma, SkSurface::RescaleMode rescaleMode, SkSurface::ReadPixelsCallback callback, SkSurface::ReadPixelsContext context)
// void SkSurface_asyncRescaleAndReadPixelsYUV420(void *surface, sk_color_space_t dstColorSpace, int yuvColorSpace, const void *srcRect, const void *dstSize, int rescaleGamma, int rescaleMode, SkSurface::ReadPixelsCallback callback, void * context); // (SkSurface *surface, sk_color_space_t dstColorSpace, SkYUVColorSpace yuvColorSpace, const SkIRect *srcRect, const SkISize *dstSize, SkSurface::RescaleGamma rescaleGamma, SkSurface::RescaleMode rescaleMode, SkSurface::ReadPixelsCallback callback, SkSurface::ReadPixelsContext context)
// void SkSurface_asyncRescaleAndReadPixelsYUVA420(void *surface, sk_color_space_t dstColorSpace, int yuvColorSpace, const void *srcRect, const void *dstSize, int rescaleGamma, int rescaleMode, SkSurface::ReadPixelsCallback callback, void * context); // (SkSurface *surface, sk_color_space_t dstColorSpace, SkYUVColorSpace yuvColorSpace, const SkIRect *srcRect, const SkISize *dstSize, SkSurface::RescaleGamma rescaleGamma, SkSurface::RescaleMode rescaleMode, SkSurface::ReadPixelsCallback callback, SkSurface::ReadPixelsContext context)

void SkSurface_writePixels(void *surface, const void *src, int dstX, int dstY); // (SkSurface *surface, const SkPixmap *src, int dstX, int dstY)
void SkSurface_writePixels_2(void *surface, const void *src, int dstX, int dstY); // (SkSurface *surface, const SkBitmap *src, int dstX, int dstY)
const void * SkSurface_props(void *surface); // (SkSurface *surface) -> const SkSurfaceProps *
bool SkSurface_wait(void *surface, int numSemaphores, const void *waitSemaphores, bool deleteSemaphoresAfterWait); // (SkSurface *surface, int numSemaphores, const GrBackendSemaphore *waitSemaphores, bool deleteSemaphoresAfterWait) -> bool
bool SkSurface_characterize(void *surface, void *characterization); // (SkSurface *surface, GrSurfaceCharacterization *characterization) -> bool
bool SkSurface_unique(void *surface); // (SkSurface *surface) -> bool
void SkSurface_ref(void *surface); // (SkSurface *surface)
void SkSurface_unref(void *surface); // (SkSurface *surface)

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_SURFACE_H
