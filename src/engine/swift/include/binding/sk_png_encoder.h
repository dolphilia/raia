//
// Created by dolphilia on 2024/02/01.
//

#ifndef RAIA_SKIA_SK_PNG_ENCODER_H
#define RAIA_SKIA_SK_PNG_ENCODER_H

#ifdef __cplusplus
extern "C" {
#endif

bool SkPngEncoder_Encode(void* dst, const void* src, const void* options); // (SkWStream* dst, const SkPixmap* src, const SkPngEncoder::Options* options) -> bool
int SkPngEncoder_Encode_2(void* ctx, const void* img, const void* options); // (GrDirectContext* ctx, const SkImage* img, const SkPngEncoder::Options* options) -> sk_data_t
int SkPngEncoder_Make(void* dst, const void* src, const void* options); // (SkWStream* dst, const SkPixmap* src, const SkPngEncoder::Options* options) -> sk_encoder_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_PNG_ENCODER_H
