//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_stream_asset.h"
#include "static_sk_stream_asset-internal.h"

static std::set<int> static_sk_stream_asset_available_keys;
static std::map<int , std::unique_ptr<SkStreamAsset>> static_sk_stream_asset;
static int static_sk_stream_asset_index = 0;

int static_sk_stream_asset_make(std::unique_ptr<SkStreamAsset> value) {
    int key;
    if (!static_sk_stream_asset_available_keys.empty()) {
        auto it = static_sk_stream_asset_available_keys.begin();
        key = *it;
        static_sk_stream_asset_available_keys.erase(it);
    } else {
        key = static_sk_stream_asset_index++;
    }
    static_sk_stream_asset[key] = std::move(value);
    return key;
}

void static_sk_stream_asset_delete(int key) {
    static_sk_stream_asset[key].reset();
    static_sk_stream_asset.erase(key);
    static_sk_stream_asset_available_keys.insert(key);
}

void *static_sk_stream_asset_get(int key) { // -> SkStreamAsset *
    return static_sk_stream_asset[key].get();
}

void static_sk_stream_asset_set(int key, std::unique_ptr<SkStreamAsset> value) {
    static_sk_stream_asset[key] = std::move(value);
}

std::unique_ptr<SkStreamAsset> static_sk_stream_asset_move(int key) {
    return std::move(static_sk_stream_asset[key]);
}
