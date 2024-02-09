//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_DATA_TABLE_H
#define RAIA_SKIA_STATIC_SK_DATA_TABLE_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkDataTable.h"

typedef int sk_data_table_t;

int static_sk_data_table_make(sk_sp<SkDataTable> value);
extern "C" void static_sk_data_table_delete(int key);
extern "C" SkDataTable *static_sk_data_table_get(int key);
void static_sk_data_table_set(int key, sk_sp<SkDataTable> value);
sk_sp<SkDataTable> static_sk_data_table_move(int key);

#endif //RAIA_SKIA_STATIC_SK_DATA_TABLE_H
