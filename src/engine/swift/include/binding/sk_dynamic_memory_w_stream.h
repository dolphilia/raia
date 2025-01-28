//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_DYNAMIC_MEMORY_W_STREAM_H
#define RAIA_SKIA_SK_DYNAMIC_MEMORY_W_STREAM_H

#ifdef __cplusplus
extern "C" {
#endif

void *SkDynamicMemoryWStream_new(); // () -> SkDynamicMemoryWStream *
// SkDynamicMemoryWStream * SkDynamicMemoryWStream_new_2(SkDynamicMemoryWStream &&stream)
void SkDynamicMemoryWStream_delete(void *dynamic_memory_w_stream); // (SkDynamicMemoryWStream *dynamic_memory_w_stream)
bool SkDynamicMemoryWStream_write(void *dynamic_memory_w_stream, const void *buffer, unsigned long size); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, const void *buffer, size_t size) -> bool
unsigned long SkDynamicMemoryWStream_bytesWritten(void *dynamic_memory_w_stream); // (SkDynamicMemoryWStream *dynamic_memory_w_stream) -> size_t
bool SkDynamicMemoryWStream_read(void *dynamic_memory_w_stream, void *buffer, unsigned long offset, unsigned long size); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, void *buffer, size_t offset, size_t size) -> bool
void SkDynamicMemoryWStream_copyTo(void *dynamic_memory_w_stream, void *dst); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, void *dst)
bool SkDynamicMemoryWStream_writeToStream(void *dynamic_memory_w_stream, void *dst); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, SkWStream *dst) -> bool
void SkDynamicMemoryWStream_copyToAndReset(void *dynamic_memory_w_stream, void *dst); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, void *dst)
bool SkDynamicMemoryWStream_writeToAndReset(void *dynamic_memory_w_stream, void *dst); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, SkWStream *dst) -> bool
bool SkDynamicMemoryWStream_writeToAndReset_2(void *dynamic_memory_w_stream, void *dst); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, SkDynamicMemoryWStream *dst) -> bool
void SkDynamicMemoryWStream_prependToAndReset(void *dynamic_memory_w_stream, void *dst); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, SkDynamicMemoryWStream *dst)
int SkDynamicMemoryWStream_detachAsData(void *dynamic_memory_w_stream); // (SkDynamicMemoryWStream *dynamic_memory_w_stream) -> sk_data_t
int SkDynamicMemoryWStream_detachAsStream(void *dynamic_memory_w_stream); // (SkDynamicMemoryWStream *dynamic_memory_w_stream) -> sk_stream_asset_t
void SkDynamicMemoryWStream_reset(void *dynamic_memory_w_stream); // (SkDynamicMemoryWStream *dynamic_memory_w_stream)
void SkDynamicMemoryWStream_padToAlign4(void *dynamic_memory_w_stream); // (SkDynamicMemoryWStream *dynamic_memory_w_stream)
void SkDynamicMemoryWStream_flush(void *dynamic_memory_w_stream); // (SkDynamicMemoryWStream *dynamic_memory_w_stream)
bool SkDynamicMemoryWStream_write8(void *dynamic_memory_w_stream, unsigned int value); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, U8CPU value) -> bool
bool SkDynamicMemoryWStream_write16(void *dynamic_memory_w_stream, unsigned int value); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, U16CPU value) -> bool
bool SkDynamicMemoryWStream_write32(void *dynamic_memory_w_stream, unsigned int v); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, uint32_t v) -> bool
bool SkDynamicMemoryWStream_writeText(void *dynamic_memory_w_stream, const char text[]); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, const char text[]) -> bool
bool SkDynamicMemoryWStream_newline(void *dynamic_memory_w_stream); // (SkDynamicMemoryWStream *dynamic_memory_w_stream) -> bool
bool SkDynamicMemoryWStream_writeDecAsText(void *dynamic_memory_w_stream, int v); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, int32_t v) -> bool
bool SkDynamicMemoryWStream_writeBigDecAsText(void *dynamic_memory_w_stream, long long v, int minDigits); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, int64_t v, int minDigits) -> bool
bool SkDynamicMemoryWStream_writeHexAsText(void *dynamic_memory_w_stream, unsigned int v, int minDigits); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, uint32_t v, int minDigits) -> bool
bool SkDynamicMemoryWStream_writeScalarAsText(void *dynamic_memory_w_stream, float scalar); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, SkScalar scalar) -> bool
bool SkDynamicMemoryWStream_writeBool(void *dynamic_memory_w_stream, bool v); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, bool v) -> bool
bool SkDynamicMemoryWStream_writeScalar(void *dynamic_memory_w_stream, float scalar); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, SkScalar scalar) -> bool
bool SkDynamicMemoryWStream_writePackedUInt(void *dynamic_memory_w_stream, unsigned long length); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, size_t length) -> bool
bool SkDynamicMemoryWStream_writeStream(void *dynamic_memory_w_stream, void *input, unsigned long length); // (SkDynamicMemoryWStream *dynamic_memory_w_stream, SkStream *input, size_t length) -> bool

// static

int SkDynamicMemoryWStream_SizeOfPackedUInt(unsigned long value); // (size_t value) -> int

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_DYNAMIC_MEMORY_W_STREAM_H
