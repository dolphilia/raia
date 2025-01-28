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
bool SkGifDecoder_IsGif(const void* ptr, size_t size); // (const void* ptr, size_t size) -> bool
sk_codec_t SkGifDecoder_Decode(int static_stream, void * result, SkCodecs::DecodeContext decodeContext); // (int static_stream, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) -> sk_codec_t
sk_codec_t SkGifDecoder_Decode_2(int static_data, void * result, SkCodecs::DecodeContext decodeContext); // (int static_data, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) -> sk_codec_t
sk_codecs_decoder_t SkGifDecoder_Decoder(); // () -> sk_codecs_decoder_t
}

#endif //RAIA_SKIA_SK_GIF_DECODER_H
