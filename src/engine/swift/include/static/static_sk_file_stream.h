//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_FILE_STREAM_H
#define RAIA_SKIA_STATIC_SK_FILE_STREAM_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_file_stream_t;
void static_sk_file_stream_delete(int key);
void *static_sk_file_stream_get_ptr(int key); // -> SkFILEStream *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_FILE_STREAM_H
