//
// Created by dolphilia on 2024/01/23.
//

#include "static_v8_isolate_create_params.h"

static std::map<std::string, v8::Isolate::CreateParams> static_v8_isolate_create_params;

void static_v8_isolate_create_params_delete(const char *key) {
    static_v8_isolate_create_params.erase(key);
}

v8::Isolate::CreateParams static_v8_isolate_create_params_get(const char *key) {
    return static_v8_isolate_create_params[key];
}

void static_v8_isolate_create_params_set(const char *key, v8::Isolate::CreateParams value) {
    static_v8_isolate_create_params[key] = std::move(value);
}

void static_v8_isolate_create_params_set_array_buffer_allocator(v8::Isolate::CreateParams *createParams, v8::ArrayBuffer::Allocator *allocator) {
    createParams->array_buffer_allocator = allocator;
}

void static_v8_isolate_create_params_delete_array_buffer_allocator(v8::Isolate::CreateParams *createParams) {
    delete createParams->array_buffer_allocator;
}