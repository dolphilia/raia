//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_STREAM_SEEKABLE_H
#define RAIA_SKIA_STATIC_SK_STREAM_SEEKABLE_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_stream_seekable_t;
void static_sk_stream_seekable_delete(int key);
void *static_sk_stream_seekable_get(int key); // -> SkStreamSeekable *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_STREAM_SEEKABLE_H
