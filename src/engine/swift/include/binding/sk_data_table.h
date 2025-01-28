//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_DATA_TABLE_H
#define RAIA_SKIA_SK_DATA_TABLE_H

#ifdef __cplusplus
extern "C" {
#endif

void SkDataTable_delete(void *data_table); // (SkDataTable *data_table)
bool SkDataTable_isEmpty(void *data_table); // (SkDataTable *data_table) -> bool
int SkDataTable_count(void *data_table); // (SkDataTable *data_table) -> int
unsigned long SkDataTable_atSize(void *data_table, int index); // (SkDataTable *data_table, int index) -> size_t
const void * SkDataTable_at(void *data_table, int index, void *size); // (SkDataTable *data_table, int index, size_t *size) -> const void *
const char * SkDataTable_atStr(void *data_table, int index); // (SkDataTable *data_table, int index) -> const char *
bool SkDataTable_unique(void *data_table); // (SkDataTable *data_table) -> bool
void SkDataTable_ref(void *data_table); // (SkDataTable *data_table)
void SkDataTable_unref(void *data_table); // (SkDataTable *data_table)

// static

int SkDataTable_MakeEmpty(); // () -> sk_data_table_t
int SkDataTable_MakeCopyArrays(const void * const * ptrs, const void * sizes, int count); // (const void *const *ptrs, const size_t sizes[], int count) -> sk_data_table_t
int SkDataTable_MakeCopyArray(const void *array, unsigned long elemSize, int count); // (const void *array, size_t elemSize, int count) -> sk_data_table_t
int SkDataTable_MakeArrayProc(const void *array, unsigned long elemSize, int count, void (*proc)(void*), void *context); // (const void *array, size_t elemSize, int count, SkDataTable::FreeProc proc, void *context) -> sk_data_table_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_DATA_TABLE_H
