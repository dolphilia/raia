//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_DYNAMIC_MEMORY_W_STREAM_H
#define RAIA_SKIA_SK_DYNAMIC_MEMORY_W_STREAM_H

#include "include/core/SkStream.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_stream_asset.h"
#include "export_api.h"

extern "C" {
RAIA_API SkDynamicMemoryWStream *SkDynamicMemoryWStream_new();
//SkDynamicMemoryWStream * SkDynamicMemoryWStream_new_2(SkDynamicMemoryWStream &&stream)
RAIA_API void SkDynamicMemoryWStream_delete(SkDynamicMemoryWStream *dynamic_memory_w_stream);
RAIA_API bool SkDynamicMemoryWStream_write(SkDynamicMemoryWStream *dynamic_memory_w_stream, const void *buffer, size_t size);
RAIA_API size_t SkDynamicMemoryWStream_bytesWritten(SkDynamicMemoryWStream *dynamic_memory_w_stream);
RAIA_API bool SkDynamicMemoryWStream_read(SkDynamicMemoryWStream *dynamic_memory_w_stream, void *buffer, size_t offset, size_t size);
RAIA_API void SkDynamicMemoryWStream_copyTo(SkDynamicMemoryWStream *dynamic_memory_w_stream, void *dst);
RAIA_API bool SkDynamicMemoryWStream_writeToStream(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkWStream *dst);
RAIA_API void SkDynamicMemoryWStream_copyToAndReset(SkDynamicMemoryWStream *dynamic_memory_w_stream, void *dst);
RAIA_API bool SkDynamicMemoryWStream_writeToAndReset(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkWStream *dst);
RAIA_API bool SkDynamicMemoryWStream_writeToAndReset_2(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkDynamicMemoryWStream *dst);
RAIA_API void SkDynamicMemoryWStream_prependToAndReset(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkDynamicMemoryWStream *dst);
RAIA_API sk_data_t SkDynamicMemoryWStream_detachAsData(SkDynamicMemoryWStream *dynamic_memory_w_stream);
RAIA_API sk_stream_asset_t SkDynamicMemoryWStream_detachAsStream(SkDynamicMemoryWStream *dynamic_memory_w_stream);
RAIA_API void SkDynamicMemoryWStream_reset(SkDynamicMemoryWStream *dynamic_memory_w_stream);
RAIA_API void SkDynamicMemoryWStream_padToAlign4(SkDynamicMemoryWStream *dynamic_memory_w_stream);
RAIA_API void SkDynamicMemoryWStream_flush(SkDynamicMemoryWStream *dynamic_memory_w_stream);
RAIA_API bool SkDynamicMemoryWStream_write8(SkDynamicMemoryWStream *dynamic_memory_w_stream, U8CPU value);
RAIA_API bool SkDynamicMemoryWStream_write16(SkDynamicMemoryWStream *dynamic_memory_w_stream, U16CPU value);
RAIA_API bool SkDynamicMemoryWStream_write32(SkDynamicMemoryWStream *dynamic_memory_w_stream, uint32_t v);
RAIA_API bool SkDynamicMemoryWStream_writeText(SkDynamicMemoryWStream *dynamic_memory_w_stream, const char text[]);
RAIA_API bool SkDynamicMemoryWStream_newline(SkDynamicMemoryWStream *dynamic_memory_w_stream);
RAIA_API bool SkDynamicMemoryWStream_writeDecAsText(SkDynamicMemoryWStream *dynamic_memory_w_stream, int32_t v);
RAIA_API bool SkDynamicMemoryWStream_writeBigDecAsText(SkDynamicMemoryWStream *dynamic_memory_w_stream, int64_t v, int minDigits);
RAIA_API bool SkDynamicMemoryWStream_writeHexAsText(SkDynamicMemoryWStream *dynamic_memory_w_stream, uint32_t v, int minDigits);
RAIA_API bool SkDynamicMemoryWStream_writeScalarAsText(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkScalar scalar);
RAIA_API bool SkDynamicMemoryWStream_writeBool(SkDynamicMemoryWStream *dynamic_memory_w_stream, bool v);
RAIA_API bool SkDynamicMemoryWStream_writeScalar(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkScalar scalar);
RAIA_API bool SkDynamicMemoryWStream_writePackedUInt(SkDynamicMemoryWStream *dynamic_memory_w_stream, size_t length);
RAIA_API bool SkDynamicMemoryWStream_writeStream(SkDynamicMemoryWStream *dynamic_memory_w_stream, SkStream *input, size_t length);
// static
RAIA_API int SkDynamicMemoryWStream_SizeOfPackedUInt(size_t value);
}

#endif //RAIA_SKIA_SK_DYNAMIC_MEMORY_W_STREAM_H
