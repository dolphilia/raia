//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_DATA_TABLE_H
#define RAIA_SKIA_SK_DATA_TABLE_H

#include "include/core/SkDataTable.h"
#include "../static/static_sk_data_table.h"

extern "C" {
void SkDataTable_delete(SkDataTable *data_table);
bool SkDataTable_isEmpty(SkDataTable *data_table);
int SkDataTable_count(SkDataTable *data_table);
size_t SkDataTable_atSize(SkDataTable *data_table, int index);
const void * SkDataTable_at(SkDataTable *data_table, int index, size_t *size);
// template<typename T>
// const T * SkDataTable_atT(int index, size_t *size=nullptr) const
const char * SkDataTable_atStr(SkDataTable *data_table, int index);
bool SkDataTable_unique(SkDataTable *data_table);
void SkDataTable_ref(SkDataTable *data_table);
void SkDataTable_unref(SkDataTable *data_table);
// static
sk_data_table_t SkDataTable_MakeEmpty();
sk_data_table_t SkDataTable_MakeCopyArrays(const void *const *ptrs, const size_t sizes[], int count);
sk_data_table_t SkDataTable_MakeCopyArray(const void *array, size_t elemSize, int count);
sk_data_table_t SkDataTable_MakeArrayProc(const void *array, size_t elemSize, int count, SkDataTable::FreeProc proc, void *context);
}

#endif //RAIA_SKIA_SK_DATA_TABLE_H
