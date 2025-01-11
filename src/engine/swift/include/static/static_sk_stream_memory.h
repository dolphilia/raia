//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_STREAM_MEMORY_H
#define RAIA_SKIA_STATIC_SK_STREAM_MEMORY_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkStream.h"
#include "export_api.h"

typedef int sk_stream_memory_t;

extern "C" {
RAIA_API void static_sk_stream_memory_delete(int key);
RAIA_API SkStreamMemory *static_sk_stream_memory_get(int key);
}

int static_sk_stream_memory_make(std::unique_ptr<SkStreamMemory> value);
void static_sk_stream_memory_set(int key, std::unique_ptr<SkStreamMemory> value);
std::unique_ptr<SkStreamMemory> static_sk_stream_memory_move(int key);

#endif //RAIA_SKIA_STATIC_SK_STREAM_MEMORY_H
