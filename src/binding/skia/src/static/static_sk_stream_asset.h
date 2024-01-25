//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_STREAM_ASSET_H
#define RAIA_SKIA_STATIC_SK_STREAM_ASSET_H

#include <string>
#include <map>
#include "include/core/SkStream.h"

int static_sk_stream_asset_make(std::unique_ptr<SkStreamAsset> value);
void static_sk_stream_asset_delete(int key);
SkStreamAsset *static_sk_stream_asset_get(int key);
void static_sk_stream_asset_set(int key, std::unique_ptr<SkStreamAsset> value);
std::unique_ptr<SkStreamAsset> static_sk_stream_asset_move(int key);

#endif //RAIA_SKIA_STATIC_SK_STREAM_ASSET_H
