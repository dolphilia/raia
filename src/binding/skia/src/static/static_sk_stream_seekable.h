//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_STREAM_SEEKABLE_H
#define RAIA_SKIA_STATIC_SK_STREAM_SEEKABLE_H

#include <string>
#include <map>
#include "include/core/SkStream.h"

void static_sk_stream_seekable_delete(const char *key);
SkStreamSeekable *static_sk_stream_seekable_get(const char *key);
void static_sk_stream_seekable_set(const char *key, std::unique_ptr<SkStreamSeekable> value);
std::unique_ptr<SkStreamSeekable> static_sk_stream_seekable_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_STREAM_SEEKABLE_H
