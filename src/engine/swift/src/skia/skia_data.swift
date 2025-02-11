extension Skia {
    typealias SkDataReleaseProc = @convention(c) (UnsafeRawPointer?, UnsafeMutableRawPointer?) -> Void

    protocol SkDataProtocol {
        var pointer: SkDataMutablePointer? { get set }
        var handle: sk_data_t { get set }
        // deinit // void SkData_delete(void *sk_data); // (SkData *sk_data)
        init(pointer: SkDataMutablePointer?, handle: sk_data_t)
        // Static Methods
        static func MakeWithCopy(data: UnsafeRawPointer?, length: UInt) -> SkData // int SkData_MakeWithCopy(const void *data, unsigned long length); // (const void *data, size_t length) -> sk_data_t
        static func MakeUninitialized(length: UInt) -> SkData // int SkData_MakeUninitialized(unsigned long length); // (size_t length) -> sk_data_t
        static func MakeZeroInitialized(length: UInt) -> SkData // int SkData_MakeZeroInitialized(unsigned long length); // (size_t length) -> sk_data_t
        static func MakeWithCString(cstr: UnsafePointer<CChar>?) -> SkData // int SkData_MakeWithCString(const char cstr[]); // (const char cstr[]) -> sk_data_t
        static func MakeWithProc(ptr: UnsafeRawPointer?, length: UInt, proc: @escaping SkDataReleaseProc, ctx: UnsafeMutableRawPointer?) -> SkData // int SkData_MakeWithProc(const void *ptr, unsigned long length, void(*proc)(const void *ptr, void *context), void *ctx); // (const void *ptr, size_t length, SkData::ReleaseProc proc, void *ctx) -> sk_data_t
        static func MakeWithoutCopy(data: UnsafeRawPointer?, length: UInt) -> SkData // int SkData_MakeWithoutCopy(const void *data, unsigned long length); // (const void *data, size_t length) -> sk_data_t
        static func MakeFromMalloc(data: UnsafeRawPointer?, length: UInt) -> SkData // int SkData_MakeFromMalloc(const void *data, unsigned long length); // (const void *data, size_t length) -> sk_data_t
        static func MakeFromFileName(path: UnsafePointer<CChar>?) -> SkData // int SkData_MakeFromFileName(const char path[]); // (const char path[]) -> sk_data_t
        static func MakeFromFILE(f: UnsafeMutableRawPointer?) -> SkData // int SkData_MakeFromFILE(void *f); // (FILE *f) -> sk_data_t
        static func MakeFromFD(fd: Int) -> SkData // int SkData_MakeFromFD(int fd); // (int fd) -> sk_data_t
        static func MakeFromStream(stream: SkStream, size: UInt) -> SkData // int SkData_MakeFromStream(void *stream, unsigned long size); // (SkStream *stream, size_t size) -> sk_data_t
        static func MakeSubset(src: SkData, offset: UInt, length: UInt) -> SkData // int SkData_MakeSubset(const void *src, unsigned long offset, unsigned long length); // (const SkData *src, size_t offset, size_t length) -> sk_data_t
        static func MakeEmpty() -> SkData // int SkData_MakeEmpty(); // () -> sk_data_t
        // Methods
        func size() -> UInt // unsigned long SkData_size(void *sk_data); // (SkData *sk_data) -> size_t
        func isEmpty() -> Bool // bool SkData_isEmpty(void *sk_data); // (SkData *sk_data) -> bool
        func data() -> UnsafeRawPointer? // const void * SkData_data(void *sk_data); // (SkData *sk_data) -> const void *
        func bytes() -> UnsafePointer<UInt8>? // const unsigned char * SkData_bytes(void *sk_data); // (SkData *sk_data) -> const uint8_t *
        func writableData() -> UnsafeMutableRawPointer? // void * SkData_writable_data(void *sk_data); // (SkData *sk_data) -> void *
        func copyRange(offset: UInt, length: UInt, buffer: UnsafeMutableRawPointer?) -> UInt // unsigned long SkData_copyRange(void *sk_data, unsigned long offset, unsigned long length, void *buffer); // (SkData *sk_data, size_t offset, size_t length, void *buffer) -> size_t
        func equals(other: SkData) -> Bool // bool SkData_equals(void *sk_data, const void *other); // (SkData *sk_data, const SkData *other) -> bool
        func unique() -> Bool // bool SkData_unique(void *sk_data); // (SkData *sk_data) -> bool
        func ref() // void SkData_ref(void *sk_data); // (SkData *sk_data)
        func unref() // void SkData_unref(void *sk_data); // (SkData *sk_data)
        func deref() // void SkData_deref(void *sk_data); // (SkData *sk_data)
        func refCntGreaterThan(threadIsolatedTestCnt: UInt) -> Bool // bool SkData_refCntGreaterThan(void *sk_data, unsigned int threadIsolatedTestCnt); // (SkData *sk_data, int32_t threadIsolatedTestCnt) -> bool
    }

    class SkData : SkDataProtocol {
        public var pointer: SkDataMutablePointer?
        public var handle: sk_data_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_data_delete(self.handle)
            } else {
                SkData_delete(self.pointer)
            }
        }

        required init(pointer: SkDataMutablePointer?, handle: sk_data_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func MakeWithCopy(data: UnsafeRawPointer?, length: UInt) -> SkData {
            let handle = SkData_MakeWithCopy(data, length);
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        static func MakeUninitialized(length: UInt) -> SkData {
            let handle = SkData_MakeUninitialized(length);
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        static func MakeZeroInitialized(length: UInt) -> SkData {
            let handle = SkData_MakeZeroInitialized(length);
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        static func MakeWithCString(cstr: UnsafePointer<CChar>?) -> SkData {
            let handle = SkData_MakeWithCString(cstr);
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        static func MakwWithString(string: String) -> SkData {
            let handle = SkData_MakeWithCString(string)
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        static func MakeWithProc(ptr: UnsafeRawPointer?, length: UInt, proc: @escaping SkDataReleaseProc, ctx: UnsafeMutableRawPointer?) -> SkData {
            let handle = SkData_MakeWithProc(ptr, length, proc, ctx);
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        static func MakeWithoutCopy(data: UnsafeRawPointer?, length: UInt) -> SkData {
            let handle = SkData_MakeWithoutCopy(data, length);
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        static func MakeFromMalloc(data: UnsafeRawPointer?, length: UInt) -> SkData {
            let handle = SkData_MakeFromMalloc(data, length);
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        static func MakeFromFileName(path: UnsafePointer<CChar>?) -> SkData {
            let handle = SkData_MakeFromFileName(path);
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        static func MakeFromaFileName(path: String) -> SkData {
            let handle = SkData_MakeFromFileName(path)
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        static func MakeFromFILE(f: UnsafeMutableRawPointer?) -> SkData {
            let handle = SkData_MakeFromFILE(f);
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        static func MakeFromFD(fd: Int) -> SkData {
            let handle = SkData_MakeFromFD(Int32(fd));
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        static func MakeFromStream(stream: SkStream, size: UInt) -> SkData {
            let handle = SkData_MakeFromStream(stream.pointer, size);
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        static func MakeSubset(src: SkData, offset: UInt, length: UInt) -> SkData {
            let handle = SkData_MakeSubset(src.pointer, offset, length);
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        static func MakeEmpty() -> SkData {
            let handle = SkData_MakeEmpty();
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        // Methods

        func size() -> UInt {
            return SkData_size(self.pointer)
        }

        func isEmpty() -> Bool {
            return SkData_isEmpty(self.pointer)
        }

        func data() -> UnsafeRawPointer? {
            return SkData_data(self.pointer)
        }

        func bytes() -> UnsafePointer<UInt8>? {
            return SkData_bytes(self.pointer)
        }

        func writableData() -> UnsafeMutableRawPointer? {
            return SkData_writable_data(self.pointer)
        }

        func copyRange(offset: UInt, length: UInt, buffer: UnsafeMutableRawPointer?) -> UInt {
            return SkData_copyRange(self.pointer, offset, length, buffer)
        }

        func equals(other: SkData) -> Bool {
            return SkData_equals(self.pointer, other.pointer)
        }

        func unique() -> Bool {
            return SkData_unique(self.pointer)
        }

        func ref() {
            SkData_ref(self.pointer)
        }

        func unref() {
            SkData_unref(self.pointer)
        }

        func deref() {
            SkData_deref(self.pointer)
        }

        func refCntGreaterThan(threadIsolatedTestCnt: UInt) -> Bool {
            return SkData_refCntGreaterThan(self.pointer, UInt32(threadIsolatedTestCnt))
        }
    }
}