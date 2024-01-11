//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_MEMORY_STREAM_H
#define RAIA_SKIA_STATIC_SK_MEMORY_STREAM_H

#include <string>
#include <map>
#include "include/core/SkStream.h"

void static_sk_memory_stream_delete(const char *key);
SkMemoryStream *static_sk_memory_stream_get(const char *key);
void static_sk_memory_stream_set(const char *key, std::unique_ptr<SkMemoryStream> value);
std::unique_ptr<SkMemoryStream> static_sk_memory_stream_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_MEMORY_STREAM_H
