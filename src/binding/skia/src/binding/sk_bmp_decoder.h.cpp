//
// Created by dolphilia on 2024/02/02.
//

#include "sk_bmp_decoder.h.h"

extern "C" {

// static

bool SkBmpDecoder_IsBmp(const void* ptr, size_t size) {
    return SkBmpDecoder::IsBmp(ptr, size);
}

sk_codec_t SkBmpDecoder_Decode(sk_stream_t stream, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkBmpDecoder::Decode(static_sk_stream_move(stream), result, decodeContext));
}

sk_codec_t SkBmpDecoder_Decode_2(sk_stream_t stream, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkBmpDecoder::Decode(static_sk_data_move(stream), result, decodeContext));
}

sk_codecs_decoder_t SkBmpDecoder_Decoder() {
    return static_sk_codecs_decoder_make(SkBmpDecoder::Decoder());
}

}
