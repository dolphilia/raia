//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_STREAM_H
#define RAIA_SKIA_SK_STREAM_H

#ifdef __cplusplus
extern "C" {
#endif

void SkStream_delete(void *stream); // (SkStream *stream)
unsigned long SkStream_read(void *stream, void *buffer, unsigned long size); // (SkStream *stream, void *buffer, size_t size) -> size_t
unsigned long SkStream_skip(void *stream, unsigned long size); // (SkStream *stream, size_t size) -> size_t
unsigned long SkStream_peek(void *stream, void *buffer, unsigned long size); // (SkStream *stream, void *buffer, size_t size) -> size_t
bool SkStream_isAtEnd(void *stream); // (SkStream *stream) -> bool
bool SkStream_readS8(void *stream, void *i); // (SkStream *stream, int8_t *i) -> bool
bool SkStream_readS16(void *stream, void *i); // (SkStream *stream, int16_t *i) -> bool
bool SkStream_readS32(void *stream, void *i); // (SkStream *stream, int32_t *i) -> bool
bool SkStream_readU8(void *stream, void *i); // (SkStream *stream, uint8_t *i) -> bool
bool SkStream_readU16(void *stream, void *i); // (SkStream *stream, uint16_t *i) -> bool
bool SkStream_readU32(void *stream, void *i); // (SkStream *stream, uint32_t *i) -> bool
bool SkStream_readBool(void *stream, void *b); // (SkStream *stream, bool *b) -> bool
bool SkStream_readScalar(void *stream, void *v); // (SkStream *stream, SkScalar *v) -> bool
bool SkStream_readPackedUInt(void *stream, void *size); // (SkStream *stream, size_t *size) -> bool
bool SkStream_rewind(void *stream); // (SkStream *stream) -> bool
int SkStream_duplicate(void *stream); // (SkStream *stream) -> sk_stream_t
int SkStream_fork(void *stream); // (SkStream *stream) -> sk_stream_t
bool SkStream_hasPosition(void *stream); // (SkStream *stream) -> bool
unsigned long SkStream_getPosition(void *stream); // (SkStream *stream) -> size_t
bool SkStream_seek(void *stream, unsigned long size); // (SkStream *stream, size_t size) -> bool
bool SkStream_move(void *stream, long i); // (SkStream *stream, long i) -> bool
bool SkStream_hasLength(void *stream); // (SkStream *stream) -> bool
unsigned long SkStream_getLength(void *stream); // (SkStream *stream) -> size_t
const void * SkStream_getMemoryBase(void *stream); // (SkStream *stream) -> const void *

// static

int SkStream_MakeFromFile(const char path[]); // (const char path[]) -> sk_stream_asset_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_STREAM_H
