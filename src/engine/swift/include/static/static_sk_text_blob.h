//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_TEXT_BLOB_H
#define RAIA_SKIA_STATIC_SK_TEXT_BLOB_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkTextBlob.h"
#include "export_api.h"

typedef int sk_text_blob_t;

extern "C" {
RAIA_API void static_sk_text_blob_delete(int key);
RAIA_API SkTextBlob *static_sk_text_blob_get(int key);
}

int static_sk_text_blob_make(sk_sp<SkTextBlob> value);
void static_sk_text_blob_set(int key, sk_sp<SkTextBlob> value);
sk_sp<SkTextBlob> static_sk_text_blob_move(int key);

#endif //RAIA_SKIA_STATIC_SK_TEXT_BLOB_H
