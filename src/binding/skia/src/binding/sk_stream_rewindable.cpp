//
// Created by dolphilia on 2024/01/11.
//

#include "sk_stream_rewindable.h"

extern "C" {

bool SkStreamRewindable_rewind(SkStreamRewindable *stream_rewindable) {
    return stream_rewindable->rewind();
}

void SkStreamRewindable_duplicate(int sk_stream_rewindable_key_out, SkStreamRewindable *stream_rewindable) {
    static_sk_stream_rewindable_set(sk_stream_rewindable_key_out, stream_rewindable->duplicate());
}

size_t SkStreamRewindable_read(SkStreamRewindable *stream_rewindable, void *buffer, size_t size) {
    return stream_rewindable->read(buffer, size);
}

size_t SkStreamRewindable_skip(SkStreamRewindable *stream_rewindable, size_t size) {
    return stream_rewindable->skip(size);
}

size_t SkStreamRewindable_peek(SkStreamRewindable *stream_rewindable, void *buffer, size_t size) {
    return stream_rewindable->peek(buffer, size);
}

bool SkStreamRewindable_isAtEnd(SkStreamRewindable *stream_rewindable) {
    return stream_rewindable->isAtEnd();
}

bool SkStreamRewindable_readS8(SkStreamRewindable *stream_rewindable, int8_t *i) {
    return stream_rewindable->readS8(i);
}

bool SkStreamRewindable_readS16(SkStreamRewindable *stream_rewindable, int16_t *i) {
    return stream_rewindable->readS16(i);
}

bool SkStreamRewindable_readS32(SkStreamRewindable *stream_rewindable, int32_t *i) {
    return stream_rewindable->readS32(i);
}

bool SkStreamRewindable_readU8(SkStreamRewindable *stream_rewindable, uint8_t *i) {
    return stream_rewindable->readU8(i);
}

bool SkStreamRewindable_readU16(SkStreamRewindable *stream_rewindable, uint16_t *i) {
    return stream_rewindable->readU16(i);
}

bool SkStreamRewindable_readU32(SkStreamRewindable *stream_rewindable, uint32_t *i) {
    return stream_rewindable->readU32(i);
}

bool SkStreamRewindable_readBool(SkStreamRewindable *stream_rewindable, bool *b) {
    return stream_rewindable->readBool(b);
}

bool SkStreamRewindable_readScalar(SkStreamRewindable *stream_rewindable, SkScalar *v) {
    return stream_rewindable->readScalar(v);
}

bool SkStreamRewindable_readPackedUInt(SkStreamRewindable *stream_rewindable, size_t *size) {
    return stream_rewindable->readPackedUInt(size);
}

void SkStreamRewindable_fork(int sk_stream_key_out, SkStreamRewindable *stream_rewindable) {
    static_sk_stream_set(sk_stream_key_out, stream_rewindable->fork());
}

bool SkStreamRewindable_hasPosition(SkStreamRewindable *stream_rewindable) {
    return stream_rewindable->hasPosition();
}

size_t SkStreamRewindable_getPosition(SkStreamRewindable *stream_rewindable) {
    return stream_rewindable->getPosition();
}

bool SkStreamRewindable_seek(SkStreamRewindable *stream_rewindable, size_t size) {
    return stream_rewindable->seek(size);
}

bool SkStreamRewindable_move(SkStreamRewindable *stream_rewindable, long i) {
    return stream_rewindable->move(i);
}

bool SkStreamRewindable_hasLength(SkStreamRewindable *stream_rewindable) {
    return stream_rewindable->hasLength();
}

size_t SkStreamRewindable_getLength(SkStreamRewindable *stream_rewindable) {
    return stream_rewindable->getLength();
}

const void * SkStreamRewindable_getMemoryBase(SkStreamRewindable *stream_rewindable) {
    return stream_rewindable->getMemoryBase();
}

// static

void SkStreamRewindable_MakeFromFile(int sk_stream_asset_key_out, const char path[]) {
    static_sk_stream_asset_set(sk_stream_asset_key_out, SkStreamRewindable::MakeFromFile(path));
}

}