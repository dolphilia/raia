//
// Created by dolphilia on 2024/01/08.
//

#include "sk_data_table.h"

extern "C" {

bool SkDataTable_isEmpty(SkDataTable *data_table) {
    return data_table->isEmpty();
}

int SkDataTable_count(SkDataTable *data_table) {
    return data_table->count();
}

size_t SkDataTable_atSize(SkDataTable *data_table, int index) {
    return data_table->atSize(index);
}

const void * SkDataTable_at(SkDataTable *data_table, int index, size_t *size) {
    return data_table->at(index, size);
}

// template<typename T>
// const T * SkDataTable_atT(int index, size_t *size=nullptr) const

const char * SkDataTable_atStr(SkDataTable *data_table, int index) {
    return data_table->atStr(index);
}

bool SkDataTable_unique(SkDataTable *data_table) {
    return data_table->unique();
}

void SkDataTable_ref(SkDataTable *data_table) {
    data_table->ref();
}

void SkDataTable_unref(SkDataTable *data_table) {
    data_table->unref();
}

// static

void SkDataTable_MakeEmpty(int sk_data_table_key_out) {
    static_sk_data_table_set(sk_data_table_key_out, SkDataTable::MakeEmpty());
}

void SkDataTable_MakeCopyArrays(int sk_data_table_key_out, const void *const *ptrs, const size_t sizes[], int count) {
    static_sk_data_table_set(sk_data_table_key_out, SkDataTable::MakeCopyArrays(ptrs, sizes, count));
}

void SkDataTable_MakeCopyArray(int sk_data_table_key_out, const void *array, size_t elemSize, int count) {
    static_sk_data_table_set(sk_data_table_key_out, SkDataTable::MakeCopyArray(array, elemSize, count));
}

void SkDataTable_MakeArrayProc(int sk_data_table_key_out, const void *array, size_t elemSize, int count, SkDataTable::FreeProc proc, void *context) {
    static_sk_data_table_set(sk_data_table_key_out, SkDataTable::MakeArrayProc(array, elemSize, count, proc, context));
}

}