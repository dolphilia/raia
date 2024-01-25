//
// Created by dolphilia on 2024/01/12.
//

#include "static_std_function_void_void.h"

#include <utility>

static std::map<int , std::function<void(void)>> static_function_void_void;
static int static_function_void_void_index = 0;

int static_function_void_void_make(std::function<void(void)> value) {
    static_function_void_void[static_function_void_void_index] = std::move(value);
    static_function_void_void_index++;
    return static_function_void_void_index - 1;
}

void static_function_void_void_delete(int key) {
    static_function_void_void.erase(key);
}

std::function<void(void)> static_function_void_void_get(int key) {
    return static_function_void_void[key];
}

void static_function_void_void_set(int key, std::function<void(void)> value) {
    static_function_void_void[key] = std::move(value);
}