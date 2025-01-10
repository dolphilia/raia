//
// Created by dolphilia on 2024/02/01.
//

#ifndef RAIA_SKIA_SK_PNG_ENCODER_H
#define RAIA_SKIA_SK_PNG_ENCODER_H

#include "include/encode/SkPngEncoder.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_encoder.h"

extern "C" {
bool SkPngEncoder_Encode(SkWStream* dst, const SkPixmap* src, const SkPngEncoder::Options* options);
sk_data_t SkPngEncoder_Encode_2(GrDirectContext* ctx, const SkImage* img, const SkPngEncoder::Options* options);
sk_encoder_t SkPngEncoder_Make(SkWStream* dst, const SkPixmap* src, const SkPngEncoder::Options* options);
}

#endif //RAIA_SKIA_SK_PNG_ENCODER_H
