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
RAIA_API bool SkGifDecoder_IsGif(const void* ptr, size_t size);
RAIA_API sk_codec_t SkGifDecoder_Decode(int static_stream, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext);
RAIA_API sk_codec_t SkGifDecoder_Decode_2(int static_data, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext);
RAIA_API sk_codecs_decoder_t SkGifDecoder_Decoder();
}

#endif //RAIA_SKIA_SK_GIF_DECODER_H
