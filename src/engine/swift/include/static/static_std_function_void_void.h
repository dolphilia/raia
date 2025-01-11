//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_STD_FUNCTION_VOID_VOID_H
#define RAIA_SKIA_STATIC_STD_FUNCTION_VOID_VOID_H

#include <set>
#include <string>
#include <map>
#ifdef _WIN32
#include <functional>
#endif
#include "export_api.h"

typedef int function_void_void_t;

extern "C" {
RAIA_API void static_function_void_void_delete(int key);
}

int static_function_void_void_make(std::function<void(void)> value);
std::function<void(void)> static_function_void_void_get(int key);
void static_function_void_void_set(int key, std::function<void(void)> value);

#endif //RAIA_SKIA_STATIC_STD_FUNCTION_VOID_VOID_H
