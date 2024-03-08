//
// Created by dolphilia on 2024/01/11.
//

#include "sk_stream.h"
#include "../static/static_sk_stream_asset.h"

extern "C" {

void SkStream_delete(SkStream *stream) {
    delete stream;
}

size_t SkStream_read(SkStream *stream, void *buffer, size_t size) {
    return stream->read(buffer, size);
}

size_t SkStream_skip(SkStream *stream, size_t size) {
    return stream->skip(size);
}

size_t SkStream_peek(SkStream *stream, void *buffer, size_t size) {
    return stream->peek(buffer, size);
}

bool SkStream_isAtEnd(SkStream *stream) {
    return stream->isAtEnd();
}

bool SkStream_readS8(SkStream *stream, int8_t *i) {
    return stream->readS8(i);
}

bool SkStream_readS16(SkStream *stream, int16_t *i) {
    return stream->readS16(i);
}

bool SkStream_readS32(SkStream *stream, int32_t *i) {
    return stream->readS32(i);
}

bool SkStream_readU8(SkStream *stream, uint8_t *i) {
    return stream->readU8(i);
}

bool SkStream_readU16(SkStream *stream, uint16_t *i) {
    return stream->readU16(i);
}

bool SkStream_readU32(SkStream *stream, uint32_t *i) {
    return stream->readU32(i);
}

bool SkStream_readBool(SkStream *stream, bool *b) {
    return stream->readBool(b);
}

bool SkStream_readScalar(SkStream *stream, SkScalar *v) {
    return stream->readScalar(v);
}

bool SkStream_readPackedUInt(SkStream *stream, size_t *size) {
    return stream->readPackedUInt(size);
}

bool SkStream_rewind(SkStream *stream) {
    return stream->rewind();
}

sk_stream_t SkStream_duplicate(SkStream *stream) {
    return static_sk_stream_make(stream->duplicate());
}

sk_stream_t SkStream_fork(SkStream *stream) {
    return static_sk_stream_make(stream->fork());
}

bool SkStream_hasPosition(SkStream *stream) {
    return stream->hasPosition();
}

size_t SkStream_getPosition(SkStream *stream) {
    return stream->getPosition();
}

bool SkStream_seek(SkStream *stream, size_t size) {
    return stream->seek(size);
}

bool SkStream_move(SkStream *stream, long i) {
    return stream->move(i);
}

bool SkStream_hasLength(SkStream *stream) {
    return stream->hasLength();
}

size_t SkStream_getLength(SkStream *stream) {
    return stream->getLength();
}

const void * SkStream_getMemoryBase(SkStream *stream) {
    return stream->getMemoryBase();
}

// static

sk_stream_asset_t SkStream_MakeFromFile(const char path[]) { // static
    return static_sk_stream_asset_make(SkStream::MakeFromFile(path));
}

}