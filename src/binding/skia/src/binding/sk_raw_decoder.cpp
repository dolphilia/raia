//
// Created by dolphilia on 2024/02/02.
//

#include "sk_raw_decoder.h"

extern "C" {

bool SkRawDecoder_IsRaw(const void* ptr, size_t size) {
    return SkRawDecoder::IsRaw(ptr, size);
}

sk_codec_t SkRawDecoder_Decode(int static_stream, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkRawDecoder::Decode(static_sk_stream_move(static_stream), result, decodeContext));
}

sk_codec_t SkRawDecoder_Decode_2(int static_data, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkRawDecoder::Decode(static_sk_data_move(static_data), result, decodeContext));
}

sk_codecs_decoder_t SkRawDecoder_Decoder() {
    return static_sk_codecs_decoder_make(SkRawDecoder::Decoder());
}

}