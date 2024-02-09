//
// Created by dolphilia on 2024/01/11.
//

#include "sk_stream_seekable.h"

extern "C" {

void SkStreamSeekable_delete(SkStreamSeekable *stream_seekable) {
    delete stream_seekable;
}

sk_stream_seekable_t SkStreamSeekable_duplicate(SkStreamSeekable *stream_seekable) {
    return static_sk_stream_seekable_make(stream_seekable->duplicate());
}

bool SkStreamSeekable_hasPosition(SkStreamSeekable *stream_seekable) {
    return stream_seekable->hasPosition();
}

size_t SkStreamSeekable_getPosition(SkStreamSeekable *stream_seekable) {
    return stream_seekable->getPosition();
}

bool SkStreamSeekable_seek(SkStreamSeekable *stream_seekable, size_t position) {
    return stream_seekable->seek(position);
}

bool SkStreamSeekable_move(SkStreamSeekable *stream_seekable, long offset) {
    return stream_seekable->move(offset);
}

sk_stream_seekable_t SkStreamSeekable_fork(SkStreamSeekable *stream_seekable) {
    return static_sk_stream_seekable_make(stream_seekable->fork());
}

bool SkStreamSeekable_rewind(SkStreamSeekable *stream_seekable) {
    return stream_seekable->rewind();
}

size_t SkStreamSeekable_read(SkStreamSeekable *stream_seekable, void *buffer, size_t size) {
    return stream_seekable->read(buffer, size);
}

size_t SkStreamSeekable_skip(SkStreamSeekable *stream_seekable, size_t size) {
    return stream_seekable->skip(size);
}

size_t SkStreamSeekable_peek(SkStreamSeekable *stream_seekable, void *buffer, size_t size) {
    return stream_seekable->peek(buffer, size);
}

bool SkStreamSeekable_isAtEnd(SkStreamSeekable *stream_seekable) {
    return stream_seekable->isAtEnd();
}

bool SkStreamSeekable_readS8(SkStreamSeekable *stream_seekable, int8_t *i) {
    return stream_seekable->readS8(i);
}

bool SkStreamSeekable_readS16(SkStreamSeekable *stream_seekable, int16_t *i) {
    return stream_seekable->readS16(i);
}

bool SkStreamSeekable_readS32(SkStreamSeekable *stream_seekable, int32_t *i) {
    return stream_seekable->readS32(i);
}

bool SkStreamSeekable_readU8(SkStreamSeekable *stream_seekable, uint8_t *i) {
    return stream_seekable->readU8(i);
}

bool SkStreamSeekable_readU16(SkStreamSeekable *stream_seekable, uint16_t *i) {
    return stream_seekable->readU16(i);
}

bool SkStreamSeekable_readU32(SkStreamSeekable *stream_seekable, uint32_t *i) {
    return stream_seekable->readU32(i);
}

bool SkStreamSeekable_readBool(SkStreamSeekable *stream_seekable, bool *b) {
    return stream_seekable->readBool(b);
}

bool SkStreamSeekable_readScalar(SkStreamSeekable *stream_seekable, SkScalar *v) {
    return stream_seekable->readScalar(v);
}

bool SkStreamSeekable_readPackedUInt(SkStreamSeekable *stream_seekable, size_t *size) {
    return stream_seekable->readPackedUInt(size);
}

bool SkStreamSeekable_hasLength(SkStreamSeekable *stream_seekable) {
    return stream_seekable->hasLength();
}

size_t SkStreamSeekable_getLength(SkStreamSeekable *stream_seekable) {
    return stream_seekable->getLength();
}

const void * SkStreamSeekable_getMemoryBase(SkStreamSeekable *stream_seekable) {
    return stream_seekable->getMemoryBase();
}

// static

sk_stream_asset_t SkStreamSeekable_MakeFromFile(const char path[]) {
    return static_sk_stream_asset_make(SkStreamSeekable::MakeFromFile(path));
}

}