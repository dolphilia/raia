//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_stream_memory.h"

static std::map<std::string, std::unique_ptr<SkStreamMemory>> static_sk_stream_memory;

void static_sk_stream_memory_delete(const char *key) {
    static_sk_stream_memory[key].reset();
    static_sk_stream_memory.erase(key);
}

SkStreamMemory *static_sk_stream_memory_get(const char *key) {
    return static_sk_stream_memory[key].get();
}

void static_sk_stream_memory_set(const char *key, std::unique_ptr<SkStreamMemory> value) {
    static_sk_stream_memory[key] = std::move(value);
}

std::unique_ptr<SkStreamMemory> static_sk_stream_memory_move(const char *key) {
    return std::move(static_sk_stream_memory[key]);
}