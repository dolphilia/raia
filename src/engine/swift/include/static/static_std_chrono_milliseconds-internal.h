#ifndef STATIC_STD_CHRONO_MILLISECONDS_INTERNAL_H
#define STATIC_STD_CHRONO_MILLISECONDS_INTERNAL_H
#include <set>
#include <map>
#ifdef _WIN32
#include <chrono>
#endif
int static_chrono_milliseconds_make(std::chrono::milliseconds value);
std::chrono::milliseconds static_chrono_milliseconds_get_entity(int key);
void static_chrono_milliseconds_set(int key, std::chrono::milliseconds value);
#endif // STATIC_STD_CHRONO_MILLISECONDS_INTERNAL_H
