#ifndef STATIC_SK_COLOR_TABLE_INTERNAL_H
#define STATIC_SK_COLOR_TABLE_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkColorTable.h"
int static_sk_color_table_make(sk_sp<SkColorTable> value);
void static_sk_color_table_set(int key, sk_sp<SkColorTable> value);
sk_sp<SkColorTable> static_sk_color_table_move(int key);
#endif // STATIC_SK_COLOR_TABLE_INTERNAL_H
