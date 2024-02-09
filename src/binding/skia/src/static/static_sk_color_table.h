//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_COLOR_TABLE_H
#define RAIA_SKIA_STATIC_SK_COLOR_TABLE_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkColorTable.h"

typedef int sk_color_table_t;

int static_sk_color_table_make(sk_sp<SkColorTable> value);
extern "C" void static_sk_color_table_delete(int key);
extern "C" SkColorTable *static_sk_color_table_get(int key);
void static_sk_color_table_set(int key, sk_sp<SkColorTable> value);
sk_sp<SkColorTable> static_sk_color_table_move(int key);

#endif //RAIA_SKIA_STATIC_SK_COLOR_TABLE_H
