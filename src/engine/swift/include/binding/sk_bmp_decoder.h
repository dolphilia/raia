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
#include "export_api.h"

extern "C" {
RAIA_API bool SkBmpDecoder_IsBmp(const void* ptr, size_t size);
RAIA_API sk_codec_t SkBmpDecoder_Decode(sk_stream_t stream, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext);
RAIA_API sk_codec_t SkBmpDecoder_Decode_2(sk_stream_t stream, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext);
RAIA_API sk_codecs_decoder_t SkBmpDecoder_Decoder();
}

#endif //RAIA_SKIA_SK_BMP_DECODER_H_H
