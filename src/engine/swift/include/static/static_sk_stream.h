//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_STREAM_H
#define RAIA_SKIA_STATIC_SK_STREAM_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_stream_t;
typedef int sk_stream_ptr_t;
void static_sk_stream_delete(int key);
void *static_sk_stream_get(int key); // -> SkStream *
void static_sk_stream_ptr_delete(int key);
void* static_sk_stream_ptr_get(int key);
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_STREAM_H
