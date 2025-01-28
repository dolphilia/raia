#ifndef STATIC_SK_FONT_STYLE_INTERNAL_H
#define STATIC_SK_FONT_STYLE_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkFontStyle.h"
int static_sk_font_style_make(SkFontStyle value);
SkFontStyle static_sk_font_style_get(int key);
void static_sk_font_style_set(int key, SkFontStyle value);
#endif // STATIC_SK_FONT_STYLE_INTERNAL_H
