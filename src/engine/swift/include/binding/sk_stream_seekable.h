//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_STREAM_SEEKABLE_H
#define RAIA_SKIA_SK_STREAM_SEEKABLE_H

#include "include/core/SkStream.h"
#include "../static/static_sk_stream_seekable.h"
#include "../static/static_sk_stream_asset.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkStreamSeekable_delete(SkStreamSeekable *stream_seekable);
RAIA_API sk_stream_seekable_t SkStreamSeekable_duplicate(SkStreamSeekable *stream_seekable);
RAIA_API bool SkStreamSeekable_hasPosition(SkStreamSeekable *stream_seekable);
RAIA_API size_t SkStreamSeekable_getPosition(SkStreamSeekable *stream_seekable);
RAIA_API bool SkStreamSeekable_seek(SkStreamSeekable *stream_seekable, size_t position);
RAIA_API bool SkStreamSeekable_move(SkStreamSeekable *stream_seekable, long offset);
RAIA_API sk_stream_seekable_t SkStreamSeekable_fork(SkStreamSeekable *stream_seekable);
RAIA_API bool SkStreamSeekable_rewind(SkStreamSeekable *stream_seekable);
RAIA_API size_t SkStreamSeekable_read(SkStreamSeekable *stream_seekable, void *buffer, size_t size);
RAIA_API size_t SkStreamSeekable_skip(SkStreamSeekable *stream_seekable, size_t size);
RAIA_API size_t SkStreamSeekable_peek(SkStreamSeekable *stream_seekable, void *buffer, size_t size);
RAIA_API bool SkStreamSeekable_isAtEnd(SkStreamSeekable *stream_seekable);
RAIA_API bool SkStreamSeekable_readS8(SkStreamSeekable *stream_seekable, int8_t *i);
RAIA_API bool SkStreamSeekable_readS16(SkStreamSeekable *stream_seekable, int16_t *i);
RAIA_API bool SkStreamSeekable_readS32(SkStreamSeekable *stream_seekable, int32_t *i);
RAIA_API bool SkStreamSeekable_readU8(SkStreamSeekable *stream_seekable, uint8_t *i);
RAIA_API bool SkStreamSeekable_readU16(SkStreamSeekable *stream_seekable, uint16_t *i);
RAIA_API bool SkStreamSeekable_readU32(SkStreamSeekable *stream_seekable, uint32_t *i);
RAIA_API bool SkStreamSeekable_readBool(SkStreamSeekable *stream_seekable, bool *b);
RAIA_API bool SkStreamSeekable_readScalar(SkStreamSeekable *stream_seekable, SkScalar *v);
RAIA_API bool SkStreamSeekable_readPackedUInt(SkStreamSeekable *stream_seekable, size_t *size);
RAIA_API bool SkStreamSeekable_hasLength(SkStreamSeekable *stream_seekable);
RAIA_API size_t SkStreamSeekable_getLength(SkStreamSeekable *stream_seekable);
RAIA_API const void * SkStreamSeekable_getMemoryBase(SkStreamSeekable *stream_seekable);
// static
RAIA_API sk_stream_asset_t SkStreamSeekable_MakeFromFile(const char path[]);
}

#endif //RAIA_SKIA_SK_STREAM_SEEKABLE_H
