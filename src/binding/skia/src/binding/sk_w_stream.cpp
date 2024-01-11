//
// Created by dolphilia on 2024/01/11.
//

#include "sk_w_stream.h"

extern "C" {

void SkWStream_delete(SkWStream *w_stream) {
    delete w_stream;
}

bool SkWStream_write(SkWStream *w_stream, const void *buffer, size_t size) {
    return w_stream->write(buffer, size);
}

void SkWStream_flush(SkWStream *w_stream) {
    return w_stream->flush();
}

size_t SkWStream_bytesWritten(SkWStream *w_stream) {
    return w_stream->bytesWritten();
}

bool SkWStream_write8(SkWStream *w_stream, U8CPU value) {
    return w_stream->write8(value);
}

bool SkWStream_write16(SkWStream *w_stream, U16CPU value) {
    return w_stream->write16(value);
}

bool SkWStream_write32(SkWStream *w_stream, uint32_t v) {
    return w_stream->write32(v);
}

bool SkWStream_writeText(SkWStream *w_stream, const char text[]) {
    return w_stream->writeText(text);
}

bool SkWStream_newline(SkWStream *w_stream) {
    return w_stream->newline();
}

bool SkWStream_writeDecAsText(SkWStream *w_stream, int32_t i) {
    return w_stream->writeDecAsText(i);
}

bool SkWStream_writeBigDecAsText(SkWStream *w_stream, int64_t i, int minDigits) {
    return w_stream->writeBigDecAsText(i, minDigits);
}

bool SkWStream_writeHexAsText(SkWStream *w_stream, uint32_t i, int minDigits) {
    return w_stream->writeHexAsText(i, minDigits);
}

bool SkWStream_writeScalarAsText(SkWStream *w_stream, SkScalar v) {
    return w_stream->writeScalarAsText(v);
}

bool SkWStream_writeBool(SkWStream *w_stream, bool v) {
    return w_stream->writeBool(v);
}

bool SkWStream_writeScalar(SkWStream *w_stream, SkScalar v) {
    return w_stream->writeScalar(v);
}

bool SkWStream_writePackedUInt(SkWStream *w_stream, size_t size) {
    return w_stream->writePackedUInt(size);
}

bool SkWStream_writeStream(SkWStream *w_stream, SkStream *input, size_t length) {
    return w_stream->writeStream(input, length);
}

// static

int SkWStream_SizeOfPackedUInt(size_t value) {
    return SkWStream::SizeOfPackedUInt(value);
}

}