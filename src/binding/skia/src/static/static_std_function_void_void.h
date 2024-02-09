//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_STD_FUNCTION_VOID_VOID_H
#define RAIA_SKIA_STATIC_STD_FUNCTION_VOID_VOID_H

#include <set>
#include <string>
#include <map>

typedef int function_void_void_t;

int static_function_void_void_make(std::function<void(void)> value);
extern "C" void static_function_void_void_delete(int key);
std::function<void(void)> static_function_void_void_get(int key);
void static_function_void_void_set(int key, std::function<void(void)> value);

#endif //RAIA_SKIA_STATIC_STD_FUNCTION_VOID_VOID_H
