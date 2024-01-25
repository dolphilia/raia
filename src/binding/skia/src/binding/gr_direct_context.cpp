//
// Created by dolphilia on 2024/01/12.
//

#include "gr_direct_context.h"

extern "C" {

void GrDirectContext_delete(GrDirectContext *direct_context) {
    delete direct_context;
}

void GrDirectContext_resetContext(GrDirectContext *direct_context, uint32_t state) {
    direct_context->resetContext(state);
}

void GrDirectContext_resetGLTextureBindings(GrDirectContext *direct_context) {
    direct_context->resetGLTextureBindings();
}

void GrDirectContext_abandonContext(GrDirectContext *direct_context) {
    direct_context->abandonContext();
}

bool GrDirectContext_abandoned(GrDirectContext *direct_context) {
    return direct_context->abandoned();
}

bool GrDirectContext_isDeviceLost(GrDirectContext *direct_context) {
    return direct_context->isDeviceLost();
}

void GrDirectContext_threadSafeProxy(int gr_context_thread_safe_proxy_key_out, GrDirectContext *direct_context) {
    static_gr_context_thread_safe_proxy_set(gr_context_thread_safe_proxy_key_out, direct_context->threadSafeProxy());
}

bool GrDirectContext_oomed(GrDirectContext *direct_context) {
    return direct_context->oomed();
}

void GrDirectContext_releaseResourcesAndAbandonContext(GrDirectContext *direct_context) {
    direct_context->releaseResourcesAndAbandonContext();
}

void GrDirectContext_getResourceCacheLimits(GrDirectContext *direct_context, int *maxResources, size_t *maxResourceBytes) {
    direct_context->getResourceCacheLimits(maxResources, maxResourceBytes);
}

size_t GrDirectContext_getResourceCacheLimit(GrDirectContext *direct_context) {
    return direct_context->getResourceCacheLimit();
}

void GrDirectContext_getResourceCacheUsage(GrDirectContext *direct_context, int *resourceCount, size_t *resourceBytes) {
    direct_context->getResourceCacheUsage(resourceCount, resourceBytes);
}

size_t GrDirectContext_getResourceCachePurgeableBytes(GrDirectContext *direct_context) {
    return direct_context->getResourceCachePurgeableBytes();
}

void GrDirectContext_setResourceCacheLimits(GrDirectContext *direct_context, int maxResources, size_t maxResourceBytes) {
    direct_context->setResourceCacheLimits(maxResources, maxResourceBytes);
}

void GrDirectContext_setResourceCacheLimit(GrDirectContext *direct_context, size_t maxResourceBytes) {
    direct_context->setResourceCacheLimit(maxResourceBytes);
}

void GrDirectContext_freeGpuResources(GrDirectContext *direct_context) {
    direct_context->freeGpuResources();
}

void GrDirectContext_performDeferredCleanup(GrDirectContext *direct_context, std::chrono::milliseconds msNotUsed, GrPurgeResourceOptions opts) {
    direct_context->performDeferredCleanup(msNotUsed, opts);
}

void GrDirectContext_purgeResourcesNotUsedInMs(GrDirectContext *direct_context, std::chrono::milliseconds msNotUsed) {
    direct_context->purgeResourcesNotUsedInMs(msNotUsed);
}

void GrDirectContext_purgeUnlockedResources(GrDirectContext *direct_context, size_t bytesToPurge, bool preferScratchResources) {
    direct_context->purgeUnlockedResources(bytesToPurge, preferScratchResources);
}

void GrDirectContext_purgeUnlockedResources_2(GrDirectContext *direct_context, GrPurgeResourceOptions opts) {
    direct_context->purgeUnlockedResources(opts);
}

bool GrDirectContext_wait(GrDirectContext *direct_context, int numSemaphores, const GrBackendSemaphore *waitSemaphores, bool deleteSemaphoresAfterWait) {
    return direct_context->wait(numSemaphores, waitSemaphores, deleteSemaphoresAfterWait);
}

void GrDirectContext_flushAndSubmit(GrDirectContext *direct_context, GrSyncCpu sync) {
    direct_context->flushAndSubmit(sync);
}

void GrDirectContext_flushAndSubmit_2(GrDirectContext *direct_context, const sk_sp< const SkImage > *image) {
    direct_context->flushAndSubmit(*image);
}

void GrDirectContext_flushAndSubmit_3(GrDirectContext *direct_context, SkSurface *surface, GrSyncCpu sync) {
    direct_context->flushAndSubmit(surface, sync);
}

GrSemaphoresSubmitted GrDirectContext_flush(GrDirectContext *direct_context, const GrFlushInfo *info) {
    return direct_context->flush(*info);
}

void GrDirectContext_flush_2(GrDirectContext *direct_context) {
    direct_context->flush();
}

GrSemaphoresSubmitted GrDirectContext_flush_3(GrDirectContext *direct_context, const sk_sp< const SkImage > *image, const GrFlushInfo *info) {
    return direct_context->flush(*image, *info);
}

void GrDirectContext_flush_4(GrDirectContext *direct_context, const sk_sp< const SkImage > *image) {
    direct_context->flush(*image);
}

GrSemaphoresSubmitted GrDirectContext_flush_5(GrDirectContext *direct_context, SkSurface *surface, SkSurfaces::BackendSurfaceAccess access, const GrFlushInfo *info) {
    return direct_context->flush(surface, access, *info);
}

GrSemaphoresSubmitted GrDirectContext_flush_6(GrDirectContext *direct_context, SkSurface *surface, const GrFlushInfo *info, const skgpu::MutableTextureState *newState) {
    return direct_context->flush(surface, *info, newState);
}

void GrDirectContext_flush_7(GrDirectContext *direct_context, SkSurface *surface) {
    direct_context->flush(surface);
}

bool GrDirectContext_submit(GrDirectContext *direct_context, GrSyncCpu sync) {
    return direct_context->submit(sync);
}

void GrDirectContext_checkAsyncWorkCompletion(GrDirectContext *direct_context) {
    direct_context->checkAsyncWorkCompletion();
}

void GrDirectContext_dumpMemoryStatistics(GrDirectContext *direct_context, SkTraceMemoryDump *traceMemoryDump) {
    direct_context->dumpMemoryStatistics(traceMemoryDump);
}

bool GrDirectContext_supportsDistanceFieldText(GrDirectContext *direct_context) {
    return direct_context->supportsDistanceFieldText();
}

void GrDirectContext_storeVkPipelineCacheData(GrDirectContext *direct_context) {
    direct_context->storeVkPipelineCacheData();
}

void GrDirectContext_createBackendTexture(int gr_backend_texture_key_out, GrDirectContext *direct_context, int width, int height, const GrBackendFormat *format, skgpu::Mipmapped mipmapped, GrRenderable renderable, GrProtected isProtected, std::string_view label) {
    static_gr_backend_texture_set(gr_backend_texture_key_out, direct_context->createBackendTexture(width, height, *format, mipmapped, renderable, isProtected, label));
}

void GrDirectContext_createBackendTexture_2(int gr_backend_texture_key_out, GrDirectContext *direct_context, int width, int height, SkColorType type, skgpu::Mipmapped mipmapped, GrRenderable renderable, GrProtected isProtected, std::string_view label) {
    static_gr_backend_texture_set(gr_backend_texture_key_out, direct_context->createBackendTexture(width, height, type, mipmapped, renderable, isProtected, label));
}

void GrDirectContext_createBackendTexture_3(int gr_backend_texture_key_out, GrDirectContext *direct_context, int width, int height, const GrBackendFormat *format, const SkColor4f *color, skgpu::Mipmapped mipmapped, GrRenderable renderable, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext, std::string_view label) {
    static_gr_backend_texture_set(gr_backend_texture_key_out, direct_context->createBackendTexture(width, height, *format, *color, mipmapped, renderable, isProtected, finishedProc, finishedContext, label));
}

void GrDirectContext_createBackendTexture_4(int gr_backend_texture_key_out, GrDirectContext *direct_context, int width, int height, SkColorType type, const SkColor4f *color, skgpu::Mipmapped mipmapped, GrRenderable renderable, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext, std::string_view label) {
    static_gr_backend_texture_set(gr_backend_texture_key_out, direct_context->createBackendTexture(width, height, type, *color, mipmapped, renderable, isProtected, finishedProc, finishedContext, label));
}

void GrDirectContext_createBackendTexture_5(int gr_backend_texture_key_out, GrDirectContext *direct_context, const SkPixmap srcData[], int numLevels, GrSurfaceOrigin textureOrigin, GrRenderable renderable, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext, std::string_view label) {
    static_gr_backend_texture_set(gr_backend_texture_key_out, direct_context->createBackendTexture(srcData, numLevels, textureOrigin, renderable, isProtected, finishedProc, finishedContext, label));
}

void GrDirectContext_createBackendTexture_6(int gr_backend_texture_key_out, GrDirectContext *direct_context, const SkPixmap *srcData, GrSurfaceOrigin textureOrigin, GrRenderable renderable, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext, std::string_view label) {
    static_gr_backend_texture_set(gr_backend_texture_key_out, direct_context->createBackendTexture(*srcData, textureOrigin, renderable, isProtected, finishedProc, finishedContext, label));
}

void GrDirectContext_createBackendTexture_7(int gr_backend_texture_key_out, GrDirectContext *direct_context, const SkPixmap srcData[], int numLevels, GrRenderable renderable, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext, std::string_view label) {
    static_gr_backend_texture_set(gr_backend_texture_key_out, direct_context->createBackendTexture(srcData, numLevels, renderable, isProtected, finishedProc, finishedContext, label));
}

void GrDirectContext_createBackendTexture_8(int gr_backend_texture_key_out, GrDirectContext *direct_context, const SkPixmap *srcData, GrRenderable renderable, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext, std::string_view label) {
    static_gr_backend_texture_set(gr_backend_texture_key_out, direct_context->createBackendTexture(*srcData, renderable, isProtected, finishedProc, finishedContext, label));
}

bool GrDirectContext_updateBackendTexture(GrDirectContext *direct_context, const GrBackendTexture *texture, const SkColor4f *color, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext) {
    return direct_context->updateBackendTexture(*texture, *color, finishedProc, finishedContext);
}

bool GrDirectContext_updateBackendTexture_2(GrDirectContext *direct_context, const GrBackendTexture *texture, SkColorType skColorType, const SkColor4f *color, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext) {
    return direct_context->updateBackendTexture(*texture, skColorType, *color, finishedProc, finishedContext);
}

bool GrDirectContext_updateBackendTexture_3(GrDirectContext *direct_context, const GrBackendTexture *texture, const SkPixmap srcData[], int numLevels, GrSurfaceOrigin textureOrigin, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext) {
    return direct_context->updateBackendTexture(*texture, srcData, numLevels, textureOrigin, finishedProc, finishedContext);
}

bool GrDirectContext_updateBackendTexture_4(GrDirectContext *direct_context, const GrBackendTexture *texture, const SkPixmap *srcData, GrSurfaceOrigin textureOrigin, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext) {
    return direct_context->updateBackendTexture(*texture, *srcData, textureOrigin, finishedProc, finishedContext);
}

bool GrDirectContext_updateBackendTexture_5(GrDirectContext *direct_context, const GrBackendTexture *texture, const SkPixmap srcData[], int numLevels, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext) {
    return direct_context->updateBackendTexture(*texture, srcData, numLevels, finishedProc, finishedContext);
}

void GrDirectContext_createCompressedBackendTexture(int gr_backend_texture_key_out, GrDirectContext *direct_context, int width, int height, const GrBackendFormat *format, const SkColor4f *color, skgpu::Mipmapped mipmapped, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext) {
    static_gr_backend_texture_set(gr_backend_texture_key_out, direct_context->createCompressedBackendTexture(width, height, *format, *color, mipmapped, isProtected, finishedProc, finishedContext));
}

void GrDirectContext_createCompressedBackendTexture_2(int gr_backend_texture_key_out, GrDirectContext *direct_context, int width, int height, SkTextureCompressionType type, const SkColor4f *color, skgpu::Mipmapped mipmapped, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext) {
    static_gr_backend_texture_set(gr_backend_texture_key_out, direct_context->createCompressedBackendTexture(width, height, type, *color, mipmapped, isProtected, finishedProc, finishedContext));
}

void GrDirectContext_createCompressedBackendTexture_3(int gr_backend_texture_key_out, GrDirectContext *direct_context, int width, int height, const GrBackendFormat *format, const void *data, size_t dataSize, skgpu::Mipmapped mipmapped, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext) {
    static_gr_backend_texture_set(gr_backend_texture_key_out, direct_context->createCompressedBackendTexture(width, height, *format, data, dataSize, mipmapped, isProtected, finishedProc, finishedContext));
}

void GrDirectContext_createCompressedBackendTexture_4(int gr_backend_texture_key_out, GrDirectContext *direct_context, int width, int height, SkTextureCompressionType type, const void *data, size_t dataSize, skgpu::Mipmapped mipmapped, GrProtected isProtected, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext) {
    static_gr_backend_texture_set(gr_backend_texture_key_out, direct_context->createCompressedBackendTexture(width, height, type, data, dataSize, mipmapped, isProtected, finishedProc, finishedContext));
}

bool GrDirectContext_updateCompressedBackendTexture(GrDirectContext *direct_context, const GrBackendTexture *texture, const SkColor4f *color, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext) {
    return direct_context->updateCompressedBackendTexture(*texture, *color, finishedProc, finishedContext);
}

bool GrDirectContext_updateCompressedBackendTexture_2(GrDirectContext *direct_context, const GrBackendTexture *texture, const void *data, size_t dataSize, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext) {
    return direct_context->updateCompressedBackendTexture(*texture, data, dataSize, finishedProc, finishedContext);
}

bool GrDirectContext_setBackendTextureState(GrDirectContext *direct_context, const GrBackendTexture *texture, const skgpu::MutableTextureState *state, skgpu::MutableTextureState *previousState, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext) {
    return direct_context->setBackendTextureState(*texture, *state, previousState, finishedProc, finishedContext);
}

bool GrDirectContext_setBackendRenderTargetState(GrDirectContext *direct_context, const GrBackendRenderTarget *target, const skgpu::MutableTextureState *state, skgpu::MutableTextureState *previousState, GrGpuFinishedProc finishedProc, GrGpuFinishedContext finishedContext) {
    return direct_context->setBackendRenderTargetState(*target, *state, previousState, finishedProc, finishedContext);
}

void GrDirectContext_deleteBackendTexture(GrDirectContext *direct_context, const GrBackendTexture *texture) {
    return direct_context->deleteBackendTexture(*texture);
}

bool GrDirectContext_precompileShader(GrDirectContext *direct_context, const SkData *key, const SkData *data) {
    return direct_context->precompileShader(*key, *data);
}

void GrDirectContext_directContextID(int gr_direct_context_direct_context_id_key_out, GrDirectContext *direct_context) {
    static_gr_direct_context_direct_context_id_set(gr_direct_context_direct_context_id_key_out, direct_context->directContextID());
}

//GrDirectContextPriv GrDirectContext_priv(GrDirectContext *direct_context) {
//    return direct_context->priv();
//}

//const GrDirectContextPriv GrDirectContext_priv_2(GrDirectContext *direct_context) {
//    return direct_context->priv();
//}

int GrDirectContext_maxTextureSize(GrDirectContext *direct_context) {
    return direct_context->maxTextureSize();
}

int GrDirectContext_maxRenderTargetSize(GrDirectContext *direct_context) {
    return direct_context->maxRenderTargetSize();
}

bool GrDirectContext_colorTypeSupportedAsImage(GrDirectContext *direct_context, SkColorType colorType) {
    return direct_context->colorTypeSupportedAsImage(colorType);
}

bool GrDirectContext_supportsProtectedContent(GrDirectContext *direct_context) {
    return direct_context->supportsProtectedContent();
}

bool GrDirectContext_colorTypeSupportedAsSurface(GrDirectContext *direct_context, SkColorType colorType) {
    return direct_context->colorTypeSupportedAsSurface(colorType);
}

bool GrDirectContext_colorTypeSupportedAsSurface_2(GrDirectContext *direct_context, SkColorType colorType) {
    return direct_context->colorTypeSupportedAsSurface(colorType);
}

int GrDirectContext_maxSurfaceSampleCountForColorType(GrDirectContext *direct_context, SkColorType colorType) {
    return direct_context->maxSurfaceSampleCountForColorType(colorType);
}

void GrDirectContext_skCapabilities(int sk_capabilities_key_out, GrDirectContext *direct_context) {
    static_const_sk_capabilities_set(sk_capabilities_key_out, direct_context->skCapabilities());
}

static sk_sp< GrDirectContext > GrDirectContext_MakeMock(const GrMockOptions *mockOptions, const GrContextOptions *contextOptions) {
    return GrDirectContext::MakeMock(mockOptions, *contextOptions);
}

static sk_sp< GrDirectContext > GrDirectContext_MakeMock_2(const GrMockOptions *mockOptions) {
    return GrDirectContext::MakeMock(mockOptions);
}

}
