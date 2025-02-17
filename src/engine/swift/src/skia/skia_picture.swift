extension Skia {
    class SkPicture {
        public var pointer: SkPictureMutablePointer?
        public var handle: sk_picture_t = -1
        // void SkPicture_delete(void *picture); // (SkPicture *picture)

        deinit {
            if self.handle > -1 {
                static_sk_picture_delete(self.handle)
            } else {
                SkPicture_delete(self.pointer)
            }
        }
        // void SkPicture_playback(void *picture, void *canvas, void *callback); // (SkPicture *picture, SkCanvas *canvas, SkPicture::AbortCallback *callback)
        // int SkPicture_cullRect(void *picture); // (SkPicture *picture) -> sk_rect_t

        func cullRect() -> SkRect {
            let handle = SkPicture_cullRect(self.pointer)
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }
        // unsigned int SkPicture_uniqueID(void *picture); // (SkPicture *picture) -> uint32_t

        func uniqueID() -> UInt32 {
            return SkPicture_uniqueID(self.pointer)
        }
        // int SkPicture_serialize(void *picture, const void *procs); // (SkPicture *picture, const SkSerialProcs *procs) -> sk_data_t
        // void SkPicture_serialize_2(void *picture, void *stream, const void *procs); // (SkPicture *picture, SkWStream *stream, const SkSerialProcs *procs)
        // unsigned long SkPicture_approximateOpCount(void *picture); // (SkPicture *picture) -> size_t

        func approximateOpCount() -> UInt {
            return UInt(SkPicture_approximateOpCount(self.pointer))
        }
        // unsigned long SkPicture_approximateBytesUsed(void *picture); // (SkPicture *picture) -> size_t

        func approximateBytesUsed() -> UInt {
            return UInt(SkPicture_approximateBytesUsed(self.pointer))
        }
        // int SkPicture_makeShader(void *picture, int tmx, int tmy, int mode, const void *localMatrix, const void *tileRect); // (SkPicture *picture, SkTileMode tmx, SkTileMode tmy, SkFilterMode mode, const SkMatrix *localMatrix, const SkRect *tileRect) -> sk_shader_t

        func makeShader(tmx: SkTileMode, tmy: SkTileMode, mode: SkFilterMode, localMatrix: SkMatrix, tileRect: SkRect) -> SkShader {
            let handle = SkPicture_makeShader(self.pointer, tmx.rawValue, tmy.rawValue, mode.rawValue, localMatrix.pointer, tileRect.pointer)
            let pointer = static_sk_shader_get(handle)
            return SkShader(pointer: pointer, handle: handle)
        }
        // int SkPicture_makeShader_2(void *picture, int tmx, int tmy, int mode); // (SkPicture *picture, SkTileMode tmx, SkTileMode tmy, SkFilterMode mode) -> sk_shader_t

        func makeShader(tmx: SkTileMode, tmy: SkTileMode, mode: SkFilterMode) -> SkShader {
            let handle = SkPicture_makeShader_2(self.pointer, tmx.rawValue, tmy.rawValue, mode.rawValue)
            let pointer = static_sk_shader_get(handle)
            return SkShader(pointer: pointer, handle: handle)
        }
        // bool SkPicture_unique(void *picture); // (SkPicture *picture) -> bool

        func unique() -> Bool {
            return SkPicture_unique(self.pointer)
        }
        // void SkPicture_ref(void *picture); // (SkPicture *picture)

        func ref() {
            SkPicture_ref(self.pointer)
        }
        // void SkPicture_unref(void *picture); // (SkPicture *picture)

        func unref() {
            SkPicture_unref(self.pointer)
        }

        // // static

        init(pointer: SkPictureMutablePointer?, handle: sk_picture_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // int SkPicture_MakeFromStream(void *stream, const void *procs); // (SkStream *stream, const SkDeserialProcs *procs) -> sk_picture_t
        // int SkPicture_MakeFromData(const void *data, const void *procs); // (const SkData *data, const SkDeserialProcs *procs) -> sk_picture_t
        // int SkPicture_MakeFromData_2(const void *data, unsigned long size, const void *procs); // (const void *data, size_t size, const SkDeserialProcs *procs) -> sk_picture_t
        // int SkPicture_MakePlaceholder(int cull); // (sk_rect_t cull) -> sk_picture_t

        static func MakePlaceholder(cull: SkRect) -> SkPicture {
            let handle = SkPicture_MakePlaceholder(cull.handle)
            let pointer = static_sk_picture_get(handle)
            return SkPicture(pointer: pointer, handle: handle)
        }
    }
}