//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_STATIC_SK_DOCUMENT_H
#define RAIA_SKIA_STATIC_SK_DOCUMENT_H

#include <string>
#include <map>
#include "include/docs/SkPDFDocument.h"

void static_sk_document_delete(const char *key);
SkDocument *static_sk_document_get(const char *key);
void static_sk_document_set(const char *key, sk_sp<SkDocument> value);
sk_sp<SkDocument> static_sk_document_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_DOCUMENT_H
