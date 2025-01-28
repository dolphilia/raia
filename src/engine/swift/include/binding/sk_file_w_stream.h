//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FILE_W_STREAM_H
#define RAIA_SKIA_SK_FILE_W_STREAM_H

#include "include/core/SkStream.h"

extern "C" {
SkFILEWStream *SkFILEWStream_new(const char path[]);
void SkFILEWStream_delete(SkFILEWStream *file_w_stream);
bool SkFILEWStream_isValid(SkFILEWStream *file_w_stream);
bool SkFILEWStream_write(SkFILEWStream *file_w_stream, const void *buffer, size_t size);
void SkFILEWStream_flush(SkFILEWStream *file_w_stream);
void SkFILEWStream_fsync(SkFILEWStream *file_w_stream);
size_t SkFILEWStream_bytesWritten(SkFILEWStream *file_w_stream);
bool SkFILEWStream_write8(SkFILEWStream *file_w_stream, U8CPU value);
bool SkFILEWStream_write16(SkFILEWStream *file_w_stream, U16CPU value);
bool SkFILEWStream_write32(SkFILEWStream *file_w_stream, uint32_t v);
bool SkFILEWStream_writeText(SkFILEWStream *file_w_stream, const char text[]);
bool SkFILEWStream_newline(SkFILEWStream *file_w_stream);
bool SkFILEWStream_writeDecAsText(SkFILEWStream *file_w_stream, int32_t v);
bool SkFILEWStream_writeBigDecAsText(SkFILEWStream *file_w_stream, int64_t v, int minDigits);
bool SkFILEWStream_writeHexAsText(SkFILEWStream *file_w_stream, uint32_t v, int minDigits);
bool SkFILEWStream_writeScalarAsText(SkFILEWStream *file_w_stream, SkScalar scalar);
bool SkFILEWStream_writeBool(SkFILEWStream *file_w_stream, bool v);
bool SkFILEWStream_writeScalar(SkFILEWStream *file_w_stream, SkScalar scalar);
bool SkFILEWStream_writePackedUInt(SkFILEWStream *file_w_stream, size_t size);
bool SkFILEWStream_writeStream(SkFILEWStream *file_w_stream, SkStream *input, size_t length);
// static
int SkFILEWStream_SizeOfPackedUInt(size_t value);
}

#endif //RAIA_SKIA_SK_FILE_W_STREAM_H
