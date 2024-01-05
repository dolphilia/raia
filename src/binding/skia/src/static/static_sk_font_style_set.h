//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_FONT_STYLE_SET_H
#define RAIA_SKIA_STATIC_SK_FONT_STYLE_SET_H

#include <string>
#include <map>
#include "include/core/SkFontMgr.h"

void static_sk_font_style_set_delete(const char *key);
SkFontStyleSet *static_sk_font_style_set_get(const char *key);
void static_sk_font_style_set_set(const char *key, sk_sp<SkFontStyleSet> value);
sk_sp<SkFontStyleSet> static_sk_font_style_set_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_FONT_STYLE_SET_H
