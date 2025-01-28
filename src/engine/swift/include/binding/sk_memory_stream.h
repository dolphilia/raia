//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_MEMORY_STREAM_H
#define RAIA_SKIA_SK_MEMORY_STREAM_H

#ifdef __cplusplus
extern "C" {
#endif

void *SkMemoryStream_new(); // () -> SkMemoryStream *
void *SkMemoryStream_new_2(unsigned long length); // (size_t length) -> SkMemoryStream *
void *SkMemoryStream_new_3(const void *data, unsigned long length, bool copyData); // (const void *data, size_t length, bool copyData) -> SkMemoryStream *
void *SkMemoryStream_new_4(int data); // (sk_data_t data) -> SkMemoryStream *
void SkMemoryStream_delete(void *memoryStream); // (SkMemoryStream *memoryStream)
void SkMemoryStream_setMemory(void *memory_stream, const void *data, unsigned long length, bool copyData); // (SkMemoryStream *memory_stream, const void *data, size_t length, bool copyData)
void SkMemoryStream_setMemoryOwned(void *memory_stream, const void *data, unsigned long length); // (SkMemoryStream *memory_stream, const void *data, size_t length)
int SkMemoryStream_asData(void *memory_stream); // (SkMemoryStream *memory_stream) -> sk_data_t
void SkMemoryStream_setData(void *memory_stream, int data); // (SkMemoryStream *memory_stream, sk_data_t data)
void SkMemoryStream_skipToAlign4(void *memory_stream); // (SkMemoryStream *memory_stream)
const void * SkMemoryStream_getAtPos(void *memory_stream); // (SkMemoryStream *memory_stream) -> const void *
unsigned long SkMemoryStream_read(void *memory_stream, void *buffer, unsigned long size); // (SkMemoryStream *memory_stream, void *buffer, size_t size) -> size_t
bool SkMemoryStream_isAtEnd(void *memory_stream); // (SkMemoryStream *memory_stream) -> bool
unsigned long SkMemoryStream_peek(void *memory_stream, void *buffer, unsigned long size); // (SkMemoryStream *memory_stream, void *buffer, size_t size) -> size_t
bool SkMemoryStream_rewind(void *memory_stream); // (SkMemoryStream *memory_stream) -> bool
int SkMemoryStream_duplicate(void *memory_stream); // (SkMemoryStream *memory_stream) -> sk_memory_stream_t
unsigned long SkMemoryStream_getPosition(void *memory_stream); // (SkMemoryStream *memory_stream) -> size_t
bool SkMemoryStream_seek(void *memory_stream, unsigned long position); // (SkMemoryStream *memory_stream, size_t position) -> bool
bool SkMemoryStream_move(void *memory_stream, long offset); // (SkMemoryStream *memory_stream, long offset) -> bool
int SkMemoryStream_fork(void *memory_stream); // (SkMemoryStream *memory_stream) -> sk_memory_stream_t
unsigned long SkMemoryStream_getLength(void *memory_stream); // (SkMemoryStream *memory_stream) -> size_t
const void * SkMemoryStream_getMemoryBase(void *memory_stream); // (SkMemoryStream *memory_stream) -> const void *
bool SkMemoryStream_hasLength(void *memory_stream); // (SkMemoryStream *memory_stream) -> bool
bool SkMemoryStream_hasPosition(void *memory_stream); // (SkMemoryStream *memory_stream) -> bool
unsigned long SkMemoryStream_skip(void *memory_stream, unsigned long size); // (SkMemoryStream *memory_stream, size_t size) -> size_t
bool SkMemoryStream_readS8(void *memory_stream, void *i); // (SkMemoryStream *memory_stream, int8_t *i) -> bool
bool SkMemoryStream_readS16(void *memory_stream, void *i); // (SkMemoryStream *memory_stream, int16_t *i) -> bool
bool SkMemoryStream_readS32(void *memory_stream, void *i); // (SkMemoryStream *memory_stream, int32_t *i) -> bool
bool SkMemoryStream_readU8(void *memory_stream, void *i); // (SkMemoryStream *memory_stream, uint8_t *i) -> bool
bool SkMemoryStream_readU16(void *memory_stream, void *i); // (SkMemoryStream *memory_stream, uint16_t *i) -> bool
bool SkMemoryStream_readU32(void *memory_stream, void *i); // (SkMemoryStream *memory_stream, uint32_t *i) -> bool
bool SkMemoryStream_readBool(void *memory_stream, void *b); // (SkMemoryStream *memory_stream, bool *b) -> bool
bool SkMemoryStream_readScalar(void *memory_stream, void *v); // (SkMemoryStream *memory_stream, SkScalar *v) -> bool
bool SkMemoryStream_readPackedUInt(void *memory_stream, void *size); // (SkMemoryStream *memory_stream, size_t *size) -> bool

// static

int SkMemoryStream_MakeCopy(const void *data, unsigned long length); // (const void *data, size_t length) -> sk_memory_stream_t
int SkMemoryStream_MakeDirect(const void *data, unsigned long length); // (const void *data, size_t length) -> sk_memory_stream_t
int SkMemoryStream_Make(int data); // (sk_data_t data) -> sk_memory_stream_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_MEMORY_STREAM_H
