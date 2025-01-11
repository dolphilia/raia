//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_W_STREAM_H
#define RAIA_SKIA_SK_W_STREAM_H

#include "include/core/SkStream.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkWStream_delete(SkWStream *w_stream);
RAIA_API bool SkWStream_write(SkWStream *w_stream, const void *buffer, size_t size);
RAIA_API void SkWStream_flush(SkWStream *w_stream);
RAIA_API size_t SkWStream_bytesWritten(SkWStream *w_stream);
RAIA_API bool SkWStream_write8(SkWStream *w_stream, U8CPU value);
RAIA_API bool SkWStream_write16(SkWStream *w_stream, U16CPU value);
RAIA_API bool SkWStream_write32(SkWStream *w_stream, uint32_t v);
RAIA_API bool SkWStream_writeText(SkWStream *w_stream, const char text[]);
RAIA_API bool SkWStream_newline(SkWStream *w_stream);
RAIA_API bool SkWStream_writeDecAsText(SkWStream *w_stream, int32_t i);
RAIA_API bool SkWStream_writeBigDecAsText(SkWStream *w_stream, int64_t i, int minDigits);
RAIA_API bool SkWStream_writeHexAsText(SkWStream *w_stream, uint32_t i, int minDigits);
RAIA_API bool SkWStream_writeScalarAsText(SkWStream *w_stream, SkScalar v);
RAIA_API bool SkWStream_writeBool(SkWStream *w_stream, bool v);
RAIA_API bool SkWStream_writeScalar(SkWStream *w_stream, SkScalar v);
RAIA_API bool SkWStream_writePackedUInt(SkWStream *w_stream, size_t size);
RAIA_API bool SkWStream_writeStream(SkWStream *w_stream, SkStream *input, size_t length);
// static
RAIA_API int SkWStream_SizeOfPackedUInt(size_t value);
}

#endif //RAIA_SKIA_SK_W_STREAM_H
