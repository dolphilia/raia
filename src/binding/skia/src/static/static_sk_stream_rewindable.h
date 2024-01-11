//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_STREAM_REWINDABLE_H
#define RAIA_SKIA_STATIC_SK_STREAM_REWINDABLE_H

#include <string>
#include <map>
#include "include/core/SkStream.h"

void static_sk_stream_rewindable_delete(const char *key);
SkStreamRewindable *static_sk_stream_rewindable_get(const char *key);
void static_sk_stream_rewindable_set(const char *key, std::unique_ptr<SkStreamRewindable> value);
std::unique_ptr<SkStreamRewindable> static_sk_stream_rewindable_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_STREAM_REWINDABLE_H
