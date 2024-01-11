//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_DATA_H
#define RAIA_SKIA_SK_DATA_H

#include "include/core/SkData.h"
#include "../static/static_sk_data.h"

extern "C" {
size_t SkData_size(SkData *sk_data);
bool SkData_isEmpty(SkData *sk_data);
const void * SkData_data(SkData *sk_data);
const uint8_t * SkData_bytes(SkData *sk_data);
void * SkData_writable_data(SkData *sk_data);
size_t SkData_copyRange(SkData *sk_data, size_t offset, size_t length, void *buffer);
bool SkData_equals(SkData *sk_data, const SkData *other);
bool SkData_unique(SkData *sk_data);
void SkData_ref(SkData *sk_data);
void SkData_unref(SkData *sk_data);
void SkData_deref(SkData *sk_data);
bool SkData_refCntGreaterThan(SkData *sk_data, int32_t threadIsolatedTestCnt);
// static
void SkData_MakeWithCopy(const char *sk_data_key_out, const void *data, size_t length);
void SkData_MakeUninitialized(const char *sk_data_key_out, size_t length);
void SkData_MakeZeroInitialized(const char *sk_data_key_out, size_t length);
void SkData_MakeWithCString(const char *sk_data_key_out, const char cstr[]);
void SkData_MakeWithProc(const char *sk_data_key_out, const void *ptr, size_t length, SkData::ReleaseProc proc, void *ctx);
void SkData_MakeWithoutCopy(const char *sk_data_key_out, const void *data, size_t length);
void SkData_MakeFromMalloc(const char *sk_data_key_out, const void *data, size_t length);
void SkData_MakeFromFileName(const char *sk_data_key_out, const char path[]);
void SkData_MakeFromFILE(const char *sk_data_key_out, FILE *f);
void SkData_MakeFromFD(const char *sk_data_key_out, int fd);
void SkData_MakeFromStream(const char *sk_data_key_out, SkStream * stream, size_t size);
void SkData_MakeSubset(const char *sk_data_key_out, const SkData *src, size_t offset, size_t length);
void SkData_MakeEmpty(const char *sk_data_key_out);
}

#endif //RAIA_SKIA_SK_DATA_H
