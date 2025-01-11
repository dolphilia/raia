//
// Created by dolphilia on 2024/02/01.
//

#ifndef RAIA_SKIA_SK_JPEG_ENCODER_H
#define RAIA_SKIA_SK_JPEG_ENCODER_H

#include "include/encode/SkJpegEncoder.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_encoder.h"

extern "C" {
RAIA_API bool SkJpegEncoder_Encode(SkWStream* dst, const SkPixmap* src, const SkJpegEncoder::Options* options);
RAIA_API bool SkJpegEncoder_Encode_2(SkWStream* dst, const SkYUVAPixmaps* src, const SkColorSpace* srcColorSpace, const SkJpegEncoder::Options* options);
RAIA_API sk_data_t SkJpegEncoder_Encode_3(GrDirectContext* ctx, const SkImage* img, const SkJpegEncoder::Options* options);
RAIA_API sk_encoder_t SkJpegEncoder_Make(SkWStream* dst, const SkPixmap* src, const SkJpegEncoder::Options* options);
RAIA_API sk_encoder_t SkJpegEncoder_Make_2(SkWStream* dst, const SkYUVAPixmaps* src, const SkColorSpace* srcColorSpace, const SkJpegEncoder::Options *options);
}

#endif //RAIA_SKIA_SK_JPEG_ENCODER_H
