//
// Created by dolphilia on 2024/02/02.
//

#ifndef RAIA_SKIA_STATIC_SK_CODEC_H
#define RAIA_SKIA_STATIC_SK_CODEC_H

#ifdef __cplusplus
extern "C" {
#endif

typedef int sk_codec_t;

void static_sk_codec_delete(int key);
void *static_sk_codec_get(int key); // -> SkCodec *

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_CODEC_H
