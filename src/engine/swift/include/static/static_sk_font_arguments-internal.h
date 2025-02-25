#ifndef STATIC_SK_FONT_ARGUMENTS_INTERNAL_H
#define STATIC_SK_FONT_ARGUMENTS_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkFontArguments.h"
int static_sk_font_arguments_make(SkFontArguments value);
SkFontArguments static_sk_font_arguments_get_entity(int key);
void static_sk_font_arguments_set(int key, SkFontArguments value);
#endif // STATIC_SK_FONT_ARGUMENTS_INTERNAL_H
