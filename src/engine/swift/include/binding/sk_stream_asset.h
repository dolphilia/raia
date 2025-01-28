//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_STREAM_ASSET_H
#define RAIA_SKIA_SK_STREAM_ASSET_H

#ifdef __cplusplus
extern "C" {
#endif

void SkStreamAsset_delete(void *stream_asset); // (SkStreamAsset *stream_asset)
bool SkStreamAsset_hasLength(void *stream_asset); // (SkStreamAsset *stream_asset) -> bool
unsigned long SkStreamAsset_getLength(void *stream_asset); // (SkStreamAsset *stream_asset) -> size_t
int SkStreamAsset_duplicate(void *stream_asset); // (SkStreamAsset *stream_asset) -> sk_stream_asset_t
int SkStreamAsset_fork(void *stream_asset); // (SkStreamAsset *stream_asset) -> sk_stream_asset_t
bool SkStreamAsset_hasPosition(void *stream_asset); // (SkStreamAsset *stream_asset) -> bool
unsigned long SkStreamAsset_getPosition(void *stream_asset); // (SkStreamAsset *stream_asset) -> size_t
bool SkStreamAsset_seek(void *stream_asset, unsigned long position); // (SkStreamAsset *stream_asset, size_t position) -> bool
bool SkStreamAsset_move(void *stream_asset, long offset); // (SkStreamAsset *stream_asset, long offset) -> bool
bool SkStreamAsset_rewind(void *stream_asset); // (SkStreamAsset *stream_asset) -> bool
unsigned long SkStreamAsset_read(void *stream_asset, void *buffer, unsigned long size); // (SkStreamAsset *stream_asset, void *buffer, size_t size) -> size_t
unsigned long SkStreamAsset_skip(void *stream_asset, unsigned long size); // (SkStreamAsset *stream_asset, size_t size) -> size_t
unsigned long SkStreamAsset_peek(void *stream_asset, void *buffer, unsigned long size); // (SkStreamAsset *stream_asset, void *buffer, size_t size) -> size_t
bool SkStreamAsset_isAtEnd(void *stream_asset); // (SkStreamAsset *stream_asset) -> bool
bool SkStreamAsset_readS8(void *stream_asset, void *i); // (SkStreamAsset *stream_asset, int8_t *i) -> bool
bool SkStreamAsset_readS16(void *stream_asset, void *i); // (SkStreamAsset *stream_asset, int16_t *i) -> bool
bool SkStreamAsset_readS32(void *stream_asset, void *i); // (SkStreamAsset *stream_asset, int32_t *i) -> bool
bool SkStreamAsset_readU8(void *stream_asset, void *i); // (SkStreamAsset *stream_asset, uint8_t *i) -> bool
bool SkStreamAsset_readU16(void *stream_asset, void *i); // (SkStreamAsset *stream_asset, uint16_t *i) -> bool
bool SkStreamAsset_readU32(void *stream_asset, void *i); // (SkStreamAsset *stream_asset, uint32_t *i) -> bool
bool SkStreamAsset_readBool(void *stream_asset, void *b); // (SkStreamAsset *stream_asset, bool *b) -> bool
bool SkStreamAsset_readScalar(void *stream_asset, void *v); // (SkStreamAsset *stream_asset, SkScalar *v) -> bool
bool SkStreamAsset_readPackedUInt(void *stream_asset, void *size); // (SkStreamAsset *stream_asset, size_t *size) -> bool
const void *SkStreamAsset_getMemoryBase(void *stream_asset); // (SkStreamAsset *stream_asset) -> const void *

// static

int SkStreamAsset_MakeFromFile(const char path[]); // (const char path[]) -> sk_stream_asset_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_STREAM_ASSET_H
