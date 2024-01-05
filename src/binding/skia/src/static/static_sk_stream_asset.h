//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_STREAM_ASSET_H
#define RAIA_SKIA_STATIC_SK_STREAM_ASSET_H

#include <string>
#include <map>
#include "include/core/SkStream.h"

void static_sk_stream_asset_delete(const char *key);
SkStreamAsset *static_sk_stream_asset_get(const char *key);
void static_sk_stream_asset_set(const char *key, std::unique_ptr<SkStreamAsset> value);
std::unique_ptr<SkStreamAsset> static_sk_stream_asset_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_STREAM_ASSET_H
