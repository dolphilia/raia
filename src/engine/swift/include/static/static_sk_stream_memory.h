//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_STREAM_MEMORY_H
#define RAIA_SKIA_STATIC_SK_STREAM_MEMORY_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_stream_memory_t;
void static_sk_stream_memory_delete(int key);
void *static_sk_stream_memory_get(int key); // -> SkStreamMemory *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_STREAM_MEMORY_H
