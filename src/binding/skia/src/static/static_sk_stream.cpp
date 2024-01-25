//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_stream.h"

static std::map<int , std::unique_ptr<SkStream>> static_sk_stream;

void static_sk_stream_delete(int key) {
    static_sk_stream[key].reset();
    static_sk_stream.erase(key);
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