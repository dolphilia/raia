//
// Created by dolphilia on 2024/02/02.
//

#ifndef RAIA_SKIA_SK_BMP_DECODER_H_H
#define RAIA_SKIA_SK_BMP_DECODER_H_H

#ifdef __cplusplus
extern "C" {
#endif

bool SkBmpDecoder_IsBmp(const void* ptr, unsigned long size); // (const void* ptr, size_t size) -> bool
int SkBmpDecoder_Decode(int stream, void * result, void * decodeContext); // (sk_stream_t stream, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) -> sk_codec_t
int SkBmpDecoder_Decode_2(int stream, void * result, void * decodeContext); // (sk_stream_t stream, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) -> sk_codec_t
int SkBmpDecoder_Decoder(); // () -> sk_codecs_decoder_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_BMP_DECODER_H_H
