//
// Created by dolphilia on 2024/02/01.
//

#ifndef RAIA_SKIA_STATIC_SK_ENCODER_H
#define RAIA_SKIA_STATIC_SK_ENCODER_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_encoder_t;
void static_sk_encoder_delete(int key);
void *static_sk_encoder_get(int key); // -> SkEncoder *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_ENCODER_H
