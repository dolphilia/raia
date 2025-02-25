#ifndef STATIC_STD_FUNCTION_VOID_VOID_INTERNAL_H
#define STATIC_STD_FUNCTION_VOID_VOID_INTERNAL_H
#include <set>
#include <map>
#ifdef _WIN32
#include <functional>
#endif
int static_function_void_void_make(std::function<void(void)> value);
std::function<void(void)> static_function_void_void_get_entity(int key);
void static_function_void_void_set(int key, std::function<void(void)> value);
#endif // STATIC_STD_FUNCTION_VOID_VOID_INTERNAL_H
