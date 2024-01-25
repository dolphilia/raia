//
// Created by dolphilia on 2024/01/08.
//

#include "sk_data.h"

extern "C" {

size_t SkData_size(SkData *sk_data) {
    return sk_data->size();
}

bool SkData_isEmpty(SkData *sk_data) {
    return sk_data->isEmpty();
}

const void * SkData_data(SkData *sk_data) {
    return sk_data->data();
}

const uint8_t * SkData_bytes(SkData *sk_data) {
    return sk_data->bytes();
}

void * SkData_writable_data(SkData *sk_data) {
    return sk_data->writable_data();
}

size_t SkData_copyRange(SkData *sk_data, size_t offset, size_t length, void *buffer) {
    return sk_data->copyRange(offset, length, buffer);
}

bool SkData_equals(SkData *sk_data, const SkData *other) {
    return sk_data->equals(other);
}

bool SkData_unique(SkData *sk_data) {
    return sk_data->unique();
}

void SkData_ref(SkData *sk_data) {
    return sk_data->ref();
}

void SkData_unref(SkData *sk_data) {
    sk_data->unref();
}

void SkData_deref(SkData *sk_data) {
    sk_data->deref();
}

bool SkData_refCntGreaterThan(SkData *sk_data, int32_t threadIsolatedTestCnt) {
    return sk_data->refCntGreaterThan(threadIsolatedTestCnt);
}

// static

int SkData_MakeWithCopy(const void *data, size_t length) {
    return static_sk_data_make(SkData::MakeWithCopy(data, length));
}

int SkData_MakeUninitialized(size_t length) {
    return static_sk_data_make(SkData::MakeUninitialized(length));
}

int SkData_MakeZeroInitialized(size_t length) {
    return static_sk_data_make(SkData::MakeZeroInitialized(length));
}

int SkData_MakeWithCString(const char cstr[]) {
    return static_sk_data_make(SkData::MakeWithCString(cstr));
}

int SkData_MakeWithProc(const void *ptr, size_t length, SkData::ReleaseProc proc, void *ctx) {
    return static_sk_data_make(SkData::MakeWithProc(ptr, length, proc, ctx));
}

int SkData_MakeWithoutCopy(const void *data, size_t length) {
    return static_sk_data_make(SkData::MakeWithoutCopy(data, length));
}

int SkData_MakeFromMalloc(const void *data, size_t length) {
    return static_sk_data_make(SkData::MakeFromMalloc(data, length));
}

int SkData_MakeFromFileName(const char path[]) {
    return static_sk_data_make(SkData::MakeFromFileName(path));
}

int SkData_MakeFromFILE(FILE *f) {
    return static_sk_data_make(SkData::MakeFromFILE(f));
}

int SkData_MakeFromFD(int fd) {
    return static_sk_data_make(SkData::MakeFromFD(fd));
}

int SkData_MakeFromStream(SkStream *stream, size_t size) {
    return static_sk_data_make(SkData::MakeFromStream(stream, size));
}

int SkData_MakeSubset(const SkData *src, size_t offset, size_t length) {
    return static_sk_data_make(SkData::MakeSubset(src, offset, length));
}

int SkData_MakeEmpty() {
    return static_sk_data_make(SkData::MakeEmpty());
}

}