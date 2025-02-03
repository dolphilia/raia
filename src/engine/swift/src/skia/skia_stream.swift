extension Skia {
    class Stream {
        public var pointer: Skia.StreamMutablePointer?
        public var handle: sk_stream_t?
        // void SkStream_delete(void *stream); // (SkStream *stream)
        deinit {
            SkStream_delete(self.pointer)
            if let handle = self.handle {
                static_sk_stream_delete(handle)
            }
        }
        // unsigned long SkStream_read(void *stream, void *buffer, unsigned long size); // (SkStream *stream, void *buffer, size_t size) -> size_t
        func read(buffer: UnsafeMutableRawPointer?, size: UInt) -> UInt {
            return SkStream_read(self.pointer, buffer, size)
        }
        // unsigned long SkStream_skip(void *stream, unsigned long size); // (SkStream *stream, size_t size) -> size_t
        func skip(size: UInt) -> UInt {
            return SkStream_skip(self.pointer, size)
        }
        // unsigned long SkStream_peek(void *stream, void *buffer, unsigned long size); // (SkStream *stream, void *buffer, size_t size) -> size_t
        func peek(buffer: UnsafeMutableRawPointer?, size: UInt) -> UInt {
            return SkStream_peek(self.pointer, buffer, size)
        }
        // bool SkStream_isAtEnd(void *stream); // (SkStream *stream) -> bool
        func isAtEnd() -> Bool {
            return SkStream_isAtEnd(self.pointer)
        }
        // bool SkStream_readS8(void *stream, void *i); // (SkStream *stream, int8_t *i) -> bool
        func readS8(i: UnsafeMutablePointer<Int8>?) -> Bool {
            return SkStream_readS8(self.pointer, i)
        }
        // bool SkStream_readS16(void *stream, void *i); // (SkStream *stream, int16_t *i) -> bool
        func readS16(i: UnsafeMutablePointer<Int16>?) -> Bool {
            return SkStream_readS16(self.pointer, i)
        }
        // bool SkStream_readS32(void *stream, void *i); // (SkStream *stream, int32_t *i) -> bool
        func readS32(i: UnsafeMutablePointer<Int32>?) -> Bool {
            return SkStream_readS32(self.pointer, i)
        }
        // bool SkStream_readU8(void *stream, void *i); // (SkStream *stream, uint8_t *i) -> bool
        func readU8(i: UnsafeMutablePointer<UInt8>?) -> Bool {
            return SkStream_readU8(self.pointer, i)
        }
        // bool SkStream_readU16(void *stream, void *i); // (SkStream *stream, uint16_t *i) -> bool
        func readU16(i: UnsafeMutablePointer<UInt16>?) -> Bool {
            return SkStream_readU16(self.pointer, i)
        }
        // bool SkStream_readU32(void *stream, void *i); // (SkStream *stream, uint32_t *i) -> bool
        func readU32(i: UnsafeMutablePointer<UInt32>?) -> Bool {
            return SkStream_readU32(self.pointer, i)
        }
        // bool SkStream_readBool(void *stream, void *b); // (SkStream *stream, bool *b) -> bool
        func readBool(b: UnsafeMutablePointer<Bool>?) -> Bool {
            return SkStream_readBool(self.pointer, b)
        }
        // bool SkStream_readScalar(void *stream, void *v); // (SkStream *stream, SkScalar *v) -> bool
        func readScalar(v: UnsafeMutablePointer<Scalar>?) -> Bool {
            return SkStream_readScalar(self.pointer, v)
        }
        // bool SkStream_readPackedUInt(void *stream, void *size); // (SkStream *stream, size_t *size) -> bool
        func readPackedUInt(size: UnsafeMutablePointer<UInt>?) -> Bool {
            return SkStream_readPackedUInt(self.pointer, size)
        }
        // bool SkStream_rewind(void *stream); // (SkStream *stream) -> bool
        func rewind() -> Bool {
            return SkStream_rewind(self.pointer)
        }
        // int SkStream_duplicate(void *stream); // (SkStream *stream) -> sk_stream_t
        func duplicate() -> Stream {
            let handle = SkStream_duplicate(self.pointer);
            let pointer = static_sk_stream_get(handle)
            return Stream(pointer: pointer, handle: handle)
        }
        // int SkStream_fork(void *stream); // (SkStream *stream) -> sk_stream_t
        func fork() -> Stream {
            let handle = SkStream_fork(self.pointer);
            let pointer = static_sk_stream_get(handle)
            return Stream(pointer: pointer, handle: handle)
        }
        // bool SkStream_hasPosition(void *stream); // (SkStream *stream) -> bool
        func hasPosition() -> Bool {
            return SkStream_hasPosition(self.pointer)
        }
        // unsigned long SkStream_getPosition(void *stream); // (SkStream *stream) -> size_t
        func getPosition() -> UInt {
            return SkStream_getPosition(self.pointer)
        }
        // bool SkStream_seek(void *stream, unsigned long size); // (SkStream *stream, size_t size) -> bool
        func seek(size: UInt) -> Bool {
            return SkStream_seek(self.pointer, size)
        }
        // bool SkStream_move(void *stream, long i); // (SkStream *stream, long i) -> bool
        func move(i: Int) -> Bool {
            return SkStream_move(self.pointer, i)
        }
        // bool SkStream_hasLength(void *stream); // (SkStream *stream) -> bool
        func hasLength() -> Bool {
            return SkStream_hasLength(self.pointer)
        }
        // unsigned long SkStream_getLength(void *stream); // (SkStream *stream) -> size_t
        func getLength() -> UInt {
            return SkStream_getLength(self.pointer)
        }
        // const void * SkStream_getMemoryBase(void *stream); // (SkStream *stream) -> const void *
        func getMemoryBase() -> UnsafeRawPointer? {
            return SkStream_getMemoryBase(self.pointer)
        }

        // // static

        init(pointer: Skia.StreamMutablePointer?, handle: sk_stream_t?) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkStream_MakeFromFile(const char path[]); // (const char path[]) -> sk_stream_asset_t
        static func MakeFromFile(path: UnsafePointer<CChar>?) -> Stream {
            let handle = SkStream_MakeFromFile(path);
            let pointer = static_sk_stream_get(handle)
            return Stream(pointer: pointer, handle: handle)
        }
        static func MakeFromFileName(fileName: String) -> Stream {
            let handle = SkStream_MakeFromFile(fileName)
            let pointer = static_sk_stream_get(handle)
            return Stream(pointer: pointer, handle: handle)
        }
    }
}