extension Skia {
    class Drawable {
        public var pointer: Skia.DrawableMutablePointer?
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
        // void SkDrawable_draw_2(void *drawable, void *canvas, float x, float y); // (SkDrawable *drawable, SkCanvas *canvas, SkScalar x, SkScalar y)
        // int SkDrawable_snapGpuDrawHandler(void *drawable, int backendApi, const void *matrix, const void *clipBounds, const void *bufferInfo); // (SkDrawable *drawable, GrBackendApi backendApi, const SkMatrix *matrix, const SkIRect *clipBounds, const SkImageInfo *bufferInfo) -> sk_drawable_gpu_draw_handler_t
        // int SkDrawable_makePictureSnapshot(void *drawable); // (SkDrawable *drawable) -> sk_picture_t
        // unsigned int SkDrawable_getGenerationID(void *drawable); // (SkDrawable *drawable) -> uint32_t
        // int SkDrawable_getBounds(void *drawable); // (SkDrawable *drawable) -> sk_rect_t
        // unsigned long SkDrawable_approximateBytesUsed(void *drawable); // (SkDrawable *drawable) -> size_t
        // void SkDrawable_notifyDrawingChanged(void *drawable); // (SkDrawable *drawable)
        // int SkDrawable_getFlattenableType(void *drawable); // (SkDrawable *drawable) -> SkFlattenable::Type
        // int SkDrawable_getFactory(void *drawable); // (SkDrawable *drawable) -> sk_flattenable_factory_t
        // const char * SkDrawable_getTypeName(void *drawable); // (SkDrawable *drawable) -> const char *
        // void SkDrawable_flatten(void *drawable, void *write_buffer); // (SkDrawable *drawable, SkWriteBuffer *write_buffer)
        // int SkDrawable_serialize(void *drawable, const void *serial_procs); // (SkDrawable *drawable, const SkSerialProcs *serial_procs) -> sk_data_t
        // unsigned long SkDrawable_serialize_2(void *drawable, void *memory, unsigned long memory_size, const void *serial_procs); // (SkDrawable *drawable, void *memory, size_t memory_size, const SkSerialProcs *serial_procs) -> size_t
        // bool SkDrawable_unique(void *drawable); // (SkDrawable *drawable) -> bool
        // void SkDrawable_ref(void *drawable); // (SkDrawable *drawable)
        // void SkDrawable_unref(void *drawable); // (SkDrawable *drawable)

        // // static

        init(pointer: Skia.DrawableMutablePointer?, handle: sk_drawable_t) {
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