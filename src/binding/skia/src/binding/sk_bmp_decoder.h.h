//
// Created by dolphilia on 2024/02/02.
//

#ifndef RAIA_SKIA_SK_BMP_DECODER_H_H
#define RAIA_SKIA_SK_BMP_DECODER_H_H

#include "include/codec/SkBmpDecoder.h"
#include "../static/static_sk_codec.h"
#include "../static/static_sk_stream.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_codecs_decoder.h"

extern "C" {
bool SkBmpDecoder_IsBmp(const void* ptr, size_t size);
int SkBmpDecoder_Decode(int static_sk_stream_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext);
int SkBmpDecoder_Decode_2(int static_sk_data_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext);
int SkBmpDecoder_Decoder();
}

#endif //RAIA_SKIA_SK_BMP_DECODER_H_H
