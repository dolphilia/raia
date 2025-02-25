#ifndef STATIC_SK_STREAM_ASSET_INTERNAL_H
#define STATIC_SK_STREAM_ASSET_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkStream.h"
int static_sk_stream_asset_make(std::unique_ptr<SkStreamAsset> value);
void static_sk_stream_asset_set(int key, std::unique_ptr<SkStreamAsset> value);
std::unique_ptr<SkStreamAsset> static_sk_stream_asset_get_entity(int key);
#endif // STATIC_SK_STREAM_ASSET_INTERNAL_H
