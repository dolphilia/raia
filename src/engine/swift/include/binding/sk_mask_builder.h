//
// Created by dolphilia on 25/01/30.
//

#ifndef SK_MASK_BUILDER_H
#define SK_MASK_BUILDER_H

#ifdef __cplusplus
extern "C" {
#endif

void * SkMaskBuilder_new(); // () -> SkMaskBuilder *
void * SkMaskBuilder_new_2(void * img, const void * bounds, unsigned int rowBytes, int format); // (uint8_t* img, const SkIRect * bounds, uint32_t rowBytes, SkMask::Format format) -> SkMaskBuilder *
void SkMaskBuilder_delete(void * maskBuilder); // (SkMaskBuilder* maskBuilder)
void * SkMaskBuilder_image(void * maskBuilder); // (SkMaskBuilder *maskBuilder) -> uint8_t*
void * SkMaskBuilder_bounds(void * maskBuilder); // (SkMaskBuilder *maskBuilder) -> SkIRect *
unsigned int SkMaskBuilder_rowBytes(void * maskBuilder); // (SkMaskBuilder *maskBuilder) -> uint32_t
int SkMaskBuilder_format(void * maskBuilder); // (SkMaskBuilder *maskBuilder) -> SkMask::Format
void * SkMaskBuilder_getAddr1(void * maskBuilder, int x, int y); // (SkMaskBuilder *maskBuilder, int x, int y) -> uint8_t*
void * SkMaskBuilder_getAddr8(void * maskBuilder, int x, int y); // (SkMaskBuilder *maskBuilder, int x, int y) -> uint8_t*
void * SkMaskBuilder_getAddrLCD16(void * maskBuilder, int x, int y); // (SkMaskBuilder *maskBuilder, int x, int y) -> uint16_t*
void * SkMaskBuilder_getAddr32(void * maskBuilder, int x, int y); // (SkMaskBuilder *maskBuilder, int x, int y) -> uint32_t*
void * SkMaskBuilder_getAddr(void * maskBuilder, int x, int y); // (SkMaskBuilder *maskBuilder, int x, int y) -> void*
// static
static void * SkMaskBuilder_AllocImage(unsigned long bytes, int alloc); // (size_t bytes, SkMaskBuilder::AllocType alloc) -> uint8_t*
static void SkMaskBuilder_FreeImage(void * image); // (void* image)
static int SkMaskBuilder_PrepareDestination(int radiusX, int radiusY, const void * src); // (int radiusX, int radiusY, const SkMask * src) -> sk_mask_builder_t

#ifdef __cplusplus
}
#endif

#endif //SK_MASK_BUILDER_H
