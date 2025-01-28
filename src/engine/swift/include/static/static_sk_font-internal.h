#ifndef STATIC_SK_FONT_INTERNAL_H
#define STATIC_SK_FONT_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkFont.h"
int static_sk_font_make(SkFont value);
SkFont static_sk_font_get(int key);
void static_sk_font_set(int key, SkFont value);
#endif // STATIC_SK_FONT_INTERNAL_H
