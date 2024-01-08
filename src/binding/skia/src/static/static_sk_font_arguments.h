//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_STATIC_SK_FONT_ARGUMENTS_H
#define RAIA_SKIA_STATIC_SK_FONT_ARGUMENTS_H

#include <string>
#include <map>
#include "include/core/SkFontArguments.h"

void static_sk_font_arguments_delete(const char *key);
SkFontArguments static_sk_font_arguments_get(const char *key);
void static_sk_font_arguments_set(const char *key, SkFontArguments value);

#endif //RAIA_SKIA_STATIC_SK_FONT_ARGUMENTS_H
