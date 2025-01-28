//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_FILE_W_STREAM_H
#define RAIA_SKIA_SK_FILE_W_STREAM_H

#ifdef __cplusplus
extern "C" {
#endif

void *SkFILEWStream_new(const char path[]); // (const char path[]) -> SkFILEWStream *
void SkFILEWStream_delete(void *file_w_stream); // (SkFILEWStream *file_w_stream)
bool SkFILEWStream_isValid(void *file_w_stream); // (SkFILEWStream *file_w_stream) -> bool
bool SkFILEWStream_write(void *file_w_stream, const void *buffer, unsigned long size); // (SkFILEWStream *file_w_stream, const void *buffer, size_t size) -> bool
void SkFILEWStream_flush(void *file_w_stream); // (SkFILEWStream *file_w_stream)
void SkFILEWStream_fsync(void *file_w_stream); // (SkFILEWStream *file_w_stream)
unsigned long SkFILEWStream_bytesWritten(void *file_w_stream); // (SkFILEWStream *file_w_stream) -> size_t
bool SkFILEWStream_write8(void *file_w_stream, unsigned int value); // (SkFILEWStream *file_w_stream, U8CPU value) -> bool
bool SkFILEWStream_write16(void *file_w_stream, unsigned int value); // (SkFILEWStream *file_w_stream, U16CPU value) -> bool
bool SkFILEWStream_write32(void *file_w_stream, unsigned int v); // (SkFILEWStream *file_w_stream, uint32_t v) -> bool
bool SkFILEWStream_writeText(void *file_w_stream, const char text[]); // (SkFILEWStream *file_w_stream, const char text[]) -> bool
bool SkFILEWStream_newline(void *file_w_stream); // (SkFILEWStream *file_w_stream) -> bool
bool SkFILEWStream_writeDecAsText(void *file_w_stream, int v); // (SkFILEWStream *file_w_stream, int32_t v) -> bool
bool SkFILEWStream_writeBigDecAsText(void *file_w_stream, long long v, int minDigits); // (SkFILEWStream *file_w_stream, int64_t v, int minDigits) -> bool
bool SkFILEWStream_writeHexAsText(void *file_w_stream, unsigned int v, int minDigits); // (SkFILEWStream *file_w_stream, uint32_t v, int minDigits) -> bool
bool SkFILEWStream_writeScalarAsText(void *file_w_stream, float scalar); // (SkFILEWStream *file_w_stream, SkScalar scalar) -> bool
bool SkFILEWStream_writeBool(void *file_w_stream, bool v); // (SkFILEWStream *file_w_stream, bool v) -> bool
bool SkFILEWStream_writeScalar(void *file_w_stream, float scalar); // (SkFILEWStream *file_w_stream, SkScalar scalar) -> bool
bool SkFILEWStream_writePackedUInt(void *file_w_stream, unsigned long size); // (SkFILEWStream *file_w_stream, size_t size) -> bool
bool SkFILEWStream_writeStream(void *file_w_stream, void *input, unsigned long length); // (SkFILEWStream *file_w_stream, SkStream *input, size_t length) -> bool

// static

int SkFILEWStream_SizeOfPackedUInt(unsigned long value); // (size_t value) -> int

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_FILE_W_STREAM_H
