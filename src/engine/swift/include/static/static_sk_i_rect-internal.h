#ifndef STATIC_SK_I_RECT_INTERNAL_H
#define STATIC_SK_I_RECT_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkRect.h"
int static_sk_i_rect_make(SkIRect value);
SkIRect static_sk_i_rect_get_entity(int key);
void static_sk_i_rect_set(int key, SkIRect value);
#endif // STATIC_SK_I_RECT_INTERNAL_H
