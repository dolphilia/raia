//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_FILE_STREAM_H
#define RAIA_SKIA_STATIC_SK_FILE_STREAM_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkStream.h"
#include "export_api.h"

typedef int sk_file_stream_t;

extern "C" {
RAIA_API void static_sk_file_stream_delete(int key);
RAIA_API SkFILEStream *static_sk_file_stream_get(int key);
}

int static_sk_file_stream_make(std::unique_ptr<SkFILEStream> value);
void static_sk_file_stream_set(int key, std::unique_ptr<SkFILEStream> value);
std::unique_ptr<SkFILEStream> static_sk_file_stream_move(int key);

#endif //RAIA_SKIA_STATIC_SK_FILE_STREAM_H
