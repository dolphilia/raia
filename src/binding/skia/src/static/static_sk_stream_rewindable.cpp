//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_stream_rewindable.h"

static std::map<int , std::unique_ptr<SkStreamRewindable>> static_sk_stream_rewindable;
static int static_sk_stream_rewindable_index = 0;

int static_sk_stream_rewindable_make(std::unique_ptr<SkStreamRewindable> value) {
    static_sk_stream_rewindable[static_sk_stream_rewindable_index] = std::move(value);
    static_sk_stream_rewindable_index++;
    return static_sk_stream_rewindable_index - 1;
}

void static_sk_stream_rewindable_delete(int key) {
    static_sk_stream_rewindable[key].reset();
    static_sk_stream_rewindable.erase(key);
}

SkStreamRewindable *static_sk_stream_rewindable_get(int key) {
    return static_sk_stream_rewindable[key].get();
}

void static_sk_stream_rewindable_set(int key, std::unique_ptr<SkStreamRewindable> value) {
    static_sk_stream_rewindable[key] = std::move(value);
}

std::unique_ptr<SkStreamRewindable> static_sk_stream_rewindable_move(int key) {
    return std::move(static_sk_stream_rewindable[key]);
}