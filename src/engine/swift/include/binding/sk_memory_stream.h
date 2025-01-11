//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_MEMORY_STREAM_H
#define RAIA_SKIA_SK_MEMORY_STREAM_H

#include "include/core/SkStream.h"
#include "../static/static_sk_memory_stream.h"
#include "../static/static_sk_data.h"
#include "export_api.h"

extern "C" {
RAIA_API SkMemoryStream *SkMemoryStream_new();
RAIA_API SkMemoryStream *SkMemoryStream_new_2(size_t length);
RAIA_API SkMemoryStream *SkMemoryStream_new_3(const void *data, size_t length, bool copyData);
RAIA_API SkMemoryStream *SkMemoryStream_new_4(sk_data_t data);
RAIA_API void SkMemoryStream_delete(SkMemoryStream *memoryStream);
RAIA_API void SkMemoryStream_setMemory(SkMemoryStream *memory_stream, const void *data, size_t length, bool copyData);
RAIA_API void SkMemoryStream_setMemoryOwned(SkMemoryStream *memory_stream, const void *data, size_t length);
RAIA_API sk_data_t SkMemoryStream_asData(SkMemoryStream *memory_stream);
RAIA_API void SkMemoryStream_setData(SkMemoryStream *memory_stream, sk_data_t data);
RAIA_API void SkMemoryStream_skipToAlign4(SkMemoryStream *memory_stream);
RAIA_API const void * SkMemoryStream_getAtPos(SkMemoryStream *memory_stream);
RAIA_API size_t SkMemoryStream_read(SkMemoryStream *memory_stream, void *buffer, size_t size);
RAIA_API bool SkMemoryStream_isAtEnd(SkMemoryStream *memory_stream);
RAIA_API size_t SkMemoryStream_peek(SkMemoryStream *memory_stream, void *buffer, size_t size);
RAIA_API bool SkMemoryStream_rewind(SkMemoryStream *memory_stream);
RAIA_API sk_memory_stream_t SkMemoryStream_duplicate(SkMemoryStream *memory_stream);
RAIA_API size_t SkMemoryStream_getPosition(SkMemoryStream *memory_stream);
RAIA_API bool SkMemoryStream_seek(SkMemoryStream *memory_stream, size_t position);
RAIA_API bool SkMemoryStream_move(SkMemoryStream *memory_stream, long offset);
RAIA_API sk_memory_stream_t SkMemoryStream_fork(SkMemoryStream *memory_stream);
RAIA_API size_t SkMemoryStream_getLength(SkMemoryStream *memory_stream);
RAIA_API const void * SkMemoryStream_getMemoryBase(SkMemoryStream *memory_stream);
RAIA_API bool SkMemoryStream_hasLength(SkMemoryStream *memory_stream);
RAIA_API bool SkMemoryStream_hasPosition(SkMemoryStream *memory_stream);
RAIA_API size_t SkMemoryStream_skip(SkMemoryStream *memory_stream, size_t size);
RAIA_API bool SkMemoryStream_readS8(SkMemoryStream *memory_stream, int8_t *i);
RAIA_API bool SkMemoryStream_readS16(SkMemoryStream *memory_stream, int16_t *i);
RAIA_API bool SkMemoryStream_readS32(SkMemoryStream *memory_stream, int32_t *i);
RAIA_API bool SkMemoryStream_readU8(SkMemoryStream *memory_stream, uint8_t *i);
RAIA_API bool SkMemoryStream_readU16(SkMemoryStream *memory_stream, uint16_t *i);
RAIA_API bool SkMemoryStream_readU32(SkMemoryStream *memory_stream, uint32_t *i);
RAIA_API bool SkMemoryStream_readBool(SkMemoryStream *memory_stream, bool *b);
RAIA_API bool SkMemoryStream_readScalar(SkMemoryStream *memory_stream, SkScalar *v);
RAIA_API bool SkMemoryStream_readPackedUInt(SkMemoryStream *memory_stream, size_t *size);
// static
RAIA_API sk_memory_stream_t SkMemoryStream_MakeCopy(const void *data, size_t length);
RAIA_API sk_memory_stream_t SkMemoryStream_MakeDirect(const void *data, size_t length);
RAIA_API sk_memory_stream_t SkMemoryStream_Make(sk_data_t data);
}

#endif //RAIA_SKIA_SK_MEMORY_STREAM_H
