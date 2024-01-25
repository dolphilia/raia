//
// Created by dolphilia on 2024/01/12.
//

#include "static_std_function_void_void.h"

static std::map<int , std::function<void(void)>> static_function_void_void;

void static_function_void_void_delete(int key) {
    static_function_void_void.erase(key);
}

std::function<void(void)> static_function_void_void_get(int key) {
    return static_function_void_void[key];
}

void static_function_void_void_set(int key, std::function<void(void)> value) {
    static_function_void_void[key] = std::move(value);
}