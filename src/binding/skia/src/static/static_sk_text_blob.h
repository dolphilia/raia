//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_TEXT_BLOB_H
#define RAIA_SKIA_STATIC_SK_TEXT_BLOB_H

#include <string>
#include <map>
#include "include/core/SkTextBlob.h"

void static_sk_text_blob_delete(const char *key);
SkTextBlob *static_sk_text_blob_get(const char *key);
void static_sk_text_blob_set(const char *key, sk_sp<SkTextBlob> value);
sk_sp<SkTextBlob> static_sk_text_blob_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_TEXT_BLOB_H