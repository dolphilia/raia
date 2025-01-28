//
// Created by dolphilia on 2024/04/03.
//

#ifndef RAIA_SKIA_STATIC_SK_CUBIC_RESAMPLER_H
#define RAIA_SKIA_STATIC_SK_CUBIC_RESAMPLER_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_cubic_resampler_t;
void static_sk_cubic_resampler_delete(int key);
void * static_sk_cubic_resampler_get_ptr(int key); // -> SkCubicResampler *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_CUBIC_RESAMPLER_H
