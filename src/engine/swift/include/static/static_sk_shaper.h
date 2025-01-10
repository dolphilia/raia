//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_SHAPER_H
#define RAIA_SKIA_STATIC_SK_SHAPER_H

#include <set>
#include <string>
#include <map>
#include "modules/skshaper/include/SkShaper.h"

typedef int sk_shaper_t;

int static_sk_shaper_make(std::unique_ptr<SkShaper> value);
extern "C" void static_sk_shaper_delete(int key);
extern "C" SkShaper *static_sk_shaper_get(int key);
void static_sk_shaper_set(int key, std::unique_ptr<SkShaper> value);
std::unique_ptr<SkShaper> static_sk_shaper_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SHAPER_H
