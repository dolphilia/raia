//
// Created by dolphilia on 2024/01/08.
//

#include "sk_file_w_stream.h"

extern "C" {

SkFILEWStream *SkFILEWStream_new(const char path[]) {
    return new SkFILEWStream(path);
}

void SkFILEWStream_delete(SkFILEWStream *file_w_stream) {
    delete file_w_stream;
}

bool SkFILEWStream_isValid(SkFILEWStream *file_w_stream) {
    return file_w_stream->isValid();
}

bool SkFILEWStream_write(SkFILEWStream *file_w_stream, const void *buffer, size_t size) {
    return file_w_stream->write(buffer, size);
}

void SkFILEWStream_flush(SkFILEWStream *file_w_stream) {
    file_w_stream->flush();
}

void SkFILEWStream_fsync(SkFILEWStream *file_w_stream) {
    return file_w_stream->fsync();
}

size_t SkFILEWStream_bytesWritten(SkFILEWStream *file_w_stream) {
    return file_w_stream->bytesWritten();
}

bool SkFILEWStream_write8(SkFILEWStream *file_w_stream, U8CPU value) {
    return file_w_stream->write8(value);
}

bool SkFILEWStream_write16(SkFILEWStream *file_w_stream, U16CPU value) {
    return file_w_stream->write16(value);
}

bool SkFILEWStream_write32(SkFILEWStream *file_w_stream, uint32_t v) {
    return file_w_stream->write32(v);
}

bool SkFILEWStream_writeText(SkFILEWStream *file_w_stream, const char text[]) {
    return file_w_stream->writeText(text);
}

bool SkFILEWStream_newline(SkFILEWStream *file_w_stream) {
    return file_w_stream->newline();
}

bool SkFILEWStream_writeDecAsText(SkFILEWStream *file_w_stream, int32_t v) {
    return file_w_stream->writeDecAsText(v);
}

bool SkFILEWStream_writeBigDecAsText(SkFILEWStream *file_w_stream, int64_t v, int minDigits) {
    return file_w_stream->writeBigDecAsText(v, minDigits);
}

bool SkFILEWStream_writeHexAsText(SkFILEWStream *file_w_stream, uint32_t v, int minDigits) {
    return file_w_stream->writeHexAsText(v, minDigits);
}

bool SkFILEWStream_writeScalarAsText(SkFILEWStream *file_w_stream, SkScalar scalar) {
    return file_w_stream->writeScalarAsText(scalar);
}

bool SkFILEWStream_writeBool(SkFILEWStream *file_w_stream, bool v) {
    return file_w_stream->writeBool(v);
}

bool SkFILEWStream_writeScalar(SkFILEWStream *file_w_stream, SkScalar scalar) {
    return file_w_stream->writeScalar(scalar);
}

bool SkFILEWStream_writePackedUInt(SkFILEWStream *file_w_stream, size_t size) {
    return file_w_stream->writePackedUInt(size);
}

bool SkFILEWStream_writeStream(SkFILEWStream *file_w_stream, SkStream *input, size_t length) {
    return file_w_stream->writeStream(input, length);
}

// static

int SkFILEWStream_SizeOfPackedUInt(size_t value) {
    return SkFILEWStream::SizeOfPackedUInt(value);
}

}