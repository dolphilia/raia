//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_GRAPHICS_H
#define RAIA_SKIA_SK_GRAPHICS_H

#include "include/core/SkGraphics.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkGraphics_delete(SkGraphics * graphics);
// static
RAIA_API void SkGraphics_Init();
RAIA_API size_t SkGraphics_GetFontCacheLimit();
RAIA_API size_t SkGraphics_SetFontCacheLimit(size_t bytes);
RAIA_API size_t SkGraphics_GetFontCacheUsed();
RAIA_API int SkGraphics_GetFontCacheCountUsed();
RAIA_API int SkGraphics_GetFontCacheCountLimit();
RAIA_API int SkGraphics_SetFontCacheCountLimit(int count);
RAIA_API void SkGraphics_PurgeFontCache();
RAIA_API void SkGraphics_PurgePinnedFontCache();
RAIA_API size_t SkGraphics_GetResourceCacheTotalBytesUsed();
RAIA_API size_t SkGraphics_GetResourceCacheTotalByteLimit();
RAIA_API size_t SkGraphics_SetResourceCacheTotalByteLimit(size_t newLimit);
RAIA_API void SkGraphics_PurgeResourceCache();
RAIA_API size_t SkGraphics_GetResourceCacheSingleAllocationByteLimit();
RAIA_API size_t SkGraphics_SetResourceCacheSingleAllocationByteLimit(size_t newLimit);
RAIA_API void SkGraphics_DumpMemoryStatistics(SkTraceMemoryDump *dump);
RAIA_API void SkGraphics_PurgeAllCaches();
RAIA_API SkGraphics::ImageGeneratorFromEncodedDataFactory SkGraphics_SetImageGeneratorFromEncodedDataFactory(SkGraphics::ImageGeneratorFromEncodedDataFactory factory);
RAIA_API SkGraphics::OpenTypeSVGDecoderFactory SkGraphics_SetOpenTypeSVGDecoderFactory(SkGraphics::OpenTypeSVGDecoderFactory factory);
RAIA_API SkGraphics::OpenTypeSVGDecoderFactory SkGraphics_GetOpenTypeSVGDecoderFactory();
}

#endif //RAIA_SKIA_SK_GRAPHICS_H
