//
// Created by dolphilia on 2024/02/02.
//

#include "sk_gif_decoder.h"

extern "C" {

bool SkGifDecoder_IsGif(const void* ptr, size_t size) {
    return SkGifDecoder::IsGif(ptr, size);
}

sk_codec_t SkGifDecoder_Decode(int static_stream, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkGifDecoder::Decode(static_sk_stream_move(static_stream), result, decodeContext));
}

sk_codec_t SkGifDecoder_Decode_2(int static_data, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkGifDecoder::Decode(static_sk_data_move(static_data), result, decodeContext));
}

sk_codecs_decoder_t SkGifDecoder_Decoder() {
    return static_sk_codecs_decoder_make(SkGifDecoder::Decoder());
}

}