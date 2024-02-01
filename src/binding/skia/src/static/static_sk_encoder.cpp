//
// Created by dolphilia on 2024/02/01.
//

#include "static_sk_encoder.h"

static std::set<int> static_sk_encoder_available_keys;
static std::map<int , std::unique_ptr<SkEncoder>> static_sk_encoder;
static int static_sk_encoder_index = 0;

int static_sk_encoder_make(std::unique_ptr<SkEncoder> value) {
    int key;
    if (!static_sk_encoder_available_keys.empty()) {
        auto it = static_sk_encoder_available_keys.begin();
        key = *it;
        static_sk_encoder_available_keys.erase(it);
    } else {
        key = static_sk_encoder_index++;
    }
    static_sk_encoder[key] = std::move(value);
    return key;
}

void static_sk_encoder_delete(int key) {
    static_sk_encoder[key].reset();
    static_sk_encoder.erase(key);
    static_sk_encoder_available_keys.insert(key);
}

SkEncoder *static_sk_encoder_get(int key) {
    return static_sk_encoder[key].get();
}

void static_sk_encoder_set(int key, std::unique_ptr<SkEncoder> value) {
    static_sk_encoder[key] = std::move(value);
}

std::unique_ptr<SkEncoder> static_sk_encoder_move(int key) {
    return std::move(static_sk_encoder[key]);
}