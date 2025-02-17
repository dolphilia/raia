extension Skia {
    class SkSurface {
        public var pointer: SkSurfaceMutablePointer?
        public var handle: sk_surface_t = -1

        // void SkSurface_delete(void *surface); // (SkSurface *surface)

        deinit {
            if self.handle > -1 {
                static_sk_surface_delete(self.handle)
            } else {
                SkSurface_delete(self.pointer)
            }
        }
        // bool SkSurface_isCompatible(void *surface, const void *characterization); // (SkSurface *surface, const GrSurfaceCharacterization *characterization) -> bool
        // int SkSurface_width(void *surface); // (SkSurface *surface) -> int

        func width() -> Int {
            return Int(SkSurface_width(self.pointer))
        }
        // int SkSurface_height(void *surface); // (SkSurface *surface) -> int

        func height() -> Int {
            return Int(SkSurface_height(self.pointer))
        }
        // int SkSurface_imageInfo(void *surface); // (SkSurface *surface) -> sk_image_info_t

        func imageInfo() -> SkImageInfo {
            let handle = SkSurface_imageInfo(self.pointer)
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }
        // unsigned int SkSurface_generationID(void *surface); // (SkSurface *surface) -> uint32_t

        func generationID() -> UInt32 {
            return SkSurface_generationID(self.pointer)
        }
        // void SkSurface_notifyContentWillChange(void *surface, int mode); // (SkSurface *surface, SkSurface::ContentChangeMode mode)
        // void * SkSurface_recordingContext(void *surface); // (SkSurface *surface) -> GrRecordingContext *
        // void * SkSurface_recorder(void *surface); // (SkSurface *surface) -> skgpu::graphite::Recorder *
        // bool SkSurface_replaceBackendTexture(void *surface, const void *backendTexture, int origin, int mode, void(* proc)(void *), void * context); // (SkSurface *surface, const GrBackendTexture *backendTexture, GrSurfaceOrigin origin, SkSurface::ContentChangeMode mode, SkSurface::TextureReleaseProc proc, SkSurface::ReleaseContext context) -> bool
        // void * SkSurface_getCanvas(void *surface); // (SkSurface *surface) -> SkCanvas *

        func getCanvas() -> SkCanvas {
            let pointer = SkSurface_getCanvas(self.pointer)
            return SkCanvas(pointer: pointer, handle: -1)
        }
        // int SkSurface_capabilities(void *surface); // (SkSurface *surface) -> const_sk_capabilities_t
        // int SkSurface_makeSurface(void *surface, const void *imageInfo); // (SkSurface *surface, const SkImageInfo *imageInfo) -> sk_surface_t

        func makeSurface(imageInfo: SkImageInfo) -> SkSurface {
            let handle = SkSurface_makeSurface(self.pointer, imageInfo.pointer)
            let pointer = static_sk_surface_get(handle)
            return SkSurface(pointer: pointer, handle: handle)
        }
        // int SkSurface_makeSurface_2(void *surface, int width, int height); // (SkSurface *surface, int width, int height) -> sk_surface_t

        func makeSurface(width: Int, height: Int) -> SkSurface {
            let handle = SkSurface_makeSurface_2(self.pointer, Int32(width), Int32(height))
            let pointer = static_sk_surface_get(handle)
            return SkSurface(pointer: pointer, handle: handle)
        }
        // int SkSurface_makeImageSnapshot(void *surface); // (SkSurface *surface) -> sk_image_t
        func makeImageSnapshot() -> SkImage {
            let handle = SkSurface_makeImageSnapshot(self.pointer)
            let pointer = static_sk_image_get(handle)
            return SkImage(pointer: pointer, handle: handle)
        }
        // int SkSurface_makeImageSnapshot_2(void *surface, const void *bounds); // (SkSurface *surface, const SkIRect *bounds) -> sk_image_t

        func makeImageSnapshot(bounds: SkIRect) -> SkImage {
            let handle = SkSurface_makeImageSnapshot_2(self.pointer, bounds.pointer)
            let pointer = static_sk_image_get(handle)
            return SkImage(pointer: pointer, handle: handle)
        }
        // void SkSurface_draw(void *surface, void *canvas, float x, float y, const void *sampling, const void *paint); // (SkSurface *surface, SkCanvas *canvas, SkScalar x, SkScalar y, const SkSamplingOptions *sampling, const SkPaint *paint)

        func draw(canvas: SkCanvas, x: Float, y: Float, sampling: SkSamplingOptions, paint: SkPaint) {
            SkSurface_draw(self.pointer, canvas.pointer, x, y, sampling.pointer, paint.pointer)
        }
        // void SkSurface_draw_2(void *surface, void *canvas, float x, float y, const void *paint); // (SkSurface *surface, SkCanvas *canvas, SkScalar x, SkScalar y, const SkPaint *paint)

        func draw(canvas: SkCanvas, x: Float, y: Float, paint: SkPaint) {
            SkSurface_draw_2(self.pointer, canvas.pointer, x, y, paint.pointer)
        }
        // bool SkSurface_peekPixels(void *surface, void *pixmap); // (SkSurface *surface, SkPixmap *pixmap) -> bool

        func peekPixels(pixmap: SkPixmap) -> Bool {
            return SkSurface_peekPixels(self.pointer, pixmap.pointer)
        }
        // bool SkSurface_readPixels(void *surface, const void *dst, int srcX, int srcY); // (SkSurface *surface, const SkPixmap *dst, int srcX, int srcY) -> bool

        func readPixels(dst: SkPixmap, srcX: Int, srcY: Int) -> Bool {
            return SkSurface_readPixels(self.pointer, dst.pointer, Int32(srcX), Int32(srcY))
        }
        // bool SkSurface_readPixels_2(void *surface, const void *dstInfo, void *dstPixels, unsigned long dstRowBytes, int srcX, int srcY); // (SkSurface *surface, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY) -> bool

        func readPixels(dstInfo: SkImageInfo, dstPixels: UnsafeMutableRawPointer, dstRowBytes: Int, srcX: Int, srcY: Int) -> Bool {
            return SkSurface_readPixels_2(self.pointer, dstInfo.pointer, dstPixels, UInt(dstRowBytes), Int32(srcX), Int32(srcY))
        }
        // bool SkSurface_readPixels_3(void *surface, const void *dst, int srcX, int srcY); // (SkSurface *surface, const SkBitmap *dst, int srcX, int srcY) -> bool

        func readPixels(dst: SkBitmap, srcX: Int, srcY: Int) -> Bool {
            return SkSurface_readPixels_3(self.pointer, dst.pointer, Int32(srcX), Int32(srcY))
        }

        // // TODO
        // // void SkSurface_asyncRescaleAndReadPixels(void *surface, const void *info, const void *srcRect, int rescaleGamma, int rescaleMode, SkSurface::ReadPixelsCallback callback, void * context); // (SkSurface *surface, const SkImageInfo *info, const SkIRect *srcRect, SkSurface::RescaleGamma rescaleGamma, SkSurface::RescaleMode rescaleMode, SkSurface::ReadPixelsCallback callback, SkSurface::ReadPixelsContext context)
        // // void SkSurface_asyncRescaleAndReadPixelsYUV420(void *surface, sk_color_space_t dstColorSpace, int yuvColorSpace, const void *srcRect, const void *dstSize, int rescaleGamma, int rescaleMode, SkSurface::ReadPixelsCallback callback, void * context); // (SkSurface *surface, sk_color_space_t dstColorSpace, SkYUVColorSpace yuvColorSpace, const SkIRect *srcRect, const SkISize *dstSize, SkSurface::RescaleGamma rescaleGamma, SkSurface::RescaleMode rescaleMode, SkSurface::ReadPixelsCallback callback, SkSurface::ReadPixelsContext context)
        // // void SkSurface_asyncRescaleAndReadPixelsYUVA420(void *surface, sk_color_space_t dstColorSpace, int yuvColorSpace, const void *srcRect, const void *dstSize, int rescaleGamma, int rescaleMode, SkSurface::ReadPixelsCallback callback, void * context); // (SkSurface *surface, sk_color_space_t dstColorSpace, SkYUVColorSpace yuvColorSpace, const SkIRect *srcRect, const SkISize *dstSize, SkSurface::RescaleGamma rescaleGamma, SkSurface::RescaleMode rescaleMode, SkSurface::ReadPixelsCallback callback, SkSurface::ReadPixelsContext context)

        // void SkSurface_writePixels(void *surface, const void *src, int dstX, int dstY); // (SkSurface *surface, const SkPixmap *src, int dstX, int dstY)

        func writePixels(src: SkPixmap, dstX: Int, dstY: Int) {
            SkSurface_writePixels(self.pointer, src.pointer, Int32(dstX), Int32(dstY))
        }
        // void SkSurface_writePixels_2(void *surface, const void *src, int dstX, int dstY); // (SkSurface *surface, const SkBitmap *src, int dstX, int dstY)

        func writePixels(src: SkBitmap, dstX: Int, dstY: Int) {
            SkSurface_writePixels_2(self.pointer, src.pointer, Int32(dstX), Int32(dstY))
        }
        // const void * SkSurface_props(void *surface); // (SkSurface *surface) -> const SkSurfaceProps *

        func props() -> SkSurfaceProps {
            let pointer = SkSurface_props(self.pointer)
            return SkSurfaceProps(pointer: UnsafeMutableRawPointer(mutating: pointer), handle: -1)
        }
        // bool SkSurface_wait(void *surface, int numSemaphores, const void *waitSemaphores, bool deleteSemaphoresAfterWait); // (SkSurface *surface, int numSemaphores, const GrBackendSemaphore *waitSemaphores, bool deleteSemaphoresAfterWait) -> bool
        // bool SkSurface_characterize(void *surface, void *characterization); // (SkSurface *surface, GrSurfaceCharacterization *characterization) -> bool
        // bool SkSurface_unique(void *surface); // (SkSurface *surface) -> bool

        func unique() -> Bool {
            return SkSurface_unique(self.pointer)
        }
        // void SkSurface_ref(void *surface); // (SkSurface *surface)

        func ref() {
            SkSurface_ref(self.pointer)
        }
        // void SkSurface_unref(void *surface); // (SkSurface *surface)

        func unref() {
            SkSurface_unref(self.pointer)
        }

        // static

        init(pointer: SkSurfaceMutablePointer?, handle: sk_surface_t) {
            self.pointer = pointer
            self.handle = handle
        }
    }
}