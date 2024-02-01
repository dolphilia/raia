//
// Created by dolphilia on 2024/02/01.
//

#include "sk_jpeg_encoder.h"

extern "C" {

bool SkJpegEncoder_Encode(SkWStream* dst, const SkPixmap* src, const SkJpegEncoder::Options* options) {
    return SkJpegEncoder::Encode(dst, *src, *options);
}

bool SkJpegEncoder_Encode_2(SkWStream* dst, const SkYUVAPixmaps* src, const SkColorSpace* srcColorSpace, const SkJpegEncoder::Options* options) {
    return SkJpegEncoder::Encode(dst, *src, srcColorSpace, *options);
}

int SkJpegEncoder_Encode_3(GrDirectContext* ctx, const SkImage* img, const SkJpegEncoder::Options* options) {
    return static_sk_data_make(SkJpegEncoder::Encode(ctx, img, *options));
}

int SkJpegEncoder_Make(SkWStream* dst, const SkPixmap* src, const SkJpegEncoder::Options* options) {
    return static_sk_encoder_make(SkJpegEncoder::Make(dst, *src, *options));
}

int SkJpegEncoder_Make_2(SkWStream* dst, const SkYUVAPixmaps* src, const SkColorSpace* srcColorSpace, const SkJpegEncoder::Options *options) {
    return static_sk_encoder_make(SkJpegEncoder::Make(dst, *src, srcColorSpace, *options));
}

}