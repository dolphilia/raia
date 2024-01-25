//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_text_blob.h"

#include <utility>

static std::map<int , sk_sp<SkTextBlob>> static_sk_text_blob;
static int static_sk_text_blob_index = 0;

int static_sk_text_blob_make(sk_sp<SkTextBlob> value) {
    static_sk_text_blob[static_sk_text_blob_index] = std::move(value);
    static_sk_text_blob_index++;
    return static_sk_text_blob_index - 1;
}

void static_sk_text_blob_delete(int key) {
    static_sk_text_blob[key].reset();
    static_sk_text_blob.erase(key);
}

SkTextBlob *static_sk_text_blob_get(int key) {
    return static_sk_text_blob[key].get();
}

void static_sk_text_blob_set(int key, sk_sp<SkTextBlob> value) {
    static_sk_text_blob[key] = std::move(value);
}

sk_sp<SkTextBlob> static_sk_text_blob_move(int key) {
    return std::move(static_sk_text_blob[key]);
}