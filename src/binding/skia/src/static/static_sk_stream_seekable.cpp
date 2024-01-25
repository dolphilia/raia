//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_stream_seekable.h"

static std::map<int , std::unique_ptr<SkStreamSeekable>> static_sk_stream_seekable;

void static_sk_stream_seekable_delete(int key) {
    static_sk_stream_seekable[key].reset();
    static_sk_stream_seekable.erase(key);
}

SkStreamSeekable *static_sk_stream_seekable_get(int key) {
    return static_sk_stream_seekable[key].get();
}

void static_sk_stream_seekable_set(int key, std::unique_ptr<SkStreamSeekable> value) {
    static_sk_stream_seekable[key] = std::move(value);
}

std::unique_ptr<SkStreamSeekable> static_sk_stream_seekable_move(int key) {
    return std::move(static_sk_stream_seekable[key]);
}