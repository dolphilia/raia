//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_W_STREAM_H
#define RAIA_SKIA_SK_W_STREAM_H

#ifdef __cplusplus
extern "C" {
#endif

void SkWStream_delete(void *w_stream); // (SkWStream *w_stream)
bool SkWStream_write(void *w_stream, const void *buffer, unsigned long size); // (SkWStream *w_stream, const void *buffer, size_t size) -> bool
void SkWStream_flush(void *w_stream); // (SkWStream *w_stream)
unsigned long SkWStream_bytesWritten(void *w_stream); // (SkWStream *w_stream) -> size_t
bool SkWStream_write8(void *w_stream, unsigned int value); // (SkWStream *w_stream, U8CPU value) -> bool
bool SkWStream_write16(void *w_stream, unsigned int value); // (SkWStream *w_stream, U16CPU value) -> bool
bool SkWStream_write32(void *w_stream, unsigned int v); // (SkWStream *w_stream, uint32_t v) -> bool
bool SkWStream_writeText(void *w_stream, const char text[]); // (SkWStream *w_stream, const char text[]) -> bool
bool SkWStream_newline(void *w_stream); // (SkWStream *w_stream) -> bool
bool SkWStream_writeDecAsText(void *w_stream, int i); // (SkWStream *w_stream, int32_t i) -> bool
bool SkWStream_writeBigDecAsText(void *w_stream, long long i, int minDigits); // (SkWStream *w_stream, int64_t i, int minDigits) -> bool
bool SkWStream_writeHexAsText(void *w_stream, unsigned int i, int minDigits); // (SkWStream *w_stream, uint32_t i, int minDigits) -> bool
bool SkWStream_writeScalarAsText(void *w_stream, float v); // (SkWStream *w_stream, SkScalar v) -> bool
bool SkWStream_writeBool(void *w_stream, bool v); // (SkWStream *w_stream, bool v) -> bool
bool SkWStream_writeScalar(void *w_stream, float v); // (SkWStream *w_stream, SkScalar v) -> bool
bool SkWStream_writePackedUInt(void *w_stream, unsigned long size); // (SkWStream *w_stream, size_t size) -> bool
bool SkWStream_writeStream(void *w_stream, void *input, unsigned long length); // (SkWStream *w_stream, SkStream *input, size_t length) -> bool

// static

int SkWStream_SizeOfPackedUInt(unsigned long value); // (size_t value) -> int

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_W_STREAM_H
