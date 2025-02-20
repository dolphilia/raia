extension Skia {
    // enum Style : uint8_t {
    //     kFill_Style,          //!< set to fill geometry
    //     kStroke_Style,        //!< set to stroke geometry
    //     kStrokeAndFill_Style, //!< sets to stroke and fill geometry
    // };
    public enum SkPaintStyle: UInt8 {
        case fill = 0
        case stroke = 1
        case strokeAndFill = 2
    }
    //  enum Cap {
    //     kButt_Cap,                  //!< no stroke extension
    //     kRound_Cap,                 //!< adds circle
    //     kSquare_Cap,                //!< adds square
    //     kLast_Cap    = kSquare_Cap, //!< largest Cap value
    //     kDefault_Cap = kButt_Cap,   //!< equivalent to kButt_Cap
    // };
    public enum SkPaintCap: UInt8 {
        case butt = 0
        case round = 1
        case square = 2
    }
    // enum Join : uint8_t {
    //     kMiter_Join,                 //!< extends to miter limit
    //     kRound_Join,                 //!< adds circle
    //     kBevel_Join,                 //!< connects outside edges
    //     kLast_Join    = kBevel_Join, //!< equivalent to the largest value for Join
    //     kDefault_Join = kMiter_Join, //!< equivalent to kMiter_Join
    // };
    public enum SkPaintJoin: UInt8 {
        case miter = 0
        case round = 1
        case bevel = 2
    }
    class SkPaint {
        public var pointer: SkPaintMutablePointer?
        public var handle: Int32 = -1

        // void SkPaint_delete(void *paint); // (SkPaint *paint)
        deinit {
            if self.handle > -1 {
                //static_sk_paint_delete(self.handle)
            } else {
                SkPaint_delete(self.pointer)
            }
        }

        // void *SkPaint_new(); // () -> SkPaint *
        init() {
            self.pointer = SkPaint_new()
        }
        // void *SkPaint_new_2(const void *color, void *colorSpace); // (const SkColor4f *color, SkColorSpace *colorSpace) -> SkPaint *

        init(color: SkColor4f, colorSpace: SkColorSpace) {
            self.pointer = SkPaint_new_2(color.pointer, colorSpace.pointer)
            self.handle = -1
        }
        
        // void *SkPaint_new_3(const void *paint); // (const SkPaint *paint) -> SkPaint *

        init(paint: SkPaint) {
            self.pointer = SkPaint_new_3(paint.pointer)
            self.handle = -1
        }
        
        // void SkPaint_reset(void *paint); // (SkPaint *paint)
        func reset() {
            SkPaint_reset(self.pointer)
        }

        // bool SkPaint_isAntiAlias(void *paint); // (SkPaint *paint) -> bool
        func isAntiAlias() -> Bool {
            return SkPaint_isAntiAlias(self.pointer)
        }
        
        // void SkPaint_setAntiAlias(void *paint, bool aa); // (SkPaint *paint, bool aa)
        func setAntiAlias(_ aa: Bool) {
            SkPaint_setAntiAlias(self.pointer, aa)
        }
        
        // bool SkPaint_isDither(void *paint); // (SkPaint *paint) -> bool
        func isDither() -> Bool {
            return SkPaint_isDither(self.pointer)
        }
        
        // void SkPaint_setDither(void *paint, bool dither); // (SkPaint *paint, bool dither)
        func setDither(dither: Bool) {
            SkPaint_setDither(self.pointer, dither)
        }

        // int SkPaint_getStyle(void *paint); // (SkPaint *paint) -> SkPaint::Style
        func getStyle() -> SkPaintStyle {
            return SkPaintStyle(rawValue: UInt8(SkPaint_getStyle(self.pointer)))!
        }
        
        // void SkPaint_setStyle(void *paint, int style); // (SkPaint *paint, SkPaint::Style style)
        func setStyle(style: SkPaintStyle) {
            SkPaint_setStyle(self.pointer, Int32(style.rawValue))
        }
        // void SkPaint_setStroke(void *paint, bool v); // (SkPaint *paint, bool v)
        func setStroke(v: Bool) {
            SkPaint_setStroke(self.pointer, v)
        }
        // unsigned int SkPaint_getColor(void *paint); // (SkPaint *paint) -> SkColor
        func getColor() -> SkColor {
            return SkColor(color: SkPaint_getColor(self.pointer))
        }
        // int SkPaint_getColor4f(void *paint); // (SkPaint *paint) -> sk_color_4f_t
        func getColor4f() -> SkColor4f {
            let handle = SkPaint_getColor4f(self.pointer)
            let pointer = static_sk_color_4f_get_ptr(handle)
            return SkColor4f(pointer: pointer, handle: handle)
        }
        // void SkPaint_setColor(void *paint, unsigned int color); // (SkPaint *paint, SkColor color)
        func setColor(color: SkColor) {
            SkPaint_setColor(self.pointer, color.color)
        }
        // void SkPaint_setColor_2(void *paint, const void *color, void *colorSpace); // (SkPaint *paint, const SkColor4f *color, SkColorSpace *colorSpace)
        func setColor(color: SkColor4f, colorSpace: SkColorSpace) {
            SkPaint_setColor_2(self.pointer, color.pointer, colorSpace.pointer)
        }
        // void SkPaint_setColor4f(void *paint, const void *color, void *colorSpace); // (SkPaint *paint, const SkColor4f *color, SkColorSpace *colorSpace)
        func setColor4f(color: SkColor4f, colorSpace: SkColorSpace) {
            SkPaint_setColor4f(self.pointer, color.pointer, colorSpace.pointer)
        }
        // float SkPaint_getAlphaf(void *paint); // (SkPaint *paint) -> float
        func getAlphaf() -> Float {
            return SkPaint_getAlphaf(self.pointer)
        }
        // unsigned char SkPaint_getAlpha(void *paint); // (SkPaint *paint) -> uint8_t
        func getAlpha() -> UInt8 {
            return SkPaint_getAlpha(self.pointer)
        }
        // void SkPaint_setAlphaf(void *paint, float a); // (SkPaint *paint, float a)
        func setAlphaf(a: Float) {
            SkPaint_setAlphaf(self.pointer, a)
        }
        // void SkPaint_setAlpha(void *paint, unsigned int a); // (SkPaint *paint, U8CPU a)
        func setAlpha(a: UInt8) {
            SkPaint_setAlpha(self.pointer, UInt32(a))
        }
        // void SkPaint_setARGB(void *paint, unsigned int a, unsigned int r, unsigned int g, unsigned int b); // (SkPaint *paint, U8CPU a, U8CPU r, U8CPU g, U8CPU b)
        func setARGB(a: UInt8, r: UInt8, g: UInt8, b: UInt8) {
            SkPaint_setARGB(self.pointer, UInt32(a), UInt32(r), UInt32(g), UInt32(b))
        }
        // float SkPaint_getStrokeWidth(void *paint); // (SkPaint *paint) -> SkScalar
        func getStrokeWidth() -> Float {
            return SkPaint_getStrokeWidth(self.pointer)
        }
        // void SkPaint_setStrokeWidth(void *paint, float width); // (SkPaint *paint, SkScalar width)
        func setStrokeWidth(width: Float) {
            SkPaint_setStrokeWidth(self.pointer, width)
        }
        // float SkPaint_getStrokeMiter(void *paint); // (SkPaint *paint) -> SkScalar
        func getStrokeMiter() -> Float {
            return SkPaint_getStrokeMiter(self.pointer)
        }
        // void SkPaint_setStrokeMiter(void *paint, float miter); // (SkPaint *paint, SkScalar miter)
        func setStrokeMiter(miter: Float) {
            SkPaint_setStrokeMiter(self.pointer, miter)
        }
        // int SkPaint_getStrokeCap(void *paint); // (SkPaint *paint) -> SkPaint::Cap
        func getStrokeCap() -> SkPaintCap {
            return SkPaintCap(rawValue: UInt8(SkPaint_getStrokeCap(self.pointer)))!
        }
        // void SkPaint_setStrokeCap(void *paint, int cap); // (SkPaint *paint, SkPaint::Cap cap)
        func setStrokeCap(cap: SkPaintCap) {
            SkPaint_setStrokeCap(self.pointer, Int32(cap.rawValue))
        }
        // int SkPaint_getStrokeJoin(void *paint); // (SkPaint *paint) -> SkPaint::Join
        func getStrokeJoin() -> SkPaintJoin {
            return SkPaintJoin(rawValue: UInt8(SkPaint_getStrokeJoin(self.pointer)))!
        }
        // void SkPaint_setStrokeJoin(void *paint, int join); // (SkPaint *paint, SkPaint::Join join)
        func setStrokeJoin(join: SkPaintJoin) {
            SkPaint_setStrokeJoin(self.pointer, Int32(join.rawValue))
        }
        // void * SkPaint_getShader(void *paint); // (SkPaint *paint) -> SkShader *
        func getShader() -> SkShader {
            let pointer = SkPaint_getShader(self.pointer)
            return SkShader(pointer: pointer, handle: -1)
        }
        // int SkPaint_refShader(void *paint); // (SkPaint *paint) -> sk_shader_t
        func refShader() -> SkShader {
            let handle = SkPaint_refShader(self.pointer)
            let pointer = static_sk_shader_get(handle)
            return SkShader(pointer: pointer, handle: handle)
        }
        // void SkPaint_setShader(void *paint, int shader); // (SkPaint *paint, sk_shader_t shader)
        func setShader(shader: SkShader) {
            SkPaint_setShader(self.pointer, shader.handle)
        }
        // void * SkPaint_getColorFilter(void *paint); // (SkPaint *paint) -> SkColorFilter *
        func getColorFilter() -> SkColorFilter {
            let pointer = SkPaint_getColorFilter(self.pointer)
            return SkColorFilter(pointer: pointer, handle: -1)
        }
        // int SkPaint_refColorFilter(void *paint); // (SkPaint *paint) -> sk_color_filter_t
        func refColorFilter() -> SkColorFilter {
            let handle = SkPaint_refColorFilter(self.pointer)
            let pointer = static_sk_color_filter_get(handle)
            return SkColorFilter(pointer: pointer, handle: handle)
        }
        // void SkPaint_setColorFilter(void *paint, int color_filter); // (SkPaint *paint, sk_color_filter_t color_filter)
        func setColorFilter(colorFilter: SkColorFilter) {
            SkPaint_setColorFilter(self.pointer, colorFilter.handle)
        }
        // int SkPaint_asBlendMode(void *paint); // (SkPaint *paint) -> int
        func asBlendMode() -> Int {
            return Int(SkPaint_asBlendMode(self.pointer))
        }
        // int SkPaint_getBlendMode_or(void *paint, int defaultMode); // (SkPaint *paint, SkBlendMode defaultMode) -> SkBlendMode
        func getBlendMode_or(defaultMode: SkBlendMode) -> SkBlendMode {
            return SkBlendMode(rawValue: SkPaint_getBlendMode_or(self.pointer, defaultMode.rawValue))!
        }

        // bool SkPaint_isSrcOver(void *paint); // (SkPaint *paint) -> bool
        func isSrcOver() -> Bool {
            return SkPaint_isSrcOver(self.pointer)
        }
        // void SkPaint_setBlendMode(void *paint, int mode); // (SkPaint *paint, SkBlendMode mode)
        func setBlendMode(mode: SkBlendMode) {
            SkPaint_setBlendMode(self.pointer, mode.rawValue)
        }
        // void * SkPaint_getBlender(void *paint); // (SkPaint *paint) -> SkBlender *
        func getBlender() -> SkBlender {
            let pointer = SkPaint_getBlender(self.pointer)
            return SkBlender(pointer: pointer, handle: -1)
        }
        // int SkPaint_refBlender(void *paint); // (SkPaint *paint) -> sk_blender_t
        func refBlender() -> SkBlender {
            let handle = SkPaint_refBlender(self.pointer)
            let pointer = static_sk_blender_get(handle)
            return SkBlender(pointer: pointer, handle: handle)
        }
        // void SkPaint_setBlender(void *paint, int blender); // (SkPaint *paint, sk_blender_t blender)
        func setBlender(blender: SkBlender) {
            SkPaint_setBlender(self.pointer, blender.handle)
        }
        // void * SkPaint_getPathEffect(void *paint); // (SkPaint *paint) -> SkPathEffect *
        func getPathEffect() -> SkPathEffect {
            let pointer = SkPaint_getPathEffect(self.pointer)
            return SkPathEffect(pointer: pointer, handle: -1)
        }
        // int SkPaint_refPathEffect(void *paint); // (SkPaint *paint) -> sk_path_effect_t
        func refPathEffect() -> SkPathEffect {
            let handle = SkPaint_refPathEffect(self.pointer)
            let pointer = static_sk_path_effect_get(handle)
            return SkPathEffect(pointer: pointer, handle: handle)
        }
        // void SkPaint_setPathEffect(void *paint, int path_effect); // (SkPaint *paint, sk_path_effect_t path_effect)
        func setPathEffect(pathEffect: SkPathEffect) {
            SkPaint_setPathEffect(self.pointer, pathEffect.handle)
        }
        // void * SkPaint_getMaskFilter(void *paint); // (SkPaint *paint) -> SkMaskFilter *
        func getMaskFilter() -> SkMaskFilter {
            let pointer = SkPaint_getMaskFilter(self.pointer)
            return SkMaskFilter(pointer: pointer, handle: -1)
        }
        // int SkPaint_refMaskFilter(void *paint); // (SkPaint *paint) -> sk_mask_filter_t
        func refMaskFilter() -> SkMaskFilter {
            let handle = SkPaint_refMaskFilter(self.pointer)
            let pointer = static_sk_mask_filter_get(handle)
            return SkMaskFilter(pointer: pointer, handle: handle)
        }
        // void SkPaint_setMaskFilter(void *paint, int mask_filter); // (SkPaint *paint, sk_mask_filter_t mask_filter)
        func setMaskFilter(maskFilter: SkMaskFilter) {
            SkPaint_setMaskFilter(self.pointer, maskFilter.handle)
        }
        // void * SkPaint_getImageFilter(void *paint); // (SkPaint *paint) -> SkImageFilter *
        func getImageFilter() -> SkImageFilter {
            let pointer = SkPaint_getImageFilter(self.pointer)
            return SkImageFilter(pointer: pointer, handle: -1)
        }
        // int SkPaint_refImageFilter(void *paint); // (SkPaint *paint) -> sk_image_filter_t
        func refImageFilter() -> SkImageFilter {
            let handle = SkPaint_refImageFilter(self.pointer)
            let pointer = static_sk_image_filter_get(handle)
            return SkImageFilter(pointer: pointer, handle: handle)
        }
        // void SkPaint_setImageFilter(void *paint, int image_filter); // (SkPaint *paint, sk_image_filter_t image_filter)
        func setImageFilter(imageFilter: SkImageFilter) {
            SkPaint_setImageFilter(self.pointer, imageFilter.handle)
        }
        // bool SkPaint_nothingToDraw(void *paint); // (SkPaint *paint) -> bool
        func nothingToDraw() -> Bool {
            return SkPaint_nothingToDraw(self.pointer)
        }
        // bool SkPaint_canComputeFastBounds(void *paint); // (SkPaint *paint) -> bool
        func canComputeFastBounds() -> Bool {
            return SkPaint_canComputeFastBounds(self.pointer)
        }
        // const void * SkPaint_computeFastBounds(void *paint, const void *orig, void *storage); // (SkPaint *paint, const SkRect *orig, SkRect *storage) -> const SkRect *
        func computeFastBounds(orig: SkRect, storage: SkRect) -> SkRect {
            let pointer = SkPaint_computeFastBounds(self.pointer, orig.pointer, storage.pointer)
            return SkRect(pointer: UnsafeMutableRawPointer(mutating: pointer), handle: -1)
        }
        // const void * SkPaint_computeFastStrokeBounds(void *paint, const void *orig, void *storage); // (SkPaint *paint, const SkRect *orig, SkRect *storage) -> const SkRect *
        func computeFastStrokeBounds(orig: SkRect, storage: SkRect) -> SkRect {
            let pointer = SkPaint_computeFastStrokeBounds(self.pointer, orig.pointer, storage.pointer)
            return SkRect(pointer: UnsafeMutableRawPointer(mutating: pointer), handle: -1)
        }
        // const void * SkPaint_doComputeFastBounds(void *paint, const void *orig, void *storage, int style); // (SkPaint *paint, const SkRect *orig, SkRect *storage, SkPaint::Style style) -> const SkRect *
        func doComputeFastBounds(orig: SkRect, storage: SkRect, style: SkPaintStyle) -> SkRect {
            let pointer = SkPaint_doComputeFastBounds(self.pointer, orig.pointer, storage.pointer, Int32(style.rawValue))
            return SkRect(pointer: UnsafeMutableRawPointer(mutating: pointer), handle: -1)
        }

    }
}