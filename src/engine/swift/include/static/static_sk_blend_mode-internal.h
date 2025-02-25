//
// Created by dolphilia on 25/01/11.
//
#ifndef STATIC_SK_BLEND_MODE_INTERNAL_H
#define STATIC_SK_BLEND_MODE_INTERNAL_H
#include "include/core/SkBlendMode.h"
#include <map>
#include <set>
#ifdef _WIN32
#include <optional>
#endif
int static_optional_sk_blend_mode_make(std::optional<SkBlendMode> value);
void static_optional_sk_blend_mode_set(int key, std::optional<SkBlendMode> value);
std::optional<SkBlendMode> static_optional_sk_blend_mode_get_entity(int key);
#endif //STATIC_SK_BLEND_MODE_INTERNAL_H
