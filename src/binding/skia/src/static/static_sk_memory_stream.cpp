//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_memory_stream.h"

static std::map<std::string, std::unique_ptr<SkMemoryStream>> static_sk_memory_stream;

void static_sk_memory_stream_delete(const char *key) {
    static_sk_memory_stream[key].reset();
    static_sk_memory_stream.erase(key);
}

SkMemoryStream *static_sk_memory_stream_get(const char *key) {
    return static_sk_memory_stream[key].get();
}

void static_sk_memory_stream_set(const char *key, std::unique_ptr<SkMemoryStream> value) {
    static_sk_memory_stream[key] = std::move(value);
}

std::unique_ptr<SkMemoryStream> static_sk_memory_stream_move(const char *key) {
    return std::move(static_sk_memory_stream[key]);
}