//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_STD_FUNCTION_VOID_VOID_H
#define RAIA_SKIA_STATIC_STD_FUNCTION_VOID_VOID_H

#include <string>
#include <map>

void static_function_void_void_delete(int key);
std::function<void(void)> static_function_void_void_get(int key);
void static_function_void_void_set(int key, std::function<void(void)> value);

#endif //RAIA_SKIA_STATIC_STD_FUNCTION_VOID_VOID_H
