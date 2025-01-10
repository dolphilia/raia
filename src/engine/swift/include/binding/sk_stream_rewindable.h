//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_STREAM_REWINDABLE_H
#define RAIA_SKIA_SK_STREAM_REWINDABLE_H

#include "include/core/SkStream.h"
#include "../static/static_sk_stream_rewindable.h"
#include "../static/static_sk_stream.h"
#include "../static/static_sk_stream_asset.h"

extern "C" {
void SkStreamRewindable_delete(SkStreamRewindable *stream_rewindable);
bool SkStreamRewindable_rewind(SkStreamRewindable *stream_rewindable);
sk_stream_rewindable_t SkStreamRewindable_duplicate(SkStreamRewindable *stream_rewindable);
size_t SkStreamRewindable_read(SkStreamRewindable *stream_rewindable, void *buffer, size_t size);
size_t SkStreamRewindable_skip(SkStreamRewindable *stream_rewindable, size_t size);
size_t SkStreamRewindable_peek(SkStreamRewindable *stream_rewindable, void *buffer, size_t size);
bool SkStreamRewindable_isAtEnd(SkStreamRewindable *stream_rewindable);
bool SkStreamRewindable_readS8(SkStreamRewindable *stream_rewindable, int8_t *i);
bool SkStreamRewindable_readS16(SkStreamRewindable *stream_rewindable, int16_t *i);
bool SkStreamRewindable_readS32(SkStreamRewindable *stream_rewindable, int32_t *i);
bool SkStreamRewindable_readU8(SkStreamRewindable *stream_rewindable, uint8_t *i);
bool SkStreamRewindable_readU16(SkStreamRewindable *stream_rewindable, uint16_t *i);
bool SkStreamRewindable_readU32(SkStreamRewindable *stream_rewindable, uint32_t *i);
bool SkStreamRewindable_readBool(SkStreamRewindable *stream_rewindable, bool *b);
bool SkStreamRewindable_readScalar(SkStreamRewindable *stream_rewindable, SkScalar *v);
bool SkStreamRewindable_readPackedUInt(SkStreamRewindable *stream_rewindable, size_t *size);
sk_stream_t SkStreamRewindable_fork(SkStreamRewindable *stream_rewindable);
bool SkStreamRewindable_hasPosition(SkStreamRewindable *stream_rewindable);
size_t SkStreamRewindable_getPosition(SkStreamRewindable *stream_rewindable);
bool SkStreamRewindable_seek(SkStreamRewindable *stream_rewindable, size_t size);
bool SkStreamRewindable_move(SkStreamRewindable *stream_rewindable, long i);
bool SkStreamRewindable_hasLength(SkStreamRewindable *stream_rewindable);
size_t SkStreamRewindable_getLength(SkStreamRewindable *stream_rewindable);
const void * SkStreamRewindable_getMemoryBase(SkStreamRewindable *stream_rewindable);
// static
sk_stream_asset_t SkStreamRewindable_MakeFromFile(const char path[]);
}

#endif //RAIA_SKIA_SK_STREAM_REWINDABLE_H
