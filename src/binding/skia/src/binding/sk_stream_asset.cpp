//
// Created by dolphilia on 2024/01/11.
//

#include "sk_stream_asset.h"

extern "C" {

void SkStreamAsset_delete(SkStreamAsset *stream_asset) {
    delete stream_asset;
}

bool SkStreamAsset_hasLength(SkStreamAsset *stream_asset) {
    return stream_asset->hasLength();
}

size_t SkStreamAsset_getLength(SkStreamAsset *stream_asset) {
    return stream_asset->getLength();
}

sk_stream_asset_t SkStreamAsset_duplicate(SkStreamAsset *stream_asset) {
    return static_sk_stream_asset_make(stream_asset->duplicate());
}

sk_stream_asset_t SkStreamAsset_fork(SkStreamAsset *stream_asset) {
    return static_sk_stream_asset_make(stream_asset->fork());
}

bool SkStreamAsset_hasPosition(SkStreamAsset *stream_asset) {
    return stream_asset->hasPosition();
}

size_t SkStreamAsset_getPosition(SkStreamAsset *stream_asset) {
    return stream_asset->getPosition();
}

bool SkStreamAsset_seek(SkStreamAsset *stream_asset, size_t position) {
    return stream_asset->seek(position);
}

bool SkStreamAsset_move(SkStreamAsset *stream_asset, long offset) {
    return stream_asset->move(offset);
}

bool SkStreamAsset_rewind(SkStreamAsset *stream_asset) {
    return stream_asset->rewind();
}

size_t SkStreamAsset_read(SkStreamAsset *stream_asset, void *buffer, size_t size) {
    return stream_asset->read(buffer, size);
}

size_t SkStreamAsset_skip(SkStreamAsset *stream_asset, size_t size) {
    return stream_asset->skip(size);
}

size_t SkStreamAsset_peek(SkStreamAsset *stream_asset, void *buffer, size_t size) {
    return stream_asset->peek(buffer, size);
}

bool SkStreamAsset_isAtEnd(SkStreamAsset *stream_asset) {
    return stream_asset->isAtEnd();
}

bool SkStreamAsset_readS8(SkStreamAsset *stream_asset, int8_t *i) {
    return stream_asset->readS8(i);
}

bool SkStreamAsset_readS16(SkStreamAsset *stream_asset, int16_t *i) {
    return stream_asset->readS16(i);
}

bool SkStreamAsset_readS32(SkStreamAsset *stream_asset, int32_t *i) {
    return stream_asset->readS32(i);
}

bool SkStreamAsset_readU8(SkStreamAsset *stream_asset, uint8_t *i) {
    return stream_asset->readU8(i);
}

bool SkStreamAsset_readU16(SkStreamAsset *stream_asset, uint16_t *i) {
    return stream_asset->readU16(i);
}

bool SkStreamAsset_readU32(SkStreamAsset *stream_asset, uint32_t *i) {
    return stream_asset->readU32(i);
}

bool SkStreamAsset_readBool(SkStreamAsset *stream_asset, bool *b) {
    return stream_asset->readBool(b);
}

bool SkStreamAsset_readScalar(SkStreamAsset *stream_asset, SkScalar *v) {
    return stream_asset->readScalar(v);
}

bool SkStreamAsset_readPackedUInt(SkStreamAsset *stream_asset, size_t *size) {
    return stream_asset->readPackedUInt(size);
}

const void * SkStreamAsset_getMemoryBase(SkStreamAsset *stream_asset) {
    return stream_asset->getMemoryBase();
}

// static

sk_stream_asset_t SkStreamAsset_MakeFromFile(const char path[]) {
    return static_sk_stream_asset_make(SkStreamAsset::MakeFromFile(path));
}

}