//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_STREAM_H
#define RAIA_SKIA_SK_STREAM_H

#include "include/core/SkStream.h"
#include "../static/static_sk_stream.h"
#include "../static/static_sk_stream_asset.h"

extern "C" {
void SkStream_delete(SkStream *stream);
size_t SkStream_read(SkStream *stream, void *buffer, size_t size);
size_t SkStream_skip(SkStream *stream, size_t size);
size_t SkStream_peek(SkStream *stream, void *buffer, size_t size);
bool SkStream_isAtEnd(SkStream *stream);
bool SkStream_readS8(SkStream *stream, int8_t *i);
bool SkStream_readS16(SkStream *stream, int16_t *i);
bool SkStream_readS32(SkStream *stream, int32_t *i);
bool SkStream_readU8(SkStream *stream, uint8_t *i);
bool SkStream_readU16(SkStream *stream, uint16_t *i);
bool SkStream_readU32(SkStream *stream, uint32_t *i);
bool SkStream_readBool(SkStream *stream, bool *b);
bool SkStream_readScalar(SkStream *stream, SkScalar *v);
bool SkStream_readPackedUInt(SkStream *stream, size_t *size);
bool SkStream_rewind(SkStream *stream);
sk_stream_t SkStream_duplicate(SkStream *stream);
sk_stream_t SkStream_fork(SkStream *stream);
bool SkStream_hasPosition(SkStream *stream);
size_t SkStream_getPosition(SkStream *stream);
bool SkStream_seek(SkStream *stream, size_t size);
bool SkStream_move(SkStream *stream, long i);
bool SkStream_hasLength(SkStream *stream);
size_t SkStream_getLength(SkStream *stream);
const void * SkStream_getMemoryBase(SkStream *stream);
// static
sk_stream_asset_t SkStream_MakeFromFile(const char path[]);
}

#endif //RAIA_SKIA_SK_STREAM_H
