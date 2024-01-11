//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_DATA_TABLE_H
#define RAIA_SKIA_STATIC_SK_DATA_TABLE_H

#include <string>
#include <map>
#include "include/core/SkDataTable.h"

void static_sk_data_table_delete(const char *key);
SkDataTable *static_sk_data_table_get(const char *key);
void static_sk_data_table_set(const char *key, sk_sp<SkDataTable> value);
sk_sp<SkDataTable> static_sk_data_table_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_DATA_TABLE_H
