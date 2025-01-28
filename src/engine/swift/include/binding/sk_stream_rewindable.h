//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_STREAM_REWINDABLE_H
#define RAIA_SKIA_SK_STREAM_REWINDABLE_H

#ifdef __cplusplus
extern "C" {
#endif

void SkStreamRewindable_delete(void *stream_rewindable); // (SkStreamRewindable *stream_rewindable)
bool SkStreamRewindable_rewind(void *stream_rewindable); // (SkStreamRewindable *stream_rewindable) -> bool
int SkStreamRewindable_duplicate(void *stream_rewindable); // (SkStreamRewindable *stream_rewindable) -> sk_stream_rewindable_t
unsigned long SkStreamRewindable_read(void *stream_rewindable, void *buffer, unsigned long size); // (SkStreamRewindable *stream_rewindable, void *buffer, size_t size) -> size_t
unsigned long SkStreamRewindable_skip(void *stream_rewindable, unsigned long size); // (SkStreamRewindable *stream_rewindable, size_t size) -> size_t
unsigned long SkStreamRewindable_peek(void *stream_rewindable, void *buffer, unsigned long size); // (SkStreamRewindable *stream_rewindable, void *buffer, size_t size) -> size_t
bool SkStreamRewindable_isAtEnd(void *stream_rewindable); // (SkStreamRewindable *stream_rewindable) -> bool
bool SkStreamRewindable_readS8(void *stream_rewindable, void *i); // (SkStreamRewindable *stream_rewindable, int8_t *i) -> bool
bool SkStreamRewindable_readS16(void *stream_rewindable, void *i); // (SkStreamRewindable *stream_rewindable, int16_t *i) -> bool
bool SkStreamRewindable_readS32(void *stream_rewindable, void *i); // (SkStreamRewindable *stream_rewindable, int32_t *i) -> bool
bool SkStreamRewindable_readU8(void *stream_rewindable, void *i); // (SkStreamRewindable *stream_rewindable, uint8_t *i) -> bool
bool SkStreamRewindable_readU16(void *stream_rewindable, void *i); // (SkStreamRewindable *stream_rewindable, uint16_t *i) -> bool
bool SkStreamRewindable_readU32(void *stream_rewindable, void *i); // (SkStreamRewindable *stream_rewindable, uint32_t *i) -> bool
bool SkStreamRewindable_readBool(void *stream_rewindable, void *b); // (SkStreamRewindable *stream_rewindable, bool *b) -> bool
bool SkStreamRewindable_readScalar(void *stream_rewindable, void *v); // (SkStreamRewindable *stream_rewindable, SkScalar *v) -> bool
bool SkStreamRewindable_readPackedUInt(void *stream_rewindable, void *size); // (SkStreamRewindable *stream_rewindable, size_t *size) -> bool
int SkStreamRewindable_fork(void *stream_rewindable); // (SkStreamRewindable *stream_rewindable) -> sk_stream_t
bool SkStreamRewindable_hasPosition(void *stream_rewindable); // (SkStreamRewindable *stream_rewindable) -> bool
unsigned long SkStreamRewindable_getPosition(void *stream_rewindable); // (SkStreamRewindable *stream_rewindable) -> size_t
bool SkStreamRewindable_seek(void *stream_rewindable, unsigned long size); // (SkStreamRewindable *stream_rewindable, size_t size) -> bool
bool SkStreamRewindable_move(void *stream_rewindable, long i); // (SkStreamRewindable *stream_rewindable, long i) -> bool
bool SkStreamRewindable_hasLength(void *stream_rewindable); // (SkStreamRewindable *stream_rewindable) -> bool
unsigned long SkStreamRewindable_getLength(void *stream_rewindable); // (SkStreamRewindable *stream_rewindable) -> size_t
const void *SkStreamRewindable_getMemoryBase(void *stream_rewindable); // (SkStreamRewindable *stream_rewindable) -> const void *

// static

int SkStreamRewindable_MakeFromFile(const char path[]); // (const char path[]) -> sk_stream_asset_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_STREAM_REWINDABLE_H
