//
// Created by dolphilia on 25/02/17.
//

#ifndef SK_WRITE_BUFFER_H
#define SK_WRITE_BUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

void SkWriteBuffer_delete(void * writeBuffer);
void SkWriteBuffer_writePad32(void * writeBuffer, const void * buffer, unsigned long bytes); // (SkWriteBuffer* writeBuffer, const void* buffer, size_t bytes)
void SkWriteBuffer_writeByteArray(void * writeBuffer, const void * data, unsigned long size); // (SkWriteBuffer* writeBuffer, const void* data, size_t size)
void SkWriteBuffer_writeDataAsByteArray(void * writeBuffer, const void * data); // (SkWriteBuffer* writeBuffer, const SkData* data)
void SkWriteBuffer_writeBool(void * writeBuffer, bool value); // (SkWriteBuffer* writeBuffer, bool value)
void SkWriteBuffer_writeScalar(void * writeBuffer, float value); // (SkWriteBuffer* writeBuffer, SkScalar value)
void SkWriteBuffer_writeScalarArray(void * writeBuffer, const void * value, unsigned int count); // (SkWriteBuffer* writeBuffer, const SkScalar* value, uint32_t count)
void SkWriteBuffer_writeInt(void * writeBuffer, int value); // (SkWriteBuffer* writeBuffer, int32_t value)
void SkWriteBuffer_writeIntArray(void * writeBuffer, const void * value, unsigned int count); // (SkWriteBuffer* writeBuffer, const int32_t* value, uint32_t count)
void SkWriteBuffer_writeUInt(void * writeBuffer, unsigned int value); // (SkWriteBuffer* writeBuffer, uint32_t value)
void SkWriteBuffer_write32(void * writeBuffer, int value); // (SkWriteBuffer* writeBuffer, int32_t value)
void SkWriteBuffer_writeString(void * writeBuffer, int value); // (SkWriteBuffer* writeBuffer, string_view_t value)
void SkWriteBuffer_writeFlattenable(void * writeBuffer, const void * flattenable); // (SkWriteBuffer* writeBuffer, const SkFlattenable* flattenable)
void SkWriteBuffer_writeColor(void * writeBuffer, unsigned int color); // (SkWriteBuffer* writeBuffer, SkColor color)
void SkWriteBuffer_writeColorArray(void * writeBuffer, const void * color, unsigned int count); // (SkWriteBuffer* writeBuffer, const SkColor* color, uint32_t count)
void SkWriteBuffer_writeColor4f(void * writeBuffer, const void * color); // (SkWriteBuffer* writeBuffer, const SkColor4f* color)
void SkWriteBuffer_writeColor4fArray(void * writeBuffer, const void * color, unsigned int count); // (SkWriteBuffer* writeBuffer, const SkColor4f* color, uint32_t count)
void SkWriteBuffer_writePoint(void * writeBuffer, const void * point); // (SkWriteBuffer* writeBuffer, const SkPoint* point)
void SkWriteBuffer_writePointArray(void * writeBuffer, const void * point, unsigned int count); // (SkWriteBuffer* writeBuffer, const SkPoint* point, uint32_t count)
void SkWriteBuffer_writePoint3(void * writeBuffer, const void * point); // (SkWriteBuffer* writeBuffer, const SkPoint3* point)
void SkWriteBuffer_write(void * writeBuffer, const void * m44); // (SkWriteBuffer* writeBuffer, const SkM44* m44)
void SkWriteBuffer_writeMatrix(void * writeBuffer, const void * matrix); // (SkWriteBuffer* writeBuffer, const SkMatrix* matrix)
void SkWriteBuffer_writeIRect(void * writeBuffer, const void * rect); // (SkWriteBuffer* writeBuffer, const SkIRect* rect)
void SkWriteBuffer_writeRect(void * writeBuffer, const void * rect); // (SkWriteBuffer* writeBuffer, const SkRect* rect)
void SkWriteBuffer_writeRegion(void * writeBuffer, const void * region); // (SkWriteBuffer* writeBuffer, const SkRegion* region)
void SkWriteBuffer_writeSampling(void * writeBuffer, const void * options); // (SkWriteBuffer* writeBuffer, const SkSamplingOptions* options)
void SkWriteBuffer_writePath(void * writeBuffer, const void * path); // (SkWriteBuffer* writeBuffer, const SkPath* path)
unsigned long SkWriteBuffer_writeStream(void * writeBuffer, void * stream, unsigned long length); // (SkWriteBuffer* writeBuffer, SkStream* stream, size_t length) -> size_t
void SkWriteBuffer_writeImage(void * writeBuffer, const void * image); // (SkWriteBuffer* writeBuffer, const SkImage* image)
void SkWriteBuffer_writeTypeface(void * writeBuffer, void * typeface); // (SkWriteBuffer* writeBuffer, SkTypeface* typeface)
void SkWriteBuffer_writePaint(void * writeBuffer, const void * paint); // (SkWriteBuffer* writeBuffer, const SkPaint& paint)
const void * SkWriteBuffer_serialProcs(void * writeBuffer); // (SkWriteBuffer* writeBuffer) -> const SkSerialProcs*


#ifdef __cplusplus
}
#endif


#endif //SK_WRITE_BUFFER_H
