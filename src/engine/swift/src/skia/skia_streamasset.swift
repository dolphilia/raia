extension Skia {
    class SkStreamAsset {
        public var pointer: SkStreamAssetMutablePointer?
        public var handle: sk_stream_asset_t = -1

        // void SkStreamAsset_delete(void *stream_asset); // (SkStreamAsset *stream_asset)

        deinit {
            if self.handle > -1 {
                static_sk_stream_asset_delete(self.handle)
            } else {
                SkStreamAsset_delete(self.pointer)
            }
        }
        // bool SkStreamAsset_hasLength(void *stream_asset); // (SkStreamAsset *stream_asset) -> bool

        func hasLength() -> Bool {
            return SkStreamAsset_hasLength(self.pointer)
        }
        // unsigned long SkStreamAsset_getLength(void *stream_asset); // (SkStreamAsset *stream_asset) -> size_t

        func getLength() -> UInt {
            return UInt(SkStreamAsset_getLength(self.pointer))
        }
        // int SkStreamAsset_duplicate(void *stream_asset); // (SkStreamAsset *stream_asset) -> sk_stream_asset_t

        func duplicate() -> SkStreamAsset {
            let handle = SkStreamAsset_duplicate(self.pointer)
            let pointer = static_sk_stream_asset_get(handle)
            return SkStreamAsset(pointer: pointer, handle: handle)
        }
        // int SkStreamAsset_fork(void *stream_asset); // (SkStreamAsset *stream_asset) -> sk_stream_asset_t

        func fork() -> SkStreamAsset {
            let handle = SkStreamAsset_fork(self.pointer)
            let pointer = static_sk_stream_asset_get(handle)
            return SkStreamAsset(pointer: pointer, handle: handle)
        }
        // bool SkStreamAsset_hasPosition(void *stream_asset); // (SkStreamAsset *stream_asset) -> bool

        func hasPosition() -> Bool {
            return SkStreamAsset_hasPosition(self.pointer)
        }
        // unsigned long SkStreamAsset_getPosition(void *stream_asset); // (SkStreamAsset *stream_asset) -> size_t

        func getPosition() -> UInt {
            return UInt(SkStreamAsset_getPosition(self.pointer))
        }
        // bool SkStreamAsset_seek(void *stream_asset, unsigned long position); // (SkStreamAsset *stream_asset, size_t position) -> bool

        func seek(position: UInt) -> Bool {
            return SkStreamAsset_seek(self.pointer, position)
        }
        // bool SkStreamAsset_move(void *stream_asset, long offset); // (SkStreamAsset *stream_asset, long offset) -> bool

        func move(offset: Int) -> Bool {
            return SkStreamAsset_move(self.pointer, offset)
        }
        // bool SkStreamAsset_rewind(void *stream_asset); // (SkStreamAsset *stream_asset) -> bool
        
        func rewind() -> Bool {
            return SkStreamAsset_rewind(self.pointer)
        }

        // unsigned long SkStreamAsset_read(void *stream_asset, void *buffer, unsigned long size); // (SkStreamAsset *stream_asset, void *buffer, size_t size) -> size_t

        func read(buffer: UnsafeMutableRawPointer, size: UInt) -> UInt {
            return UInt(SkStreamAsset_read(self.pointer, buffer, size))
        }
        // unsigned long SkStreamAsset_skip(void *stream_asset, unsigned long size); // (SkStreamAsset *stream_asset, size_t size) -> size_t

        func skip(size: UInt) -> UInt {
            return UInt(SkStreamAsset_skip(self.pointer, size))
        }
        // unsigned long SkStreamAsset_peek(void *stream_asset, void *buffer, unsigned long size); // (SkStreamAsset *stream_asset, void *buffer, size_t size) -> size_t
        
        func peek(buffer: UnsafeMutableRawPointer, size: UInt) -> UInt {
            return UInt(SkStreamAsset_peek(self.pointer, buffer, size))
        }
        // bool SkStreamAsset_isAtEnd(void *stream_asset); // (SkStreamAsset *stream_asset) -> bool

        func isAtEnd() -> Bool {
            return SkStreamAsset_isAtEnd(self.pointer)
        }
        // bool SkStreamAsset_readS8(void *stream_asset, void *i); // (SkStreamAsset *stream_asset, int8_t *i) -> bool

        func readS8(i: inout Int8) -> Bool {
            return SkStreamAsset_readS8(self.pointer, &i)
        }
        // bool SkStreamAsset_readS16(void *stream_asset, void *i); // (SkStreamAsset *stream_asset, int16_t *i) -> bool

        func readS16(i: inout Int16) -> Bool {
            return SkStreamAsset_readS16(self.pointer, &i)
        }
        // bool SkStreamAsset_readS32(void *stream_asset, void *i); // (SkStreamAsset *stream_asset, int32_t *i) -> bool

        func readS32(i: inout Int32) -> Bool {
            return SkStreamAsset_readS32(self.pointer, &i)
        }
        // bool SkStreamAsset_readU8(void *stream_asset, void *i); // (SkStreamAsset *stream_asset, uint8_t *i) -> bool

        func readU8(i: inout UInt8) -> Bool {
            return SkStreamAsset_readU8(self.pointer, &i)
        }
        // bool SkStreamAsset_readU16(void *stream_asset, void *i); // (SkStreamAsset *stream_asset, uint16_t *i) -> bool

        func readU16(i: inout UInt16) -> Bool {
            return SkStreamAsset_readU16(self.pointer, &i)
        }
        // bool SkStreamAsset_readU32(void *stream_asset, void *i); // (SkStreamAsset *stream_asset, uint32_t *i) -> bool

        func readU32(i: inout UInt32) -> Bool {
            return SkStreamAsset_readU32(self.pointer, &i)
        }
        // bool SkStreamAsset_readBool(void *stream_asset, void *b); // (SkStreamAsset *stream_asset, bool *b) -> bool

        func readBool(b: inout Bool) -> Bool {
            return SkStreamAsset_readBool(self.pointer, &b)
        }
        // bool SkStreamAsset_readScalar(void *stream_asset, void *v); // (SkStreamAsset *stream_asset, SkScalar *v) -> bool

        func readScalar(v: inout Float) -> Bool {
            return SkStreamAsset_readScalar(self.pointer, &v)
        }
        // bool SkStreamAsset_readPackedUInt(void *stream_asset, void *size); // (SkStreamAsset *stream_asset, size_t *size) -> bool

        func readPackedUInt(size: inout UInt) -> Bool {
            return SkStreamAsset_readPackedUInt(self.pointer, &size)
        }
        // const void *SkStreamAsset_getMemoryBase(void *stream_asset); // (SkStreamAsset *stream_asset) -> const void *

        func getMemoryBase() -> UnsafeMutableRawPointer {
            return UnsafeMutableRawPointer(mutating: SkStreamAsset_getMemoryBase(self.pointer))
        }

        // // static

        init(pointer: SkStreamAssetMutablePointer?, handle: sk_stream_asset_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkStreamAsset_MakeFromFile(const char path[]); // (const char path[]) -> sk_stream_asset_t

        static func MakeFromFile(path: String) -> SkStreamAsset {
            let handle = SkStreamAsset_MakeFromFile(path)
            let pointer = static_sk_stream_asset_get(handle)
            return SkStreamAsset(pointer: pointer, handle: handle)
        }
    }
}