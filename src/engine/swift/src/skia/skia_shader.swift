extension Skia {
    protocol SkShaderProtocol {
        var pointer: Skia.SkShaderMutablePointer? { get set }
        var handle: sk_shader_t { get set }
        // deinit // void SkShader_delete(void *shader); // (SkShader *shader)
        init(pointer: Skia.SkShaderMutablePointer?, handle: sk_shader_t)
        // Static Methods
        static func NameToFactory(name: UnsafePointer<CChar>?) -> Flattenable // int SkShader_NameToFactory(const char name[]); // (const char name[]) -> sk_flattenable_factory_t
        static func NameToFactory(name: String) -> Flattenable
        static func FactoryToName(factory: Flattenable) -> UnsafePointer<CChar>? // const char *SkShader_FactoryToName(int factory); // (sk_flattenable_factory_t factory) -> const char *
        static func FactoryToName(factory: Flattenable) -> String?
        static func Register(name: UnsafePointer<CChar>?, factory: Flattenable) // void SkShader_Register(const char name[], int factory); // (const char name[], sk_flattenable_factory_t factory)
        static func Register(name: String, factory: Flattenable)
        static func Deserialize(type: Flattenable, data: UnsafeRawPointer, length: UInt, procs: UnsafeRawPointer) -> Flattenable // int SkShader_Deserialize(int type, const void *data, unsigned long length, const void *procs); // (SkShader::Type type, const void *data, size_t length, const SkDeserialProcs *procs) -> sk_flattenable_t
        // Methods
        func isOpaque() -> Bool // bool SkShader_isOpaque(void *shader); // (SkShader *shader) -> bool
        func isAImage(localMatrix: Skia.SkMatrix, xy: [SkTileMode]) -> Skia.Image? // void *SkShader_isAImage(void *shader, void *localMatrix, void * xy); // (SkShader *shader, SkMatrix *localMatrix, SkTileMode xy[2]) -> SkImage *
        func isAImage() -> Bool // bool SkShader_isAImage_2(void *shader); // (SkShader *shader) -> bool
        func makeWithLocalMatrix(matrix: Skia.SkMatrix) -> SkShader // int SkShader_makeWithLocalMatrix(void *shader, const void *matrix); // (SkShader *shader, const SkMatrix *matrix) -> sk_shader_t
        func makeWithColorFilter(colorFilter: ColorFilter) -> SkShader // int SkShader_makeWithColorFilter(void *shader, int color_filter); // (SkShader *shader, sk_color_filter_t color_filter) -> sk_shader_t
        func makeWithWorkingColorSpace(colorSpace: ColorSpace) -> SkShader // int SkShader_makeWithWorkingColorSpace(void *shader, int color_space); // (SkShader *shader, sk_color_space_t color_space) -> sk_shader_t
        func getFactory() -> Flattenable // int SkShader_getFactory(void *shader); // (SkShader *shader) -> sk_flattenable_factory_t
        func getTypeName() -> UnsafePointer<CChar>? // const char *SkShader_getTypeName(void *shader); // (SkShader *shader) -> const char *
        func getTypeName() -> String?
        // void SkShader_flatten(void *shader, void *buffer); // (SkShader *shader, SkWriteBuffer *buffer)
        // int SkShader_getFlattenableType(void *shader); // (SkShader *shader) -> SkShader::Type
        func serialize(procs: UnsafeRawPointer) -> Data // int SkShader_serialize(void *shader, const void *procs); // (SkShader *shader, const SkSerialProcs *procs) -> sk_data_t
        func serialize(memory: UnsafeMutableRawPointer?, memorySize: UInt, procs: UnsafeRawPointer) -> UInt // unsigned long SkShader_serialize_2(void *shader, void *memory, unsigned long memory_size, const void *procs); // (SkShader *shader, void *memory, size_t memory_size, const SkSerialProcs *procs) -> size_t
        func unique() -> Bool // bool SkShader_unique(void *shader); // (SkShader *shader) -> bool
        func ref() // void SkShader_ref(void *shader); // (SkShader *shader)
        func unref() // void SkShader_unref(void *shader); // (SkShader *shader)
    }

    class SkShader : SkShaderProtocol {
        public var pointer: Skia.SkShaderMutablePointer?
        public var handle: sk_shader_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_shader_delete(self.handle)
            } else {
                SkShader_delete(self.pointer)
            }
        }

        required init(pointer: Skia.SkShaderMutablePointer?, handle: sk_shader_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func NameToFactory(name: UnsafePointer<CChar>?) -> Flattenable {
            let handle = SkShader_NameToFactory(name)
            let pointer = static_sk_flattenable_get(handle)
            return Flattenable(pointer: pointer, handle: handle)
        }

        static func NameToFactory(name: String) -> Flattenable {
            let handle = name.withCString { cstr in
                return SkShader_NameToFactory(cstr)
            }
            let pointer = static_sk_flattenable_get(handle)
            return Flattenable(pointer: pointer, handle: handle)
        }

        static func FactoryToName(factory: Flattenable) -> UnsafePointer<CChar>? {
            return SkShader_FactoryToName(factory.handle)
        }

        static func FactoryToName(factory: Flattenable) -> String? {
            guard let cstr = SkShader_FactoryToName(factory.handle) else {
                return nil
            }
            return String(cString: cstr)
        }

        static func Register(name: UnsafePointer<CChar>?, factory: Flattenable) {
            SkShader_Register(name, factory.handle)
        }

        static func Register(name: String, factory: Flattenable) {
            name.withCString { cstr in
                SkShader_Register(cstr, factory.handle)
            }
        }

        static func Deserialize(type: Flattenable, data: UnsafeRawPointer, length: UInt, procs: UnsafeRawPointer) -> Flattenable {
            let deserialize_handle = SkShader_Deserialize(type.handle, data, length, procs)
            let pointer = static_sk_flattenable_get(deserialize_handle)
            return Flattenable(pointer: pointer, handle: deserialize_handle)
        }

        // Methods

        func isOpaque() -> Bool {
            return SkShader_isOpaque(pointer)
        }

        func isAImage(localMatrix: Skia.SkMatrix, xy: [SkTileMode]) -> Skia.Image? {
            guard let image = SkShader_isAImage(pointer, localMatrix.pointer, UnsafeMutableRawPointer(mutating: xy)) else {
                return nil
            }
            return Skia.Image(pointer: image, handle: -1)
        }

        func isAImage() -> Bool {
            return SkShader_isAImage_2(pointer)
        }

        func makeWithLocalMatrix(matrix: Skia.SkMatrix) -> SkShader {
            let handle = SkShader_makeWithLocalMatrix(pointer, matrix.pointer)
            let pointer = static_sk_shader_get(handle)
            return SkShader(pointer: pointer, handle: handle)
        }

        func makeWithColorFilter(colorFilter: ColorFilter) -> SkShader {
            let handle = SkShader_makeWithColorFilter(pointer, colorFilter.handle)
            let pointer = static_sk_shader_get(handle)
            return SkShader(pointer: pointer, handle: handle)
        }

        func makeWithWorkingColorSpace(colorSpace: ColorSpace) -> SkShader {
            let handle = SkShader_makeWithWorkingColorSpace(pointer, colorSpace.handle)
            let pointer = static_sk_shader_get(handle)
            return SkShader(pointer: pointer, handle: handle)
        }

        func getFactory() -> Flattenable {
            let handle = SkShader_getFactory(pointer)
            let pointer = static_sk_flattenable_get(handle)
            return Flattenable(pointer: pointer, handle: handle)
        }

        func getTypeName() -> UnsafePointer<CChar>? {
            return SkShader_getTypeName(pointer)
        }

        func getTypeName() -> String? {
            guard let cstr = SkShader_getTypeName(pointer) else {
                return nil
            }
            return String(cString: cstr)
        }

        // void SkShader_flatten(void *shader, void *buffer); // (SkShader *shader, SkWriteBuffer *buffer)
        // int SkShader_getFlattenableType(void *shader); // (SkShader *shader) -> SkShader::Type

        func serialize(procs: UnsafeRawPointer) -> Data {
            let handle = SkShader_serialize(pointer, procs)
            let pointer = static_sk_data_get(handle)
            return Data(pointer: pointer, handle: handle)
        }

        func serialize(memory: UnsafeMutableRawPointer?, memorySize: UInt, procs: UnsafeRawPointer) -> UInt {
            return SkShader_serialize_2(pointer, memory, memorySize, procs)
        }

        func unique() -> Bool {
            return SkShader_unique(pointer)
        }

        func ref() {
            SkShader_ref(pointer)
        }

        func unref() {
            SkShader_unref(pointer)
        }
    }
}