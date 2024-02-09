//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_STATIC_SK_FONT_H
#define RAIA_SKIA_STATIC_SK_FONT_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkFont.h"

typedef int sk_font_t;

int static_sk_font_make(SkFont value);
extern "C" void static_sk_font_delete(int key);
SkFont static_sk_font_get(int key);
void static_sk_font_set(int key, SkFont value);

#endif //RAIA_SKIA_STATIC_SK_FONT_H
