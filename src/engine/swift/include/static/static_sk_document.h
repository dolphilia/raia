//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_STATIC_SK_DOCUMENT_H
#define RAIA_SKIA_STATIC_SK_DOCUMENT_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_document_t;
void static_sk_document_delete(int key);
void *static_sk_document_get(int key); // -> SkDocument *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_DOCUMENT_H
