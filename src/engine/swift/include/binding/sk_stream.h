//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_STREAM_H
#define RAIA_SKIA_SK_STREAM_H

#include "include/core/SkStream.h"
#include "../static/static_sk_stream.h"
#include "../static/static_sk_stream_asset.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkStream_delete(SkStream *stream);
RAIA_API size_t SkStream_read(SkStream *stream, void *buffer, size_t size);
RAIA_API size_t SkStream_skip(SkStream *stream, size_t size);
RAIA_API size_t SkStream_peek(SkStream *stream, void *buffer, size_t size);
RAIA_API bool SkStream_isAtEnd(SkStream *stream);
RAIA_API bool SkStream_readS8(SkStream *stream, int8_t *i);
RAIA_API bool SkStream_readS16(SkStream *stream, int16_t *i);
RAIA_API bool SkStream_readS32(SkStream *stream, int32_t *i);
RAIA_API bool SkStream_readU8(SkStream *stream, uint8_t *i);
RAIA_API bool SkStream_readU16(SkStream *stream, uint16_t *i);
RAIA_API bool SkStream_readU32(SkStream *stream, uint32_t *i);
RAIA_API bool SkStream_readBool(SkStream *stream, bool *b);
RAIA_API bool SkStream_readScalar(SkStream *stream, SkScalar *v);
RAIA_API bool SkStream_readPackedUInt(SkStream *stream, size_t *size);
RAIA_API bool SkStream_rewind(SkStream *stream);
RAIA_API sk_stream_t SkStream_duplicate(SkStream *stream);
RAIA_API sk_stream_t SkStream_fork(SkStream *stream);
RAIA_API bool SkStream_hasPosition(SkStream *stream);
RAIA_API size_t SkStream_getPosition(SkStream *stream);
RAIA_API bool SkStream_seek(SkStream *stream, size_t size);
RAIA_API bool SkStream_move(SkStream *stream, long i);
RAIA_API bool SkStream_hasLength(SkStream *stream);
RAIA_API size_t SkStream_getLength(SkStream *stream);
RAIA_API const void * SkStream_getMemoryBase(SkStream *stream);
// static
RAIA_API sk_stream_asset_t SkStream_MakeFromFile(const char path[]);
}

#endif //RAIA_SKIA_SK_STREAM_H
