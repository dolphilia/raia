//
// Created by dolphilia on 25/02/17.
//

#ifndef STATIC_SK_PAINT_INTERNAL_H
#define STATIC_SK_PAINT_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkPaint.h"
int static_sk_paint_make(SkPaint value);
SkPaint static_sk_paint_get_entity(int key);
void static_sk_paint_set(int key, SkPaint value);
#endif //STATIC_SK_PAINT_INTERNAL_H
