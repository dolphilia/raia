//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_STREAM_MEMORY_H
#define RAIA_SKIA_SK_STREAM_MEMORY_H

#include "include/core/SkStream.h"
#include "../static/static_sk_stream_memory.h"
#include "../static/static_sk_stream_asset.h"

extern "C" {
void SkStreamMemory_delete(SkStreamMemory *stream_memory);
const void * SkStreamMemory_getMemoryBase(SkStreamMemory *stream_memory);
sk_stream_memory_t SkStreamMemory_duplicate(SkStreamMemory *stream_memory);
sk_stream_memory_t SkStreamMemory_fork(SkStreamMemory *stream_memory);
bool SkStreamMemory_hasLength(SkStreamMemory *stream_memory);
size_t SkStreamMemory_getLength(SkStreamMemory *stream_memory);
bool SkStreamMemory_hasPosition(SkStreamMemory *stream_memory);
size_t SkStreamMemory_getPosition(SkStreamMemory *stream_memory);
bool SkStreamMemory_seek(SkStreamMemory *stream_memory, size_t position);
bool SkStreamMemory_move(SkStreamMemory *stream_memory, long offset);
bool SkStreamMemory_rewind(SkStreamMemory *stream_memory);
size_t SkStreamMemory_read(SkStreamMemory *stream_memory, void *buffer, size_t size);
size_t SkStreamMemory_skip(SkStreamMemory *stream_memory, size_t size);
size_t SkStreamMemory_peek(SkStreamMemory *stream_memory, void *buffer, size_t size);
bool SkStreamMemory_isAtEnd(SkStreamMemory *stream_memory);
bool SkStreamMemory_readS8(SkStreamMemory *stream_memory, int8_t *i);
bool SkStreamMemory_readS16(SkStreamMemory *stream_memory, int16_t *i);
bool SkStreamMemory_readS32(SkStreamMemory *stream_memory, int32_t *i);
bool SkStreamMemory_readU8(SkStreamMemory *stream_memory, uint8_t *i);
bool SkStreamMemory_readU16(SkStreamMemory *stream_memory, uint16_t *i);
bool SkStreamMemory_readU32(SkStreamMemory *stream_memory, uint32_t *i);
bool SkStreamMemory_readBool(SkStreamMemory *stream_memory, bool *b);
bool SkStreamMemory_readScalar(SkStreamMemory *stream_memory, SkScalar *v);
bool SkStreamMemory_readPackedUInt(SkStreamMemory *stream_memory, size_t *size);
// static
sk_stream_asset_t SkStreamMemory_MakeFromFile(const char path[]);
}

#endif //RAIA_SKIA_SK_STREAM_MEMORY_H
