#ifndef STATIC_SK_STREAM_REWINDABLE_INTERNAL_H
#define STATIC_SK_STREAM_REWINDABLE_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkStream.h"
int static_sk_stream_rewindable_make(std::unique_ptr<SkStreamRewindable> value);
void static_sk_stream_rewindable_set(int key, std::unique_ptr<SkStreamRewindable> value);
std::unique_ptr<SkStreamRewindable> static_sk_stream_rewindable_get_entity(int key);
#endif // STATIC_SK_STREAM_REWINDABLE_INTERNAL_H
