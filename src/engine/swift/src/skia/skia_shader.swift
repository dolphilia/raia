extension Skia {
    class Shader {
        public var pointer: Skia.ShaderMutablePointer?
        public var handle: sk_shader_t?
        // void SkShader_delete(void *shader); // (SkShader *shader)
        deinit {
            SkShader_delete(pointer)
            if let handle = self.handle {
                static_sk_shader_delete(handle)
            }
        }
        // bool SkShader_isOpaque(void *shader); // (SkShader *shader) -> bool
        func isOpaque() -> Bool {
            return SkShader_isOpaque(pointer)
        }
        // void *SkShader_isAImage(void *shader, void *localMatrix, void * xy); // (SkShader *shader, SkMatrix *localMatrix, SkTileMode xy[2]) -> SkImage *
        func isAImage(localMatrix: Skia.Matrix, xy: [TileMode]) -> Skia.Image? {
            guard let image = SkShader_isAImage(pointer, localMatrix.pointer, UnsafeMutableRawPointer(mutating: xy)) else {
                return nil
            }
            return Skia.Image(pointer: image, handle: nil)
        }
        // bool SkShader_isAImage_2(void *shader); // (SkShader *shader) -> bool
        func isAImage() -> Bool {
            return SkShader_isAImage_2(pointer)
        }
        // int SkShader_makeWithLocalMatrix(void *shader, const void *matrix); // (SkShader *shader, const SkMatrix *matrix) -> sk_shader_t
        func makeWithLocalMatrix(matrix: Skia.Matrix) -> Shader {
            let handle = SkShader_makeWithLocalMatrix(pointer, matrix.pointer)
            let pointer = static_sk_shader_get(handle)
            return Shader(pointer: pointer, handle: handle)
        }
        // int SkShader_makeWithColorFilter(void *shader, int color_filter); // (SkShader *shader, sk_color_filter_t color_filter) -> sk_shader_t
        func makeWithColorFilter(colorFilter: ColorFilter) -> Shader {
            guard let colorFilterHandle = colorFilter.handle else {
                fatalError("ColorFilter handle is nil")
            }
            let handle = SkShader_makeWithColorFilter(pointer, colorFilterHandle)
            let pointer = static_sk_shader_get(handle)
            return Shader(pointer: pointer, handle: handle)
        }
        // int SkShader_makeWithWorkingColorSpace(void *shader, int color_space); // (SkShader *shader, sk_color_space_t color_space) -> sk_shader_t
        func makeWithWorkingColorSpace(colorSpace: ColorSpace) -> Shader {
            guard let colorSpaceHandle = colorSpace.handle else {
                fatalError("ColorSpace handle is nil")
            }
            let handle = SkShader_makeWithWorkingColorSpace(pointer, colorSpaceHandle)
            let pointer = static_sk_shader_get(handle)
            return Shader(pointer: pointer, handle: handle)
        }
        // int SkShader_getFactory(void *shader); // (SkShader *shader) -> sk_flattenable_factory_t
        func getFactory() -> Flattenable {
            let handle = SkShader_getFactory(pointer)
            let pointer = static_sk_flattenable_get(handle)
            return Flattenable(pointer: pointer, handle: handle)
        }
        // const char *SkShader_getTypeName(void *shader); // (SkShader *shader) -> const char *
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
        // int SkShader_serialize(void *shader, const void *procs); // (SkShader *shader, const SkSerialProcs *procs) -> sk_data_t
        func serialize(procs: UnsafeRawPointer) -> Data {
            let handle = SkShader_serialize(pointer, procs)
            let pointer = static_sk_data_get(handle)
            return Data(pointer: pointer, handle: handle)
        }
        // unsigned long SkShader_serialize_2(void *shader, void *memory, unsigned long memory_size, const void *procs); // (SkShader *shader, void *memory, size_t memory_size, const SkSerialProcs *procs) -> size_t
        func serialize(memory: UnsafeMutableRawPointer?, memorySize: UInt, procs: UnsafeRawPointer) -> UInt {
            return SkShader_serialize_2(pointer, memory, memorySize, procs)
        }
        // bool SkShader_unique(void *shader); // (SkShader *shader) -> bool
        func unique() -> Bool {
            return SkShader_unique(pointer)
        }
        // void SkShader_ref(void *shader); // (SkShader *shader)
        func ref() {
            SkShader_ref(pointer)
        }
        // void SkShader_unref(void *shader); // (SkShader *shader)
        func unref() {
            SkShader_unref(pointer)
        }

        // // static

        init(pointer: Skia.ShaderMutablePointer?, handle: sk_shader_t?) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkShader_NameToFactory(const char name[]); // (const char name[]) -> sk_flattenable_factory_t
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
        // const char *SkShader_FactoryToName(int factory); // (sk_flattenable_factory_t factory) -> const char *
        static func FactoryToName(factory: Flattenable) -> UnsafePointer<CChar>? {
            guard let handle = factory.handle else {
                return nil
            }
            return SkShader_FactoryToName(handle)
        }
        static func FactoryToName(factory: Flattenable) -> String? {
            guard let handle = factory.handle else {
                return nil
            }
            guard let cstr = SkShader_FactoryToName(handle) else {
                return nil
            }
            return String(cString: cstr)
        }
        // void SkShader_Register(const char name[], int factory); // (const char name[], sk_flattenable_factory_t factory)
        static func Register(name: UnsafePointer<CChar>?, factory: Flattenable) {
            guard let handle = factory.handle else {
                return
            }
            SkShader_Register(name, handle)
        }
        static func Register(name: String, factory: Flattenable) {
            guard let handle = factory.handle else {
                return
            }
            name.withCString { cstr in
                SkShader_Register(cstr, handle)
            }
        }
        // int SkShader_Deserialize(int type, const void *data, unsigned long length, const void *procs); // (SkShader::Type type, const void *data, size_t length, const SkDeserialProcs *procs) -> sk_flattenable_t
        static func Deserialize(type: Flattenable, data: UnsafeRawPointer, length: UInt, procs: UnsafeRawPointer) -> Flattenable {
            guard let handle = type.handle else {
                return Flattenable(pointer: nil, handle: nil)
            }
            let deserialize_handle = SkShader_Deserialize(handle, data, length, procs)
            let pointer = static_sk_flattenable_get(deserialize_handle)
            return Flattenable(pointer: pointer, handle: deserialize_handle)
        }

    }
}