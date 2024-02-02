//
// Created by dolphilia on 2024/02/02.
//

#include "sk_bmp_decoder.h.h"

extern "C" {

bool SkBmpDecoder_IsBmp(const void* ptr, size_t size) {
    return SkBmpDecoder::IsBmp(ptr, size);
}

int SkBmpDecoder_Decode(int static_sk_stream_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkBmpDecoder::Decode(static_sk_stream_move(static_sk_stream_key_in), result, decodeContext));
}

int SkBmpDecoder_Decode_2(int static_sk_data_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkBmpDecoder::Decode(static_sk_data_move(static_sk_data_key_in), result, decodeContext));
}

int SkBmpDecoder_Decoder() {
    return static_sk_codecs_decoder_make(SkBmpDecoder::Decoder());
}

}
