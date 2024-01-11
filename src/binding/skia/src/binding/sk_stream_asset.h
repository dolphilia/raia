//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_STREAM_ASSET_H
#define RAIA_SKIA_SK_STREAM_ASSET_H

#include "include/core/SkStream.h"
#include "../static/static_sk_stream_asset.h"

extern "C" {
bool SkStreamAsset_hasLength(SkStreamAsset *stream_asset);
size_t SkStreamAsset_getLength(SkStreamAsset *stream_asset);
void SkStreamAsset_duplicate(const char *sk_stream_asset_key_out, SkStreamAsset *stream_asset);
void SkStreamAsset_fork(const char *sk_stream_asset_key_out, SkStreamAsset *stream_asset);
bool SkStreamAsset_hasPosition(SkStreamAsset *stream_asset);
size_t SkStreamAsset_getPosition(SkStreamAsset *stream_asset);
bool SkStreamAsset_seek(SkStreamAsset *stream_asset, size_t position);
bool SkStreamAsset_move(SkStreamAsset *stream_asset, long offset);
bool SkStreamAsset_rewind(SkStreamAsset *stream_asset);
size_t SkStreamAsset_read(SkStreamAsset *stream_asset, void *buffer, size_t size);
size_t SkStreamAsset_skip(SkStreamAsset *stream_asset, size_t size);
size_t SkStreamAsset_peek(SkStreamAsset *stream_asset, void *buffer, size_t size);
bool SkStreamAsset_isAtEnd(SkStreamAsset *stream_asset);
bool SkStreamAsset_readS8(SkStreamAsset *stream_asset, int8_t *i) ;
bool SkStreamAsset_readS16(SkStreamAsset *stream_asset, int16_t *i);
bool SkStreamAsset_readS32(SkStreamAsset *stream_asset, int32_t *i);
bool SkStreamAsset_readU8(SkStreamAsset *stream_asset, uint8_t *i);
bool SkStreamAsset_readU16(SkStreamAsset *stream_asset, uint16_t *i);
bool SkStreamAsset_readU32(SkStreamAsset *stream_asset, uint32_t *i);
bool SkStreamAsset_readBool(SkStreamAsset *stream_asset, bool *b);
bool SkStreamAsset_readScalar(SkStreamAsset *stream_asset, SkScalar *v);
bool SkStreamAsset_readPackedUInt(SkStreamAsset *stream_asset, size_t *size);
const void * SkStreamAsset_getMemoryBase(SkStreamAsset *stream_asset);
// static
void SkStreamAsset_MakeFromFile(const char *sk_stream_asset_key_out, const char path[]);
}

#endif //RAIA_SKIA_SK_STREAM_ASSET_H
