//
// Created by dolphilia on 2024/01/08.
//

#include "sk_dynamic_memory_w_stream.h"

extern "C" {

SkDynamicMemoryWStream *SkDynamicMemoryWStream_new() {
    return new SkDynamicMemoryWStream();
}

//SkDynamicMemoryWStream * SkDynamicMemoryWStream_new_2(SkDynamicMemoryWStream &&stream) {
//    return new SkDynamicMemoryWStream(&stream);
//}

void SkDynamicMemoryWStream_delete(SkDynamicMemoryWStream *dynamic_memory_w_stream) {
    delete dynamic_memory_w_stream;
}

bool SkDynamicMemoryWStream_write(SkDynamicMemoryWStream *dynamic_memory_w_stream, const void *buffer, size_t size) {
    return dynamic_memory_w_stream->write(buffer, size);
}

size_t SkDynamicMemoryWStream_bytesWritten(SkDynamicMemoryWStream *dynamic_memory_w_stream) {
    return dynamic_memory_w_stream->bytesWritten();
}

bool SkDynamicMemoryWStream_read(SkDynamicMemoryWStream *dynamic_memory_w_stream, void *buffer, size_t offset, size_t size) {
    return dynamic_memory_w_stream->read(buffer, offset, size);
}

void SkDynamicMemoryWStream_copyTo(SkDynamicMemoryWStream *dynamic_memory_w_stream, void *dst) {
    return dynamic_memory_w_stream->copyTo(dst);
}

bool SkDynamicMemoryWStream_writeToStream(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkWStream *dst) {
    return dynamic_memory_w_stream->writeToStream(dst);
}

void SkDynamicMemoryWStream_copyToAndReset(SkDynamicMemoryWStream *dynamic_memory_w_stream, void *dst) {
    return dynamic_memory_w_stream->copyToAndReset(dst);
}

bool SkDynamicMemoryWStream_writeToAndReset(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkWStream *dst) {
    return dynamic_memory_w_stream->writeToAndReset(dst);
}

bool SkDynamicMemoryWStream_writeToAndReset_2(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkDynamicMemoryWStream *dst) {
    return dynamic_memory_w_stream->writeToAndReset(dst);
}

void SkDynamicMemoryWStream_prependToAndReset(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkDynamicMemoryWStream *dst) {
    dynamic_memory_w_stream->prependToAndReset(dst);
}

sk_data_t SkDynamicMemoryWStream_detachAsData(SkDynamicMemoryWStream *dynamic_memory_w_stream) {
    return static_sk_data_make(dynamic_memory_w_stream->detachAsData());
}

sk_stream_asset_t SkDynamicMemoryWStream_detachAsStream(SkDynamicMemoryWStream *dynamic_memory_w_stream) {
    return static_sk_stream_asset_make(dynamic_memory_w_stream->detachAsStream());
}

void SkDynamicMemoryWStream_reset(SkDynamicMemoryWStream *dynamic_memory_w_stream) {
    dynamic_memory_w_stream->reset();
}

void SkDynamicMemoryWStream_padToAlign4(SkDynamicMemoryWStream *dynamic_memory_w_stream) {
    dynamic_memory_w_stream->padToAlign4();
}

void SkDynamicMemoryWStream_flush(SkDynamicMemoryWStream *dynamic_memory_w_stream) {
    dynamic_memory_w_stream->flush();
}

bool SkDynamicMemoryWStream_write8(SkDynamicMemoryWStream *dynamic_memory_w_stream, U8CPU value) {
    return dynamic_memory_w_stream->write8(value);
}

bool SkDynamicMemoryWStream_write16(SkDynamicMemoryWStream *dynamic_memory_w_stream, U16CPU value) {
    return dynamic_memory_w_stream->write16(value);
}

bool SkDynamicMemoryWStream_write32(SkDynamicMemoryWStream *dynamic_memory_w_stream, uint32_t v) {
    return dynamic_memory_w_stream->write32(v);
}

bool SkDynamicMemoryWStream_writeText(SkDynamicMemoryWStream *dynamic_memory_w_stream, const char text[]) {
    return dynamic_memory_w_stream->writeText(text);
}

bool SkDynamicMemoryWStream_newline(SkDynamicMemoryWStream *dynamic_memory_w_stream) {
    return dynamic_memory_w_stream->newline();
}

bool SkDynamicMemoryWStream_writeDecAsText(SkDynamicMemoryWStream *dynamic_memory_w_stream, int32_t v) {
    return dynamic_memory_w_stream->writeDecAsText(v);
}

bool SkDynamicMemoryWStream_writeBigDecAsText(SkDynamicMemoryWStream *dynamic_memory_w_stream, int64_t v, int minDigits) {
    return dynamic_memory_w_stream->writeBigDecAsText(v, minDigits);
}

bool SkDynamicMemoryWStream_writeHexAsText(SkDynamicMemoryWStream *dynamic_memory_w_stream, uint32_t v, int minDigits) {
    return dynamic_memory_w_stream->writeHexAsText(v, minDigits);
}

bool SkDynamicMemoryWStream_writeScalarAsText(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkScalar scalar) {
    return dynamic_memory_w_stream->writeScalarAsText(scalar);
}

bool SkDynamicMemoryWStream_writeBool(SkDynamicMemoryWStream *dynamic_memory_w_stream, bool v) {
    return dynamic_memory_w_stream->writeBool(v);
}

bool SkDynamicMemoryWStream_writeScalar(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkScalar scalar) {
    return dynamic_memory_w_stream->writeScalar(scalar);
}

bool SkDynamicMemoryWStream_writePackedUInt(SkDynamicMemoryWStream *dynamic_memory_w_stream, size_t length) {
    return dynamic_memory_w_stream->writePackedUInt(length);
}

bool SkDynamicMemoryWStream_writeStream(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkStream *input, size_t length) {
    return dynamic_memory_w_stream->writeStream(input, length);
}

// static

int SkDynamicMemoryWStream_SizeOfPackedUInt(size_t value) {
    return SkDynamicMemoryWStream::SizeOfPackedUInt(value);
}

}