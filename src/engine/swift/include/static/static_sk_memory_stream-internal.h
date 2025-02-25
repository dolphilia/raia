#ifndef STATIC_SK_MEMORY_STREAM_INTERNAL_H
#define STATIC_SK_MEMORY_STREAM_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkStream.h"
int static_sk_memory_stream_make(std::unique_ptr<SkMemoryStream> value);
void static_sk_memory_stream_set(int key, std::unique_ptr<SkMemoryStream> value);
std::unique_ptr<SkMemoryStream> static_sk_memory_stream_get_entity(int key);
#endif // STATIC_SK_MEMORY_STREAM_INTERNAL_H
