//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_STATIC_SK_BLEND_MODE_H
#define RAIA_SKIA_STATIC_SK_BLEND_MODE_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkBlendMode.h"

typedef int optional_sk_blend_mode_t;

int static_optional_sk_blend_mode_make(std::optional<SkBlendMode> value);
extern "C" void static_optional_sk_blend_mode_delete(int key);
SkBlendMode static_optional_sk_blend_mode_get(int key);
void static_optional_sk_blend_mode_set(int key, std::optional<SkBlendMode> value);
std::optional<SkBlendMode> static_optional_sk_blend_mode_move(int key);

#endif //RAIA_SKIA_STATIC_SK_BLEND_MODE_H
