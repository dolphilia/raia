//
// Created by dolphilia on 2024/01/13.
//

#include "static_sk_document.h"

#include <utility>

static std::set<int> static_sk_document_available_keys;
static std::map<int , sk_sp<SkDocument>> static_sk_document;
static int static_sk_document_index = 0;

int static_sk_document_make(sk_sp<SkDocument> value) {
    int key;
    if (!static_sk_document_available_keys.empty()) {
        auto it = static_sk_document_available_keys.begin();
        key = *it;
        static_sk_document_available_keys.erase(it);
    } else {
        key = static_sk_document_index++;
    }
    static_sk_document[key] = std::move(value);
    return key;
}

void static_sk_document_delete(int key) {
    static_sk_document[key].reset();
    static_sk_document.erase(key);
    static_sk_document_available_keys.insert(key);
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