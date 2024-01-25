//
// Created by dolphilia on 2024/01/13.
//

#include "sk_malloc_pixel_ref.h"

extern "C" {

int SkMallocPixelRef_MakeAllocate(const SkImageInfo *imageInfo, size_t rowBytes) {
    return static_sk_pixel_ref_make(SkMallocPixelRef::MakeAllocate(*imageInfo, rowBytes));
}

int SkMallocPixelRef_MakeWithData(int sk_data_key_in, const SkImageInfo &imageInfo, size_t rowBytes) {
    return static_sk_pixel_ref_make(SkMallocPixelRef::MakeWithData(imageInfo, rowBytes, static_sk_data_move(sk_data_key_in)));
}

}