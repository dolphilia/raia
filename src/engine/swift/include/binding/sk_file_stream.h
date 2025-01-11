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
RAIA_API SkFILEStream *SkFILEStream_new(const char path[]);
RAIA_API SkFILEStream *SkFILEStream_new_2(FILE *file);
RAIA_API SkFILEStream *SkFILEStream_new_3(FILE *file, size_t size);
RAIA_API void SkFILEStream_delete(SkFILEStream *file_stream);
RAIA_API bool SkFILEStream_isValid(SkFILEStream *file_stream);
RAIA_API void SkFILEStream_close(SkFILEStream *file_stream);
RAIA_API size_t SkFILEStream_read(SkFILEStream *file_stream, void *buffer, size_t size);
RAIA_API bool SkFILEStream_isAtEnd(SkFILEStream *file_stream);
RAIA_API bool SkFILEStream_rewind(SkFILEStream *file_stream);
RAIA_API sk_stream_asset_t SkFILEStream_duplicate(SkFILEStream *file_stream);
RAIA_API size_t SkFILEStream_getPosition(SkFILEStream *file_stream);
RAIA_API bool SkFILEStream_seek(SkFILEStream *file_stream, size_t position);
RAIA_API bool SkFILEStream_move(SkFILEStream *file_stream, long offset);
RAIA_API sk_stream_asset_t SkFILEStream_fork(SkFILEStream *file_stream);
RAIA_API size_t SkFILEStream_getLength(SkFILEStream *file_stream);
RAIA_API bool SkFILEStream_hasLength(SkFILEStream *file_stream);
RAIA_API bool SkFILEStream_hasPosition(SkFILEStream *file_stream);
RAIA_API size_t SkFILEStream_skip(SkFILEStream *file_stream, size_t size);
RAIA_API size_t SkFILEStream_peek(SkFILEStream *file_stream, void *ptr, size_t size);
RAIA_API bool SkFILEStream_readS8(SkFILEStream *file_stream, int8_t *i);
RAIA_API bool SkFILEStream_readS16(SkFILEStream *file_stream, int16_t *i);
RAIA_API bool SkFILEStream_readS32(SkFILEStream *file_stream, int32_t *i);
RAIA_API bool SkFILEStream_readU8(SkFILEStream *file_stream, uint8_t *i);
RAIA_API bool SkFILEStream_readU16(SkFILEStream *file_stream, uint16_t *i);
RAIA_API bool SkFILEStream_readU32(SkFILEStream *file_stream, uint32_t *i);
RAIA_API bool SkFILEStream_readBool(SkFILEStream *file_stream, bool *b);
RAIA_API bool SkFILEStream_readScalar(SkFILEStream *file_stream, SkScalar *scalar);
RAIA_API bool SkFILEStream_readPackedUInt(SkFILEStream *file_stream, size_t *size);
RAIA_API const void * SkFILEStream_getMemoryBase(SkFILEStream *file_stream);
// static
RAIA_API sk_file_stream_t SkFILEStream_Make(const char path[]);
}

#endif //RAIA_SKIA_SK_FILE_STREAM_H
