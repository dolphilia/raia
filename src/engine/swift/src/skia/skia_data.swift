extension Skia {
    class Data {
        public var pointer: Skia.DataMutablePointer?
        public var handle: sk_data_t = -1

        // void SkData_delete(void *sk_data); // (SkData *sk_data)
        deinit {
            if self.handle > -1 {
                static_sk_data_delete(self.handle)
            } else {
                SkData_delete(self.pointer)
            }
        }

        // unsigned long SkData_size(void *sk_data); // (SkData *sk_data) -> size_t
        func size() -> UInt {
            return SkData_size(self.pointer)
        }
        // bool SkData_isEmpty(void *sk_data); // (SkData *sk_data) -> bool
        func isEmpty() -> Bool {
            return SkData_isEmpty(self.pointer)
        }
        // const void * SkData_data(void *sk_data); // (SkData *sk_data) -> const void *
        func data() -> UnsafeRawPointer? {
            return SkData_data(self.pointer)
        }
        // const unsigned char * SkData_bytes(void *sk_data); // (SkData *sk_data) -> const uint8_t *
        func bytes() -> UnsafePointer<UInt8>? {
            return SkData_bytes(self.pointer)
        }
        // void * SkData_writable_data(void *sk_data); // (SkData *sk_data) -> void *
        func writableData() -> UnsafeMutableRawPointer? {
            return SkData_writable_data(self.pointer)
        }
        // unsigned long SkData_copyRange(void *sk_data, unsigned long offset, unsigned long length, void *buffer); // (SkData *sk_data, size_t offset, size_t length, void *buffer) -> size_t
        func copyRange(offset: UInt, length: UInt, buffer: UnsafeMutableRawPointer?) -> UInt {
            return SkData_copyRange(self.pointer, offset, length, buffer)
        }
        // bool SkData_equals(void *sk_data, const void *other); // (SkData *sk_data, const SkData *other) -> bool
        func equals(other: Data) -> Bool {
            return SkData_equals(self.pointer, other.pointer)
        }
        // bool SkData_unique(void *sk_data); // (SkData *sk_data) -> bool
        func unique() -> Bool {
            return SkData_unique(self.pointer)
        }
        // void SkData_ref(void *sk_data); // (SkData *sk_data)
        func ref() {
            SkData_ref(self.pointer)
        }
        // void SkData_unref(void *sk_data); // (SkData *sk_data)
        func unref() {
            SkData_unref(self.pointer)
        }
        // void SkData_deref(void *sk_data); // (SkData *sk_data)
        func deref() {
            SkData_deref(self.pointer)
        }
        // bool SkData_refCntGreaterThan(void *sk_data, unsigned int threadIsolatedTestCnt); // (SkData *sk_data, int32_t threadIsolatedTestCnt) -> bool
        func refCntGreaterThan(threadIsolatedTestCnt: UInt) -> Bool {
            return SkData_refCntGreaterThan(self.pointer, UInt32(threadIsolatedTestCnt))
        }

        // // static

        init(pointer: Skia.DataMutablePointer?, handle: sk_data_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkData_MakeWithCopy(const void *data, unsigned long length); // (const void *data, size_t length) -> sk_data_t
        static func MakeWithCopy(data: UnsafeRawPointer?, length: UInt) -> Data {
            let handle = SkData_MakeWithCopy(data, length);
            let pointer = static_sk_data_get(handle)
            return Data(pointer: pointer, handle: handle)
        }
        // int SkData_MakeUninitialized(unsigned long length); // (size_t length) -> sk_data_t
        static func MakeUninitialized(length: UInt) -> Data {
            let handle = SkData_MakeUninitialized(length);
            let pointer = static_sk_data_get(handle)
            return Data(pointer: pointer, handle: handle)
        }
        // int SkData_MakeZeroInitialized(unsigned long length); // (size_t length) -> sk_data_t
        static func MakeZeroInitialized(length: UInt) -> Data {
            let handle = SkData_MakeZeroInitialized(length);
            let pointer = static_sk_data_get(handle)
            return Data(pointer: pointer, handle: handle)
        }
        // int SkData_MakeWithCString(const char cstr[]); // (const char cstr[]) -> sk_data_t
        static func MakeWithCString(cstr: UnsafePointer<CChar>?) -> Data {
            let handle = SkData_MakeWithCString(cstr);
            let pointer = static_sk_data_get(handle)
            return Data(pointer: pointer, handle: handle)
        }
        static func MakwWithString(string: String) -> Data {
            let handle = SkData_MakeWithCString(string)
            let pointer = static_sk_data_get(handle)
            return Data(pointer: pointer, handle: handle)
        }

        // int SkData_MakeWithProc(const void *ptr, unsigned long length, void(*proc)(const void *ptr, void *context), void *ctx); // (const void *ptr, size_t length, SkData::ReleaseProc proc, void *ctx) -> sk_data_t
        typealias ReleaseProc = @convention(c) (UnsafeRawPointer?, UnsafeMutableRawPointer?) -> Void
        static func MakeWithProc(ptr: UnsafeRawPointer?, length: UInt, proc: @escaping ReleaseProc, ctx: UnsafeMutableRawPointer?) -> Data {
            let handle = SkData_MakeWithProc(ptr, length, proc, ctx);
            let pointer = static_sk_data_get(handle)
            return Data(pointer: pointer, handle: handle)
        }
        // int SkData_MakeWithoutCopy(const void *data, unsigned long length); // (const void *data, size_t length) -> sk_data_t
        static func MakeWithoutCopy(data: UnsafeRawPointer?, length: UInt) -> Data {
            let handle = SkData_MakeWithoutCopy(data, length);
            let pointer = static_sk_data_get(handle)
            return Data(pointer: pointer, handle: handle)
        }
        // int SkData_MakeFromMalloc(const void *data, unsigned long length); // (const void *data, size_t length) -> sk_data_t
        static func MakeFromMalloc(data: UnsafeRawPointer?, length: UInt) -> Data {
            let handle = SkData_MakeFromMalloc(data, length);
            let pointer = static_sk_data_get(handle)
            return Data(pointer: pointer, handle: handle)
        }
        // int SkData_MakeFromFileName(const char path[]); // (const char path[]) -> sk_data_t
        static func MakeFromFileName(path: UnsafePointer<CChar>?) -> Data {
            let handle = SkData_MakeFromFileName(path);
            let pointer = static_sk_data_get(handle)
            return Data(pointer: pointer, handle: handle)
        }
        static func MakeFromaFileName(path: String) -> Data {
            let handle = SkData_MakeFromFileName(path)
            let pointer = static_sk_data_get(handle)
            return Data(pointer: pointer, handle: handle)
        }
        // int SkData_MakeFromFILE(void *f); // (FILE *f) -> sk_data_t
        static func MakeFromFILE(f: UnsafeMutableRawPointer?) -> Data {
            let handle = SkData_MakeFromFILE(f);
            let pointer = static_sk_data_get(handle)
            return Data(pointer: pointer, handle: handle)
        }
        // int SkData_MakeFromFD(int fd); // (int fd) -> sk_data_t
        static func MakeFromFD(fd: Int) -> Data {
            let handle = SkData_MakeFromFD(Int32(fd));
            let pointer = static_sk_data_get(handle)
            return Data(pointer: pointer, handle: handle)
        }
        // int SkData_MakeFromStream(void *stream, unsigned long size); // (SkStream *stream, size_t size) -> sk_data_t
        static func MakeFromStream(stream: Skia.SkStream, size: UInt) -> Data {
            let handle = SkData_MakeFromStream(stream.pointer, size);
            let pointer = static_sk_data_get(handle)
            return Data(pointer: pointer, handle: handle)
        }
        
        // int SkData_MakeSubset(const void *src, unsigned long offset, unsigned long length); // (const SkData *src, size_t offset, size_t length) -> sk_data_t
        static func MakeSubset(src: Data, offset: UInt, length: UInt) -> Data {
            let handle = SkData_MakeSubset(src.pointer, offset, length);
            let pointer = static_sk_data_get(handle)
            return Data(pointer: pointer, handle: handle)
        }
        // int SkData_MakeEmpty(); // () -> sk_data_t
        static func MakeEmpty() -> Data {
            let handle = SkData_MakeEmpty();
            let pointer = static_sk_data_get(handle)
            return Data(pointer: pointer, handle: handle)
        }
    }
}