//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_shaper.h"

static std::set<int> static_sk_shaper_available_keys;
static std::map<int , std::unique_ptr<SkShaper>> static_sk_shaper;
static int static_sk_shaper_index = 0;

int static_sk_shaper_make(std::unique_ptr<SkShaper> value) {
    int key;
    if (!static_sk_shaper_available_keys.empty()) {
        auto it = static_sk_shaper_available_keys.begin();
        key = *it;
        static_sk_shaper_available_keys.erase(it);
    } else {
        key = static_sk_shaper_index++;
    }
    static_sk_shaper[key] = std::move(value);
    return key;
}

void static_sk_shaper_delete(int key) {
    static_sk_shaper[key].reset();
    static_sk_shaper.erase(key);
    static_sk_shaper_available_keys.insert(key);
}

SkShaper *static_sk_shaper_get(int key) {
    return static_sk_shaper[key].get();
}

void static_sk_shaper_set(int key, std::unique_ptr<SkShaper> value) {
    static_sk_shaper[key] = std::move(value);
}

std::unique_ptr<SkShaper> static_sk_shaper_move(int key) {
    return std::move(static_sk_shaper[key]);
}