#ifndef STATIC_SK_STREAM_SEEKABLE_INTERNAL_H
#define STATIC_SK_STREAM_SEEKABLE_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkStream.h"
int static_sk_stream_seekable_make(std::unique_ptr<SkStreamSeekable> value);
void static_sk_stream_seekable_set(int key, std::unique_ptr<SkStreamSeekable> value);
std::unique_ptr<SkStreamSeekable> static_sk_stream_seekable_get_entity(int key);
#endif // STATIC_SK_STREAM_SEEKABLE_INTERNAL_H
