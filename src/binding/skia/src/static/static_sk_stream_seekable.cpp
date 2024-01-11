//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_stream_seekable.h"

static std::map<std::string, std::unique_ptr<SkStreamSeekable>> static_sk_stream_seekable;

void static_sk_stream_seekable_delete(const char *key) {
    static_sk_stream_seekable[key].reset();
    static_sk_stream_seekable.erase(key);
}

SkStreamSeekable *static_sk_stream_seekable_get(const char *key) {
    return static_sk_stream_seekable[key].get();
}

void static_sk_stream_seekable_set(const char *key, std::unique_ptr<SkStreamSeekable> value) {
    static_sk_stream_seekable[key] = std::move(value);
}

std::unique_ptr<SkStreamSeekable> static_sk_stream_seekable_move(const char *key) {
    return std::move(static_sk_stream_seekable[key]);
}