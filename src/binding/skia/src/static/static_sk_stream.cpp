//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_stream.h"

static std::set<int> static_sk_stream_available_keys;
static std::map<int , std::unique_ptr<SkStream>> static_sk_stream;
static int static_sk_stream_index = 0;

int static_sk_stream_make(std::unique_ptr<SkStream> value) {
    int key;
    if (!static_sk_stream_available_keys.empty()) {
        auto it = static_sk_stream_available_keys.begin();
        key = *it;
        static_sk_stream_available_keys.erase(it);
    } else {
        key = static_sk_stream_index++;
    }
    static_sk_stream[key] = std::move(value);
    return key;
}

void static_sk_stream_delete(int key) {
    static_sk_stream[key].reset();
    static_sk_stream.erase(key);
    static_sk_stream_available_keys.insert(key);
}

SkStream *static_sk_stream_get(int key) {
    return static_sk_stream[key].get();
}

void static_sk_stream_set(int key, std::unique_ptr<SkStream> value) {
    static_sk_stream[key] = std::move(value);
}

std::unique_ptr<SkStream> static_sk_stream_move(int key) {
    return std::move(static_sk_stream[key]);
}