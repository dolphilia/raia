//
// Created by dolphilia on 2024/02/02.
//

#include "static_sk_android_codec.h"

static std::set<int> static_sk_android_codec_available_keys;
static std::map<int , std::unique_ptr<SkAndroidCodec>> static_sk_android_codec;
static int static_sk_android_codec_index = 0;

int static_sk_android_codec_make(std::unique_ptr<SkAndroidCodec> value) {
    int key;
    if (!static_sk_android_codec_available_keys.empty()) {
        auto it = static_sk_android_codec_available_keys.begin();
        key = *it;
        static_sk_android_codec_available_keys.erase(it);
    } else {
        key = static_sk_android_codec_index++;
    }
    static_sk_android_codec[key] = std::move(value);
    return key;
}

void static_sk_android_codec_delete(int key) {
    static_sk_android_codec[key].reset();
    static_sk_android_codec.erase(key);
    static_sk_android_codec_available_keys.insert(key);
}

SkAndroidCodec *static_sk_android_codec_get(int key) {
    return static_sk_android_codec[key].get();
}

void static_sk_android_codec_set(int key, std::unique_ptr<SkAndroidCodec> value) {
    static_sk_android_codec[key] = std::move(value);
}

std::unique_ptr<SkAndroidCodec> static_sk_android_codec_move(int key) {
    return std::move(static_sk_android_codec[key]);
}