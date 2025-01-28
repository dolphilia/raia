//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_GRAPHICS_H
#define RAIA_SKIA_SK_GRAPHICS_H

#ifdef __cplusplus
extern "C" {
#endif

void SkGraphics_delete(void *graphics); // (SkGraphics *graphics)

// static

void SkGraphics_Init(); // ()
unsigned long SkGraphics_GetFontCacheLimit(); // () -> size_t
unsigned long SkGraphics_SetFontCacheLimit(unsigned long bytes); // (size_t bytes) -> size_t
unsigned long SkGraphics_GetFontCacheUsed(); // () -> size_t
int SkGraphics_GetFontCacheCountUsed(); // () -> int
int SkGraphics_GetFontCacheCountLimit(); // () -> int
int SkGraphics_SetFontCacheCountLimit(int count); // (int count) -> int
void SkGraphics_PurgeFontCache(); // ()
void SkGraphics_PurgePinnedFontCache(); // ()
unsigned long SkGraphics_GetResourceCacheTotalBytesUsed(); // () -> size_t
unsigned long SkGraphics_GetResourceCacheTotalByteLimit(); // () -> size_t
unsigned long SkGraphics_SetResourceCacheTotalByteLimit(unsigned long newLimit); // (size_t newLimit) -> size_t
void SkGraphics_PurgeResourceCache(); // ()
unsigned long SkGraphics_GetResourceCacheSingleAllocationByteLimit(); // () -> size_t
unsigned long SkGraphics_SetResourceCacheSingleAllocationByteLimit(unsigned long newLimit); // (size_t newLimit) -> size_t
void SkGraphics_DumpMemoryStatistics(void *dump); // (SkTraceMemoryDump *dump)
void SkGraphics_PurgeAllCaches(); // ()

// TODO
//void * SkGraphics_SetImageGeneratorFromEncodedDataFactory(void * factory); // (SkGraphics::ImageGeneratorFromEncodedDataFactory factory) -> SkGraphics::ImageGeneratorFromEncodedDataFactory
//void * SkGraphics_SetOpenTypeSVGDecoderFactory(SkGraphics::OpenTypeSVGDecoderFactory factory); // (SkGraphics::OpenTypeSVGDecoderFactory factory) -> SkGraphics::OpenTypeSVGDecoderFactory
//void * SkGraphics_GetOpenTypeSVGDecoderFactory(); // () -> SkGraphics::OpenTypeSVGDecoderFactory

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_GRAPHICS_H
