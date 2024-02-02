//
// Created by dolphilia on 2024/02/02.
//

#include "sk_ico_cecoder.h"

extern "C" {

bool SkIcoDecoder_IsIco(const void* ptr, size_t size) {
    return SkIcoDecoder::IsIco(ptr, size);
}

int SkIcoDecoder_Decode(int static_sk_stream_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkIcoDecoder::Decode(static_sk_stream_move(static_sk_stream_key_in), result, decodeContext));
}

int SkIcoDecoder_Decode_2(int static_sk_data_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkIcoDecoder::Decode(static_sk_data_move(static_sk_data_key_in), result, decodeContext));
}

int SkIcoDecoder_Decoder() {
    return static_sk_codecs_decoder_make(SkIcoDecoder::Decoder());
}

}
