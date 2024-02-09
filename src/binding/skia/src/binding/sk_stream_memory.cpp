//
// Created by dolphilia on 2024/01/11.
//

#include "sk_stream_memory.h"

extern "C" {

void SkStreamMemory_delete(SkStreamMemory *stream_memory) {
    delete stream_memory;
}

const void * SkStreamMemory_getMemoryBase(SkStreamMemory *stream_memory) {
    return stream_memory->getMemoryBase();
}

sk_stream_memory_t SkStreamMemory_duplicate(SkStreamMemory *stream_memory) {
    return static_sk_stream_memory_make(stream_memory->duplicate());
}

sk_stream_memory_t SkStreamMemory_fork(SkStreamMemory *stream_memory) {
    return static_sk_stream_memory_make(stream_memory->fork());
}

bool SkStreamMemory_hasLength(SkStreamMemory *stream_memory) {
    return stream_memory->hasLength();
}

size_t SkStreamMemory_getLength(SkStreamMemory *stream_memory) {
    return stream_memory->getLength();
}

bool SkStreamMemory_hasPosition(SkStreamMemory *stream_memory) {
    return stream_memory->hasPosition();
}

size_t SkStreamMemory_getPosition(SkStreamMemory *stream_memory) {
    return stream_memory->getPosition();
}

bool SkStreamMemory_seek(SkStreamMemory *stream_memory, size_t position) {
    return stream_memory->seek(position);
}

bool SkStreamMemory_move(SkStreamMemory *stream_memory, long offset) {
    return stream_memory->move(offset);
}

bool SkStreamMemory_rewind(SkStreamMemory *stream_memory) {
    return stream_memory->rewind();
}

size_t SkStreamMemory_read(SkStreamMemory *stream_memory, void *buffer, size_t size) {
    return stream_memory->read(buffer, size);
}

size_t SkStreamMemory_skip(SkStreamMemory *stream_memory, size_t size) {
    return stream_memory->skip(size);
}

size_t SkStreamMemory_peek(SkStreamMemory *stream_memory, void *buffer, size_t size) {
    return stream_memory->peek(buffer, size);
}

bool SkStreamMemory_isAtEnd(SkStreamMemory *stream_memory) {
    return stream_memory->isAtEnd();
}

bool SkStreamMemory_readS8(SkStreamMemory *stream_memory, int8_t *i) {
    return stream_memory->readS8(i);
}

bool SkStreamMemory_readS16(SkStreamMemory *stream_memory, int16_t *i) {
    return stream_memory->readS16(i);
}

bool SkStreamMemory_readS32(SkStreamMemory *stream_memory, int32_t *i) {
    return stream_memory->readS32(i);
}

bool SkStreamMemory_readU8(SkStreamMemory *stream_memory, uint8_t *i) {
    return stream_memory->readU8(i);
}

bool SkStreamMemory_readU16(SkStreamMemory *stream_memory, uint16_t *i) {
    return stream_memory->readU16(i);
}

bool SkStreamMemory_readU32(SkStreamMemory *stream_memory, uint32_t *i) {
    return stream_memory->readU32(i);
}

bool SkStreamMemory_readBool(SkStreamMemory *stream_memory, bool *b) {
    return stream_memory->readBool(b);
}

bool SkStreamMemory_readScalar(SkStreamMemory *stream_memory, SkScalar *v) {
    return stream_memory->readScalar(v);
}

bool SkStreamMemory_readPackedUInt(SkStreamMemory *stream_memory, size_t *size) {
    return stream_memory->readPackedUInt(size);
}

// static

sk_stream_asset_t SkStreamMemory_MakeFromFile(const char path[]) {
    return static_sk_stream_asset_make(SkStreamMemory::MakeFromFile(path));
}

}