//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_STREAM_MEMORY_H
#define RAIA_SKIA_SK_STREAM_MEMORY_H

#ifdef __cplusplus
extern "C" {
#endif

void SkStreamMemory_delete(void *stream_memory); // (SkStreamMemory *stream_memory)
const void *SkStreamMemory_getMemoryBase(void *stream_memory); // (SkStreamMemory *stream_memory) -> const void *
int SkStreamMemory_duplicate(void *stream_memory); // (SkStreamMemory *stream_memory) -> sk_stream_memory_t
int SkStreamMemory_fork(void *stream_memory); // (SkStreamMemory *stream_memory) -> sk_stream_memory_t
bool SkStreamMemory_hasLength(void *stream_memory); // (SkStreamMemory *stream_memory) -> bool
unsigned long SkStreamMemory_getLength(void *stream_memory); // (SkStreamMemory *stream_memory) -> size_t
bool SkStreamMemory_hasPosition(void *stream_memory); // (SkStreamMemory *stream_memory) -> bool
unsigned long SkStreamMemory_getPosition(void *stream_memory); // (SkStreamMemory *stream_memory) -> size_t
bool SkStreamMemory_seek(void *stream_memory, unsigned long position); // (SkStreamMemory *stream_memory, size_t position) -> bool
bool SkStreamMemory_move(void *stream_memory, long offset); // (SkStreamMemory *stream_memory, long offset) -> bool
bool SkStreamMemory_rewind(void *stream_memory); // (SkStreamMemory *stream_memory) -> bool
unsigned long SkStreamMemory_read(void *stream_memory, void *buffer, unsigned long size); // (SkStreamMemory *stream_memory, void *buffer, size_t size) -> size_t
unsigned long SkStreamMemory_skip(void *stream_memory, unsigned long size); // (SkStreamMemory *stream_memory, size_t size) -> size_t
unsigned long SkStreamMemory_peek(void *stream_memory, void *buffer, unsigned long size); // (SkStreamMemory *stream_memory, void *buffer, size_t size) -> size_t
bool SkStreamMemory_isAtEnd(void *stream_memory); // (SkStreamMemory *stream_memory) -> bool
bool SkStreamMemory_readS8(void *stream_memory, void *i); // (SkStreamMemory *stream_memory, int8_t *i) -> bool
bool SkStreamMemory_readS16(void *stream_memory, void *i); // (SkStreamMemory *stream_memory, int16_t *i) -> bool
bool SkStreamMemory_readS32(void *stream_memory, void *i); // (SkStreamMemory *stream_memory, int32_t *i) -> bool
bool SkStreamMemory_readU8(void *stream_memory, void *i); // (SkStreamMemory *stream_memory, uint8_t *i) -> bool
bool SkStreamMemory_readU16(void *stream_memory, void *i); // (SkStreamMemory *stream_memory, uint16_t *i) -> bool
bool SkStreamMemory_readU32(void *stream_memory, void *i); // (SkStreamMemory *stream_memory, uint32_t *i) -> bool
bool SkStreamMemory_readBool(void *stream_memory, void *b); // (SkStreamMemory *stream_memory, bool *b) -> bool
bool SkStreamMemory_readScalar(void *stream_memory, void *v); // (SkStreamMemory *stream_memory, SkScalar *v) -> bool
bool SkStreamMemory_readPackedUInt(void *stream_memory, void *size); // (SkStreamMemory *stream_memory, size_t *size) -> bool

// static

int SkStreamMemory_MakeFromFile(const char path[]); // (const char path[]) -> sk_stream_asset_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_STREAM_MEMORY_H
