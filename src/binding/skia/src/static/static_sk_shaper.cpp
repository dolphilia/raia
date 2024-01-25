//
// Created by dolphilia on 2024/01/11.
//

#include "static_sk_shaper.h"

static std::map<int , std::unique_ptr<SkShaper>> static_sk_shaper;
static int static_sk_shaper_index = 0;

int static_sk_shaper_make(std::unique_ptr<SkShaper> value) {
    static_sk_shaper[static_sk_shaper_index] = std::move(value);
    static_sk_shaper_index++;
    return static_sk_shaper_index - 1;
}

void static_sk_shaper_delete(int key) {
    static_sk_shaper[key].reset();
    static_sk_shaper.erase(key);
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