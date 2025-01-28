//
// Created by dolphilia on 2024/02/02.
//

#ifndef RAIA_SKIA_SK_WBMP_DECODER_H
#define RAIA_SKIA_SK_WBMP_DECODER_H

#ifdef __cplusplus
extern "C" {
#endif

bool SkWbmpDecoder_IsWbmp(const void* ptr, unsigned long size); // (const void* ptr, size_t size) -> bool
int SkWbmpDecoder_Decode(int static_stream, void * result, void * decodeContext); // (int static_stream, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) -> sk_codec_t
int SkWbmpDecoder_Decode_2(int static_data, void * result, void * decodeContext); // (int static_data, SkCodec::Result* result, SkCodecs::DecodeContext decodeContext) -> sk_codec_t
int SkWbmpDecoder_Decoder(); // () -> sk_codecs_decoder_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_WBMP_DECODER_H
