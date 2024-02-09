//
// Created by dolphilia on 2024/01/13.
//

#include "sk_malloc_pixel_ref.h"

extern "C" {

sk_pixel_ref_t SkMallocPixelRef_MakeAllocate(const SkImageInfo *imageInfo, size_t rowBytes) {
    return static_sk_pixel_ref_make(SkMallocPixelRef::MakeAllocate(*imageInfo, rowBytes));
}

sk_pixel_ref_t SkMallocPixelRef_MakeWithData(const SkImageInfo &imageInfo, size_t rowBytes, sk_data_t data) {
    return static_sk_pixel_ref_make(SkMallocPixelRef::MakeWithData(imageInfo, rowBytes, static_sk_data_move(data)));
}

}