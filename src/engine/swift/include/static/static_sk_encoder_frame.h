//
// Created by dolphilia on 2024/02/01.
//

#ifndef RAIA_SKIA_STATIC_SK_ENCODER_FRAME_H
#define RAIA_SKIA_STATIC_SK_ENCODER_FRAME_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int const_sk_encoder_frame_t;
void static_const_sk_encoder_frame_delete(int key);
const void * static_const_sk_encoder_frame_get_ptr(int key, int index); // -> const SkEncoder::Frame *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_ENCODER_FRAME_H
