//
// Created by dolphilia on 2024/02/02.
//

#ifndef RAIA_SKIA_SK_GIF_DECODER_H
#define RAIA_SKIA_SK_GIF_DECODER_H

#include "include/codec/SkGifDecoder.h"
#include "../static/static_sk_stream.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_codec.h"
#include "../static/static_sk_codecs_decoder.h"

extern "C" {
bool SkGifDecoder_IsGif(const void* ptr, size_t size);
int SkGifDecoder_Decode(int static_sk_stream_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext);
int SkGifDecoder_Decode_2(int static_sk_data_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext);
int SkGifDecoder_Decoder();
}

#endif //RAIA_SKIA_SK_GIF_DECODER_H
