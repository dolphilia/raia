#ifndef STATIC_SK_DATA_TABLE_INTERNAL_H
#define STATIC_SK_DATA_TABLE_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkDataTable.h"
int static_sk_data_table_make(sk_sp<SkDataTable> value);
void static_sk_data_table_set(int key, sk_sp<SkDataTable> value);
sk_sp<SkDataTable> static_sk_data_table_get_entity(int key);
#endif // STATIC_SK_DATA_TABLE_INTERNAL_H
