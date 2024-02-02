//
// Created by dolphilia on 2024/02/02.
//

#include "sk_webp_decoder.h"

extern "C" {

bool SkWebpDecoder_IsWbmp(const void* ptr, size_t size) {
    return SkWebpDecoder::IsWebp(ptr, size);
}

int SkWebpDecoder_Decode(int static_sk_stream_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkWebpDecoder::Decode(static_sk_stream_move(static_sk_stream_key_in), result, decodeContext));
}

int SkWebpDecoder_Decode_2(int static_sk_data_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkWebpDecoder::Decode(static_sk_data_move(static_sk_data_key_in), result, decodeContext));
}

int SkWebpDecoder_Decoder() {
    return static_sk_codecs_decoder_make(SkWebpDecoder::Decoder());
}

}
