//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_MEMORY_STREAM_H
#define RAIA_SKIA_SK_MEMORY_STREAM_H

#include "include/core/SkStream.h"
#include "../static/static_sk_memory_stream.h"
#include "../static/static_sk_data.h"

extern "C" {
SkMemoryStream *SkMemoryStream_new();
SkMemoryStream *SkMemoryStream_new_2(size_t length);
SkMemoryStream *SkMemoryStream_new_3(const void *data, size_t length, bool copyData);
SkMemoryStream *SkMemoryStream_new_4(sk_data_t data);
void SkMemoryStream_delete(SkMemoryStream *memoryStream);
void SkMemoryStream_setMemory(SkMemoryStream *memory_stream, const void *data, size_t length, bool copyData);
void SkMemoryStream_setMemoryOwned(SkMemoryStream *memory_stream, const void *data, size_t length);
sk_data_t SkMemoryStream_asData(SkMemoryStream *memory_stream);
void SkMemoryStream_setData(SkMemoryStream *memory_stream, sk_data_t data);
void SkMemoryStream_skipToAlign4(SkMemoryStream *memory_stream);
const void * SkMemoryStream_getAtPos(SkMemoryStream *memory_stream);
size_t SkMemoryStream_read(SkMemoryStream *memory_stream, void *buffer, size_t size);
bool SkMemoryStream_isAtEnd(SkMemoryStream *memory_stream);
size_t SkMemoryStream_peek(SkMemoryStream *memory_stream, void *buffer, size_t size);
bool SkMemoryStream_rewind(SkMemoryStream *memory_stream);
sk_memory_stream_t SkMemoryStream_duplicate(SkMemoryStream *memory_stream);
size_t SkMemoryStream_getPosition(SkMemoryStream *memory_stream);
bool SkMemoryStream_seek(SkMemoryStream *memory_stream, size_t position);
bool SkMemoryStream_move(SkMemoryStream *memory_stream, long offset);
sk_memory_stream_t SkMemoryStream_fork(SkMemoryStream *memory_stream);
size_t SkMemoryStream_getLength(SkMemoryStream *memory_stream);
const void * SkMemoryStream_getMemoryBase(SkMemoryStream *memory_stream);
bool SkMemoryStream_hasLength(SkMemoryStream *memory_stream);
bool SkMemoryStream_hasPosition(SkMemoryStream *memory_stream);
size_t SkMemoryStream_skip(SkMemoryStream *memory_stream, size_t size);
bool SkMemoryStream_readS8(SkMemoryStream *memory_stream, int8_t *i);
bool SkMemoryStream_readS16(SkMemoryStream *memory_stream, int16_t *i);
bool SkMemoryStream_readS32(SkMemoryStream *memory_stream, int32_t *i);
bool SkMemoryStream_readU8(SkMemoryStream *memory_stream, uint8_t *i);
bool SkMemoryStream_readU16(SkMemoryStream *memory_stream, uint16_t *i);
bool SkMemoryStream_readU32(SkMemoryStream *memory_stream, uint32_t *i);
bool SkMemoryStream_readBool(SkMemoryStream *memory_stream, bool *b);
bool SkMemoryStream_readScalar(SkMemoryStream *memory_stream, SkScalar *v);
bool SkMemoryStream_readPackedUInt(SkMemoryStream *memory_stream, size_t *size);
// static
sk_memory_stream_t SkMemoryStream_MakeCopy(const void *data, size_t length);
sk_memory_stream_t SkMemoryStream_MakeDirect(const void *data, size_t length);
sk_memory_stream_t SkMemoryStream_Make(sk_data_t data);
}

#endif //RAIA_SKIA_SK_MEMORY_STREAM_H
