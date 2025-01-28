//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_MEMORY_STREAM_H
#define RAIA_SKIA_STATIC_SK_MEMORY_STREAM_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_memory_stream_t;
void static_sk_memory_stream_delete(int key);
void *static_sk_memory_stream_get(int key); // -> SkMemoryStream *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_MEMORY_STREAM_H
