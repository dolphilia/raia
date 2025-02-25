//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_STREAM_REWINDABLE_H
#define RAIA_SKIA_STATIC_SK_STREAM_REWINDABLE_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_stream_rewindable_t;
void static_sk_stream_rewindable_delete(int key);
void *static_sk_stream_rewindable_get_ptr(int key); // -> SkStreamRewindable *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_STREAM_REWINDABLE_H
