//
// Created by dolphilia on 2024/04/08.
//

#include "static_sk_shaper_run_handler_buffer.h"

static std::set<int> static_sk_shaper_run_handler_buffer_available_keys;
static std::map<int , SkShaper::RunHandler::Buffer> static_sk_shaper_run_handler_buffer;
static int static_sk_shaper_run_handler_buffer_index = 0;

int static_sk_shaper_run_handler_buffer_make(SkShaper::RunHandler::Buffer value) {
    int key;
    if (!static_sk_shaper_run_handler_buffer_available_keys.empty()) {
        auto it = static_sk_shaper_run_handler_buffer_available_keys.begin();
        key = *it;
        static_sk_shaper_run_handler_buffer_available_keys.erase(it);
    } else {
        key = static_sk_shaper_run_handler_buffer_index++;
    }
    static_sk_shaper_run_handler_buffer[key] = value;
    return key;
}

void static_sk_shaper_run_handler_buffer_delete(int key) {
    static_sk_shaper_run_handler_buffer.erase(key);
    static_sk_shaper_run_handler_buffer_available_keys.insert(key);
}

SkShaper::RunHandler::Buffer static_sk_shaper_run_handler_buffer_get(int key) {
    return static_sk_shaper_run_handler_buffer[key];
}

void static_sk_shaper_run_handler_buffer_set(int key, SkShaper::RunHandler::Buffer value) {
    static_sk_shaper_run_handler_buffer[key] = value;
}