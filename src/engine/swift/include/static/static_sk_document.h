//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_STATIC_SK_DOCUMENT_H
#define RAIA_SKIA_STATIC_SK_DOCUMENT_H

#include <set>
#include <string>
#include <map>
#include "include/docs/SkPDFDocument.h"

typedef int sk_document_t;

int static_sk_document_make(sk_sp<SkDocument> value);
extern "C" void static_sk_document_delete(int key);
extern "C" SkDocument *static_sk_document_get(int key);
void static_sk_document_set(int key, sk_sp<SkDocument> value);
sk_sp<SkDocument> static_sk_document_move(int key);

#endif //RAIA_SKIA_STATIC_SK_DOCUMENT_H
