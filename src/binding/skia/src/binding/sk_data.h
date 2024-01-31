//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_DATA_H
#define RAIA_SKIA_SK_DATA_H

#include "include/core/SkData.h"
#include "../static/static_sk_data.h"

extern "C" {
void SkData_delete(SkData *sk_data);
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
int SkData_MakeWithCopy(const void *data, size_t length);
int SkData_MakeUninitialized(size_t length);
int SkData_MakeZeroInitialized(size_t length);
int SkData_MakeWithCString(const char cstr[]);
int SkData_MakeWithProc(const void *ptr, size_t length, SkData::ReleaseProc proc, void *ctx);
int SkData_MakeWithoutCopy(const void *data, size_t length);
int SkData_MakeFromMalloc(const void *data, size_t length);
int SkData_MakeFromFileName(const char path[]);
int SkData_MakeFromFILE(FILE *f);
int SkData_MakeFromFD(int fd);
int SkData_MakeFromStream(SkStream *stream, size_t size);
int SkData_MakeSubset(const SkData *src, size_t offset, size_t length);
int SkData_MakeEmpty();
}

#endif //RAIA_SKIA_SK_DATA_H
