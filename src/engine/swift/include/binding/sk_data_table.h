//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_DATA_TABLE_H
#define RAIA_SKIA_SK_DATA_TABLE_H

#include "include/core/SkDataTable.h"
#include "../static/static_sk_data_table.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkDataTable_delete(SkDataTable *data_table);
RAIA_API bool SkDataTable_isEmpty(SkDataTable *data_table);
RAIA_API int SkDataTable_count(SkDataTable *data_table);
RAIA_API size_t SkDataTable_atSize(SkDataTable *data_table, int index);
RAIA_API const void * SkDataTable_at(SkDataTable *data_table, int index, size_t *size);
RAIA_API const char * SkDataTable_atStr(SkDataTable *data_table, int index);
RAIA_API bool SkDataTable_unique(SkDataTable *data_table);
RAIA_API void SkDataTable_ref(SkDataTable *data_table);
RAIA_API void SkDataTable_unref(SkDataTable *data_table);
// static
RAIA_API sk_data_table_t SkDataTable_MakeEmpty();
RAIA_API sk_data_table_t SkDataTable_MakeCopyArrays(const void *const *ptrs, const size_t sizes[], int count);
RAIA_API sk_data_table_t SkDataTable_MakeCopyArray(const void *array, size_t elemSize, int count);
RAIA_API sk_data_table_t SkDataTable_MakeArrayProc(const void *array, size_t elemSize, int count, SkDataTable::FreeProc proc, void *context);
}

#endif //RAIA_SKIA_SK_DATA_TABLE_H
