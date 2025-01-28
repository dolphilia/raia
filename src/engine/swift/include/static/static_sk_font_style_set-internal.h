#ifndef STATIC_SK_FONT_STYLE_SET_INTERNAL_H
#define STATIC_SK_FONT_STYLE_SET_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkFontMgr.h"
int static_sk_font_style_set_make(sk_sp<SkFontStyleSet> value);
void static_sk_font_style_set_set(int key, sk_sp<SkFontStyleSet> value);
sk_sp<SkFontStyleSet> static_sk_font_style_set_move(int key);
#endif // STATIC_SK_FONT_STYLE_SET_INTERNAL_H
