//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_STREAM_SEEKABLE_H
#define RAIA_SKIA_STATIC_SK_STREAM_SEEKABLE_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkStream.h"
#include "export_api.h"

typedef int sk_stream_seekable_t;

extern "C" {
RAIA_API void static_sk_stream_seekable_delete(int key);
RAIA_API SkStreamSeekable *static_sk_stream_seekable_get(int key);
}

int static_sk_stream_seekable_make(std::unique_ptr<SkStreamSeekable> value);
void static_sk_stream_seekable_set(int key, std::unique_ptr<SkStreamSeekable> value);
std::unique_ptr<SkStreamSeekable> static_sk_stream_seekable_move(int key);

#endif //RAIA_SKIA_STATIC_SK_STREAM_SEEKABLE_H
