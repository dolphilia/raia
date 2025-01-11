//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_STATIC_SK_DOCUMENT_H
#define RAIA_SKIA_STATIC_SK_DOCUMENT_H

#include <set>
#include <string>
#include <map>
#include "include/docs/SkPDFDocument.h"
#include "export_api.h"

typedef int sk_document_t;

extern "C" {
RAIA_API void static_sk_document_delete(int key);
RAIA_API SkDocument *static_sk_document_get(int key);
}

int static_sk_document_make(sk_sp<SkDocument> value);
void static_sk_document_set(int key, sk_sp<SkDocument> value);
sk_sp<SkDocument> static_sk_document_move(int key);

#endif //RAIA_SKIA_STATIC_SK_DOCUMENT_H
