//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_DYNAMIC_MEMORY_W_STREAM_H
#define RAIA_SKIA_SK_DYNAMIC_MEMORY_W_STREAM_H

#include "include/core/SkStream.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_stream_asset.h"

extern "C" {
SkDynamicMemoryWStream *SkDynamicMemoryWStream_new();
//SkDynamicMemoryWStream * SkDynamicMemoryWStream_new_2(SkDynamicMemoryWStream &&stream)
void SkDynamicMemoryWStream_delete(SkDynamicMemoryWStream *dynamic_memory_w_stream);
bool SkDynamicMemoryWStream_write(SkDynamicMemoryWStream *dynamic_memory_w_stream, const void *buffer, size_t size);
size_t SkDynamicMemoryWStream_bytesWritten(SkDynamicMemoryWStream *dynamic_memory_w_stream);
bool SkDynamicMemoryWStream_read(SkDynamicMemoryWStream *dynamic_memory_w_stream, void *buffer, size_t offset, size_t size);
void SkDynamicMemoryWStream_copyTo(SkDynamicMemoryWStream *dynamic_memory_w_stream, void *dst);
bool SkDynamicMemoryWStream_writeToStream(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkWStream *dst);
void SkDynamicMemoryWStream_copyToAndReset(SkDynamicMemoryWStream *dynamic_memory_w_stream, void *dst);
bool SkDynamicMemoryWStream_writeToAndReset(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkWStream *dst);
bool SkDynamicMemoryWStream_writeToAndReset_2(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkDynamicMemoryWStream *dst);
void SkDynamicMemoryWStream_prependToAndReset(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkDynamicMemoryWStream *dst);
sk_data_t SkDynamicMemoryWStream_detachAsData(SkDynamicMemoryWStream *dynamic_memory_w_stream);
sk_stream_asset_t SkDynamicMemoryWStream_detachAsStream(SkDynamicMemoryWStream *dynamic_memory_w_stream);
void SkDynamicMemoryWStream_reset(SkDynamicMemoryWStream *dynamic_memory_w_stream);
void SkDynamicMemoryWStream_padToAlign4(SkDynamicMemoryWStream *dynamic_memory_w_stream);
void SkDynamicMemoryWStream_flush(SkDynamicMemoryWStream *dynamic_memory_w_stream);
bool SkDynamicMemoryWStream_write8(SkDynamicMemoryWStream *dynamic_memory_w_stream, U8CPU value);
bool SkDynamicMemoryWStream_write16(SkDynamicMemoryWStream *dynamic_memory_w_stream, U16CPU value);
bool SkDynamicMemoryWStream_write32(SkDynamicMemoryWStream *dynamic_memory_w_stream, uint32_t v);
bool SkDynamicMemoryWStream_writeText(SkDynamicMemoryWStream *dynamic_memory_w_stream, const char text[]);
bool SkDynamicMemoryWStream_newline(SkDynamicMemoryWStream *dynamic_memory_w_stream);
bool SkDynamicMemoryWStream_writeDecAsText(SkDynamicMemoryWStream *dynamic_memory_w_stream, int32_t v);
bool SkDynamicMemoryWStream_writeBigDecAsText(SkDynamicMemoryWStream *dynamic_memory_w_stream, int64_t v, int minDigits);
bool SkDynamicMemoryWStream_writeHexAsText(SkDynamicMemoryWStream *dynamic_memory_w_stream, uint32_t v, int minDigits);
bool SkDynamicMemoryWStream_writeScalarAsText(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkScalar scalar);
bool SkDynamicMemoryWStream_writeBool(SkDynamicMemoryWStream *dynamic_memory_w_stream, bool v);
bool SkDynamicMemoryWStream_writeScalar(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkScalar scalar);
bool SkDynamicMemoryWStream_writePackedUInt(SkDynamicMemoryWStream *dynamic_memory_w_stream, size_t length);
bool SkDynamicMemoryWStream_writeStream(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkStream *input, size_t length);
// static
int SkDynamicMemoryWStream_SizeOfPackedUInt(size_t value);
}

#endif //RAIA_SKIA_SK_DYNAMIC_MEMORY_W_STREAM_H
