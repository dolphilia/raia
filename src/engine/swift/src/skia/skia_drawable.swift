extension Skia {
    protocol SkDrawableProtocol {
        var pointer: SkDrawableMutablePointer? { get set }
        var handle: sk_drawable_t { get set }
        // deinit // void SkDrawable_delete(void *drawable); // (SkDrawable *drawable)
        init(pointer: SkDrawableMutablePointer?, handle: sk_drawable_t)
        // Static Methods
        static func GetFlattenableType() -> SkFlattenableType // int SkDrawable_GetFlattenableType(); // () -> SkFlattenable::Type
        static func Deserialize(data: UnsafeRawPointer, size: UInt, procs: SkDeserialProcs) -> SkDrawable // int SkDrawable_Deserialize(const void *data, unsigned long size, const void *procs); // (const void *data, size_t size, const SkDeserialProcs *procs) -> sk_drawable_t
        static func NameToFactory(name: String) -> SkFlattenableFactory // int SkDrawable_NameToFactory(const char name[]); // (const char name[]) -> sk_flattenable_factory_t
        static func FactoryToName(factory: SkFlattenableFactory) -> String // const char * SkDrawable_FactoryToName(int factory); // (sk_flattenable_factory_t factory) -> const char *
        static func Register(name: String, factory: SkFlattenableFactory) // void SkDrawable_Register(const char name[], int factory); // (const char name[], sk_flattenable_factory_t factory)
        // Methods
        func draw(canvas: SkCanvas, matrix: SkMatrix) // void SkDrawable_draw(void *drawable, void * canvas, const void * matrix); // (SkDrawable *drawable, SkCanvas *canvas, const SkMatrix *matrix)
        func draw(canvas: SkCanvas, x: Float, y: Float) // void SkDrawable_draw_2(void *drawable, void *canvas, float x, float y); // (SkDrawable *drawable, SkCanvas *canvas, SkScalar x, SkScalar y)
        // int SkDrawable_snapGpuDrawHandler(void *drawable, int backendApi, const void *matrix, const void *clipBounds, const void *bufferInfo); // (SkDrawable *drawable, GrBackendApi backendApi, const SkMatrix *matrix, const SkIRect *clipBounds, const SkImageInfo *bufferInfo) -> sk_drawable_gpu_draw_handler_t
        func makePictureSnapshot() -> SkPicture // int SkDrawable_makePictureSnapshot(void *drawable); // (SkDrawable *drawable) -> sk_picture_t
        func getGenerationID() -> UInt32 // unsigned int SkDrawable_getGenerationID(void *drawable); // (SkDrawable *drawable) -> uint32_t
        func getBounds() -> SkRect // int SkDrawable_getBounds(void *drawable); // (SkDrawable *drawable) -> sk_rect_t
        func approximateBytesUsed() -> UInt // unsigned long SkDrawable_approximateBytesUsed(void *drawable); // (SkDrawable *drawable) -> size_t
        func notifyDrawingChanged() // void SkDrawable_notifyDrawingChanged(void *drawable); // (SkDrawable *drawable)
        func getFlattenableType() -> SkFlattenableType // int SkDrawable_getFlattenableType(void *drawable); // (SkDrawable *drawable) -> SkFlattenable::Type
        func getFactory() -> SkFlattenableFactory // int SkDrawable_getFactory(void *drawable); // (SkDrawable *drawable) -> sk_flattenable_factory_t
        func getTypeName() -> String // const char * SkDrawable_getTypeName(void *drawable); // (SkDrawable *drawable) -> const char *
        func flatten(writeBuffer: SkWriteBuffer) // void SkDrawable_flatten(void *drawable, void *write_buffer); // (SkDrawable *drawable, SkWriteBuffer *write_buffer)
        func serialize(serialProcs: SkSerialProcs) -> SkData // int SkDrawable_serialize(void *drawable, const void *serial_procs); // (SkDrawable *drawable, const SkSerialProcs *serial_procs) -> sk_data_t
        func serialize(memory: UnsafeMutableRawPointer, memorySize: UInt, serialProcs: SkSerialProcs) -> UInt // unsigned long SkDrawable_serialize_2(void *drawable, void *memory, unsigned long memory_size, const void *serial_procs); // (SkDrawable *drawable, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) -> size_t
        func unique() -> Bool // bool SkDrawable_unique(void *drawable); // (SkDrawable *drawable) -> bool
        func ref() // void SkDrawable_ref(void *drawable); // (SkDrawable *drawable)
        func unref() // void SkDrawable_unref(void *drawable); // (SkDrawable *drawable)
    }
 
    class SkDrawable : SkDrawableProtocol {
        public var pointer: SkDrawableMutablePointer?
        public var handle: sk_drawable_t = -1

        deinit {
            if self.handle > -1 {
                static_sk_drawable_delete(self.handle)
            } else {
                SkDrawable_delete(self.pointer)
            }
        }

        required init(pointer: SkDrawableMutablePointer?, handle: sk_drawable_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // Static Methods

        static func GetFlattenableType() -> SkFlattenableType {
            return SkFlattenableType(rawValue: SkDrawable_GetFlattenableType())!
        }

        static func Deserialize(data: UnsafeRawPointer, size: UInt, procs: SkDeserialProcs) -> SkDrawable {
            let handle = SkDrawable_Deserialize(data, size, procs.pointer)
            let pointer = static_sk_drawable_get(handle)
            return SkDrawable(pointer: pointer, handle: handle)
        }

        static func NameToFactory(name: String) -> SkFlattenableFactory {
            return name.withCString { cstr in
                let handle = SkDrawable_NameToFactory(cstr)
                let pointer = static_sk_flattenable_factory_get_ptr(handle)
                return SkFlattenableFactory(pointer: pointer, handle: handle)
            }
        }

        static func FactoryToName(factory: SkFlattenableFactory) -> String {
            return String(cString: SkDrawable_FactoryToName(factory.handle))
        }

        static func Register(name: String, factory: SkFlattenableFactory) {
            name.withCString { cstr in
                SkDrawable_Register(cstr, factory.handle)
            }
        }

        // Methods

        func draw(canvas: SkCanvas, matrix: SkMatrix) {
            SkDrawable_draw(self.pointer, canvas.pointer, matrix.pointer)
        }

        func draw(canvas: SkCanvas, x: Float, y: Float) {
            SkDrawable_draw_2(self.pointer, canvas.pointer, x, y)
        }

        // int SkDrawable_snapGpuDrawHandler(void *drawable, int backendApi, const void *matrix, const void *clipBounds, const void *bufferInfo); // (SkDrawable *drawable, GrBackendApi backendApi, const SkMatrix *matrix, const SkIRect *clipBounds, const SkImageInfo *bufferInfo) -> sk_drawable_gpu_draw_handler_t

        func makePictureSnapshot() -> SkPicture {
            let handle = SkDrawable_makePictureSnapshot(self.pointer)
            let pointer = static_sk_picture_get(handle)
            return SkPicture(pointer: pointer, handle: handle)
        }

        func getGenerationID() -> UInt32 {
            return SkDrawable_getGenerationID(self.pointer)
        }

        func getBounds() -> SkRect {
            let handle = SkDrawable_getBounds(self.pointer)
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }

        func approximateBytesUsed() -> UInt {
            return UInt(SkDrawable_approximateBytesUsed(self.pointer))
        }

        func notifyDrawingChanged() {
            SkDrawable_notifyDrawingChanged(self.pointer)
        }

        func getFlattenableType() -> SkFlattenableType {
            return SkFlattenableType(rawValue: SkDrawable_getFlattenableType(self.pointer))!
        }

        func getFactory() -> SkFlattenableFactory {
            let handle = SkDrawable_getFactory(self.pointer)
            let pointer = static_sk_flattenable_factory_get_ptr(handle)
            return SkFlattenableFactory(pointer: pointer, handle: handle)
        }

        func getTypeName() -> String {
            return String(cString: SkDrawable_getTypeName(self.pointer))
        }

        func flatten(writeBuffer: SkWriteBuffer) {
            SkDrawable_flatten(self.pointer, writeBuffer.pointer)
        }

        func serialize(serialProcs: SkSerialProcs) -> SkData {
            let handle = SkDrawable_serialize(self.pointer, serialProcs.pointer)
            let pointer = static_sk_data_get(handle)
            return SkData(pointer: pointer, handle: handle)
        }

        func serialize(memory: UnsafeMutableRawPointer, memorySize: UInt, serialProcs: SkSerialProcs) -> UInt {
            return SkDrawable_serialize_2(self.pointer, memory, memorySize, serialProcs.pointer)
        }

        func unique() -> Bool {
            return SkDrawable_unique(self.pointer)
        }

        func ref() {
            SkDrawable_ref(self.pointer)
        }

        func unref() {
            SkDrawable_unref(self.pointer)
        }
    }
}