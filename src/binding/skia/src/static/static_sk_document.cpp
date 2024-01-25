//
// Created by dolphilia on 2024/01/13.
//

#include "static_sk_document.h"

static std::map<int , sk_sp<SkDocument>> static_sk_document;

void static_sk_document_delete(int key) {
    static_sk_document[key].reset();
    static_sk_document.erase(key);
}

SkDocument *static_sk_document_get(int key) {
    return static_sk_document[key].get();
}

void static_sk_document_set(int key, sk_sp<SkDocument> value) {
    static_sk_document[key] = std::move(value);
}

sk_sp<SkDocument> static_sk_document_move(int key) {
    return std::move(static_sk_document[key]);
}