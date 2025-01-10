//
// Created by dolphilia on 2024/02/01.
//

#ifndef RAIA_SKIA_SK_WEBP_ENCODER_H
#define RAIA_SKIA_SK_WEBP_ENCODER_H

#include "include/encode/SkWebpEncoder.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_encoder_frame.h"

extern "C" {
bool SkWebpEncoder_Encode(SkWStream* dst, const SkPixmap* src, const SkWebpEncoder::Options* options);
sk_data_t SkWebpEncoder_Encode_2(GrDirectContext* ctx, const SkImage* img, const SkWebpEncoder::Options* options);
bool SkWebpEncoder_EncodeAnimated(SkWStream* dst, const_sk_encoder_frame_t encoderFrame, const SkWebpEncoder::Options* options);
}

#endif //RAIA_SKIA_SK_WEBP_ENCODER_H
