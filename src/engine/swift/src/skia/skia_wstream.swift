extension Skia {
    typealias sk_w_stream_t = Int32

    protocol SkWStreamProtocol {
        var pointer: SkWStreamMutablePointer? { get set }
        var handle: sk_w_stream_t { get set }
        // deinit // void SkWStream_delete(void *w_stream); // (SkWStream *w_stream)
        init(pointer: SkWStreamMutablePointer?, handle: sk_w_stream_t)
        // Static Methods
        static func SizeOfPackedUInt(value: UInt) -> Int // int SkWStream_SizeOfPackedUInt(unsigned long value); // (size_t value) -> int
        // Methods
        func write(buffer: UnsafeRawPointer?, size: UInt) -> Bool // bool SkWStream_write(void *w_stream, const void *buffer, unsigned long size); // (SkWStream *w_stream, const void *buffer, size_t size) -> bool
        func flush() // void SkWStream_flush(void *w_stream); // (SkWStream *w_stream)
        func bytesWritten() -> UInt // unsigned long SkWStream_bytesWritten(void *w_stream); // (SkWStream *w_stream) -> size_t
        func write8(value: UInt) -> Bool // bool SkWStream_write8(void *w_stream, unsigned int value); // (SkWStream *w_stream, U8CPU value) -> bool
        func write16(value: UInt) -> Bool // bool SkWStream_write16(void *w_stream, unsigned int value); // (SkWStream *w_stream, U16CPU value) -> bool
        func write32(v: UInt) -> Bool // bool SkWStream_write32(void *w_stream, unsigned int v); // (SkWStream *w_stream, uint32_t v) -> bool
        func writeText(text: UnsafePointer<CChar>?) -> Bool // bool SkWStream_writeText(void *w_stream, const char text[]); // (SkWStream *w_stream, const char text[]) -> bool
        func writeText(text: String) -> Bool
        func newline() -> Bool // bool SkWStream_newline(void *w_stream); // (SkWStream *w_stream) -> bool
        func writeDecAsText(i: Int) -> Bool // bool SkWStream_writeDecAsText(void *w_stream, int i); // (SkWStream *w_stream, int32_t i) -> bool
        func writeBigDecAsText(i: Int64, minDigits: Int) -> Bool // bool SkWStream_writeBigDecAsText(void *w_stream, long long i, int minDigits); // (SkWStream *w_stream, int64_t i, int minDigits) -> bool
        func writeHexAsText(i: UInt, minDigits: Int) -> Bool // bool SkWStream_writeHexAsText(void *w_stream, unsigned int i, int minDigits); // (SkWStream *w_stream, uint32_t i, int minDigits) -> bool
        func writeScalarAsText(v: Float) -> Bool // bool SkWStream_writeScalarAsText(void *w_stream, float v); // (SkWStream *w_stream, SkScalar v) -> bool
        func writeBool(v: Bool) -> Bool // bool SkWStream_writeBool(void *w_stream, bool v); // (SkWStream *w_stream, bool v) -> bool
        func writeScalar(v: Float) -> Bool // bool SkWStream_writeScalar(void *w_stream, float v); // (SkWStream *w_stream, SkScalar v) -> bool
        func writePackedUInt(size: UInt) -> Bool // bool SkWStream_writePackedUInt(void *w_stream, unsigned long size); // (SkWStream *w_stream, size_t size) -> bool
        func writeStream(input: SkStream, length: UInt) -> Bool // bool SkWStream_writeStream(void *w_stream, void *input, unsigned long length); // (SkWStream *w_stream, SkStream *input, size_t length) -> bool
    }

    class SkWStream : SkWStreamProtocol {
        public var pointer: SkWStreamMutablePointer?
        public var handle: sk_w_stream_t = -1

        deinit {
            if self.handle > -1 {
                // static_sk_w_stream_delete(self.handle)
            } else {
                SkWStream_delete(self.pointer)
            }

        }

        required init(pointer: SkWStreamMutablePointer?, handle: sk_w_stream_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func SizeOfPackedUInt(value: UInt) -> Int {
            return Int(SkWStream_SizeOfPackedUInt(value))
        }

        // Methods

        func write(buffer: UnsafeRawPointer?, size: UInt) -> Bool {
            return SkWStream_write(self.pointer, buffer, size)
        }

        func flush() {
            SkWStream_flush(self.pointer)
        }

        func bytesWritten() -> UInt {
            return SkWStream_bytesWritten(self.pointer)
        }

        func write8(value: UInt) -> Bool {
            return SkWStream_write8(self.pointer, UInt32(value))
        }

        func write16(value: UInt) -> Bool {
            return SkWStream_write16(self.pointer, UInt32(value))
        }

        func write32(v: UInt) -> Bool {
            return SkWStream_write32(self.pointer, UInt32(v))
        }

        func writeText(text: UnsafePointer<CChar>?) -> Bool {
            return SkWStream_writeText(self.pointer, text)
        }

        func writeText(text: String) -> Bool {
            return text.withCString { cString in
                return SkWStream_writeText(self.pointer, cString)
            }
        }

        func newline() -> Bool {
            return SkWStream_newline(self.pointer)
        }

        func writeDecAsText(i: Int) -> Bool {
            return SkWStream_writeDecAsText(self.pointer, Int32(i))
        }

        func writeBigDecAsText(i: Int64, minDigits: Int) -> Bool {
            return SkWStream_writeBigDecAsText(self.pointer, i, Int32(minDigits))
        }

        func writeHexAsText(i: UInt, minDigits: Int) -> Bool {
            return SkWStream_writeHexAsText(self.pointer, UInt32(i), Int32(minDigits))
        }

        func writeScalarAsText(v: Float) -> Bool {
            return SkWStream_writeScalarAsText(self.pointer, v)
        }

        func writeBool(v: Bool) -> Bool {
            return SkWStream_writeBool(self.pointer, v)
        }

        func writeScalar(v: Float) -> Bool {
            return SkWStream_writeScalar(self.pointer, v)
        }

        func writePackedUInt(size: UInt) -> Bool {
            return SkWStream_writePackedUInt(self.pointer, size)
        }

        func writeStream(input: SkStream, length: UInt) -> Bool {
            return SkWStream_writeStream(self.pointer, input.pointer, length)
        }
    }
}