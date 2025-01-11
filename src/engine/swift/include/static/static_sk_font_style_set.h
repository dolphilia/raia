//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_FONT_STYLE_SET_H
#define RAIA_SKIA_STATIC_SK_FONT_STYLE_SET_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkFontMgr.h"
#include "export_api.h"

typedef int sk_font_style_set_t;

extern "C" {
RAIA_API void static_sk_font_style_set_delete(int key);
RAIA_API SkFontStyleSet *static_sk_font_style_set_get(int key);
}

int static_sk_font_style_set_make(sk_sp<SkFontStyleSet> value);
void static_sk_font_style_set_set(int key, sk_sp<SkFontStyleSet> value);
sk_sp<SkFontStyleSet> static_sk_font_style_set_move(int key);

#endif //RAIA_SKIA_STATIC_SK_FONT_STYLE_SET_H
