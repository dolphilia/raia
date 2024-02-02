//
// Created by dolphilia on 2024/02/02.
//

#include "sk_png_decoder.h"

extern "C" {

bool SkPngDecoder_IsPng(const void* ptr, size_t size) {
    return SkPngDecoder::IsPng(ptr, size);
}

int SkPngDecoder_Decode(int static_sk_stream_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkPngDecoder::Decode(static_sk_stream_move(static_sk_stream_key_in), result, decodeContext));
}

int SkPngDecoder_Decode_2(int static_sk_data_key_in, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkPngDecoder::Decode(static_sk_data_move(static_sk_data_key_in), result, decodeContext));
}

int SkPngDecoder_Decoder() {
    return static_sk_codecs_decoder_make(SkPngDecoder::Decoder());
}

}