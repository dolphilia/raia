extension Skia {
    protocol SkColorFilterProtocol {
        var pointer: SkColorFilterMutablePointer? { get set }
        var handle: sk_color_filter_t { get set }
        // deinit // void SkColorFilter_delete(void *color_filter); // (SkColorFilter *color_filter)
        init(pointer: SkColorFilterMutablePointer?, handle: sk_color_filter_t)
        // Static Methods
        static func Deserialize(data: UnsafeRawPointer, size: UInt, procs: SkDeserialProcs) -> SkColorFilter // int SkColorFilter_Deserialize(const void *data, unsigned long size, const void *procs); // (const void *data, size_t size, const SkDeserialProcs *procs) -> sk_color_filter_t
        static func NameToFactory(name: String) -> SkFlattenableFactory // int SkColorFilter_NameToFactory(const char name[]); // (const char name[]) -> sk_flattenable_factory_t
        static func FactoryToName(factory: SkFlattenableFactory) -> String // const char *SkColorFilter_FactoryToName(int factory); // (sk_flattenable_factory_t factory) -> const char *
        static func Register(name: String, factory: SkFlattenableFactory) // void SkColorFilter_Register(const char name[], int factory); // (const char name[], sk_flattenable_factory_t factory)
        // Methods
        func asAColorMode(color: UnsafeMutablePointer<SkColor>, mode: UnsafeMutablePointer<SkBlendMode>) -> Bool // bool SkColorFilter_asAColorMode(void *color_filter, void *color, void *mode); // (SkColorFilter *color_filter, SkColor *color, SkBlendMode *mode) -> bool
        func asAColorMatrix(matrix: [Float]) -> Bool // bool SkColorFilter_asAColorMatrix(void *color_filter, float matrix[20]); // (SkColorFilter *color_filter, float matrix[20]) -> bool
        func isAlphaUnchanged() -> Bool // bool SkColorFilter_isAlphaUnchanged(void *color_filter); // (SkColorFilter *color_filter) -> bool
        func filterColor(color: SkColor) -> SkColor // unsigned int  SkColorFilter_filterColor(void *color_filter, unsigned int  color); // (SkColorFilter *color_filter, SkColor color) -> SkColor
        func filterColor4f(srcColor: SkColor4f, srcCS: SkColorSpace, dstCS: SkColorSpace) -> SkColor4f // int SkColorFilter_filterColor4f(void *color_filter, const void *srcColor, void *srcCS, void *dstCS); // (SkColorFilter *color_filter, const SkColor4f *srcColor, SkColorSpace *srcCS, SkColorSpace *dstCS) -> sk_color_4f_t
        func makeComposed(inner: SkColorFilter) -> SkColorFilter // int SkColorFilter_makeComposed(void *color_filter, int inner); // (SkColorFilter *color_filter, sk_color_filter_t inner) -> sk_color_filter_t
        func makeWithWorkingColorSpace(colorSpace: SkColorSpace) -> SkColorFilter // int SkColorFilter_makeWithWorkingColorSpace(void *color_filter, int colorSpace); // (SkColorFilter *color_filter, sk_color_space_t colorSpace) -> sk_color_filter_t
        func getFactory() -> SkFlattenableFactory // int SkColorFilter_getFactory(void *color_filter); // (SkColorFilter *color_filter) -> sk_flattenable_factory_t
        func getTypeName() -> String // const char *SkColorFilter_getTypeName(void *color_filter); // (SkColorFilter *color_filter) -> const char *
        func flatten(writeBuffer: SkWriteBuffer) // void SkColorFilter_flatten(void *color_filter, void *write_buffer); // (SkColorFilter *color_filter, SkWriteBuffer *write_buffer)
        func getFlattenableType() -> SkFlattenableType // int SkColorFilter_getFlattenableType(void *color_filter); // (SkColorFilter *color_filter) -> SkColorFilter::Type
        func serialize(serialProcs: UnsafeRawPointer?) -> SkData // int SkColorFilter_serialize(void *color_filter, const void *serial_procs); // (SkColorFilter *color_filter, const SkSerialProcs *serial_procs) -> sk_data_t
        func serialize(memory: UnsafeMutableRawPointer, memorySize: UInt, serialProcs: SkSerialProcs) -> UInt // unsigned long SkColorFilter_serialize_2(void *color_filter, void *memory, unsigned long memory_size, const void *serial_procs); // (SkColorFilter *color_filter, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) -> size_t
        func isUnique() -> Bool // bool SkColorFilter_unique(void *color_filter); // (SkColorFilter *color_filter) -> bool
        func ref() // void SkColorFilter_ref(void *color_filter); // (SkColorFilter *color_filter)
        func unref() // void SkColorFilter_unref(void *color_filter); // (SkColorFilter *color_filter)
    }

    class SkColorFilter : SkColorFilterProtocol {
        public var pointer: SkColorFilterMutablePointer?
        public var handle: sk_color_filter_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_color_filter_delete(self.handle)
            } else {
                SkColorFilter_delete(self.pointer)
            }
        }

        required init(pointer: SkColorFilterMutablePointer?, handle: sk_color_filter_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func Deserialize(data: UnsafeRawPointer, size: UInt, procs: SkDeserialProcs) -> SkColorFilter {
            let handle = SkColorFilter_Deserialize(data, size, procs.pointer)
            let pointer = static_sk_color_filter_get(handle)
            return SkColorFilter(pointer: pointer, handle: handle)
        }

        static func NameToFactory(name: String) -> SkFlattenableFactory {
            return name.withCString { cstr in
                let handle = SkColorFilter_NameToFactory(cstr)
                let pointer = static_sk_flattenable_factory_get_ptr(handle)
                return SkFlattenableFactory(pointer: pointer, handle: handle)
            }
        }

        static func FactoryToName(factory: SkFlattenableFactory) -> String {
            return String(cString: SkColorFilter_FactoryToName(factory.handle))
        }

        static func Register(name: String, factory: SkFlattenableFactory) {
            name.withCString { cstr in
                SkColorFilter_Register(cstr, factory.handle)
            }
        }

        // Methods

        func asAColorMode(color: UnsafeMutablePointer<SkColor>, mode: UnsafeMutablePointer<SkBlendMode>) -> Bool {
            return SkColorFilter_asAColorMode(self.pointer, color, mode)
        }

        func asAColorMatrix(matrix: [Float]) -> Bool {
            guard matrix.count == 20 else {
                return false
            }
            var mutableMatrix = matrix
            return mutableMatrix.withUnsafeMutableBufferPointer { buffer in
                return SkColorFilter_asAColorMatrix(self.pointer, buffer.baseAddress)
            }
        }

        func isAlphaUnchanged() -> Bool {
            return SkColorFilter_isAlphaUnchanged(self.pointer)
        }

        func filterColor(color: SkColor) -> SkColor {
            return SkColorFilter_filterColor(self.pointer, color)
        }

        func filterColor4f(srcColor: SkColor4f, srcCS: SkColorSpace, dstCS: SkColorSpace) -> SkColor4f {
            let handle = SkColorFilter_filterColor4f(self.pointer, srcColor.pointer, srcCS.pointer, dstCS.pointer)
            let pointer = static_sk_color_4f_get_ptr(handle)
            return SkColor4f(pointer: pointer, handle: handle)
        }

        func makeComposed(inner: SkColorFilter) -> SkColorFilter {
            let handle = SkColorFilter_makeComposed(self.pointer, inner.handle)
            let pointer = static_sk_color_filter_get(handle)
            return SkColorFilter(pointer: pointer, handle: handle)
        }

        func makeWithWorkingColorSpace(colorSpace: SkColorSpace) -> SkColorFilter {
            let handle = SkColorFilter_makeWithWorkingColorSpace(self.pointer, colorSpace.handle)
            let pointer = static_sk_color_filter_get(handle)
            return SkColorFilter(pointer: pointer, handle: handle)
        }

        func getFactory() -> SkFlattenableFactory {
            let handle = SkColorFilter_getFactory(self.pointer)
            let pointer = static_sk_flattenable_factory_get_ptr(handle)
            return SkFlattenableFactory(pointer: pointer, handle: handle)
        }

        func getTypeName() -> String {
            guard let cstr = SkColorFilter_getTypeName(self.pointer) else {
                return ""
            }
            return String(cString: cstr)
        }

        func flatten(writeBuffer: SkWriteBuffer) {
            SkColorFilter_flatten(self.pointer, writeBuffer.pointer)
        }

        func getFlattenableType() -> SkFlattenableType {
            return SkFlattenableType(rawValue: SkColorFilter_getFlattenableType(self.pointer))!
        }

        func serialize(serialProcs: UnsafeRawPointer?) -> SkData {
            let handle = SkColorFilter_serialize(self.pointer, serialProcs)
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        func serialize(memory: UnsafeMutableRawPointer, memorySize: UInt, serialProcs: SkSerialProcs) -> UInt {
            return UInt(SkColorFilter_serialize_2(self.pointer, memory, memorySize, serialProcs.pointer))
        }

        func isUnique() -> Bool {
            return SkColorFilter_unique(self.pointer)
        }

        func ref() {
            SkColorFilter_ref(self.pointer)
        }

        func unref() {
            SkColorFilter_unref(self.pointer)
        }
    }
}