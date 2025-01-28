//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_TEXT_BLOB_H
#define RAIA_SKIA_STATIC_SK_TEXT_BLOB_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_text_blob_t;
void static_sk_text_blob_delete(int key);
void * static_sk_text_blob_get(int key); // -> SkTextBlob *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_TEXT_BLOB_H
