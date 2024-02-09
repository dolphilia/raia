//
// Created by dolphilia on 2024/01/08.
//

#include "sk_file_stream.h"

extern "C" {

SkFILEStream *SkFILEStream_new(const char path[]) {
    return new SkFILEStream(path);
}

SkFILEStream *SkFILEStream_new_2(FILE *file) {
    return new SkFILEStream(file);
}

SkFILEStream *SkFILEStream_new_3(FILE *file, size_t size) {
    return new SkFILEStream(file, size);
}

void SkFILEStream_delete(SkFILEStream *file_stream) {
    delete file_stream;
}

bool SkFILEStream_isValid(SkFILEStream *file_stream) {
    return file_stream->isValid();
}

void SkFILEStream_close(SkFILEStream *file_stream) {
    file_stream->close();
}

size_t SkFILEStream_read(SkFILEStream *file_stream, void *buffer, size_t size) {
    return file_stream->read(buffer, size);
}

bool SkFILEStream_isAtEnd(SkFILEStream *file_stream) {
    return file_stream->isAtEnd();
}

bool SkFILEStream_rewind(SkFILEStream *file_stream) {
    return file_stream->rewind();
}

sk_stream_asset_t SkFILEStream_duplicate(SkFILEStream *file_stream) {
    return static_sk_stream_asset_make(file_stream->duplicate());
}

size_t SkFILEStream_getPosition(SkFILEStream *file_stream) {
    return file_stream->getPosition();
}

bool SkFILEStream_seek(SkFILEStream *file_stream, size_t position) {
    return file_stream->seek(position);
}

bool SkFILEStream_move(SkFILEStream *file_stream, long offset) {
    return file_stream->move(offset);
}

sk_stream_asset_t SkFILEStream_fork(SkFILEStream *file_stream) {
    return static_sk_stream_asset_make(file_stream->fork());
}

size_t SkFILEStream_getLength(SkFILEStream *file_stream) {
    return file_stream->getLength();
}

bool SkFILEStream_hasLength(SkFILEStream *file_stream) {
    return file_stream->hasLength();
}

bool SkFILEStream_hasPosition(SkFILEStream *file_stream) {
    return file_stream->hasPosition();
}

size_t SkFILEStream_skip(SkFILEStream *file_stream, size_t size) {
    return file_stream->skip(size);
}

size_t SkFILEStream_peek(SkFILEStream *file_stream, void *ptr, size_t size) {
    return file_stream->peek(ptr, size);
}

bool SkFILEStream_readS8(SkFILEStream *file_stream, int8_t *i) {
    return file_stream->readS8(i);
}

bool SkFILEStream_readS16(SkFILEStream *file_stream, int16_t *i) {
    return file_stream->readS16(i);
}

bool SkFILEStream_readS32(SkFILEStream *file_stream, int32_t *i) {
    return file_stream->readS32(i);
}

bool SkFILEStream_readU8(SkFILEStream *file_stream, uint8_t *i) {
    return file_stream->readU8(i);
}

bool SkFILEStream_readU16(SkFILEStream *file_stream, uint16_t *i) {
    return file_stream->readU16(i);
}

bool SkFILEStream_readU32(SkFILEStream *file_stream, uint32_t *i) {
    return file_stream->readU32(i);
}

bool SkFILEStream_readBool(SkFILEStream *file_stream, bool *b) {
    return file_stream->readBool(b);
}

bool SkFILEStream_readScalar(SkFILEStream *file_stream, SkScalar *scalar) {
    return file_stream->readScalar(scalar);
}

bool SkFILEStream_readPackedUInt(SkFILEStream *file_stream, size_t *size) {
    return file_stream->readPackedUInt(size);
}

const void * SkFILEStream_getMemoryBase(SkFILEStream *file_stream) {
    return file_stream->getMemoryBase();
}

// static

sk_file_stream_t SkFILEStream_Make(const char path[]) {
    return static_sk_file_stream_make(SkFILEStream::Make(path));
}

}