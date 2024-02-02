//
// Created by dolphilia on 2024/02/02.
//

#include "sk_raw_decoder.h"

extern "C" {

bool SkRawDecoder_IsRaw(const void* ptr, size_t size) {
    return SkRawDecoder::IsRaw(ptr, size);
}

int SkRawDecoder_Decode(int static_sk_stream_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkRawDecoder::Decode(static_sk_stream_move(static_sk_stream_key_in), result, decodeContext));
}

int SkRawDecoder_Decode_2(int static_sk_data_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkRawDecoder::Decode(static_sk_data_move(static_sk_data_key_in), result, decodeContext));
}

int SkRawDecoder_Decoder() {
    return static_sk_codecs_decoder_make(SkRawDecoder::Decoder());
}

}