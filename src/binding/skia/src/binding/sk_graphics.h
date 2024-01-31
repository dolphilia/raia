//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_GRAPHICS_H
#define RAIA_SKIA_SK_GRAPHICS_H

#include "include/core/SkGraphics.h"

extern "C" {
void SkGraphics_delete(SkGraphics * graphics);
// static
void SkGraphics_Init();
size_t SkGraphics_GetFontCacheLimit();
size_t SkGraphics_SetFontCacheLimit(size_t bytes);
size_t SkGraphics_GetFontCacheUsed();
int SkGraphics_GetFontCacheCountUsed();
int SkGraphics_GetFontCacheCountLimit();
int SkGraphics_SetFontCacheCountLimit(int count);
void SkGraphics_PurgeFontCache();
void SkGraphics_PurgePinnedFontCache();
size_t SkGraphics_GetResourceCacheTotalBytesUsed();
size_t SkGraphics_GetResourceCacheTotalByteLimit();
size_t SkGraphics_SetResourceCacheTotalByteLimit(size_t newLimit);
void SkGraphics_PurgeResourceCache();
size_t SkGraphics_GetResourceCacheSingleAllocationByteLimit();
size_t SkGraphics_SetResourceCacheSingleAllocationByteLimit(size_t newLimit);
void SkGraphics_DumpMemoryStatistics(SkTraceMemoryDump *dump);
void SkGraphics_PurgeAllCaches();
SkGraphics::ImageGeneratorFromEncodedDataFactory SkGraphics_SetImageGeneratorFromEncodedDataFactory(SkGraphics::ImageGeneratorFromEncodedDataFactory factory);
SkGraphics::OpenTypeSVGDecoderFactory SkGraphics_SetOpenTypeSVGDecoderFactory(SkGraphics::OpenTypeSVGDecoderFactory factory);
SkGraphics::OpenTypeSVGDecoderFactory SkGraphics_GetOpenTypeSVGDecoderFactory();
}

#endif //RAIA_SKIA_SK_GRAPHICS_H
