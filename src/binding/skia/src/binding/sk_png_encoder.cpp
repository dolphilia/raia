//
// Created by dolphilia on 2024/02/01.
//

#include "sk_png_encoder.h"

extern "C" {

bool SkPngEncoder_Encode(SkWStream* dst, const SkPixmap* src, const SkPngEncoder::Options* options) {
    return SkPngEncoder::Encode(dst, *src, *options);
}

sk_data_t SkPngEncoder_Encode_2(GrDirectContext* ctx, const SkImage* img, const SkPngEncoder::Options* options) {
    return static_sk_data_make(SkPngEncoder::Encode(ctx, img, *options));
}

sk_encoder_t SkPngEncoder_Make(SkWStream* dst, const SkPixmap* src, const SkPngEncoder::Options* options) {
    return static_sk_encoder_make(SkPngEncoder::Make(dst, *src, *options));
}

}