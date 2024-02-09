//
// Created by dolphilia on 2024/02/01.
//

#include "sk_webp_encoder.h"

extern "C" {

bool SkWebpEncoder_Encode(SkWStream* dst, const SkPixmap* src, const SkWebpEncoder::Options* options) {
    return SkWebpEncoder::Encode(dst, *src, *options);
}

sk_data_t SkWebpEncoder_Encode_2(GrDirectContext* ctx, const SkImage* img, const SkWebpEncoder::Options* options) {
    return static_sk_data_make(SkWebpEncoder::Encode(ctx, img, *options));
}

bool SkWebpEncoder_EncodeAnimated(SkWStream* dst, const_sk_encoder_frame_t encoderFrame, const SkWebpEncoder::Options* options) {
    return SkWebpEncoder::EncodeAnimated(dst, static_const_sk_encoder_frame_get(encoderFrame), *options);
}

}