//
// Created by dolphilia on 2024/02/02.
//

#include "sk_jpeg_decoder.h"

extern "C" {

bool SkJpegDecoder_IsJpeg(const void* ptr, size_t size) {
    return SkJpegDecoder::IsJpeg(ptr, size);
}

sk_codec_t SkJpegDecoder_Decode(int static_stream, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkJpegDecoder::Decode(static_sk_stream_move(static_stream), result, decodeContext));
}

sk_codec_t SkJpegDecoder_Decode_2(int static_data, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) {
    return static_sk_codec_make(SkJpegDecoder::Decode(static_sk_data_move(static_data), result, decodeContext));
}

sk_codecs_decoder_t SkJpegDecoder_Decoder() {
    return static_sk_codecs_decoder_make(SkJpegDecoder::Decoder());
}

}
