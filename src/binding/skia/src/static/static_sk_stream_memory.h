//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_STREAM_MEMORY_H
#define RAIA_SKIA_STATIC_SK_STREAM_MEMORY_H

#include <string>
#include <map>
#include "include/core/SkStream.h"

void static_sk_stream_memory_delete(const char *key);
SkStreamMemory *static_sk_stream_memory_get(const char *key);
void static_sk_stream_memory_set(const char *key, std::unique_ptr<SkStreamMemory> value);
std::unique_ptr<SkStreamMemory> static_sk_stream_memory_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_STREAM_MEMORY_H
