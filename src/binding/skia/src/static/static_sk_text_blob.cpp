//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_text_blob.h"

static std::map<std::string, sk_sp<SkTextBlob>> static_sk_text_blob;

void static_sk_text_blob_delete(const char *key) {
    static_sk_text_blob[key].reset();
    static_sk_text_blob.erase(key);
}

SkTextBlob *static_sk_text_blob_get(const char *key) {
    return static_sk_text_blob[key].get();
}

void static_sk_text_blob_set(const char *key, sk_sp<SkTextBlob> value) {
    static_sk_text_blob[key] = std::move(value);
}

sk_sp<SkTextBlob> static_sk_text_blob_move(const char *key) {
    return std::move(static_sk_text_blob[key]);
}