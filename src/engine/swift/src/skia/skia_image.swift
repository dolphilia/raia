extension Skia {
    class SkImage {
        public var pointer: SkImageMutablePointer?
        public var handle: sk_image_t = -1

        // void SkImage_delete(void *image); // (SkImage *image)
        deinit {
            if self.handle > -1 {
                static_sk_image_delete(self.handle)
            } else {
                SkImage_delete(self.pointer)
            }
        }

        init (pointer: SkImageMutablePointer?, handle: sk_image_t) {
            self.pointer = pointer
            self.handle = handle
        }

        // // TODO
        // // const void *SkImage_imageInfo(void *image); // (SkImage *image) -> const SkImageInfo *
        // int SkImage_width(void *image); // (SkImage *image) -> int

        func width() -> Int {
            return Int(SkImage_width(self.pointer))
        }
        // int SkImage_height(void *image); // (SkImage *image) -> int
        func height() -> Int {
            return Int(SkImage_height(self.pointer))
        }
        // int SkImage_dimensions(void *image); // (SkImage *image) -> sk_i_size_t
        
        func dimensions() -> SkISize {
            let handle = SkImage_dimensions(self.pointer)
            let pointer = static_sk_i_size_get_ptr(handle)
            return SkISize(pointer: pointer, handle: handle)
        }
        // int SkImage_bounds(void *image); // (SkImage *image) -> sk_i_rect_t

        func bounds() -> SkIRect {
            let handle = SkImage_bounds(self.pointer)
            let pointer = static_sk_i_rect_get_ptr(handle)
            return SkIRect(pointer: pointer, handle: handle)
        }
        // unsigned int SkImage_uniqueID(void *image); // (SkImage *image) -> uint32_t

        func uniqueID() -> UInt32 {
            return SkImage_uniqueID(self.pointer)
        }
        // int SkImage_alphaType(void *image); // (SkImage *image) -> SkAlphaType

        func alphaType() -> SkAlphaType {
            return SkAlphaType(rawValue: SkImage_alphaType(self.pointer))!
        }
        // int SkImage_colorType(void *image); // (SkImage *image) -> SkColorType

        func colorType() -> SkColorType {
            return SkColorType(rawValue: SkImage_colorType(self.pointer))!
        }
        // void *SkImage_colorSpace(void *image); // (SkImage *image) -> SkColorSpace *

        func colorSpace() -> SkColorSpace {
            let pointer = SkImage_colorSpace(self.pointer)
            return SkColorSpace(pointer: pointer, handle: -1)
        }
        // int SkImage_refColorSpace(void *image); // (SkImage *image) -> sk_color_space_t

        func refColorSpace() -> SkColorSpace {
            let handle = SkImage_refColorSpace(self.pointer)
            let pointer = static_sk_color_space_get_ptr(handle)
            return SkColorSpace(pointer: pointer, handle: handle)
        }
        // bool SkImage_isAlphaOnly(void *image); // (SkImage *image) -> bool

        func isAlphaOnly() -> Bool {
            return SkImage_isAlphaOnly(self.pointer)
        }
        // bool SkImage_isOpaque(void *image); // (SkImage *image) -> bool

        func isOpaque() -> Bool {
            return SkImage_isOpaque(self.pointer)
        }
        // int SkImage_makeShader(void *image, int tmx, int tmy, const void *sampling, const void *localMatrix); // (SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix) -> sk_shader_t

        func makeShader(tmx: SkTileMode, tmy: SkTileMode, sampling: SkSamplingOptions, localMatrix: SkMatrix) -> SkShader {
            let handle = SkImage_makeShader(self.pointer, tmx.rawValue, tmy.rawValue, sampling.pointer, localMatrix.pointer)
            let pointer = static_sk_shader_get_ptr(handle)
            return SkShader(pointer: pointer, handle: handle)
        }
        // int SkImage_makeShader_2(void *image, int tmx, int tmy, const void *sampling, const void *lm); // (SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t

        func makeShader(tmx: SkTileMode, tmy: SkTileMode, sampling: SkSamplingOptions, lm: SkMatrix) -> SkShader {
            let handle = SkImage_makeShader_2(self.pointer, tmx.rawValue, tmy.rawValue, sampling.pointer, lm.pointer)
            let pointer = static_sk_shader_get_ptr(handle)
            return SkShader(pointer: pointer, handle: handle)
        }
        // int SkImage_makeShader_3(void *image, const void *sampling, const void *lm); // (SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t

        func makeShader(sampling: SkSamplingOptions, lm: SkMatrix) -> SkShader {
            let handle = SkImage_makeShader_3(self.pointer, sampling.pointer, lm.pointer)
            let pointer = static_sk_shader_get_ptr(handle)
            return SkShader(pointer: pointer, handle: handle)
        }
        // int SkImage_makeShader_4(void *image, const void *sampling, const void *lm); // (SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t

        func makeShader_2(sampling: SkSamplingOptions, lm: SkMatrix) -> SkShader {
            let handle = SkImage_makeShader_4(self.pointer, sampling.pointer, lm.pointer)
            let pointer = static_sk_shader_get_ptr(handle)
            return SkShader(pointer: pointer, handle: handle)
        }
        // int SkImage_makeRawShader(void *image, int tmx, int tmy, const void *sampling, const void *localMatrix); // (SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *localMatrix) -> sk_shader_t

        func makeRawShader(tmx: SkTileMode, tmy: SkTileMode, sampling: SkSamplingOptions, localMatrix: SkMatrix) -> SkShader {
            let handle = SkImage_makeRawShader(self.pointer, tmx.rawValue, tmy.rawValue, sampling.pointer, localMatrix.pointer)
            let pointer = static_sk_shader_get_ptr(handle)
            return SkShader(pointer: pointer, handle: handle)
        }
        // int SkImage_makeRawShader_2(void *image, int tmx, int tmy, const void *sampling, const void *lm); // (SkImage *image, SkTileMode tmx, SkTileMode tmy, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t

        func makeRawShader_2(tmx: SkTileMode, tmy: SkTileMode, sampling: SkSamplingOptions, lm: SkMatrix) -> SkShader {
            let handle = SkImage_makeRawShader_2(self.pointer, tmx.rawValue, tmy.rawValue, sampling.pointer, lm.pointer)
            let pointer = static_sk_shader_get_ptr(handle)
            return SkShader(pointer: pointer, handle: handle)
        }
        // int SkImage_makeRawShader_3(void *image, const void *sampling, const void *lm); // (SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t
        
        func makeRawShader(sampling: SkSamplingOptions, lm: SkMatrix) -> SkShader {
            let handle = SkImage_makeRawShader_3(self.pointer, sampling.pointer, lm.pointer)
            let pointer = static_sk_shader_get_ptr(handle)
            return SkShader(pointer: pointer, handle: handle)
        }
        
        // int SkImage_makeRawShader_4(void *image, const void *sampling, const void *lm); // (SkImage *image, const SkSamplingOptions *sampling, const SkMatrix *lm) -> sk_shader_t

        func makeRawShader_2(sampling: SkSamplingOptions, lm: SkMatrix) -> SkShader {
            let handle = SkImage_makeRawShader_4(self.pointer, sampling.pointer, lm.pointer)
            let pointer = static_sk_shader_get_ptr(handle)
            return SkShader(pointer: pointer, handle: handle)
        }
        // bool SkImage_peekPixels(void *image, void *pixmap); // (SkImage *image, SkPixmap *pixmap) -> bool

        func peekPixels(pixmap: SkPixmap) -> Bool {
            return SkImage_peekPixels(self.pointer, pixmap.pointer)
        }
        // bool SkImage_isTextureBacked(void *image); // (SkImage *image) -> bool

        func isTextureBacked() -> Bool {
            return SkImage_isTextureBacked(self.pointer)
        }
        // unsigned long SkImage_textureSize(void *image); // (SkImage *image) -> size_t

        func textureSize() -> UInt {
            return UInt(SkImage_textureSize(self.pointer))
        }
        // bool SkImage_isValid(void *image, void *context); // (SkImage *image, GrRecordingContext *context) -> bool
        // bool SkImage_readPixels(void *image, void *context, const void *dstInfo, void *dstPixels, unsigned long dstRowBytes, int srcX, int srcY, int cachingHint); // (SkImage *image, GrDirectContext *context, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY, SkImage::CachingHint cachingHint) -> bool
        // bool SkImage_readPixels_2(void *image, void *context, const void *dst, int srcX, int srcY, int cachingHint); // (SkImage *image, GrDirectContext *context, const SkPixmap *dst, int srcX, int srcY, SkImage::CachingHint cachingHint) -> bool
        // bool SkImage_readPixels_3(void *image, const void *dstInfo, void *dstPixels, unsigned long dstRowBytes, int srcX, int srcY, int cachingHint); // (SkImage *image, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY, SkImage::CachingHint cachingHint) -> bool
        // bool SkImage_readPixels_4(void *image, const void *dst, int srcX, int srcY, int cachingHint); // (SkImage *image, const SkPixmap *dst, int srcX, int srcY, SkImage::CachingHint cachingHint) -> bool

        // // TODO
        // // void SkImage_asyncRescaleAndReadPixels(void *image, const void *info, const void *srcRect, int rescaleGamma, int rescaleMode, SkImage::ReadPixelsCallback callback, void * context); // (SkImage *image, const SkImageInfo *info, const SkIRect *srcRect, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context)
        // // void SkImage_asyncRescaleAndReadPixelsYUV420(void *image, int yuvColorSpace, sk_color_space_t color_space, const void *srcRect, const void *dstSize, int rescaleGamma, int rescaleMode, SkImage::ReadPixelsCallback callback, void * context); // (SkImage *image, SkYUVColorSpace yuvColorSpace, sk_color_space_t color_space, const SkIRect *srcRect, const SkISize *dstSize, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context)
        // // void SkImage_asyncRescaleAndReadPixelsYUVA420(void *image, int yuvColorSpace, sk_color_space_t color_space, const void *srcRect, const void *dstSize, int rescaleGamma, int rescaleMode, SkImage::ReadPixelsCallback callback, void * context); // (SkImage *image, SkYUVColorSpace yuvColorSpace, sk_color_space_t color_space, const SkIRect *srcRect, const SkISize *dstSize, SkImage::RescaleGamma rescaleGamma, SkImage::RescaleMode rescaleMode, SkImage::ReadPixelsCallback callback, SkImage::ReadPixelsContext context)
        // bool SkImage_scalePixels(void *image, const void *dst, const void *sampling, int cachingHint); // (SkImage *image, const SkPixmap *dst, const SkSamplingOptions *sampling, SkImage::CachingHint cachingHint) -> bool
        // int SkImage_refEncodedData(void *image); // (SkImage *image) -> sk_data_t

        func refEncodedData() -> SkData {
            let handle = SkImage_refEncodedData(self.pointer)
            let pointer = static_sk_data_get_ptr(handle)
            return SkData(pointer: pointer, handle: handle)
        }
        // int SkImage_makeSubset(void *image, void *direct, const void *subset); // (SkImage *image, GrDirectContext *direct, const SkIRect *subset) -> sk_image_t
        // int SkImage_makeSubset_2(void *image, void *recorder, const void *subset, int properties); // (SkImage *image, skgpu::graphite::Recorder *recorder, const SkIRect *subset, sk_image_required_properties_t properties) -> sk_image_t
        // bool SkImage_hasMipmaps(void *image); // (SkImage *image) -> bool

        func hasMipmaps() -> Bool {
            return SkImage_hasMipmaps(self.pointer)
        }
        // bool SkImage_isProtected(void *image); // (SkImage *image) -> bool

        func isProtected() -> Bool {
            return SkImage_isProtected(self.pointer)
        }
        // int SkImage_withDefaultMipmaps(void *image); // (SkImage *image) -> sk_image_t

        func withDefaultMipmaps() -> SkImage {
            let handle = SkImage_withDefaultMipmaps(self.pointer)
            let pointer = static_sk_image_get_ptr(handle)
            return SkImage(pointer: pointer, handle: handle)
        }
        // int SkImage_makeNonTextureImage(void *image, void *context); // (SkImage *image, GrDirectContext *context) -> sk_image_t
        // int SkImage_makeRasterImage(void *image, void *context, int cachingHint); // (SkImage *image, GrDirectContext *context, SkImage::CachingHint cachingHint) -> sk_image_t
        // int SkImage_makeRasterImage_2(void *image, int cachingHint); // (SkImage *image, SkImage::CachingHint cachingHint) -> sk_image_t
        // bool SkImage_asLegacyBitmap(void *image, void *bitmap, int legacyBitmapMode); // (SkImage *image, SkBitmap *bitmap, SkImage::LegacyBitmapMode legacyBitmapMode) -> bool
        // bool SkImage_isLazyGenerated(void *image); // (SkImage *image) -> bool

        func isLazyGenerated() -> Bool {
            return SkImage_isLazyGenerated(self.pointer)
        }
        // int SkImage_makeColorSpace(void *image, void *direct, int color_space); // (SkImage *image, GrDirectContext *direct, sk_color_space_t color_space) -> sk_image_t
        // int SkImage_makeColorSpace_2(void *image, void *recorder, int color_space, int properties); // (SkImage *image, skgpu::graphite::Recorder *recorder, sk_color_space_t color_space, sk_image_required_properties_t properties) -> sk_image_t
        // int SkImage_makeColorTypeAndColorSpace(void *image, void *direct, int targetColorType, int color_space); // (SkImage *image, GrDirectContext *direct, SkColorType targetColorType, sk_color_space_t color_space) -> sk_image_t
        // int SkImage_makeColorTypeAndColorSpace_2(void *image, void *recorder, int targetColorType, int color_space, int properties); // (SkImage *image, skgpu::graphite::Recorder *recorder, SkColorType targetColorType, sk_color_space_t color_space, sk_image_required_properties_t properties) -> sk_image_t
        // int SkImage_reinterpretColorSpace(void *image, int color_space); // (SkImage *image, sk_color_space_t color_space) -> sk_image_t

        func reinterpretColorSpace(colorSpace: SkColorSpace) -> SkImage {
            let handle = SkImage_reinterpretColorSpace(self.pointer, colorSpace.handle)
            let pointer = static_sk_image_get_ptr(handle)
            return SkImage(pointer: pointer, handle: handle)
        }
        // bool SkImage_unique(void *image); // (SkImage *image) -> bool

        func unique() -> Bool {
            return SkImage_unique(self.pointer)
        }

        // void SkImage_ref(void *image); // (SkImage *image)

        func ref() {
            SkImage_ref(self.pointer)
        }

        // void SkImage_unref(void *image); // (SkImage *image)

        func unref() {
            SkImage_unref(self.pointer)
        }
    }
}