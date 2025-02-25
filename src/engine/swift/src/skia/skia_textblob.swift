extension Skia {
    protocol SkTextBlobProtocol {
        var pointer: SkTextBlobMutablePointer? { get set }
        var handle: sk_text_blob_t { get set }
        // deinit // void SkTextBlob_delete(void *text_blob); // (SkTextBlob *text_blob)
        init(pointer: SkTextBlobMutablePointer?, handle: sk_text_blob_t)
        // Static Methods
        static func MakeFromText(text: UnsafeRawPointer?, byteLength: UInt, font: Skia.SkFont, encoding: SkTextEncoding) -> SkTextBlob // int SkTextBlob_MakeFromText(const void *text, unsigned long byteLength, const void *font, int encoding); // (const void *text, size_t byteLength, const SkFont *font, SkTextEncoding encoding) -> sk_text_blob_t
        static func MakeFromString(string: String, font: SkFont, encoding: SkTextEncoding) -> SkTextBlob // int SkTextBlob_MakeFromString(const char *string, const void *font, int encoding); // (const char *string, const SkFont *font, SkTextEncoding encoding) -> sk_text_blob_t
        static func MakeFromPosTextH(text: UnsafeRawPointer?, byteLength: UInt, xpos: [Float], constY: Float, font: SkFont, encoding: SkTextEncoding) -> SkTextBlob // int SkTextBlob_MakeFromPosTextH(const void *text, unsigned long byteLength, const void * xpos, float constY, const void *font, int encoding); // (const void *text, size_t byteLength, const SkScalar xpos[], SkScalar constY, const SkFont *font, SkTextEncoding encoding) -> sk_text_blob_t
        static func MakeFromPosText(text: UnsafeRawPointer?, byteLength: UInt, pos: [SkPoint], font: SkFont, encoding: SkTextEncoding) -> SkTextBlob // int SkTextBlob_MakeFromPosText(const void *text, unsigned long byteLength, const void * pos, const void *font, int encoding); // (const void *text, size_t byteLength, const SkPoint pos[], const SkFont *font, SkTextEncoding encoding) -> sk_text_blob_t
        static func MakeFromRSXform(text: UnsafeRawPointer?, byteLength: UInt, xform: [SkRSXform], font: SkFont, encoding: SkTextEncoding) -> SkTextBlob // int SkTextBlob_MakeFromRSXform(const void *text, unsigned long byteLength, const void * xform, const void *font, int encoding); // (const void *text, size_t byteLength, const SkRSXform xform[], const SkFont *font, SkTextEncoding encoding) -> sk_text_blob_t
        static func Deserialize(data: UnsafeRawPointer, size: UInt, procs: SkDeserialProcs) -> SkTextBlob // int SkTextBlob_Deserialize(const void *data, unsigned long size, const void *procs); // (const void *data, size_t size, const SkDeserialProcs *procs) -> sk_text_blob_t
        // Methods
        func bounds() -> SkRect // const void * SkTextBlob_bounds(void *text_blob); // (SkTextBlob *text_blob) -> const SkRect *
        func uniqueID() -> UInt32 // unsigned int SkTextBlob_uniqueID(void *text_blob); // (SkTextBlob *text_blob) -> uint32_t
        func getIntercepts(bounds: [Float], intervals: inout [Float], paint: SkPaint) -> Int // int SkTextBlob_getIntercepts(void *text_blob, const void * bounds, void * intervals, const void *paint); // (SkTextBlob *text_blob, const SkScalar bounds[2], SkScalar intervals[], const SkPaint *paint) -> int
        func serialize(procs: SkSerialProcs, memory: UnsafeMutableRawPointer, size: UInt) -> UInt // unsigned long SkTextBlob_serialize(void *text_blob, const void *procs, void *memory, unsigned long memory_size); // (SkTextBlob *text_blob, const SkSerialProcs *procs, void *memory, size_t memory_size) -> size_t
        func serialize(procs: SkSerialProcs) -> SkData // int SkTextBlob_serialize_2(void *text_blob, const void *procs); // (SkTextBlob *text_blob, const SkSerialProcs *procs) -> sk_data_t
        func unique() -> Bool // bool SkTextBlob_unique(void *text_blob); // (SkTextBlob *text_blob) -> bool
        func ref() // void SkTextBlob_ref(void *text_blob); // (SkTextBlob *text_blob)
        func unref() // void SkTextBlob_unref(void *text_blob); // (SkTextBlob *text_blob)
        func deref() // void SkTextBlob_deref(void *text_blob); // (SkTextBlob *text_blob)
        func refCntGreaterThan(threadIsolatedTestCnt: Int32) -> Bool // bool SkTextBlob_refCntGreaterThan(void *text_blob, int threadIsolatedTestCnt); // (SkTextBlob *text_blob, int32_t threadIsolatedTestCnt) -> bool
    }

    class SkTextBlob : SkTextBlobProtocol{
        public var pointer: SkTextBlobMutablePointer?
        public var handle: sk_text_blob_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_text_blob_delete(self.handle)
            } else {
                SkTextBlob_delete(self.pointer)
            }
        }

        required init(pointer: SkTextBlobMutablePointer?, handle: sk_text_blob_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func MakeFromText(text: UnsafeRawPointer?, byteLength: UInt, font: Skia.SkFont, encoding: SkTextEncoding) -> SkTextBlob {
            let handle = SkTextBlob_MakeFromText(text, byteLength, font.pointer, encoding.rawValue)
            let pointer = static_sk_text_blob_get_ptr(handle)
            return SkTextBlob(pointer: pointer, handle: handle)
        }

        static func MakeFromString(string: String, font: SkFont, encoding: SkTextEncoding) -> SkTextBlob {
            let handle = SkTextBlob_MakeFromString(string, font.pointer, encoding.rawValue)
            let pointer = static_sk_text_blob_get_ptr(handle)
            return SkTextBlob(pointer: pointer, handle: handle)
        }

        static func MakeFromPosTextH(text: UnsafeRawPointer?, byteLength: UInt, xpos: [Float], constY: Float, font: SkFont, encoding: SkTextEncoding) -> SkTextBlob {
            let handle = SkTextBlob_MakeFromPosTextH(text, byteLength, xpos, constY, font.pointer, encoding.rawValue)
            let pointer = static_sk_text_blob_get_ptr(handle)
            return SkTextBlob(pointer: pointer, handle: handle)
        }

        static func MakeFromPosText(text: UnsafeRawPointer?, byteLength: UInt, pos: [SkPoint], font: SkFont, encoding: SkTextEncoding) -> SkTextBlob {
            let handle = pos.withUnsafeBufferPointer { buffer in
                SkTextBlob_MakeFromPosText(text, byteLength, buffer.baseAddress, font.pointer, encoding.rawValue)
            }
            let pointer = static_sk_text_blob_get_ptr(handle)
            return SkTextBlob(pointer: pointer, handle: handle)
        }

        static func MakeFromRSXform(text: UnsafeRawPointer?, byteLength: UInt, xform: [SkRSXform], font: SkFont, encoding: SkTextEncoding) -> SkTextBlob {
            let handle = xform.withUnsafeBufferPointer { buffer in
                SkTextBlob_MakeFromRSXform(text, byteLength, buffer.baseAddress, font.pointer, encoding.rawValue)
            }
            let pointer = static_sk_text_blob_get_ptr(handle)
            return SkTextBlob(pointer: pointer, handle: handle)
        }

        static func Deserialize(data: UnsafeRawPointer, size: UInt, procs: SkDeserialProcs) -> SkTextBlob {
            let handle = SkTextBlob_Deserialize(data, size, procs.pointer)
            let pointer = static_sk_text_blob_get_ptr(handle)
            return SkTextBlob(pointer: pointer, handle: handle)
        }

        // Methods

        func bounds() -> SkRect {
            let pointer = SkTextBlob_bounds(self.pointer)
            return SkRect(pointer: UnsafeMutableRawPointer(mutating: pointer), handle: -1)
        }

        func uniqueID() -> UInt32 {
            return SkTextBlob_uniqueID(self.pointer)
        }

        func getIntercepts(bounds: [Float], intervals: inout [Float], paint: SkPaint) -> Int {
            return intervals.withUnsafeMutableBufferPointer { (buffer: inout UnsafeMutableBufferPointer<Float>) -> Int in
                Int(SkTextBlob_getIntercepts(self.pointer, bounds, buffer.baseAddress, paint.pointer))
            }
        }

        func serialize(procs: SkSerialProcs, memory: UnsafeMutableRawPointer, size: UInt) -> UInt {
            return UInt(SkTextBlob_serialize(self.pointer, procs.pointer, memory, size))
        }

        func serialize(procs: SkSerialProcs) -> SkData {
            let handle = SkTextBlob_serialize_2(self.pointer, procs.pointer)
            let pointer = static_sk_data_get_ptr(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        func unique() -> Bool {
            return SkTextBlob_unique(self.pointer)
        }

        func ref() {
            SkTextBlob_ref(self.pointer)
        }

        func unref() {
            SkTextBlob_unref(self.pointer)
        }

        func deref() {
            SkTextBlob_deref(self.pointer)
        }

        func refCntGreaterThan(threadIsolatedTestCnt: Int32) -> Bool {
            return SkTextBlob_refCntGreaterThan(self.pointer, threadIsolatedTestCnt)
        }
    }
}