#ifndef STATIC_SK_TEXT_BLOB_INTERNAL_H
#define STATIC_SK_TEXT_BLOB_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkTextBlob.h"
int static_sk_text_blob_make(sk_sp<SkTextBlob> value);
void static_sk_text_blob_set(int key, sk_sp<SkTextBlob> value);
sk_sp<SkTextBlob> static_sk_text_blob_move(int key);
#endif // STATIC_SK_TEXT_BLOB_INTERNAL_H
