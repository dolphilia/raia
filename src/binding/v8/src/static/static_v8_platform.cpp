//
// Created by dolphilia on 2024/01/23.
//

#include "static_v8_platform.h"

static int static_v8_platform_index = 0;
static std::map<int, std::unique_ptr<v8::Platform>> static_v8_platform;

void static_v8_platform_delete(int key) {
    static_v8_platform[key].reset();
    static_v8_platform.erase(key);
}

v8::Platform *static_v8_platform_get(int key) {
    return static_v8_platform[key].get();
}

std::unique_ptr<v8::Platform> static_v8_platform_move(int key) {
    return std::move(static_v8_platform[key]);
}

void static_v8_platform_set(int key, std::unique_ptr<v8::Platform> value) {
    static_v8_platform[key] = std::move(value);
}

int static_v8_platform_make(std::unique_ptr<v8::Platform> value) {
    static_v8_platform[static_v8_platform_index] = std::move(value);
    static_v8_platform_index++;
    return static_v8_platform_index - 1;
}