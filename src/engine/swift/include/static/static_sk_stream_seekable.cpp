//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_stream_seekable.h"
#include "static_sk_stream_seekable-internal.h"

static std::set<int> static_sk_stream_seekable_available_keys;
static std::map<int , std::unique_ptr<SkStreamSeekable>> static_sk_stream_seekable;
static int static_sk_stream_seekable_index = 0;

int static_sk_stream_seekable_make(std::unique_ptr<SkStreamSeekable> value) {
    int key;
    if (!static_sk_stream_seekable_available_keys.empty()) {
        auto it = static_sk_stream_seekable_available_keys.begin();
        key = *it;
        static_sk_stream_seekable_available_keys.erase(it);
    } else {
        key = static_sk_stream_seekable_index++;
    }
    static_sk_stream_seekable[key] = std::move(value);
    return key;
}

void static_sk_stream_seekable_delete(int key) {
    static_sk_stream_seekable[key].reset();
    static_sk_stream_seekable.erase(key);
    static_sk_stream_seekable_available_keys.insert(key);
}

void *static_sk_stream_seekable_get(int key) { // -> SkStreamSeekable *
    return static_sk_stream_seekable[key].get();
}

void static_sk_stream_seekable_set(int key, std::unique_ptr<SkStreamSeekable> value) {
    static_sk_stream_seekable[key] = std::move(value);
}

std::unique_ptr<SkStreamSeekable> static_sk_stream_seekable_move(int key) {
    return std::move(static_sk_stream_seekable[key]);
}
