//
// Created by dolphilia on 25/01/30.
//

#ifndef SK_MASK_H
#define SK_MASK_H

#ifdef __cplusplus
extern "C" {
#endif

int SkMask_new(const void * img, const void * bounds, unsigned int rowBytes, int format); // (const uint8_t* img, const SkIRect * bounds, uint32_t rowBytes, SkMask::Format format) -> sk_mask_t
void SkMask_delete(void *mask);

// member

const void * SkMask_fImage(void *mask); // (SkMask *mask) -> const uint8_t *
int SkMask_fBounds(void *mask); // (SkMask *mask) -> sk_i_rect_t
unsigned int SkMask_fRowBytes(void *mask); // (SkMask *mask) -> uint32_t
int SkMask_fFormat(void *mask); // (SkMask *mask) -> SkMask::Format

// Method
bool SkMask_isEmpty(void *mask); // (SkMask *mask) -> bool
unsigned long SkMask_computeImageSize(void *mask); // (SkMask *mask) -> size_t
unsigned long SkMask_computeTotalImageSize(void *mask); // (SkMask *mask) -> size_t
const void* SkMask_getAddr1(void *mask, int x, int y); // (SkMask *mask, int x, int y) -> const uint8_t*
const void* SkMask_getAddr8(void *mask, int x, int y); // (SkMask *mask, int x, int y) -> const uint8_t*
const void* SkMask_getAddrLCD16(void *mask, int x, int y); // (SkMask *mask, int x, int y) -> const uint16_t*
const void* SkMask_getAddr32(void *mask, int x, int y); // (SkMask *mask, int x, int y) -> const uint32_t*
const void* SkMask_getAddr(void *mask, int x, int y); // (SkMask *mask, int x, int y) -> const void*

// static
static bool SkMask_IsValidFormat(unsigned int format); // (uint8_t format) -> bool

#ifdef __cplusplus
}
#endif

#endif //SK_MASK_H
