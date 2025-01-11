//
// Created by dolphilia on 2024/02/02.
//

#ifndef RAIA_SKIA_STATIC_SK_CODECS_DECODER_H
#define RAIA_SKIA_STATIC_SK_CODECS_DECODER_H

#include <set>
#include <string>
#include <map>
#include "include/codec/SkCodec.h"
#include "export_api.h"

typedef int sk_codecs_decoder_t;

extern "C" {
RAIA_API void static_sk_codecs_decoder_delete(int key);
RAIA_API SkCodecs::Decoder * static_sk_codecs_decoder_get_ptr(int key);
}

int static_sk_codecs_decoder_make(SkCodecs::Decoder value);
SkCodecs::Decoder static_sk_codecs_decoder_get(int key);
void static_sk_codecs_decoder_set(int key, SkCodecs::Decoder value);

#endif //RAIA_SKIA_STATIC_SK_CODECS_DECODER_H
