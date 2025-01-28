//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_STREAM_SEEKABLE_H
#define RAIA_SKIA_SK_STREAM_SEEKABLE_H

#ifdef __cplusplus
extern "C" {
#endif

void SkStreamSeekable_delete(void *stream_seekable); // Deletes the SkStreamSeekable object and releases its resources.
int SkStreamSeekable_duplicate(void *stream_seekable); // Creates a duplicate of the given SkStreamSeekable object.
bool SkStreamSeekable_hasPosition(void *stream_seekable); // Checks if the stream supports position querying.
unsigned long SkStreamSeekable_getPosition(void *stream_seekable); // Returns the current position in the stream.
bool SkStreamSeekable_seek(void *stream_seekable, unsigned long position); // Moves the read position to the specified offset.
bool SkStreamSeekable_move(void *stream_seekable, long offset); // Moves the read position by the specified offset relative to the current position.
int SkStreamSeekable_fork(void *stream_seekable); // Creates a forked copy of the current stream at its current position.
bool SkStreamSeekable_rewind(void *stream_seekable); // Resets the read position to the beginning of the stream.
unsigned long SkStreamSeekable_read(void *stream_seekable, void *buffer, unsigned long size); // Reads up to `size` bytes from the stream into `buffer`.
unsigned long SkStreamSeekable_skip(void *stream_seekable, unsigned long size); // Skips over the specified number of bytes in the stream.
unsigned long SkStreamSeekable_peek(void *stream_seekable, void *buffer, unsigned long size); // Reads `size` bytes into `buffer` without advancing the read position.
bool SkStreamSeekable_isAtEnd(void *stream_seekable); // Checks if the stream has reached its end.
bool SkStreamSeekable_readS8(void *stream_seekable, void *i); // Reads an 8-bit signed integer from the stream.
bool SkStreamSeekable_readS16(void *stream_seekable, void *i); // Reads a 16-bit signed integer from the stream.
bool SkStreamSeekable_readS32(void *stream_seekable, void *i); // Reads a 32-bit signed integer from the stream.
bool SkStreamSeekable_readU8(void *stream_seekable, void *i); // Reads an 8-bit unsigned integer from the stream.
bool SkStreamSeekable_readU16(void *stream_seekable, void *i); // Reads a 16-bit unsigned integer from the stream.
bool SkStreamSeekable_readU32(void *stream_seekable, void *i); // Reads a 32-bit unsigned integer from the stream.
bool SkStreamSeekable_readBool(void *stream_seekable, void *b); // Reads a boolean value from the stream.
bool SkStreamSeekable_readScalar(void *stream_seekable, void *v); // Reads a scalar value from the stream.
bool SkStreamSeekable_readPackedUInt(void *stream_seekable, void *size); // Reads a packed unsigned integer from the stream.
bool SkStreamSeekable_hasLength(void *stream_seekable); // Checks if the stream has a known length.
unsigned long SkStreamSeekable_getLength(void *stream_seekable); // Returns the total length of the stream.
const void * SkStreamSeekable_getMemoryBase(void *stream_seekable); // Returns a pointer to the stream's memory base if available.

// static

int SkStreamSeekable_MakeFromFile(const char path[]); // Creates a SkStreamSeekable object from the specified file.

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_STREAM_SEEKABLE_H
