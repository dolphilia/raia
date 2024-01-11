//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_SHAPER_H
#define RAIA_SKIA_STATIC_SK_SHAPER_H

#include <string>
#include <map>
#include "modules/skshaper/include/SkShaper.h"

void static_sk_shaper_delete(const char *key);
SkShaper *static_sk_shaper_get(const char *key);
void static_sk_shaper_set(const char *key, std::unique_ptr<SkShaper> value);
std::unique_ptr<SkShaper> static_sk_shaper_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_SHAPER_H
