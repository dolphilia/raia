extension Skia {
    protocol SkStreamProtocol {
        var pointer: Skia.SkStreamMutablePointer? { get set }
        var handle: sk_stream_t { get set }
        // deinit // void SkStream_delete(void *stream); // (SkStream *stream)
        init(pointer: Skia.SkStreamMutablePointer?, handle: sk_stream_t)
        // Static Methods
        static func MakeFromFile(path: UnsafePointer<CChar>?) -> SkStream // int SkStream_MakeFromFile(const char path[]); // (const char path[]) -> sk_stream_asset_t
        static func MakeFromFileName(fileName: String) -> SkStream
        // Methods
        func read(buffer: UnsafeMutableRawPointer?, size: UInt) -> UInt // unsigned long SkStream_read(void *stream, void *buffer, unsigned long size); // (SkStream *stream, void *buffer, size_t size) -> size_t
        func skip(size: UInt) -> UInt // unsigned long SkStream_skip(void *stream, unsigned long size); // (SkStream *stream, size_t size) -> size_t
        func peek(buffer: UnsafeMutableRawPointer?, size: UInt) -> UInt // unsigned long SkStream_peek(void *stream, void *buffer, unsigned long size); // (SkStream *stream, void *buffer, size_t size) -> size_t
        func isAtEnd() -> Bool // bool SkStream_isAtEnd(void *stream); // (SkStream *stream) -> bool
        func readS8(i: UnsafeMutablePointer<Int8>?) -> Bool // bool SkStream_readS8(void *stream, void *i); // (SkStream *stream, int8_t *i) -> bool
        func readS16(i: UnsafeMutablePointer<Int16>?) -> Bool // bool SkStream_readS16(void *stream, void *i); // (SkStream *stream, int16_t *i) -> bool
        func readS32(i: UnsafeMutablePointer<Int32>?) -> Bool // bool SkStream_readS32(void *stream, void *i); // (SkStream *stream, int32_t *i) -> bool
        func readU8(i: UnsafeMutablePointer<UInt8>?) -> Bool // bool SkStream_readU8(void *stream, void *i); // (SkStream *stream, uint8_t *i) -> bool
        func readU16(i: UnsafeMutablePointer<UInt16>?) -> Bool // bool SkStream_readU16(void *stream, void *i); // (SkStream *stream, uint16_t *i) -> bool
        func readU32(i: UnsafeMutablePointer<UInt32>?) -> Bool // bool SkStream_readU32(void *stream, void *i); // (SkStream *stream, uint32_t *i) -> bool
        func readBool(b: UnsafeMutablePointer<Bool>?) -> Bool // bool SkStream_readBool(void *stream, void *b); // (SkStream *stream, bool *b) -> bool
        func readScalar(v: UnsafeMutablePointer<Float>?) -> Bool // bool SkStream_readScalar(void *stream, void *v); // (SkStream *stream, SkScalar *v) -> bool
        func readPackedUInt(size: UnsafeMutablePointer<UInt>?) -> Bool // bool SkStream_readPackedUInt(void *stream, void *size); // (SkStream *stream, size_t *size) -> bool
        func rewind() -> Bool // bool SkStream_rewind(void *stream); // (SkStream *stream) -> bool
        func duplicate() -> SkStream // int SkStream_duplicate(void *stream); // (SkStream *stream) -> sk_stream_t
        func fork() -> SkStream // int SkStream_fork(void *stream); // (SkStream *stream) -> sk_stream_t
        func hasPosition() -> Bool // bool SkStream_hasPosition(void *stream); // (SkStream *stream) -> bool
        func getPosition() -> UInt // unsigned long SkStream_getPosition(void *stream); // (SkStream *stream) -> size_t
        func seek(size: UInt) -> Bool // bool SkStream_seek(void *stream, unsigned long size); // (SkStream *stream, size_t size) -> bool
        func move(i: Int) -> Bool // bool SkStream_move(void *stream, long i); // (SkStream *stream, long i) -> bool
        func hasLength() -> Bool // bool SkStream_hasLength(void *stream); // (SkStream *stream) -> bool
        func getLength() -> UInt // unsigned long SkStream_getLength(void *stream); // (SkStream *stream) -> size_t
        func getMemoryBase() -> UnsafeRawPointer? // const void * SkStream_getMemoryBase(void *stream); // (SkStream *stream) -> const void *
    }

    class SkStream : SkStreamProtocol {
        public var pointer: Skia.SkStreamMutablePointer?
        public var handle: sk_stream_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_stream_delete(self.handle)
            } else {
                SkStream_delete(self.pointer)
            }
        }

        required init(pointer: Skia.SkStreamMutablePointer?, handle: sk_stream_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func MakeFromFile(path: UnsafePointer<CChar>?) -> SkStream {
            let handle = SkStream_MakeFromFile(path);
            let pointer = static_sk_stream_get(handle)
            return SkStream(pointer: pointer, handle: handle)
        }
        static func MakeFromFileName(fileName: String) -> SkStream {
            let handle = SkStream_MakeFromFile(fileName)
            let pointer = static_sk_stream_get(handle)
            return SkStream(pointer: pointer, handle: handle)
        }

        // Methods

        func read(buffer: UnsafeMutableRawPointer?, size: UInt) -> UInt {
            return SkStream_read(self.pointer, buffer, size)
        }

        func skip(size: UInt) -> UInt {
            return SkStream_skip(self.pointer, size)
        }

        func peek(buffer: UnsafeMutableRawPointer?, size: UInt) -> UInt {
            return SkStream_peek(self.pointer, buffer, size)
        }

        func isAtEnd() -> Bool {
            return SkStream_isAtEnd(self.pointer)
        }

        func readS8(i: UnsafeMutablePointer<Int8>?) -> Bool {
            return SkStream_readS8(self.pointer, i)
        }

        func readS16(i: UnsafeMutablePointer<Int16>?) -> Bool {
            return SkStream_readS16(self.pointer, i)
        }

        func readS32(i: UnsafeMutablePointer<Int32>?) -> Bool {
            return SkStream_readS32(self.pointer, i)
        }

        func readU8(i: UnsafeMutablePointer<UInt8>?) -> Bool {
            return SkStream_readU8(self.pointer, i)
        }

        func readU16(i: UnsafeMutablePointer<UInt16>?) -> Bool {
            return SkStream_readU16(self.pointer, i)
        }

        func readU32(i: UnsafeMutablePointer<UInt32>?) -> Bool {
            return SkStream_readU32(self.pointer, i)
        }

        func readBool(b: UnsafeMutablePointer<Bool>?) -> Bool {
            return SkStream_readBool(self.pointer, b)
        }

        func readScalar(v: UnsafeMutablePointer<Float>?) -> Bool {
            return SkStream_readScalar(self.pointer, v)
        }

        func readPackedUInt(size: UnsafeMutablePointer<UInt>?) -> Bool {
            return SkStream_readPackedUInt(self.pointer, size)
        }

        func rewind() -> Bool {
            return SkStream_rewind(self.pointer)
        }

        func duplicate() -> SkStream {
            let handle = SkStream_duplicate(self.pointer);
            let pointer = static_sk_stream_get(handle)
            return SkStream(pointer: pointer, handle: handle)
        }

        func fork() -> SkStream {
            let handle = SkStream_fork(self.pointer);
            let pointer = static_sk_stream_get(handle)
            return SkStream(pointer: pointer, handle: handle)
        }

        func hasPosition() -> Bool {
            return SkStream_hasPosition(self.pointer)
        }

        func getPosition() -> UInt {
            return SkStream_getPosition(self.pointer)
        }

        func seek(size: UInt) -> Bool {
            return SkStream_seek(self.pointer, size)
        }

        func move(i: Int) -> Bool {
            return SkStream_move(self.pointer, i)
        }

        func hasLength() -> Bool {
            return SkStream_hasLength(self.pointer)
        }

        func getLength() -> UInt {
            return SkStream_getLength(self.pointer)
        }

        func getMemoryBase() -> UnsafeRawPointer? {
            return SkStream_getMemoryBase(self.pointer)
        }
    }
}