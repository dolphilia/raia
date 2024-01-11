//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_STREAM_H
#define RAIA_SKIA_STATIC_SK_STREAM_H

#include <string>
#include <map>
#include "include/core/SkStream.h"

void static_sk_stream_delete(const char *key);
SkStream *static_sk_stream_get(const char *key);
void static_sk_stream_set(const char *key, std::unique_ptr<SkStream> value);
std::unique_ptr<SkStream> static_sk_stream_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_STREAM_H
