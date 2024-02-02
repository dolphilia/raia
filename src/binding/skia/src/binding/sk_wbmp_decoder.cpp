//
// Created by dolphilia on 2024/02/02.
//

#include "sk_wbmp_decoder.h"

extern "C" {

bool SkWbmpDecoder_IsWbmp(const void* ptr, size_t size) {
    return SkWbmpDecoder::IsWbmp(ptr, size);
}

int SkWbmpDecoder_Decode(int static_sk_stream_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkWbmpDecoder::Decode(static_sk_stream_move(static_sk_stream_key_in), result, decodeContext));
}

int SkWbmpDecoder_Decode_2(int static_sk_data_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkWbmpDecoder::Decode(static_sk_data_move(static_sk_data_key_in), result, decodeContext));
}

int SkWbmpDecoder_Decoder() {
    return static_sk_codecs_decoder_make(SkWbmpDecoder::Decoder());
}

}
