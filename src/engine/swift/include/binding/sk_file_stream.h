//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FILE_STREAM_H
#define RAIA_SKIA_SK_FILE_STREAM_H

#ifdef __cplusplus
extern "C" {
#endif

void *SkFILEStream_new(const char path[]); // (const char path[]) -> SkFILEStream *
void *SkFILEStream_new_2(void *file); // (FILE *file) -> SkFILEStream *
void *SkFILEStream_new_3(void *file, unsigned long size); // (FILE *file, size_t size) -> SkFILEStream *
void SkFILEStream_delete(void *file_stream); // (SkFILEStream *file_stream)
bool SkFILEStream_isValid(void *file_stream); // (SkFILEStream *file_stream) -> bool
void SkFILEStream_close(void *file_stream); // (SkFILEStream *file_stream)
unsigned long SkFILEStream_read(void *file_stream, void *buffer, unsigned long size); // (SkFILEStream *file_stream, void *buffer, size_t size) -> size_t
bool SkFILEStream_isAtEnd(void *file_stream); // (SkFILEStream *file_stream) -> bool
bool SkFILEStream_rewind(void *file_stream); // (SkFILEStream *file_stream) -> bool
int SkFILEStream_duplicate(void *file_stream); // (SkFILEStream *file_stream) -> sk_stream_asset_t
unsigned long SkFILEStream_getPosition(void *file_stream); // (SkFILEStream *file_stream) -> size_t
bool SkFILEStream_seek(void *file_stream, unsigned long position); // (SkFILEStream *file_stream, size_t position) -> bool
bool SkFILEStream_move(void *file_stream, long offset); // (SkFILEStream *file_stream, long offset) -> bool
int SkFILEStream_fork(void *file_stream); // (SkFILEStream *file_stream) -> sk_stream_asset_t
unsigned long SkFILEStream_getLength(void *file_stream); // (SkFILEStream *file_stream) -> size_t
bool SkFILEStream_hasLength(void *file_stream); // (SkFILEStream *file_stream) -> bool
bool SkFILEStream_hasPosition(void *file_stream); // (SkFILEStream *file_stream) -> bool
unsigned long SkFILEStream_skip(void *file_stream, unsigned long size); // (SkFILEStream *file_stream, size_t size) -> size_t
unsigned long SkFILEStream_peek(void *file_stream, void *ptr, unsigned long size); // (SkFILEStream *file_stream, void *ptr, size_t size) -> size_t
bool SkFILEStream_readS8(void *file_stream, void *i); // (SkFILEStream *file_stream, int8_t *i) -> bool
bool SkFILEStream_readS16(void *file_stream, void *i); // (SkFILEStream *file_stream, int16_t *i) -> bool
bool SkFILEStream_readS32(void *file_stream, void *i); // (SkFILEStream *file_stream, int32_t *i) -> bool
bool SkFILEStream_readU8(void *file_stream, void *i); // (SkFILEStream *file_stream, uint8_t *i) -> bool
bool SkFILEStream_readU16(void *file_stream, void *i); // (SkFILEStream *file_stream, uint16_t *i) -> bool
bool SkFILEStream_readU32(void *file_stream, void *i); // (SkFILEStream *file_stream, uint32_t *i) -> bool
bool SkFILEStream_readBool(void *file_stream, void *b); // (SkFILEStream *file_stream, bool *b) -> bool
bool SkFILEStream_readScalar(void *file_stream, void *scalar); // (SkFILEStream *file_stream, SkScalar *scalar) -> bool
bool SkFILEStream_readPackedUInt(void *file_stream, void *size); // (SkFILEStream *file_stream, size_t *size) -> bool
const void * SkFILEStream_getMemoryBase(void *file_stream); // (SkFILEStream *file_stream) -> const void *

// static

int SkFILEStream_Make(const char path[]); // (const char path[]) -> sk_file_stream_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_FILE_STREAM_H
