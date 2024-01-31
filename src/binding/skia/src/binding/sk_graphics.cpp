//
// Created by dolphilia on 2024/01/08.
//

#include "sk_graphics.h"

extern "C" {

void SkGraphics_delete(SkGraphics * graphics) {
    delete graphics;
}

// static

void SkGraphics_Init() {
    SkGraphics::Init();
}

size_t SkGraphics_GetFontCacheLimit() {
    return SkGraphics::GetFontCacheLimit();
}

size_t SkGraphics_SetFontCacheLimit(size_t bytes) {
    return SkGraphics::SetFontCacheLimit(bytes);
}

size_t SkGraphics_GetFontCacheUsed() {
    return SkGraphics::GetFontCacheUsed();
}

int SkGraphics_GetFontCacheCountUsed() {
    return SkGraphics::GetFontCacheCountUsed();
}

int SkGraphics_GetFontCacheCountLimit() {
    return SkGraphics::GetFontCacheCountLimit();
}

int SkGraphics_SetFontCacheCountLimit(int count) {
    return SkGraphics::SetFontCacheCountLimit(count);
}

void SkGraphics_PurgeFontCache() {
    SkGraphics::PurgeFontCache();
}

void SkGraphics_PurgePinnedFontCache() {
    SkGraphics::PurgePinnedFontCache();
}

size_t SkGraphics_GetResourceCacheTotalBytesUsed() {
    return SkGraphics::GetResourceCacheTotalBytesUsed();
}

size_t SkGraphics_GetResourceCacheTotalByteLimit() {
    return SkGraphics::GetResourceCacheTotalByteLimit();
}

size_t SkGraphics_SetResourceCacheTotalByteLimit(size_t newLimit) {
    return SkGraphics::SetResourceCacheTotalByteLimit(newLimit);
}

void SkGraphics_PurgeResourceCache() {
    SkGraphics::PurgeResourceCache();
}
size_t SkGraphics_GetResourceCacheSingleAllocationByteLimit() {
    return SkGraphics::GetResourceCacheSingleAllocationByteLimit();
}

size_t SkGraphics_SetResourceCacheSingleAllocationByteLimit(size_t newLimit) {
    return SkGraphics::SetResourceCacheSingleAllocationByteLimit(newLimit);
}

void SkGraphics_DumpMemoryStatistics(SkTraceMemoryDump *dump) {
    SkGraphics::DumpMemoryStatistics(dump);
}

void SkGraphics_PurgeAllCaches() {
    SkGraphics::PurgeAllCaches();
}

SkGraphics::ImageGeneratorFromEncodedDataFactory SkGraphics_SetImageGeneratorFromEncodedDataFactory(SkGraphics::ImageGeneratorFromEncodedDataFactory factory) {
    return SkGraphics::SetImageGeneratorFromEncodedDataFactory(factory);
}

SkGraphics::OpenTypeSVGDecoderFactory SkGraphics_SetOpenTypeSVGDecoderFactory(SkGraphics::OpenTypeSVGDecoderFactory factory) {
    return SkGraphics::SetOpenTypeSVGDecoderFactory(factory);
}

SkGraphics::OpenTypeSVGDecoderFactory SkGraphics_GetOpenTypeSVGDecoderFactory() {
    return SkGraphics::GetOpenTypeSVGDecoderFactory();
}

}