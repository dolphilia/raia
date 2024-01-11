//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_stream_asset.h"

static std::map<std::string, std::unique_ptr<SkStreamAsset>> static_sk_stream_asset;

void static_sk_stream_asset_delete(const char *key) {
    static_sk_stream_asset[key].reset();
    static_sk_stream_asset.erase(key);
}

SkStreamAsset *static_sk_stream_asset_get(const char *key) {
    return static_sk_stream_asset[key].get();
}

void static_sk_stream_asset_set(const char *key, std::unique_ptr<SkStreamAsset> value) {
    static_sk_stream_asset[key] = std::move(value);
}

std::unique_ptr<SkStreamAsset> static_sk_stream_asset_move(const char *key) {
    return std::move(static_sk_stream_asset[key]);
}