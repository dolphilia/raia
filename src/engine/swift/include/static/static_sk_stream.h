//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_STREAM_H
#define RAIA_SKIA_STATIC_SK_STREAM_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkStream.h"

typedef int sk_stream_t;

int static_sk_stream_make(std::unique_ptr<SkStream> value);
extern "C" void static_sk_stream_delete(int key);
extern "C" SkStream *static_sk_stream_get(int key);
void static_sk_stream_set(int key, std::unique_ptr<SkStream> value);
std::unique_ptr<SkStream> static_sk_stream_move(int key);

#endif //RAIA_SKIA_STATIC_SK_STREAM_H
