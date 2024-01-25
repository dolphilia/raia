//
// Created by dolphilia on 2024/01/09.
//

#include "sk_memory_stream.h"

extern "C" {

SkMemoryStream *SkMemoryStream_new() {
    return new SkMemoryStream();
}

SkMemoryStream *SkMemoryStream_new_2(size_t length) {
    return new SkMemoryStream(length);
}

SkMemoryStream *SkMemoryStream_new_3(const void *data, size_t length, bool copyData) {
    return new SkMemoryStream(data, length, copyData);
}

SkMemoryStream *SkMemoryStream_new_4(int sk_data_key_in) {
    return new SkMemoryStream(static_sk_data_move(sk_data_key_in));
}

void SkMemoryStream_setMemory(SkMemoryStream *memory_stream, const void *data, size_t length, bool copyData) {
    memory_stream->setMemory(data, length, copyData);
}

void SkMemoryStream_setMemoryOwned(SkMemoryStream *memory_stream, const void *data, size_t length) {
    memory_stream->setMemoryOwned(data, length);
}

void SkMemoryStream_asData(int sk_data_key_out, SkMemoryStream *memory_stream) {
    static_sk_data_set(sk_data_key_out, memory_stream->asData());
}

void SkMemoryStream_setData(int sk_data_key_in, SkMemoryStream *memory_stream) {
    memory_stream->setData(static_sk_data_move(sk_data_key_in));
}

void SkMemoryStream_skipToAlign4(SkMemoryStream *memory_stream) {
    memory_stream->skipToAlign4();
}

const void * SkMemoryStream_getAtPos(SkMemoryStream *memory_stream) {
    return memory_stream->getAtPos();
}

size_t SkMemoryStream_read(SkMemoryStream *memory_stream, void *buffer, size_t size) {
    return memory_stream->read(buffer, size);
}

bool SkMemoryStream_isAtEnd(SkMemoryStream *memory_stream) {
    return memory_stream->isAtEnd();
}

size_t SkMemoryStream_peek(SkMemoryStream *memory_stream, void *buffer, size_t size) {
    return memory_stream->peek(buffer, size);
}

bool SkMemoryStream_rewind(SkMemoryStream *memory_stream) {
    return memory_stream->rewind();
}

void SkMemoryStream_duplicate(int sk_memory_stream_key_out, SkMemoryStream *memory_stream) {
    static_sk_memory_stream_set(sk_memory_stream_key_out, memory_stream->duplicate());
}

size_t SkMemoryStream_getPosition(SkMemoryStream *memory_stream) {
    return memory_stream->getPosition();
}

bool SkMemoryStream_seek(SkMemoryStream *memory_stream, size_t position) {
    return memory_stream->seek(position);
}

bool SkMemoryStream_move(SkMemoryStream *memory_stream, long offset) {
    return memory_stream->move(offset);
}

void SkMemoryStream_fork(int sk_memory_stream_key_out, SkMemoryStream *memory_stream) {
    static_sk_memory_stream_set(sk_memory_stream_key_out, memory_stream->fork());
}

size_t SkMemoryStream_getLength(SkMemoryStream *memory_stream) {
    return memory_stream->getLength();
}

const void * SkMemoryStream_getMemoryBase(SkMemoryStream *memory_stream) {
    return memory_stream->getMemoryBase();
}

bool SkMemoryStream_hasLength(SkMemoryStream *memory_stream) {
    return memory_stream->hasLength();
}

bool SkMemoryStream_hasPosition(SkMemoryStream *memory_stream) {
    return memory_stream->hasPosition();
}

size_t SkMemoryStream_skip(SkMemoryStream *memory_stream, size_t size) {
    return memory_stream->skip(size);
}

bool SkMemoryStream_readS8(SkMemoryStream *memory_stream, int8_t *i) {
    return memory_stream->readS8(i);
}

bool SkMemoryStream_readS16(SkMemoryStream *memory_stream, int16_t *i) {
    return memory_stream->readS16(i);
}

bool SkMemoryStream_readS32(SkMemoryStream *memory_stream, int32_t *i) {
    return memory_stream->readS32(i);
}

bool SkMemoryStream_readU8(SkMemoryStream *memory_stream, uint8_t *i) {
    return memory_stream->readU8(i);
}

bool SkMemoryStream_readU16(SkMemoryStream *memory_stream, uint16_t *i) {
    return memory_stream->readU16(i);
}

bool SkMemoryStream_readU32(SkMemoryStream *memory_stream, uint32_t *i) {
    return memory_stream->readU32(i);
}

bool SkMemoryStream_readBool(SkMemoryStream *memory_stream, bool *b) {
    return memory_stream->readBool(b);
}

bool SkMemoryStream_readScalar(SkMemoryStream *memory_stream, SkScalar *v) {
    return memory_stream->readScalar(v);
}

bool SkMemoryStream_readPackedUInt(SkMemoryStream *memory_stream, size_t *size) {
    return memory_stream->readPackedUInt(size);
}

// static

void SkMemoryStream_MakeCopy(int sk_memory_stream_key_out, const void *data, size_t length) {
    static_sk_memory_stream_set(sk_memory_stream_key_out, SkMemoryStream::MakeCopy(data, length));
}

void SkMemoryStream_MakeDirect(int sk_memory_stream_key_out, const void *data, size_t length) {
    static_sk_memory_stream_set(sk_memory_stream_key_out, SkMemoryStream::MakeDirect(data, length));
}

void SkMemoryStream_Make(int sk_memory_stream_key_out, int sk_data_key_in) {
    static_sk_memory_stream_set(sk_memory_stream_key_out, SkMemoryStream::Make(static_sk_data_move(sk_data_key_in)));
}

}