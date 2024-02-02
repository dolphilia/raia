//
// Created by dolphilia on 2024/02/02.
//

#include "sk_gif_decoder.h"

extern "C" {

bool SkGifDecoder_IsGif(const void* ptr, size_t size) {
    return SkGifDecoder::IsGif(ptr, size);
}

int SkGifDecoder_Decode(int static_sk_stream_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkGifDecoder::Decode(static_sk_stream_move(static_sk_stream_key_in), result, decodeContext));
}

int SkGifDecoder_Decode_2(int static_sk_data_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkGifDecoder::Decode(static_sk_data_move(static_sk_data_key_in), result, decodeContext));
}

int SkGifDecoder_Decoder() {
    return static_sk_codecs_decoder_make(SkGifDecoder::Decoder());
}

}