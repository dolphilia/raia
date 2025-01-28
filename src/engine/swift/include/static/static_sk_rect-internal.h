#ifndef STATIC_SK_RECT_INTERNAL_H
#define STATIC_SK_RECT_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkRect.h"
int static_sk_rect_make(SkRect value);
SkRect static_sk_rect_get(int key);
void static_sk_rect_set(int key, SkRect value);
#endif // STATIC_SK_RECT_INTERNAL_H
