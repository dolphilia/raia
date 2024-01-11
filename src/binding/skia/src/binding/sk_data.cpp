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

void SkData_MakeWithCopy(const char *sk_data_key_out, const void *data, size_t length) {
    static_sk_data_set(sk_data_key_out, SkData::MakeWithCopy(data, length));
}

void SkData_MakeUninitialized(const char *sk_data_key_out, size_t length) {
    static_sk_data_set(sk_data_key_out, SkData::MakeUninitialized(length));
}

void SkData_MakeZeroInitialized(const char *sk_data_key_out, size_t length) {
    static_sk_data_set(sk_data_key_out, SkData::MakeZeroInitialized(length));
}

void SkData_MakeWithCString(const char *sk_data_key_out, const char cstr[]) {
    static_sk_data_set(sk_data_key_out, SkData::MakeWithCString(cstr));
}

void SkData_MakeWithProc(const char *sk_data_key_out, const void *ptr, size_t length, SkData::ReleaseProc proc, void *ctx) {
    static_sk_data_set(sk_data_key_out, SkData::MakeWithProc(ptr, length, proc, ctx));
}

void SkData_MakeWithoutCopy(const char *sk_data_key_out, const void *data, size_t length) {
    static_sk_data_set(sk_data_key_out, SkData::MakeWithoutCopy(data, length));
}

void SkData_MakeFromMalloc(const char *sk_data_key_out, const void *data, size_t length) {
    static_sk_data_set(sk_data_key_out, SkData::MakeFromMalloc(data, length));
}

void SkData_MakeFromFileName(const char *sk_data_key_out, const char path[]) {
    static_sk_data_set(sk_data_key_out, SkData::MakeFromFileName(path));
}

void SkData_MakeFromFILE(const char *sk_data_key_out, FILE *f) {
    static_sk_data_set(sk_data_key_out, SkData::MakeFromFILE(f));
}

void SkData_MakeFromFD(const char *sk_data_key_out, int fd) {
    static_sk_data_set(sk_data_key_out, SkData::MakeFromFD(fd));
}

void SkData_MakeFromStream(const char *sk_data_key_out, SkStream * stream, size_t size) {
    static_sk_data_set(sk_data_key_out, SkData::MakeFromStream(stream, size));
}

void SkData_MakeSubset(const char *sk_data_key_out, const SkData *src, size_t offset, size_t length) {
    static_sk_data_set(sk_data_key_out, SkData::MakeSubset(src, offset, length));
}

void SkData_MakeEmpty(const char *sk_data_key_out) {
    static_sk_data_set(sk_data_key_out, SkData::MakeEmpty());
}

}