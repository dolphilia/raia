//
// Created by dolphilia on 2024/01/23.
//

#ifndef RAIA_V8_V8_ISOLATE_CREATE_PARAMS_H
#define RAIA_V8_V8_ISOLATE_CREATE_PARAMS_H

#include "v8-isolate.h"
#include "v8-array-buffer.h"
#include <string>
#include <map>

void static_v8_isolate_create_params_delete(const char *key);
v8::Isolate::CreateParams static_v8_isolate_create_params_get(const char *key);
void static_v8_isolate_create_params_set(const char *key, v8::Isolate::CreateParams value);
void static_v8_isolate_create_params_set_array_buffer_allocator(v8::Isolate::CreateParams *createParams, v8::ArrayBuffer::Allocator *allocator);

#endif //RAIA_V8_V8_ISOLATE_CREATE_PARAMS_H
