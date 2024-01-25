//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_stream_asset.h"

static std::map<int , std::unique_ptr<SkStreamAsset>> static_sk_stream_asset;

void static_sk_stream_asset_delete(int key) {
    static_sk_stream_asset[key].reset();
    static_sk_stream_asset.erase(key);
}

SkStreamAsset *static_sk_stream_asset_get(int key) {
    return static_sk_stream_asset[key].get();
}

void static_sk_stream_asset_set(int key, std::unique_ptr<SkStreamAsset> value) {
    static_sk_stream_asset[key] = std::move(value);
}

std::unique_ptr<SkStreamAsset> static_sk_stream_asset_move(int key) {
    return std::move(static_sk_stream_asset[key]);
}