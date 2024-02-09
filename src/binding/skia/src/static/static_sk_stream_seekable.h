//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_STREAM_SEEKABLE_H
#define RAIA_SKIA_STATIC_SK_STREAM_SEEKABLE_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkStream.h"

typedef int sk_stream_seekable_t;

int static_sk_stream_seekable_make(std::unique_ptr<SkStreamSeekable> value);
extern "C" void static_sk_stream_seekable_delete(int key);
extern "C" SkStreamSeekable *static_sk_stream_seekable_get(int key);
void static_sk_stream_seekable_set(int key, std::unique_ptr<SkStreamSeekable> value);
std::unique_ptr<SkStreamSeekable> static_sk_stream_seekable_move(int key);

#endif //RAIA_SKIA_STATIC_SK_STREAM_SEEKABLE_H
