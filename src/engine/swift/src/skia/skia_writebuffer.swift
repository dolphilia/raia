extension Skia {
    typealias sk_writebuffer_t = Int32

    protocol SkWriteBufferProtocol {
        var pointer: SkWriteBufferMutablePointer? { get set }
        var handle: sk_writebuffer_t { get set }
        // void SkWriteBuffer_delete(void * writeBuffer);

        deinit {
            if self.handle > -1 {
                // static_sk_writebuffer_delete(self.handle)
            } else {
                SkWriteBuffer_delete(self.pointer)
            }
        }

        init(pointer: SkWriteBufferMutablePointer?, handle: sk_writebuffer_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // void SkWriteBuffer_writePad32(void * writeBuffer, const void * buffer, unsigned long bytes); // (SkWriteBuffer* writeBuffer, const void* buffer, size_t bytes)

        func writePad32(buffer: UnsafeRawPointer, bytes: UInt) {
            SkWriteBuffer_writePad32(self.pointer, buffer, bytes)
        }
        // void SkWriteBuffer_writeByteArray(void * writeBuffer, const void * data, unsigned long size); // (SkWriteBuffer* writeBuffer, const void* data, size_t size)

        func writeByteArray(data: UnsafeRawPointer, size: UInt) {
            SkWriteBuffer_writeByteArray(self.pointer, data, size)
        }
        // void SkWriteBuffer_writeDataAsByteArray(void * writeBuffer, const void * data); // (SkWriteBuffer* writeBuffer, const SkData* data)

        func writeDataAsByteArray(data: SkData) {
            SkWriteBuffer_writeDataAsByteArray(self.pointer, data.pointer)
        }
        // void SkWriteBuffer_writeBool(void * writeBuffer, bool value); // (SkWriteBuffer* writeBuffer, bool value)

        func writeBool(value: Bool) {
            SkWriteBuffer_writeBool(self.pointer, value)
        }
        // void SkWriteBuffer_writeScalar(void * writeBuffer, float value); // (SkWriteBuffer* writeBuffer, SkScalar value)

        func writeScalar(value: Float) {
            SkWriteBuffer_writeScalar(self.pointer, value)
        }
        // void SkWriteBuffer_writeScalarArray(void * writeBuffer, const void * value, unsigned int count); // (SkWriteBuffer* writeBuffer, const SkScalar* value, uint32_t count)

        func writeScalarArray(value: [Float], count: UInt) {
            SkWriteBuffer_writeScalarArray(self.pointer, value, UInt32(count))
        }
        // void SkWriteBuffer_writeInt(void * writeBuffer, int value); // (SkWriteBuffer* writeBuffer, int32_t value)

        func writeInt(value: Int) {
            SkWriteBuffer_writeInt(self.pointer, Int32(value))
        }
        // void SkWriteBuffer_writeIntArray(void * writeBuffer, const void * value, unsigned int count); // (SkWriteBuffer* writeBuffer, const int32_t* value, uint32_t count)
        
        func writeIntArray(values: [Int]) {
            let int32Values = values.map { Int32($0) }
            SkWriteBuffer_writeIntArray(self.pointer, int32Values, UInt32(int32Values.count))
        }
        // void SkWriteBuffer_writeUInt(void * writeBuffer, unsigned int value); // (SkWriteBuffer* writeBuffer, uint32_t value)
        
        func writeUInt(value: UInt) {
            SkWriteBuffer_writeUInt(self.pointer, UInt32(value))
        }
        // void SkWriteBuffer_write32(void * writeBuffer, int value); // (SkWriteBuffer* writeBuffer, int32_t value)
        
        func write32(value: Int) {
            SkWriteBuffer_write32(self.pointer, Int32(value))
        }
        // void SkWriteBuffer_writeString(void * writeBuffer, int value); // (SkWriteBuffer* writeBuffer, string_view_t value)

        func writeString(value: StringView) {
            SkWriteBuffer_writeString(self.pointer, value.handle)
        }
        // void SkWriteBuffer_writeFlattenable(void * writeBuffer, const void * flattenable); // (SkWriteBuffer* writeBuffer, const SkFlattenable* flattenable)

        func writeFlattenable(flattenable: SkFlattenable) {
            SkWriteBuffer_writeFlattenable(self.pointer, flattenable.pointer)
        }
        // void SkWriteBuffer_writeColor(void * writeBuffer, unsigned int color); // (SkWriteBuffer* writeBuffer, SkColor color)

        func writeColor(color: SkColor) {
            SkWriteBuffer_writeColor(self.pointer, color)
        }
        // void SkWriteBuffer_writeColorArray(void * writeBuffer, const void * color, unsigned int count); // (SkWriteBuffer* writeBuffer, const SkColor* color, uint32_t count)

        func writeColorArray(color: [SkColor]) {
            SkWriteBuffer_writeColorArray(self.pointer, color, UInt32(color.count))
        }
        // void SkWriteBuffer_writeColor4f(void * writeBuffer, const void * color); // (SkWriteBuffer* writeBuffer, const SkColor4f* color)
        
        func writeColor4f(color: SkColor4f) {
            SkWriteBuffer_writeColor4f(self.pointer, color.pointer)
        }
        // void SkWriteBuffer_writeColor4fArray(void * writeBuffer, const void * color, unsigned int count); // (SkWriteBuffer* writeBuffer, const SkColor4f* color, uint32_t count)
        
        func writeColor4fArray(colors: [SkColor4f]) {
            SkWriteBuffer_writeColor4fArray(self.pointer, colors.map { $0.pointer }, UInt32(colors.count))
        }
        // void SkWriteBuffer_writePoint(void * writeBuffer, const void * point); // (SkWriteBuffer* writeBuffer, const SkPoint* point)

        func writePoint(point: SkPoint) {
            SkWriteBuffer_writePoint(self.pointer, point.pointer)
        }
        // void SkWriteBuffer_writePointArray(void * writeBuffer, const void * point, unsigned int count); // (SkWriteBuffer* writeBuffer, const SkPoint* point, uint32_t count)

        func writePointArray(points: [SkPoint]) {
            SkWriteBuffer_writePointArray(self.pointer, points.map { $0.pointer }, UInt32(points.count))
        }
        // void SkWriteBuffer_writePoint3(void * writeBuffer, const void * point); // (SkWriteBuffer* writeBuffer, const SkPoint3* point)

        func writePoint3(point: SkPoint3) {
            SkWriteBuffer_writePoint3(self.pointer, point.pointer)
        }
        // void SkWriteBuffer_write(void * writeBuffer, const void * m44); // (SkWriteBuffer* writeBuffer, const SkM44* m44)

        func write(m44: SkM44) {
            SkWriteBuffer_write(self.pointer, m44.pointer)
        }
        // void SkWriteBuffer_writeMatrix(void * writeBuffer, const void * matrix); // (SkWriteBuffer* writeBuffer, const SkMatrix* matrix)

        func writeMatrix(matrix: SkMatrix) {
            SkWriteBuffer_writeMatrix(self.pointer, matrix.pointer)
        }
        // void SkWriteBuffer_writeIRect(void * writeBuffer, const void * rect); // (SkWriteBuffer* writeBuffer, const SkIRect* rect)

        func writeIRect(rect: SkIRect) {
            SkWriteBuffer_writeIRect(self.pointer, rect.pointer)
        }
        // void SkWriteBuffer_writeRect(void * writeBuffer, const void * rect); // (SkWriteBuffer* writeBuffer, const SkRect* rect)

        func writeRect(rect: SkRect) {
            SkWriteBuffer_writeRect(self.pointer, rect.pointer)
        }
        // void SkWriteBuffer_writeRegion(void * writeBuffer, const void * region); // (SkWriteBuffer* writeBuffer, const SkRegion* region)

        func writeRegion(region: SkRegion) {
            SkWriteBuffer_writeRegion(self.pointer, region.pointer)
        }
        // void SkWriteBuffer_writeSampling(void * writeBuffer, const void * options); // (SkWriteBuffer* writeBuffer, const SkSamplingOptions* options)

        func writeSampling(options: SkSamplingOptions) {
            SkWriteBuffer_writeSampling(self.pointer, options.pointer)
        }
        // void SkWriteBuffer_writePath(void * writeBuffer, const void * path); // (SkWriteBuffer* writeBuffer, const SkPath* path)

        func writePath(path: SkPath)
        // unsigned long SkWriteBuffer_writeStream(void * writeBuffer, void * stream, unsigned long length); // (SkWriteBuffer* writeBuffer, SkStream* stream, size_t length) -> size_t

        func writeStream(stream: SkStream, length: UInt) -> UInt
        // void SkWriteBuffer_writeImage(void * writeBuffer, const void * image); // (SkWriteBuffer* writeBuffer, const SkImage* image)

        func writeImage(image: SkImage)
        // void SkWriteBuffer_writeTypeface(void * writeBuffer, void * typeface); // (SkWriteBuffer* writeBuffer, SkTypeface* typeface)

        func writeTypeface(typeface: SkTypeface)
        // void SkWriteBuffer_writePaint(void * writeBuffer, const void * paint); // (SkWriteBuffer* writeBuffer, const SkPaint& paint)
        
        func writePaint(paint: SkPaint)
        
        // const void * SkWriteBuffer_serialProcs(void * writeBuffer); // (SkWriteBuffer* writeBuffer) -> const SkSerialProcs*

        func serialProcs() -> SkSerialProcs
    }

    class SkWriteBuffer : SkWriteBufferProtocol {
        public var pointer: SkWriteBufferMutablePointer?
        public var handle: sk_writebuffer_t = -1

        // void SkWriteBuffer_delete(void * writeBuffer);

        deinit {
            if self.handle > -1 {
                // static_sk_writebuffer_delete(self.handle)
            } else {
                SkWriteBuffer_delete(self.pointer)
            }
        }

        init(pointer: SkWriteBufferMutablePointer?, handle: sk_writebuffer_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // void SkWriteBuffer_writePad32(void * writeBuffer, const void * buffer, unsigned long bytes); // (SkWriteBuffer* writeBuffer, const void* buffer, size_t bytes)

        func writePad32(buffer: UnsafeRawPointer, bytes: UInt) {
            SkWriteBuffer_writePad32(self.pointer, buffer, bytes)
        }
        // void SkWriteBuffer_writeByteArray(void * writeBuffer, const void * data, unsigned long size); // (SkWriteBuffer* writeBuffer, const void* data, size_t size)

        func writeByteArray(data: UnsafeRawPointer, size: UInt) {
            SkWriteBuffer_writeByteArray(self.pointer, data, size)
        }
        // void SkWriteBuffer_writeDataAsByteArray(void * writeBuffer, const void * data); // (SkWriteBuffer* writeBuffer, const SkData* data)

        func writeDataAsByteArray(data: SkData) {
            SkWriteBuffer_writeDataAsByteArray(self.pointer, data.pointer)
        }
        // void SkWriteBuffer_writeBool(void * writeBuffer, bool value); // (SkWriteBuffer* writeBuffer, bool value)

        func writeBool(value: Bool) {
            SkWriteBuffer_writeBool(self.pointer, value)
        }
        // void SkWriteBuffer_writeScalar(void * writeBuffer, float value); // (SkWriteBuffer* writeBuffer, SkScalar value)

        func writeScalar(value: Float) {
            SkWriteBuffer_writeScalar(self.pointer, value)
        }
        // void SkWriteBuffer_writeScalarArray(void * writeBuffer, const void * value, unsigned int count); // (SkWriteBuffer* writeBuffer, const SkScalar* value, uint32_t count)

        func writeScalarArray(value: [Float], count: UInt) {
            SkWriteBuffer_writeScalarArray(self.pointer, value, UInt32(count))
        }
        // void SkWriteBuffer_writeInt(void * writeBuffer, int value); // (SkWriteBuffer* writeBuffer, int32_t value)

        func writeInt(value: Int) {
            SkWriteBuffer_writeInt(self.pointer, Int32(value))
        }
        // void SkWriteBuffer_writeIntArray(void * writeBuffer, const void * value, unsigned int count); // (SkWriteBuffer* writeBuffer, const int32_t* value, uint32_t count)
        
        func writeIntArray(values: [Int]) {
            let int32Values = values.map { Int32($0) }
            SkWriteBuffer_writeIntArray(self.pointer, int32Values, UInt32(int32Values.count))
        }
        // void SkWriteBuffer_writeUInt(void * writeBuffer, unsigned int value); // (SkWriteBuffer* writeBuffer, uint32_t value)
        
        func writeUInt(value: UInt) {
            SkWriteBuffer_writeUInt(self.pointer, UInt32(value))
        }
        // void SkWriteBuffer_write32(void * writeBuffer, int value); // (SkWriteBuffer* writeBuffer, int32_t value)
        
        func write32(value: Int) {
            SkWriteBuffer_write32(self.pointer, Int32(value))
        }
        // void SkWriteBuffer_writeString(void * writeBuffer, int value); // (SkWriteBuffer* writeBuffer, string_view_t value)

        func writeString(value: StringView) {
            SkWriteBuffer_writeString(self.pointer, value.handle)
        }
        // void SkWriteBuffer_writeFlattenable(void * writeBuffer, const void * flattenable); // (SkWriteBuffer* writeBuffer, const SkFlattenable* flattenable)

        func writeFlattenable(flattenable: SkFlattenable) {
            SkWriteBuffer_writeFlattenable(self.pointer, flattenable.pointer)
        }
        // void SkWriteBuffer_writeColor(void * writeBuffer, unsigned int color); // (SkWriteBuffer* writeBuffer, SkColor color)

        func writeColor(color: SkColor) {
            SkWriteBuffer_writeColor(self.pointer, color)
        }
        // void SkWriteBuffer_writeColorArray(void * writeBuffer, const void * color, unsigned int count); // (SkWriteBuffer* writeBuffer, const SkColor* color, uint32_t count)

        func writeColorArray(color: [SkColor]) {
            SkWriteBuffer_writeColorArray(self.pointer, color, UInt32(color.count))
        }
        // void SkWriteBuffer_writeColor4f(void * writeBuffer, const void * color); // (SkWriteBuffer* writeBuffer, const SkColor4f* color)
        
        func writeColor4f(color: SkColor4f) {
            SkWriteBuffer_writeColor4f(self.pointer, color.pointer)
        }
        // void SkWriteBuffer_writeColor4fArray(void * writeBuffer, const void * color, unsigned int count); // (SkWriteBuffer* writeBuffer, const SkColor4f* color, uint32_t count)
        
        func writeColor4fArray(colors: [SkColor4f]) {
            SkWriteBuffer_writeColor4fArray(self.pointer, colors.map { $0.pointer }, UInt32(colors.count))
        }
        // void SkWriteBuffer_writePoint(void * writeBuffer, const void * point); // (SkWriteBuffer* writeBuffer, const SkPoint* point)

        func writePoint(point: SkPoint) {
            SkWriteBuffer_writePoint(self.pointer, point.pointer)
        }
        // void SkWriteBuffer_writePointArray(void * writeBuffer, const void * point, unsigned int count); // (SkWriteBuffer* writeBuffer, const SkPoint* point, uint32_t count)

        func writePointArray(points: [SkPoint]) {
            SkWriteBuffer_writePointArray(self.pointer, points.map { $0.pointer }, UInt32(points.count))
        }
        // void SkWriteBuffer_writePoint3(void * writeBuffer, const void * point); // (SkWriteBuffer* writeBuffer, const SkPoint3* point)

        func writePoint3(point: SkPoint3) {
            SkWriteBuffer_writePoint3(self.pointer, point.pointer)
        }
        // void SkWriteBuffer_write(void * writeBuffer, const void * m44); // (SkWriteBuffer* writeBuffer, const SkM44* m44)

        func write(m44: SkM44) {
            SkWriteBuffer_write(self.pointer, m44.pointer)
        }
        // void SkWriteBuffer_writeMatrix(void * writeBuffer, const void * matrix); // (SkWriteBuffer* writeBuffer, const SkMatrix* matrix)

        func writeMatrix(matrix: SkMatrix) {
            SkWriteBuffer_writeMatrix(self.pointer, matrix.pointer)
        }
        // void SkWriteBuffer_writeIRect(void * writeBuffer, const void * rect); // (SkWriteBuffer* writeBuffer, const SkIRect* rect)

        func writeIRect(rect: SkIRect) {
            SkWriteBuffer_writeIRect(self.pointer, rect.pointer)
        }
        // void SkWriteBuffer_writeRect(void * writeBuffer, const void * rect); // (SkWriteBuffer* writeBuffer, const SkRect* rect)

        func writeRect(rect: SkRect) {
            SkWriteBuffer_writeRect(self.pointer, rect.pointer)
        }
        // void SkWriteBuffer_writeRegion(void * writeBuffer, const void * region); // (SkWriteBuffer* writeBuffer, const SkRegion* region)

        func writeRegion(region: SkRegion) {
            SkWriteBuffer_writeRegion(self.pointer, region.pointer)
        }
        // void SkWriteBuffer_writeSampling(void * writeBuffer, const void * options); // (SkWriteBuffer* writeBuffer, const SkSamplingOptions* options)

        func writeSampling(options: SkSamplingOptions) {
            SkWriteBuffer_writeSampling(self.pointer, options.pointer)
        }
        // void SkWriteBuffer_writePath(void * writeBuffer, const void * path); // (SkWriteBuffer* writeBuffer, const SkPath* path)

        func writePath(path: SkPath) {
            SkWriteBuffer_writePath(self.pointer, path.pointer)
        }
        // unsigned long SkWriteBuffer_writeStream(void * writeBuffer, void * stream, unsigned long length); // (SkWriteBuffer* writeBuffer, SkStream* stream, size_t length) -> size_t

        func writeStream(stream: SkStream, length: UInt) -> UInt {
            return SkWriteBuffer_writeStream(self.pointer, stream.pointer, length)
        }
        // void SkWriteBuffer_writeImage(void * writeBuffer, const void * image); // (SkWriteBuffer* writeBuffer, const SkImage* image)

        func writeImage(image: SkImage) {
            SkWriteBuffer_writeImage(self.pointer, image.pointer)
        }
        // void SkWriteBuffer_writeTypeface(void * writeBuffer, void * typeface); // (SkWriteBuffer* writeBuffer, SkTypeface* typeface)

        func writeTypeface(typeface: SkTypeface) {
            SkWriteBuffer_writeTypeface(self.pointer, typeface.pointer)
        }
        // void SkWriteBuffer_writePaint(void * writeBuffer, const void * paint); // (SkWriteBuffer* writeBuffer, const SkPaint& paint)
        
        func writePaint(paint: SkPaint) {
            SkWriteBuffer_writePaint(self.pointer, paint.pointer)
        }
        
        // const void * SkWriteBuffer_serialProcs(void * writeBuffer); // (SkWriteBuffer* writeBuffer) -> const SkSerialProcs*

        func serialProcs() -> SkSerialProcs {
            let pointer = SkWriteBuffer_serialProcs(self.pointer)
            return SkSerialProcs(pointer: UnsafeMutableRawPointer(mutating: pointer), handle: -1)
        }

    }
}