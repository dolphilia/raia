//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_SK_MALLOC_PIXEL_REF_H
#define RAIA_SKIA_SK_MALLOC_PIXEL_REF_H

#ifdef __cplusplus
extern "C" {
#endif

int SkMallocPixelRef_MakeAllocate(const void *imageInfo, unsigned long rowBytes); // (const SkImageInfo *imageInfo, size_t rowBytes) -> sk_pixel_ref_t
int SkMallocPixelRef_MakeWithData(const void *imageInfo, unsigned long rowBytes, int data); // (const SkImageInfo &imageInfo, size_t rowBytes, sk_data_t data) -> sk_pixel_ref_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_MALLOC_PIXEL_REF_H
