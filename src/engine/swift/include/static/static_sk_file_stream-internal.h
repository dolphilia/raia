#ifndef STATIC_SK_FILE_STREAM_INTERNAL_H
#define STATIC_SK_FILE_STREAM_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkStream.h"
int static_sk_file_stream_make(std::unique_ptr<SkFILEStream> value);
void static_sk_file_stream_set(int key, std::unique_ptr<SkFILEStream> value);
std::unique_ptr<SkFILEStream> static_sk_file_stream_move(int key);
#endif // STATIC_SK_FILE_STREAM_INTERNAL_H
