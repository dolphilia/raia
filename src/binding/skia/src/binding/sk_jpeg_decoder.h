//
// Created by dolphilia on 2024/02/02.
//

#ifndef RAIA_SKIA_SK_JPEG_DECODER_H
#define RAIA_SKIA_SK_JPEG_DECODER_H

#include "include/codec/SkJpegDecoder.h"
#include "../static/static_sk_stream.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_codec.h"
#include "../static/static_sk_codecs_decoder.h"

extern "C" {
bool SkJpegDecoder_IsJpeg(const void* ptr, size_t size);
int SkJpegDecoder_Decode(int static_sk_stream_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext);
int SkJpegDecoder_Decode_2(int static_sk_data_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext);
int SkJpegDecoder_Decoder();
}

#endif //RAIA_SKIA_SK_JPEG_DECODER_H
