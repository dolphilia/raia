//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FILE_STREAM_H
#define RAIA_SKIA_SK_FILE_STREAM_H

#include "include/core/SkStream.h"
#include "../static/static_sk_file_stream.h"
#include "../static/static_sk_stream_asset.h"
#include "export_api.h"

extern "C" {
SkFILEStream *SkFILEStream_new(const char path[]);
SkFILEStream *SkFILEStream_new_2(FILE *file);
SkFILEStream *SkFILEStream_new_3(FILE *file, size_t size);
void SkFILEStream_delete(SkFILEStream *file_stream);
bool SkFILEStream_isValid(SkFILEStream *file_stream);
void SkFILEStream_close(SkFILEStream *file_stream);
size_t SkFILEStream_read(SkFILEStream *file_stream, void *buffer, size_t size);
bool SkFILEStream_isAtEnd(SkFILEStream *file_stream);
bool SkFILEStream_rewind(SkFILEStream *file_stream);
sk_stream_asset_t SkFILEStream_duplicate(SkFILEStream *file_stream);
size_t SkFILEStream_getPosition(SkFILEStream *file_stream);
bool SkFILEStream_seek(SkFILEStream *file_stream, size_t position);
bool SkFILEStream_move(SkFILEStream *file_stream, long offset);
sk_stream_asset_t SkFILEStream_fork(SkFILEStream *file_stream);
size_t SkFILEStream_getLength(SkFILEStream *file_stream);
bool SkFILEStream_hasLength(SkFILEStream *file_stream);
bool SkFILEStream_hasPosition(SkFILEStream *file_stream);
size_t SkFILEStream_skip(SkFILEStream *file_stream, size_t size);
size_t SkFILEStream_peek(SkFILEStream *file_stream, void *ptr, size_t size);
bool SkFILEStream_readS8(SkFILEStream *file_stream, int8_t *i);
bool SkFILEStream_readS16(SkFILEStream *file_stream, int16_t *i);
bool SkFILEStream_readS32(SkFILEStream *file_stream, int32_t *i);
bool SkFILEStream_readU8(SkFILEStream *file_stream, uint8_t *i);
bool SkFILEStream_readU16(SkFILEStream *file_stream, uint16_t *i);
bool SkFILEStream_readU32(SkFILEStream *file_stream, uint32_t *i);
bool SkFILEStream_readBool(SkFILEStream *file_stream, bool *b);
bool SkFILEStream_readScalar(SkFILEStream *file_stream, SkScalar *scalar);
bool SkFILEStream_readPackedUInt(SkFILEStream *file_stream, size_t *size);
const void * SkFILEStream_getMemoryBase(SkFILEStream *file_stream);
// static
sk_file_stream_t SkFILEStream_Make(const char path[]);
}

#endif //RAIA_SKIA_SK_FILE_STREAM_H
