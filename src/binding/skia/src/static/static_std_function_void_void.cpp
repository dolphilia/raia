//
// Created by dolphilia on 2024/01/12.
//

#include "static_std_function_void_void.h"

static std::map<std::string, std::function<void(void)>> static_function_void_void;

void static_function_void_void_delete(const char *key) {
    static_function_void_void.erase(key);
}

std::function<void(void)> static_function_void_void_get(const char *key) {
    return static_function_void_void[key];
}

void static_function_void_void_set(const char *key, std::function<void(void)> value) {
    static_function_void_void[key] = std::move(value);
}