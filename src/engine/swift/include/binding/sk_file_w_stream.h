//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FILE_W_STREAM_H
#define RAIA_SKIA_SK_FILE_W_STREAM_H

#include "include/core/SkStream.h"
#include "export_api.h"

extern "C" {
RAIA_API SkFILEWStream *SkFILEWStream_new(const char path[]);
RAIA_API void SkFILEWStream_delete(SkFILEWStream *file_w_stream);
RAIA_API bool SkFILEWStream_isValid(SkFILEWStream *file_w_stream);
RAIA_API bool SkFILEWStream_write(SkFILEWStream *file_w_stream, const void *buffer, size_t size);
RAIA_API void SkFILEWStream_flush(SkFILEWStream *file_w_stream);
RAIA_API void SkFILEWStream_fsync(SkFILEWStream *file_w_stream);
RAIA_API size_t SkFILEWStream_bytesWritten(SkFILEWStream *file_w_stream);
RAIA_API bool SkFILEWStream_write8(SkFILEWStream *file_w_stream, U8CPU value);
RAIA_API bool SkFILEWStream_write16(SkFILEWStream *file_w_stream, U16CPU value);
RAIA_API bool SkFILEWStream_write32(SkFILEWStream *file_w_stream, uint32_t v);
RAIA_API bool SkFILEWStream_writeText(SkFILEWStream *file_w_stream, const char text[]);
RAIA_API bool SkFILEWStream_newline(SkFILEWStream *file_w_stream);
RAIA_API bool SkFILEWStream_writeDecAsText(SkFILEWStream *file_w_stream, int32_t v);
RAIA_API bool SkFILEWStream_writeBigDecAsText(SkFILEWStream *file_w_stream, int64_t v, int minDigits);
RAIA_API bool SkFILEWStream_writeHexAsText(SkFILEWStream *file_w_stream, uint32_t v, int minDigits);
RAIA_API bool SkFILEWStream_writeScalarAsText(SkFILEWStream *file_w_stream, SkScalar scalar);
RAIA_API bool SkFILEWStream_writeBool(SkFILEWStream *file_w_stream, bool v);
RAIA_API bool SkFILEWStream_writeScalar(SkFILEWStream *file_w_stream, SkScalar scalar);
RAIA_API bool SkFILEWStream_writePackedUInt(SkFILEWStream *file_w_stream, size_t size);
RAIA_API bool SkFILEWStream_writeStream(SkFILEWStream *file_w_stream, SkStream *input, size_t length);
// static
RAIA_API int SkFILEWStream_SizeOfPackedUInt(size_t value);
}

#endif //RAIA_SKIA_SK_FILE_W_STREAM_H
