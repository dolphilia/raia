//
// Created by dolphilia on 2024/04/01.
//

#ifndef RAIA_SKIA_STATIC_STD_CHRONO_MILLISECONDS_H
#define RAIA_SKIA_STATIC_STD_CHRONO_MILLISECONDS_H

#include <set>
#include <string>
#include <map>

typedef int chrono_milliseconds_t;

int static_chrono_milliseconds_make(std::chrono::milliseconds value);
extern "C" void static_chrono_milliseconds_delete(int key);
std::chrono::milliseconds static_chrono_milliseconds_get(int key);
void static_chrono_milliseconds_set(int key, std::chrono::milliseconds value);

#endif //RAIA_SKIA_STATIC_STD_CHRONO_MILLISECONDS_H
