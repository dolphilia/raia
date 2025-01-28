//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_SAMPLING_OPTIONS_H
#define RAIA_SKIA_STATIC_SK_SAMPLING_OPTIONS_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_sampling_options_t;
void static_sk_sampling_options_delete(int key);
void * static_sk_sampling_options_get_ptr(int key); // -> SkSamplingOptions *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_SAMPLING_OPTIONS_H
