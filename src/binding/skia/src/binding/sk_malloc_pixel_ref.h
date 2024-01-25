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
void SkMallocPixelRef_MakeAllocate(int sk_pixel_ref_key_out, const SkImageInfo *imageInfo, size_t rowBytes);
void SkMallocPixelRef_MakeWithData(int sk_pixel_ref_key_out, int sk_data_key_in, const SkImageInfo &imageInfo, size_t rowBytes);
}

#endif //RAIA_SKIA_SK_MALLOC_PIXEL_REF_H
