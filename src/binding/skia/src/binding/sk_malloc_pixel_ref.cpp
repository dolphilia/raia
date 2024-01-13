//
// Created by dolphilia on 2024/01/13.
//

#include "sk_malloc_pixel_ref.h"

extern "C" {

void SkMallocPixelRef_MakeAllocate(const char *sk_pixel_ref_key_out, const SkImageInfo *imageInfo, size_t rowBytes) {
    static_sk_pixel_ref_set(sk_pixel_ref_key_out, SkMallocPixelRef::MakeAllocate(*imageInfo, rowBytes));
}

void SkMallocPixelRef_MakeWithData(const char *sk_pixel_ref_key_out, const char *sk_data_key_in, const SkImageInfo &imageInfo, size_t rowBytes) {
    static_sk_pixel_ref_set(sk_pixel_ref_key_out, SkMallocPixelRef::MakeWithData(imageInfo, rowBytes, static_sk_data_move(sk_data_key_in)));
}

}