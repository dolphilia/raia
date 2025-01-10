//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_SK_MALLOC_PIXEL_REF_H
#define RAIA_SKIA_SK_MALLOC_PIXEL_REF_H

#include "include/core/SkPixelRef.h"
#include "include/core/SkImageInfo.h"
#include "include/core/SkData.h"
#include "include/core/SkMallocPixelRef.h"
#include "../static/static_sk_pixel_ref.h"
#include "../static/static_sk_data.h"

extern "C" {
sk_pixel_ref_t SkMallocPixelRef_MakeAllocate(const SkImageInfo *imageInfo, size_t rowBytes);
sk_pixel_ref_t SkMallocPixelRef_MakeWithData(const SkImageInfo &imageInfo, size_t rowBytes, sk_data_t data);
}

#endif //RAIA_SKIA_SK_MALLOC_PIXEL_REF_H
