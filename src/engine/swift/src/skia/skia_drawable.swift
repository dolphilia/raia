extension Skia {
    class SkDrawable {
        public var pointer: SkDrawableMutablePointer?
        public var handle: sk_drawable_t = -1

        // void SkDrawable_delete(void *drawable); // (SkDrawable *drawable)
        deinit {
            if self.handle > -1 {
                static_sk_drawable_delete(self.handle)
            } else {
                SkDrawable_delete(self.pointer)
            }
        }
        // void SkDrawable_draw(void *drawable, void * canvas, const void * matrix); // (SkDrawable *drawable, SkCanvas *canvas, const SkMatrix *matrix)

        func draw(canvas: SkCanvas, matrix: SkMatrix) {
            SkDrawable_draw(self.pointer, canvas.pointer, matrix.pointer)
        }
        // void SkDrawable_draw_2(void *drawable, void *canvas, float x, float y); // (SkDrawable *drawable, SkCanvas *canvas, SkScalar x, SkScalar y)

        func draw(canvas: SkCanvas, x: Float, y: Float) {
            SkDrawable_draw_2(self.pointer, canvas.pointer, x, y)
        }

        // int SkDrawable_snapGpuDrawHandler(void *drawable, int backendApi, const void *matrix, const void *clipBounds, const void *bufferInfo); // (SkDrawable *drawable, GrBackendApi backendApi, const SkMatrix *matrix, const SkIRect *clipBounds, const SkImageInfo *bufferInfo) -> sk_drawable_gpu_draw_handler_t
        // int SkDrawable_makePictureSnapshot(void *drawable); // (SkDrawable *drawable) -> sk_picture_t

        func makePictureSnapshot() -> SkPicture {
            let handle = SkDrawable_makePictureSnapshot(self.pointer)
            let pointer = static_sk_picture_get(handle)
            return SkPicture(pointer: pointer, handle: handle)
        }

        // unsigned int SkDrawable_getGenerationID(void *drawable); // (SkDrawable *drawable) -> uint32_t

        func getGenerationID() -> UInt32 {
            return SkDrawable_getGenerationID(self.pointer)
        }

        // int SkDrawable_getBounds(void *drawable); // (SkDrawable *drawable) -> sk_rect_t

        func getBounds() -> SkRect {
            let handle = SkDrawable_getBounds(self.pointer)
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }

        // unsigned long SkDrawable_approximateBytesUsed(void *drawable); // (SkDrawable *drawable) -> size_t

        func approximateBytesUsed() -> UInt {
            return UInt(SkDrawable_approximateBytesUsed(self.pointer))
        }

        // void SkDrawable_notifyDrawingChanged(void *drawable); // (SkDrawable *drawable)

        func notifyDrawingChanged() {
            SkDrawable_notifyDrawingChanged(self.pointer)
        }

        // int SkDrawable_getFlattenableType(void *drawable); // (SkDrawable *drawable) -> SkFlattenable::Type
        // int SkDrawable_getFactory(void *drawable); // (SkDrawable *drawable) -> sk_flattenable_factory_t
        // const char * SkDrawable_getTypeName(void *drawable); // (SkDrawable *drawable) -> const char *

        func getTypeName() -> String {
            return String(cString: SkDrawable_getTypeName(self.pointer))
        }

        // void SkDrawable_flatten(void *drawable, void *write_buffer); // (SkDrawable *drawable, SkWriteBuffer *write_buffer)
        // int SkDrawable_serialize(void *drawable, const void *serial_procs); // (SkDrawable *drawable, const SkSerialProcs *serial_procs) -> sk_data_t
        // unsigned long SkDrawable_serialize_2(void *drawable, void *memory, unsigned long memory_size, const void *serial_procs); // (SkDrawable *drawable, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) -> size_t
        // bool SkDrawable_unique(void *drawable); // (SkDrawable *drawable) -> bool

        func unique() -> Bool {
            return SkDrawable_unique(self.pointer)
        }
        // void SkDrawable_ref(void *drawable); // (SkDrawable *drawable)

        func ref() {
            SkDrawable_ref(self.pointer)
        }
        // void SkDrawable_unref(void *drawable); // (SkDrawable *drawable)

        func unref() {
            SkDrawable_unref(self.pointer)
        }



        // // static

        init(pointer: SkDrawableMutablePointer?, handle: sk_drawable_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkDrawable_GetFlattenableType(); // () -> SkFlattenable::Type
        // int SkDrawable_Deserialize(const void *data, unsigned long size, const void *procs); // (const void *data, size_t size, const SkDeserialProcs *procs) -> sk_drawable_t
        // int SkDrawable_NameToFactory(const char name[]); // (const char name[]) -> sk_flattenable_factory_t
        // const char * SkDrawable_FactoryToName(int factory); // (sk_flattenable_factory_t factory) -> const char *
        // void SkDrawable_Register(const char name[], int factory); // (const char name[], sk_flattenable_factory_t factory)
    }
}