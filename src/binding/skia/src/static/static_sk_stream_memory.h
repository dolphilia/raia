//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_STREAM_MEMORY_H
#define RAIA_SKIA_STATIC_SK_STREAM_MEMORY_H

#include <string>
#include <map>
#include "include/core/SkStream.h"

void static_sk_stream_memory_delete(int key);
SkStreamMemory *static_sk_stream_memory_get(int key);
void static_sk_stream_memory_set(int key, std::unique_ptr<SkStreamMemory> value);
std::unique_ptr<SkStreamMemory> static_sk_stream_memory_move(int key);

#endif //RAIA_SKIA_STATIC_SK_STREAM_MEMORY_H
