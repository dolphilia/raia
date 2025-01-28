//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_DATA_H
#define RAIA_SKIA_SK_DATA_H

#ifdef __cplusplus
extern "C" {
#endif

void SkData_delete(void *sk_data); // (SkData *sk_data)
unsigned long SkData_size(void *sk_data); // (SkData *sk_data) -> size_t
bool SkData_isEmpty(void *sk_data); // (SkData *sk_data) -> bool
const void * SkData_data(void *sk_data); // (SkData *sk_data) -> const void *
const unsigned char * SkData_bytes(void *sk_data); // (SkData *sk_data) -> const uint8_t *
void * SkData_writable_data(void *sk_data); // (SkData *sk_data) -> void *
unsigned long SkData_copyRange(void *sk_data, unsigned long offset, unsigned long length, void *buffer); // (SkData *sk_data, size_t offset, size_t length, void *buffer) -> size_t
bool SkData_equals(void *sk_data, const void *other); // (SkData *sk_data, const SkData *other) -> bool
bool SkData_unique(void *sk_data); // (SkData *sk_data) -> bool
void SkData_ref(void *sk_data); // (SkData *sk_data)
void SkData_unref(void *sk_data); // (SkData *sk_data)
void SkData_deref(void *sk_data); // (SkData *sk_data)
bool SkData_refCntGreaterThan(void *sk_data, unsigned int threadIsolatedTestCnt); // (SkData *sk_data, int32_t threadIsolatedTestCnt) -> bool

// static

int SkData_MakeWithCopy(const void *data, unsigned long length); // (const void *data, size_t length) -> sk_data_t
int SkData_MakeUninitialized(unsigned long length); // (size_t length) -> sk_data_t
int SkData_MakeZeroInitialized(unsigned long length); // (size_t length) -> sk_data_t
int SkData_MakeWithCString(const char cstr[]); // (const char cstr[]) -> sk_data_t
int SkData_MakeWithProc(const void *ptr, unsigned long length, void(*proc)(const void *ptr, void *context), void *ctx); // (const void *ptr, size_t length, SkData::ReleaseProc proc, void *ctx) -> sk_data_t
int SkData_MakeWithoutCopy(const void *data, unsigned long length); // (const void *data, size_t length) -> sk_data_t
int SkData_MakeFromMalloc(const void *data, unsigned long length); // (const void *data, size_t length) -> sk_data_t
int SkData_MakeFromFileName(const char path[]); // (const char path[]) -> sk_data_t
int SkData_MakeFromFILE(void *f); // (FILE *f) -> sk_data_t
int SkData_MakeFromFD(int fd); // (int fd) -> sk_data_t
int SkData_MakeFromStream(void *stream, unsigned long size); // (SkStream *stream, size_t size) -> sk_data_t
int SkData_MakeSubset(const void *src, unsigned long offset, unsigned long length); // (const SkData *src, size_t offset, size_t length) -> sk_data_t
int SkData_MakeEmpty(); // () -> sk_data_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_DATA_H
