//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_STREAM_ASSET_H
#define RAIA_SKIA_STATIC_SK_STREAM_ASSET_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkStream.h"
#include "export_api.h"

typedef int sk_stream_asset_t;

extern "C" {
RAIA_API void static_sk_stream_asset_delete(int key);
RAIA_API SkStreamAsset *static_sk_stream_asset_get(int key);
}

int static_sk_stream_asset_make(std::unique_ptr<SkStreamAsset> value);
void static_sk_stream_asset_set(int key, std::unique_ptr<SkStreamAsset> value);
std::unique_ptr<SkStreamAsset> static_sk_stream_asset_move(int key);

#endif //RAIA_SKIA_STATIC_SK_STREAM_ASSET_H
