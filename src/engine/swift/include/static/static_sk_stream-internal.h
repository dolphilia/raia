#ifndef STATIC_SK_STREAM_INTERNAL_H
#define STATIC_SK_STREAM_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkStream.h"
int static_sk_stream_make(std::unique_ptr<SkStream> value);
void static_sk_stream_set(int key, std::unique_ptr<SkStream> value);
std::unique_ptr<SkStream> static_sk_stream_move(int key);
int static_sk_stream_ptr_make(std::unique_ptr<SkStream>* value);
void static_sk_stream_ptr_set(int key, std::unique_ptr<SkStream>* value);
std::unique_ptr<SkStream>* static_sk_stream_ptr_move(int key);
#endif // STATIC_SK_STREAM_INTERNAL_H
