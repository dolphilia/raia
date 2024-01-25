//
// Created by dolphilia on 2024/01/23.
//

#ifndef RAIA_V8_STATIC_V8_PLATFORM_H
#define RAIA_V8_STATIC_V8_PLATFORM_H

#include <string>
#include <map>
#include "cppgc/platform.h"

void static_v8_platform_delete(int key);
v8::Platform *static_v8_platform_get(int key);
std::unique_ptr<v8::Platform> static_v8_platform_move(int key);
void static_v8_platform_set(int key, std::unique_ptr<v8::Platform> value);
int static_v8_platform_make(std::unique_ptr<v8::Platform> value);

#endif //RAIA_V8_STATIC_V8_PLATFORM_H
