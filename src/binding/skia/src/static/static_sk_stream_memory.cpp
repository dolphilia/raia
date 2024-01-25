//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_stream_memory.h"

static std::map<int , std::unique_ptr<SkStreamMemory>> static_sk_stream_memory;

void static_sk_stream_memory_delete(int key) {
    static_sk_stream_memory[key].reset();
    static_sk_stream_memory.erase(key);
}

SkStreamMemory *static_sk_stream_memory_get(int key) {
    return static_sk_stream_memory[key].get();
}

void static_sk_stream_memory_set(int key, std::unique_ptr<SkStreamMemory> value) {
    static_sk_stream_memory[key] = std::move(value);
}

std::unique_ptr<SkStreamMemory> static_sk_stream_memory_move(int key) {
    return std::move(static_sk_stream_memory[key]);
}