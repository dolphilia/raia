extension Skia {
    class WStream {
        typealias sk_w_stream_t = Int32
        public var pointer: Skia.WStreamMutablePointer?
        public var handle: sk_w_stream_t?

        // void SkWStream_delete(void *w_stream); // (SkWStream *w_stream)
        deinit {
            SkWStream_delete(self.pointer)
        }
        // bool SkWStream_write(void *w_stream, const void *buffer, unsigned long size); // (SkWStream *w_stream, const void *buffer, size_t size) -> bool
        func write(buffer: UnsafeRawPointer?, size: UInt) -> Bool {
            return SkWStream_write(self.pointer, buffer, size)
        }
        // void SkWStream_flush(void *w_stream); // (SkWStream *w_stream)
        func flush() {
            SkWStream_flush(self.pointer)
        }
        // unsigned long SkWStream_bytesWritten(void *w_stream); // (SkWStream *w_stream) -> size_t
        func bytesWritten() -> UInt {
            return SkWStream_bytesWritten(self.pointer)
        }
        // bool SkWStream_write8(void *w_stream, unsigned int value); // (SkWStream *w_stream, U8CPU value) -> bool
        func write8(value: UInt) -> Bool {
            return SkWStream_write8(self.pointer, UInt32(value))
        }
        // bool SkWStream_write16(void *w_stream, unsigned int value); // (SkWStream *w_stream, U16CPU value) -> bool
        func write16(value: UInt) -> Bool {
            return SkWStream_write16(self.pointer, UInt32(value))
        }
        // bool SkWStream_write32(void *w_stream, unsigned int v); // (SkWStream *w_stream, uint32_t v) -> bool
        func write32(v: UInt) -> Bool {
            return SkWStream_write32(self.pointer, UInt32(v))
        }
        // bool SkWStream_writeText(void *w_stream, const char text[]); // (SkWStream *w_stream, const char text[]) -> bool
        func writeText(text: UnsafePointer<CChar>?) -> Bool {
            return SkWStream_writeText(self.pointer, text)
        }
        func writeText(text: String) -> Bool {
            return text.withCString { cString in
                return SkWStream_writeText(self.pointer, cString)
            }
        }
        // bool SkWStream_newline(void *w_stream); // (SkWStream *w_stream) -> bool
        func newline() -> Bool {
            return SkWStream_newline(self.pointer)
        }
        // bool SkWStream_writeDecAsText(void *w_stream, int i); // (SkWStream *w_stream, int32_t i) -> bool
        func writeDecAsText(i: Int) -> Bool {
            return SkWStream_writeDecAsText(self.pointer, Int32(i))
        }
        // bool SkWStream_writeBigDecAsText(void *w_stream, long long i, int minDigits); // (SkWStream *w_stream, int64_t i, int minDigits) -> bool
        func writeBigDecAsText(i: Int64, minDigits: Int) -> Bool {
            return SkWStream_writeBigDecAsText(self.pointer, i, Int32(minDigits))
        }
        // bool SkWStream_writeHexAsText(void *w_stream, unsigned int i, int minDigits); // (SkWStream *w_stream, uint32_t i, int minDigits) -> bool
        func writeHexAsText(i: UInt, minDigits: Int) -> Bool {
            return SkWStream_writeHexAsText(self.pointer, UInt32(i), Int32(minDigits))
        }
        // bool SkWStream_writeScalarAsText(void *w_stream, float v); // (SkWStream *w_stream, SkScalar v) -> bool
        func writeScalarAsText(v: Float) -> Bool {
            return SkWStream_writeScalarAsText(self.pointer, v)
        }
        // bool SkWStream_writeBool(void *w_stream, bool v); // (SkWStream *w_stream, bool v) -> bool
        func writeBool(v: Bool) -> Bool {
            return SkWStream_writeBool(self.pointer, v)
        }
        // bool SkWStream_writeScalar(void *w_stream, float v); // (SkWStream *w_stream, SkScalar v) -> bool
        func writeScalar(v: Float) -> Bool {
            return SkWStream_writeScalar(self.pointer, v)
        }
        // bool SkWStream_writePackedUInt(void *w_stream, unsigned long size); // (SkWStream *w_stream, size_t size) -> bool
        func writePackedUInt(size: UInt) -> Bool {
            return SkWStream_writePackedUInt(self.pointer, size)
        }
        // bool SkWStream_writeStream(void *w_stream, void *input, unsigned long length); // (SkWStream *w_stream, SkStream *input, size_t length) -> bool
        func writeStream(input: Stream, length: UInt) -> Bool {
            return SkWStream_writeStream(self.pointer, input.pointer, length)
        }

        // // static

        init(pointer: Skia.WStreamMutablePointer?, handle: sk_w_stream_t?) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkWStream_SizeOfPackedUInt(unsigned long value); // (size_t value) -> int

        static func SizeOfPackedUInt(value: UInt) -> Int {
            return Int(SkWStream_SizeOfPackedUInt(value))
        }
    }
}