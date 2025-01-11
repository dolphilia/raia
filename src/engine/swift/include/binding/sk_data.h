//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_DATA_H
#define RAIA_SKIA_SK_DATA_H

#include "include/core/SkData.h"
#include "../static/static_sk_data.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkData_delete(SkData *sk_data);
RAIA_API size_t SkData_size(SkData *sk_data);
RAIA_API bool SkData_isEmpty(SkData *sk_data);
RAIA_API const void * SkData_data(SkData *sk_data);
RAIA_API const uint8_t * SkData_bytes(SkData *sk_data);
RAIA_API void * SkData_writable_data(SkData *sk_data);
RAIA_API size_t SkData_copyRange(SkData *sk_data, size_t offset, size_t length, void *buffer);
RAIA_API bool SkData_equals(SkData *sk_data, const SkData *other);
RAIA_API bool SkData_unique(SkData *sk_data);
RAIA_API void SkData_ref(SkData *sk_data);
RAIA_API void SkData_unref(SkData *sk_data);
RAIA_API void SkData_deref(SkData *sk_data);
RAIA_API bool SkData_refCntGreaterThan(SkData *sk_data, int32_t threadIsolatedTestCnt);
// static
RAIA_API sk_data_t SkData_MakeWithCopy(const void *data, size_t length);
RAIA_API sk_data_t SkData_MakeUninitialized(size_t length);
RAIA_API sk_data_t SkData_MakeZeroInitialized(size_t length);
RAIA_API sk_data_t SkData_MakeWithCString(const char cstr[]);
RAIA_API sk_data_t SkData_MakeWithProc(const void *ptr, size_t length, SkData::ReleaseProc proc, void *ctx);
RAIA_API sk_data_t SkData_MakeWithoutCopy(const void *data, size_t length);
RAIA_API sk_data_t SkData_MakeFromMalloc(const void *data, size_t length);
RAIA_API sk_data_t SkData_MakeFromFileName(const char path[]);
RAIA_API sk_data_t SkData_MakeFromFILE(FILE *f);
RAIA_API sk_data_t SkData_MakeFromFD(int fd);
RAIA_API sk_data_t SkData_MakeFromStream(SkStream *stream, size_t size);
RAIA_API sk_data_t SkData_MakeSubset(const SkData *src, size_t offset, size_t length);
RAIA_API sk_data_t SkData_MakeEmpty();
}

#endif //RAIA_SKIA_SK_DATA_H
