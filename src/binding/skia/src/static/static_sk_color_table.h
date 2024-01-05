//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_COLOR_TABLE_H
#define RAIA_SKIA_STATIC_SK_COLOR_TABLE_H

#include <string>
#include <map>
#include "include/core/SkColorTable.h"

void static_sk_color_table_delete(const char *key);
SkColorTable *static_sk_color_table_get(const char *key);
void static_sk_color_table_set(const char *key, sk_sp<SkColorTable> value);
sk_sp<SkColorTable> static_sk_color_table_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_COLOR_TABLE_H