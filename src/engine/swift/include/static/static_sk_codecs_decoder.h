//
// Created by dolphilia on 2024/02/02.
//

#ifndef RAIA_SKIA_STATIC_SK_CODECS_DECODER_H
#define RAIA_SKIA_STATIC_SK_CODECS_DECODER_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_codecs_decoder_t;
void static_sk_codecs_decoder_delete(int key);
void * static_sk_codecs_decoder_get_ptr(int key); // -> SkCodecs::Decoder *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_CODECS_DECODER_H
