//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_GR_DIRECT_CONTEXT_H
#define RAIA_SKIA_GR_DIRECT_CONTEXT_H

#include "include/core/SkCapabilities.h"
#include "include/gpu/GrDirectContext.h"
#include "include/gpu/GrContextThreadSafeProxy.h"
#include "include/gpu/GrBackendSurface.h"
#include "../static/static_gr_context_thread_safe_proxy.h"
#include "../static/static_gr_backend_texture.h"
#include "../static/static_sk_capabilities.h"
#include "../static/static_gr_direct_context_direct_context_id.h"

extern "C" {
void GrDirectContext_delete(GrDirectContext *direct_context);
void GrDirectContext_resetContext(GrDirectContext *direct_context, uint32_t state);
void GrDirectContext_resetGLTextureBindings(GrDirectContext *direct_context);
void GrDirectContext_abandonContext(GrDirectContext *direct_context);
bool GrDirectContext_abandoned(GrDirectContext *direct_context);
bool GrDirectContext_isDeviceLost(GrDirectContext *direct_context);
int GrDirectContext_threadSafeProxy(GrDirectContext *direct_context);
bool GrDirectContext_oomed(GrDirectContext *direct_context);
void GrDirectContext_releaseResourcesAndAbandonContext(GrDirectContext *direct_context);
void GrDirectContext_getResourceCacheLimits(GrDirectContext *direct_context, int *maxResources, size_t *maxResourceBytes);
size_t GrDirectContext_getResourceCacheLimit(GrDirectContext *direct_context);
void GrDirectContext_getResourceCacheUsage(GrDirectContext *direct_context, int *resourceCount, size_t *resourceBytes);
size_t GrDirectContext_getResourceCachePurgeableBytes(GrDirectContext *direct_context);
void GrDirectContext_setResourceCacheLimits(GrDirectContext *direct_context, int maxResources, size_t maxResourceBytes);
void GrDirectContext_setResourceCacheLimit(GrDirectContext *direct_context, size_t maxResourceBytes);
void GrDirectContext_freeGpuResources(GrDirectContext *direct_context);
void GrDirectContext_performDeferredCleanup(GrDirectContext *direct_context, std::chrono::milliseconds msNotUsed, GrPurgeResourceOptions opts);
void GrDirectContext_purgeResourcesNotUsedInMs(GrDirectContext *direct_context, std::chrono::milliseconds msNotUsed);
void GrDirectContext_purgeUnlockedResources(GrDirectContext *direct_context, size_t bytesToPurge, bool preferScratchResources);
void GrDirectContext_purgeUnlockedResources_2(GrDirectContext *direct_context, GrPurgeResourceOptions opts);
bool GrDirectContext_wait(GrDirectContext *direct_context, int numSemaphores, const GrBackendSemaphore *waitSemaphores, bool deleteSemaphoresAfterWait);
void GrDirectContext_flushAndSubmit(GrDirectContext *direct_context, GrSyncCpu sync);
void GrDirectContext_flushAndSubmit_2(GrDirectContext *direct_context, const sk_sp< const SkImage > *image);
void GrDirectContext_flushAndSubmit_3(GrDirectContext *direct_context, SkSurface *surface, GrSyncCpu sync);
GrSemaphoresSubmitted GrDirectContext_flush(GrDirectContext *direct_context, const GrFlushInfo *info);
void GrDirectContext_flush_2(GrDirectContext *direct_context);
GrSemaphoresSubmitted GrDirectContext_flush_3(GrDirectContext *direct_context, const sk_sp< const SkImage > *image, const GrFlushInfo *info);
void GrDirectContext_flush_4(GrDirectContext *direct_context, const sk_sp< const SkImage > *image);
GrSemaphoresSubmitted GrDirectContext_flush_5(GrDirectContext *direct_context, SkSurface *surface, SkSurfaces::BackendSurfaceAccess access, const GrFlushInfo *info);
GrSemaphoresSubmitted GrDirectContext_flush_6(GrDirectContext *direct_context, SkSurface *surface, const GrFlushInfo *info, const skgpu::MutableTextureState *newState);
void GrDirectContext_flush_7(GrDirectContext *direct_context, SkSurface *surface);
bool GrDirectContext_submit(GrDirectContext *direct_context, GrSyncCpu sync);
void GrDirectContext_checkAsyncWorkCompletion(GrDirectContext *direct_context);
void GrDirectContext_dumpMemoryStatistics(GrDirectContext *direct_context, SkTraceMemoryDump *traceMemoryDump);
bool GrDirectContext_supportsDistanceFieldText(GrDirectContext *direct_context);
void GrDirectContext_storeVkPipelineCacheData(GrDirectContext *direct_context);
int GrDirectContext_createBackendTexture(GrDirectContext *direct_context, int width, int height, const GrBackendFormat *format, skgpu::Mipmapped mipmapped, GrRenderable renderable, GrProtected isProtected, std::string_view label);
int GrDirectContext_createBackendTexture_2(GrDirectContext *direct_context, int width, int height, SkColorType type, skgpu::Mipmapped mipmapped, GrRenderable renderable, GrProtected isProtected, std::string_view label);
int GrDirectContext_createBackendTexture_3(GrDirectContext *direct_context, int width, int height, const GrBackendFormat *format, const SkColor4f *color, skgpu::Mipmapped mipmapped, GrRenderable renderable, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext, std::string_view label);
int GrDirectContext_createBackendTexture_4(GrDirectContext *direct_context, int width, int height, SkColorType type, const SkColor4f *color, skgpu::Mipmapped mipmapped, GrRenderable renderable, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext, std::string_view label);
int GrDirectContext_createBackendTexture_5(GrDirectContext *direct_context, const SkPixmap srcData[], int numLevels, GrSurfaceOrigin textureOrigin, GrRenderable renderable, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext, std::string_view label);
int GrDirectContext_createBackendTexture_6(GrDirectContext *direct_context, const SkPixmap *srcData, GrSurfaceOrigin textureOrigin, GrRenderable renderable, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext, std::string_view label);
int GrDirectContext_createBackendTexture_7(GrDirectContext *direct_context, const SkPixmap srcData[], int numLevels, GrRenderable renderable, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext, std::string_view label);
int GrDirectContext_createBackendTexture_8(GrDirectContext *direct_context, const SkPixmap *srcData, GrRenderable renderable, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext, std::string_view label);
bool GrDirectContext_updateBackendTexture(GrDirectContext *direct_context, const GrBackendTexture *texture, const SkColor4f *color, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
bool GrDirectContext_updateBackendTexture_2(GrDirectContext *direct_context, const GrBackendTexture *texture, SkColorType skColorType, const SkColor4f *color, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
bool GrDirectContext_updateBackendTexture_3(GrDirectContext *direct_context, const GrBackendTexture *texture, const SkPixmap srcData[], int numLevels, GrSurfaceOrigin textureOrigin, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
bool GrDirectContext_updateBackendTexture_4(GrDirectContext *direct_context, const GrBackendTexture *texture, const SkPixmap *srcData, GrSurfaceOrigin textureOrigin, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
bool GrDirectContext_updateBackendTexture_5(GrDirectContext *direct_context, const GrBackendTexture *texture, const SkPixmap srcData[], int numLevels, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
int GrDirectContext_createCompressedBackendTexture(GrDirectContext *direct_context, int width, int height, const GrBackendFormat *format, const SkColor4f *color, skgpu::Mipmapped mipmapped, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
int GrDirectContext_createCompressedBackendTexture_2(GrDirectContext *direct_context, int width, int height, SkTextureCompressionType type, const SkColor4f *color, skgpu::Mipmapped mipmapped, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
int GrDirectContext_createCompressedBackendTexture_3(GrDirectContext *direct_context, int width, int height, const GrBackendFormat *format, const void *data, size_t dataSize, skgpu::Mipmapped mipmapped, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
int GrDirectContext_createCompressedBackendTexture_4(GrDirectContext *direct_context, int width, int height, SkTextureCompressionType type, const void *data, size_t dataSize, skgpu::Mipmapped mipmapped, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
bool GrDirectContext_updateCompressedBackendTexture(GrDirectContext *direct_context, const GrBackendTexture *texture, const SkColor4f *color, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
bool GrDirectContext_updateCompressedBackendTexture_2(GrDirectContext *direct_context, const GrBackendTexture *texture, const void *data, size_t dataSize, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
bool GrDirectContext_setBackendTextureState(GrDirectContext *direct_context, const GrBackendTexture *texture, const skgpu::MutableTextureState *state, skgpu::MutableTextureState *previousState, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
bool GrDirectContext_setBackendRenderTargetState(GrDirectContext *direct_context, const GrBackendRenderTarget *target, const skgpu::MutableTextureState *state, skgpu::MutableTextureState *previousState, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext);
void GrDirectContext_deleteBackendTexture(GrDirectContext *direct_context, const GrBackendTexture *texture);
bool GrDirectContext_precompileShader(GrDirectContext *direct_context, const SkData *key, const SkData *data);
int GrDirectContext_directContextID(GrDirectContext *direct_context);
// GrDirectContextPriv GrDirectContext_priv(GrDirectContext *direct_context);
// const GrDirectContextPriv GrDirectContext_priv_2(GrDirectContext *direct_context);
int GrDirectContext_maxTextureSize(GrDirectContext *direct_context);
int GrDirectContext_maxRenderTargetSize(GrDirectContext *direct_context);
bool GrDirectContext_colorTypeSupportedAsImage(GrDirectContext *direct_context, SkColorType colorType);
bool GrDirectContext_supportsProtectedContent(GrDirectContext *direct_context);
bool GrDirectContext_colorTypeSupportedAsSurface(GrDirectContext *direct_context, SkColorType colorType);
bool GrDirectContext_colorTypeSupportedAsSurface_2(GrDirectContext *direct_context, SkColorType colorType);
int GrDirectContext_maxSurfaceSampleCountForColorType(GrDirectContext *direct_context, SkColorType colorType);
int GrDirectContext_skCapabilities(GrDirectContext *direct_context);
static sk_sp< GrDirectContext > GrDirectContext_MakeMock(const GrMockOptions *mockOptions, const GrContextOptions *contextOptions);
static sk_sp< GrDirectContext > GrDirectContext_MakeMock_2(const GrMockOptions *mockOptions);
}

#endif //RAIA_SKIA_GR_DIRECT_CONTEXT_H
