#ifndef STATIC_SK_DOCUMENT_INTERNAL_H
#define STATIC_SK_DOCUMENT_INTERNAL_H
#include <set>
#include <map>
#include "include/docs/SkPDFDocument.h"
int static_sk_document_make(sk_sp<SkDocument> value);
void static_sk_document_set(int key, sk_sp<SkDocument> value);
sk_sp<SkDocument> static_sk_document_move(int key);
#endif // STATIC_SK_DOCUMENT_INTERNAL_H
