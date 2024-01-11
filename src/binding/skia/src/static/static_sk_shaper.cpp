//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_shaper.h"

static std::map<std::string, std::unique_ptr<SkShaper>> static_sk_shaper;

void static_sk_shaper_delete(const char *key) {
    static_sk_shaper[key].reset();
    static_sk_shaper.erase(key);
}

SkShaper *static_sk_shaper_get(const char *key) {
    return static_sk_shaper[key].get();
}

void static_sk_shaper_set(const char *key, std::unique_ptr<SkShaper> value) {
    static_sk_shaper[key] = std::move(value);
}

std::unique_ptr<SkShaper> static_sk_shaper_move(const char *key) {
    return std::move(static_sk_shaper[key]);
}