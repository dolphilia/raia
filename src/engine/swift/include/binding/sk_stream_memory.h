//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_STREAM_MEMORY_H
#define RAIA_SKIA_SK_STREAM_MEMORY_H

#include "include/core/SkStream.h"
#include "../static/static_sk_stream_memory.h"
#include "../static/static_sk_stream_asset.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkStreamMemory_delete(SkStreamMemory *stream_memory);
RAIA_API const void * SkStreamMemory_getMemoryBase(SkStreamMemory *stream_memory);
RAIA_API sk_stream_memory_t SkStreamMemory_duplicate(SkStreamMemory *stream_memory);
RAIA_API sk_stream_memory_t SkStreamMemory_fork(SkStreamMemory *stream_memory);
RAIA_API bool SkStreamMemory_hasLength(SkStreamMemory *stream_memory);
RAIA_API size_t SkStreamMemory_getLength(SkStreamMemory *stream_memory);
RAIA_API bool SkStreamMemory_hasPosition(SkStreamMemory *stream_memory);
RAIA_API size_t SkStreamMemory_getPosition(SkStreamMemory *stream_memory);
RAIA_API bool SkStreamMemory_seek(SkStreamMemory *stream_memory, size_t position);
RAIA_API bool SkStreamMemory_move(SkStreamMemory *stream_memory, long offset);
RAIA_API bool SkStreamMemory_rewind(SkStreamMemory *stream_memory);
RAIA_API size_t SkStreamMemory_read(SkStreamMemory *stream_memory, void *buffer, size_t size);
RAIA_API size_t SkStreamMemory_skip(SkStreamMemory *stream_memory, size_t size);
RAIA_API size_t SkStreamMemory_peek(SkStreamMemory *stream_memory, void *buffer, size_t size);
RAIA_API bool SkStreamMemory_isAtEnd(SkStreamMemory *stream_memory);
RAIA_API bool SkStreamMemory_readS8(SkStreamMemory *stream_memory, int8_t *i);
RAIA_API bool SkStreamMemory_readS16(SkStreamMemory *stream_memory, int16_t *i);
RAIA_API bool SkStreamMemory_readS32(SkStreamMemory *stream_memory, int32_t *i);
RAIA_API bool SkStreamMemory_readU8(SkStreamMemory *stream_memory, uint8_t *i);
RAIA_API bool SkStreamMemory_readU16(SkStreamMemory *stream_memory, uint16_t *i);
RAIA_API bool SkStreamMemory_readU32(SkStreamMemory *stream_memory, uint32_t *i);
RAIA_API bool SkStreamMemory_readBool(SkStreamMemory *stream_memory, bool *b);
RAIA_API bool SkStreamMemory_readScalar(SkStreamMemory *stream_memory, SkScalar *v);
RAIA_API bool SkStreamMemory_readPackedUInt(SkStreamMemory *stream_memory, size_t *size);
// static
RAIA_API sk_stream_asset_t SkStreamMemory_MakeFromFile(const char path[]);
}

#endif //RAIA_SKIA_SK_STREAM_MEMORY_H
