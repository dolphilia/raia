//
// Created by dolphilia on 2024/02/02.
//

#include "sk_ico_cecoder.h"

extern "C" {

bool SkIcoDecoder_IsIco(const void* ptr, size_t size) {
    return SkIcoDecoder::IsIco(ptr, size);
}

sk_codec_t SkIcoDecoder_Decode(int static_stream, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkIcoDecoder::Decode(static_sk_stream_move(static_stream), result, decodeContext));
}

sk_codec_t SkIcoDecoder_Decode_2(int static_data, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkIcoDecoder::Decode(static_sk_data_move(static_data), result, decodeContext));
}

sk_codecs_decoder_t SkIcoDecoder_Decoder() {
    return static_sk_codecs_decoder_make(SkIcoDecoder::Decoder());
}

}
