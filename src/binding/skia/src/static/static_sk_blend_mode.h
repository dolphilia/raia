//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_STATIC_SK_BLEND_MODE_H
#define RAIA_SKIA_STATIC_SK_BLEND_MODE_H

#include <string>
#include <map>
#include "include/core/SkBlendMode.h"

void static_optional_sk_blend_mode_delete(const char *key);
SkBlendMode static_optional_sk_blend_mode_get(const char *key);
void static_optional_sk_blend_mode_set(const char *key, std::optional<SkBlendMode> value);
std::optional<SkBlendMode> static_optional_sk_blend_mode_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_BLEND_MODE_H
