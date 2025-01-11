//
// Created by dolphilia on 2024/04/01.
//

#ifndef RAIA_SKIA_STATIC_STD_CHRONO_MILLISECONDS_H
#define RAIA_SKIA_STATIC_STD_CHRONO_MILLISECONDS_H

#include <set>
#include <string>
#include <map>
#ifdef _WIN32
#include <chrono>
#endif
#include "export_api.h"

typedef int chrono_milliseconds_t;

extern "C" {
RAIA_API void static_chrono_milliseconds_delete(int key);
}

int static_chrono_milliseconds_make(std::chrono::milliseconds value);
std::chrono::milliseconds static_chrono_milliseconds_get(int key);
void static_chrono_milliseconds_set(int key, std::chrono::milliseconds value);

#endif //RAIA_SKIA_STATIC_STD_CHRONO_MILLISECONDS_H
