#ifndef STATIC_SK_STREAM_INTERNAL_H
#define STATIC_SK_STREAM_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkStream.h"
int static_sk_stream_make(std::unique_ptr<SkStream> value);
void static_sk_stream_set(int key, std::unique_ptr<SkStream> value);
std::unique_ptr<SkStream> static_sk_stream_get_entity(int key);
int static_sk_stream_ptr_make(std::unique_ptr<SkStream>* value);
void static_sk_stream_ptr_set(int key, std::unique_ptr<SkStream>* value);
std::unique_ptr<SkStream>* static_sk_stream_ptr_get_entity(int key);
#endif // STATIC_SK_STREAM_INTERNAL_H
