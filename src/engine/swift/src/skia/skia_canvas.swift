extension Skia {
    public enum SkCanvasSrcRectConstraint: Int32 {
        case kStrict_SrcRectConstraint
        case kFast_SrcRectConstraint
    }
    class SkCanvas {


        public var pointer: SkCanvasMutablePointer?
        public var handle: sk_canvas_t = -1

        // void SkCanvas_delete(void *canvas); // (SkCanvas *canvas)

        deinit {
            if handle > -1 {
                static_sk_canvas_delete(handle)
            } else {
                SkCanvas_delete(self.pointer)
            }
        }

        // void * SkCanvas_new(); // () -> SkCanvas *
        init() {
            self.pointer = SkCanvas_new()
        }
        // void * SkCanvas_new_2(int width, int height, const void *props); // (int width, int height, const SkSurfaceProps *props) -> SkCanvas *
        init(width: Int, height: Int, props: SkSurfacePropsConstPointer?) {
            self.pointer = SkCanvas_new_2(Int32(width), Int32(height), props)
        }
        // void * SkCanvas_new_3(void *bitmap); // (SkBitmap *bitmap) -> SkCanvas *
        init(bitmap: SkBitmapMutablePointer?) {
            self.pointer = SkCanvas_new_3(bitmap)
        }
        init(bitmap: SkBitmap) {
            self.pointer = SkCanvas_new_3(bitmap.pointer)
        }
        // void * SkCanvas_new_4(const void *bitmap, const void *props); // (const SkBitmap *bitmap, const SkSurfaceProps *props) -> SkCanvas *
        init(bitmap: SkBitmapConstPointer?, props: SkSurfacePropsConstPointer?) {
            self.pointer = SkCanvas_new_4(bitmap, props)
        }
        init(bitmap: SkBitmap, props: SkSurfaceProps) {
            self.pointer = SkCanvas_new_4(bitmap.pointer, props.pointer)
        }
        
        // void * SkCanvas_accessTopLayerPixels(void *canvas, void *info, void *rowBytes, void *origin); // (SkCanvas *canvas, SkImageInfo *info, size_t *rowBytes, SkIPoint *origin) -> void *

        func accessTopLayerPixels(info: SkImageInfo, rowBytes: UnsafeMutablePointer<UInt>?, origin: SkIPoint) -> UnsafeMutableRawPointer? {
            return SkCanvas_accessTopLayerPixels(self.pointer, info.pointer, rowBytes, origin.pointer)
        }
        // void * SkCanvas_accessTopRasterHandle(void *canvas); // (SkCanvas *canvas) -> SkRasterHandleAllocator::Handle
        // void SkCanvas_androidFramework_setDeviceClipRestriction(void *canvas, const void *rect); // (SkCanvas *canvas, const SkIRect *rect)

        func androidFramework_setDeviceClipRestriction(rect: SkIRect) {
            SkCanvas_androidFramework_setDeviceClipRestriction(self.pointer, rect.pointer)
        }
        // void SkCanvas_clear(void *canvas, const void *color); // (SkCanvas *canvas, const SkColor4f *color)
        func clear(color: SkColor4f) {
            SkCanvas_clear(self.pointer, color.pointer)
        }
        // void SkCanvas_clear_2(void *canvas, unsigned int color); // (SkCanvas *canvas, SkColor color)
        func clear(color: SkColor) {
            SkCanvas_clear_2(self.pointer, color)
        }
        // void SkCanvas_clipIRect(void *canvas, const void *irect, int op); // (SkCanvas *canvas, const SkIRect *irect, SkClipOp op)

        func clipIRect(irect: SkIRect, op: SkClipOp) {
            SkCanvas_clipIRect(self.pointer, irect.pointer, Int32(op.rawValue))
        }
        // void SkCanvas_clipPath(void *canvas, const void *path, bool doAntiAlias); // (SkCanvas *canvas, const SkPath *path, bool doAntiAlias)

        func clipPath(path: SkPath, doAntiAlias: Bool) {
            SkCanvas_clipPath(self.pointer, path.pointer, doAntiAlias)
        }
        // void SkCanvas_clipPath_2(void *canvas, const void *path, int op); // (SkCanvas *canvas, const SkPath *path, SkClipOp op)

        func clipPath(path: SkPath, op: SkClipOp) {
            SkCanvas_clipPath_2(self.pointer, path.pointer, Int32(op.rawValue))
        }
        // void SkCanvas_clipPath_3(void *canvas, const void *path, int op, bool doAntiAlias); // (SkCanvas *canvas, const SkPath *path, SkClipOp op, bool doAntiAlias)

        func clipPath(path: SkPath, op: SkClipOp, doAntiAlias: Bool) {
            SkCanvas_clipPath_3(self.pointer, path.pointer, Int32(op.rawValue), doAntiAlias)
        }
        // void SkCanvas_clipRect(void *canvas, const void *rect, bool doAntiAlias); // (SkCanvas *canvas, const SkRect *rect, bool doAntiAlias)

        func clipRect(rect: SkRect, doAntiAlias: Bool) {
            SkCanvas_clipRect(self.pointer, rect.pointer, doAntiAlias)
        }
        // void SkCanvas_clipRect_2(void *canvas, const void *rect, int op); // (SkCanvas *canvas, const SkRect *rect, SkClipOp op)

        func clipRect(rect: SkRect, op: SkClipOp) {
            SkCanvas_clipRect_2(self.pointer, rect.pointer, Int32(op.rawValue))
        }
        // void SkCanvas_clipRect_3(void *canvas, const void *rect, int op, bool doAntiAlias); // (SkCanvas *canvas, const SkRect *rect, SkClipOp op, bool doAntiAlias)

        func clipRect(rect: SkRect, op: SkClipOp, doAntiAlias: Bool) {
            SkCanvas_clipRect_3(self.pointer, rect.pointer, Int32(op.rawValue), doAntiAlias)
        }
        // void SkCanvas_clipRegion(void *canvas, const void *deviceRgn, int op); // (SkCanvas *canvas, const SkRegion *deviceRgn, SkClipOp op)

        func clipRegion(deviceRgn: SkRegion, op: SkClipOp) {
            SkCanvas_clipRegion(self.pointer, deviceRgn.pointer, Int32(op.rawValue))
        }
        // void SkCanvas_clipRRect(void *canvas, const void *rrect, bool doAntiAlias); // (SkCanvas *canvas, const SkRRect *rrect, bool doAntiAlias)

        func clipRRect(rrect: SkRRect, doAntiAlias: Bool) {
            SkCanvas_clipRRect(self.pointer, rrect.pointer, doAntiAlias)
        }
        // void SkCanvas_clipRRect_2(void *canvas, const void *rrect, int op); // (SkCanvas *canvas, const SkRRect *rrect, SkClipOp op)

        func clipRRect(rrect: SkRRect, op: SkClipOp) {
            SkCanvas_clipRRect_2(self.pointer, rrect.pointer, Int32(op.rawValue))
        }
        // void SkCanvas_clipRRect_3(void *canvas, const void *rrect, int op, bool doAntiAlias); // (SkCanvas *canvas, const SkRRect *rrect, SkClipOp op, bool doAntiAlias)

        func clipRRect(rrect: SkRRect, op: SkClipOp, doAntiAlias: Bool) {
            SkCanvas_clipRRect_3(self.pointer, rrect.pointer, Int32(op.rawValue), doAntiAlias)
        }
        // void SkCanvas_clipShader(void *canvas, int shader, int op); // (SkCanvas *canvas, sk_shader_t shader, SkClipOp op)

        func clipShader(shader: SkShader, op: SkClipOp) {
            SkCanvas_clipShader(self.pointer, shader.handle, Int32(op.rawValue))
        }
        // void SkCanvas_concat(void *canvas, const void * m44); // (SkCanvas *canvas, const SkM44 *m44)

        func concat(m44: SkM44) {
            SkCanvas_concat(self.pointer, m44.pointer)
        }
        // void SkCanvas_concat_2(void *canvas, const void * matrix); // (SkCanvas *canvas, const SkMatrix *matrix)

        func concat(matrix: SkMatrix) {
            SkCanvas_concat_2(self.pointer, matrix.pointer)
        }
        // void SkCanvas_discard(void *canvas); // (SkCanvas *canvas)

        func discard() {
            SkCanvas_discard(self.pointer)
        }
        // void SkCanvas_drawAnnotation(void *canvas, const void *rect, const char * key, int data); // (SkCanvas *canvas, const SkRect *rect, const char key[], sk_data_t data)
        func drawAnnotation(rect: SkRect, Key: UnsafePointer<CChar>, data: SkData) {
            SkCanvas_drawAnnotation(self.pointer, rect.pointer, Key, Int32(data.handle))
        }
        func drawAnnotation(rect: SkRect, key: String, data: SkData) {
            SkCanvas_drawAnnotation(self.pointer, rect.pointer, key, data.handle)
        }
        // void SkCanvas_drawAnnotation_2(void *canvas, const void *rect, const char * key, void *value); // (SkCanvas *canvas, const SkRect *rect, const char key[], SkData *value)
        func drawAnnotation(rect: SkRect, key: UnsafePointer<CChar>, value: SkData) {
            SkCanvas_drawAnnotation_2(self.pointer, rect.pointer, key, value.pointer)
        }
        func drawAnnotation(rect: SkRect, key: String, value: SkData) {
            SkCanvas_drawAnnotation_2(self.pointer, rect.pointer, key, value.pointer)
        }
        // void SkCanvas_drawArc(void *canvas, const void *oval, float startAngle, float sweepAngle, bool useCenter, const void *paint); // (SkCanvas *canvas, const SkRect *oval, SkScalar startAngle, SkScalar sweepAngle, bool useCenter, const SkPaint *paint)

        func drawArc(oval: SkRect, startAngle: Float, sweepAngle: Float, useCenter: Bool, paint: SkPaint) {
            SkCanvas_drawArc(self.pointer, oval.pointer, startAngle, sweepAngle, useCenter, paint.pointer)
        }
        // void SkCanvas_drawAtlas(void *canvas, const void *atlas, const void * xform, const void * tex, const void * colors, int count, int mode, const void *sampling, const void *cullRect, const void *paint); // (SkCanvas *canvas, const SkImage *atlas, const SkRSXform xform[], const SkRect tex[], const SkColor colors[], int count, SkBlendMode mode, const SkSamplingOptions *sampling, const SkRect *cullRect, const SkPaint *paint)

        func drawAtlas(atlas: SkImage, xform: [SkRSXform], tex: [SkRect], colors: [Color], count: Int, mode: SkBlendMode, sampling: SkSamplingOptions, cullRect: SkRect, paint: SkPaint) {
            xform.withUnsafeBufferPointer { xformPointer in
                tex.withUnsafeBufferPointer { texPointer in
                    SkCanvas_drawAtlas(self.pointer, atlas.pointer, xformPointer.baseAddress, texPointer.baseAddress, colors, Int32(count), Int32(mode.rawValue), sampling.pointer, cullRect.pointer, paint.pointer)
                }
            }
        }
        // void SkCanvas_drawCircle(void *canvas, int center, float radius, const void *paint); // (SkCanvas *canvas, sk_point_t center, SkScalar radius, const SkPaint *paint)

        func drawCircle(center: SkPoint, radius: Float, paint: SkPaint) {
            SkCanvas_drawCircle(self.pointer, Int32(center.handle), radius, paint.pointer)
        }
        // void SkCanvas_drawCircle_2(void *canvas, float cx, float cy, float radius, const void *paint); // (SkCanvas *canvas, SkScalar cx, SkScalar cy, SkScalar radius, const SkPaint *paint)

        func drawCircle(cx: Float, cy: Float, radius: Float, paint: SkPaint) {
            SkCanvas_drawCircle_2(self.pointer, cx, cy, radius, paint.pointer)
        }
        // void SkCanvas_drawColor(void *canvas, const void * color, int mode); // (SkCanvas *canvas, const SkColor4f *color, SkBlendMode mode)

        func drawColor(color: SkColor4f, mode: SkBlendMode) {
            SkCanvas_drawColor(self.pointer, color.pointer, Int32(mode.rawValue))
        }
        // void SkCanvas_drawColor_2(void *canvas, unsigned int color, int mode); // (SkCanvas *canvas, SkColor color, SkBlendMode mode)

        func drawColor(color: SkColor, mode: SkBlendMode) {
            SkCanvas_drawColor_2(self.pointer, color, Int32(mode.rawValue))
        }
        // void SkCanvas_drawDrawable(void *canvas, void *drawable, const void *matrix); // (SkCanvas *canvas, SkDrawable *drawable, const SkMatrix *matrix)

        func drawDrawable(drawable: SkDrawable, matrix: SkMatrix) {
            SkCanvas_drawDrawable(self.pointer, drawable.pointer, matrix.pointer)
        }
        // void SkCanvas_drawDrawable_2(void *canvas, void *drawable, float x, float y); // (SkCanvas *canvas, SkDrawable *drawable, SkScalar x, SkScalar y)

        func drawDrawable(drawable: SkDrawable, x: Float, y: Float) {
            SkCanvas_drawDrawable_2(self.pointer, drawable.pointer, x, y)
        }
        // void SkCanvas_drawDRRect(void *canvas, const void *outer, const void *inner, const void *paint); // (SkCanvas *canvas, const SkRRect *outer, const SkRRect *inner, const SkPaint *paint)

        func drawDRRect(outer: SkRRect, inner: SkRRect, paint: SkPaint) {
            SkCanvas_drawDRRect(self.pointer, outer.pointer, inner.pointer, paint.pointer)
        }
        // void SkCanvas_drawGlyphs(void *canvas, int count, const void * glyphs, const void * positions, const void * clusters, int textByteCount, const char * utf8text, int origin, const void *font, const void *paint); // (SkCanvas *canvas, int count, const SkGlyphID glyphs[], const SkPoint positions[], const uint32_t clusters[], int textByteCount, const char utf8text[], sk_point_t origin, const SkFont *font, const SkPaint *paint)

        typealias GlyphID = UInt16

        func drawGlyphs(count: Int, glyphs: [GlyphID], positions: [SkPoint], clusters: [UInt32], textByteCount: Int, utf8text: String, origin: SkPoint, font: SkFont, paint: SkPaint) {
            glyphs.withUnsafeBufferPointer { glyphsPointer in
                positions.withUnsafeBufferPointer { positionsPointer in
                    clusters.withUnsafeBufferPointer { clustersPointer in
                        SkCanvas_drawGlyphs(self.pointer, Int32(count), glyphsPointer.baseAddress, positionsPointer.baseAddress, clustersPointer.baseAddress, Int32(textByteCount), utf8text, origin.handle, font.pointer, paint.pointer)
                    }
                }
            }
        }
        // void SkCanvas_drawGlyphs_2(void *canvas, int count, const void * glyphs, const void * positions, int origin, const void *font, const void *paint); // (SkCanvas *canvas, int count, const SkGlyphID glyphs[], const SkPoint positions[], sk_point_t origin, const SkFont *font, const SkPaint *paint)

        func drawGlyphs(count: Int, glyphs: [GlyphID], positions: [SkPoint], origin: SkPoint, font: SkFont, paint: SkPaint) {
            glyphs.withUnsafeBufferPointer { glyphsPointer in
                positions.withUnsafeBufferPointer { positionsPointer in
                    SkCanvas_drawGlyphs_2(self.pointer, Int32(count), glyphsPointer.baseAddress, positionsPointer.baseAddress, origin.handle, font.pointer, paint.pointer)
                }
            }
        }
        // void SkCanvas_drawGlyphs_3(void *canvas, int count, const void * glyphs, const void * xforms, int origin, const void *font, const void *paint); // (SkCanvas *canvas, int count, const SkGlyphID glyphs[], const SkRSXform xforms[], sk_point_t origin, const SkFont *font, const SkPaint *paint)

        func drawGlyphs(count: Int, glyphs: [GlyphID], xforms: [SkRSXform], origin: SkPoint, font: SkFont, paint: SkPaint) {
            glyphs.withUnsafeBufferPointer { glyphsPointer in
                xforms.withUnsafeBufferPointer { xformsPointer in
                    SkCanvas_drawGlyphs_3(self.pointer, Int32(count), glyphsPointer.baseAddress, xformsPointer.baseAddress, origin.handle, font.pointer, paint.pointer)
                }
            }
        }
        // void SkCanvas_drawImage(void *canvas, int image, float left, float top); // (SkCanvas *canvas, sk_image_t image, SkScalar left, SkScalar top)

        func drawImage(image: SkImage, left: Float, top: Float) {
            SkCanvas_drawImage(self.pointer, image.handle, left, top)
        }
        // void SkCanvas_drawImage_2(void *canvas, int image, float x, float y, const void *sampling, const void *paint); // (SkCanvas *canvas, sk_image_t image, SkScalar x, SkScalar y, const SkSamplingOptions *sampling, const SkPaint *paint)

        func drawImage(image: SkImage, x: Float, y: Float, sampling: SkSamplingOptions, paint: SkPaint) {
            SkCanvas_drawImage_2(self.pointer, image.handle, x, y, sampling.pointer, paint.pointer)
        }
        // void SkCanvas_drawImage_3(void *canvas, const void *image, float x, float y, const void *sampling, const void *paint); // (SkCanvas *canvas, const SkImage *image, SkScalar x, SkScalar y, const SkSamplingOptions *sampling, const SkPaint *paint)

        func drawImage_3(image: SkImage, x: Float, y: Float, sampling: SkSamplingOptions, paint: SkPaint) {
            SkCanvas_drawImage_3(self.pointer, image.pointer, x, y, sampling.pointer, paint.pointer)
        }
        // void SkCanvas_drawImage_4(void *canvas, const void *image, float left, float top); // (SkCanvas *canvas, const SkImage *image, SkScalar left, SkScalar top)

        func drawImage_4(image: SkImage, left: Float, top: Float) {
            SkCanvas_drawImage_4(self.pointer, image.pointer, left, top)
        }
        // void SkCanvas_drawImageLattice(void *canvas, const void *image, const void *lattice, const void *dst); // (SkCanvas *canvas, const SkImage *image, const SkCanvas::Lattice *lattice, const SkRect *dst)
        // void SkCanvas_drawImageLattice_2(void *canvas, const void *image, const void *lattice, const void *dst, int filter, const void *paint); // (SkCanvas *canvas, const SkImage *image, const SkCanvas::Lattice *lattice, const SkRect *dst, SkFilterMode filter, const SkPaint *paint)
        // void SkCanvas_drawImageNine(void *canvas, const void *image, const void *center, const void *dst, int filter, const void *paint); // (SkCanvas *canvas, const SkImage *image, const SkIRect *center, const SkRect *dst, SkFilterMode filter, const SkPaint *paint)

        func drawImageNine(image: SkImage, center: SkIRect, dst: SkRect, filter: SkFilterMode, paint: SkPaint) {
            SkCanvas_drawImageNine(self.pointer, image.pointer, center.pointer, dst.pointer, Int32(filter.rawValue), paint.pointer)
        }
        // void SkCanvas_drawImageRect(void *canvas, int image, const void *dst, const void *sampling, const void *paint); // (SkCanvas *canvas, sk_image_t image, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint)

        func drawImageRect(image: SkImage, dst: SkRect, sampling: SkSamplingOptions, paint: SkPaint) {
            SkCanvas_drawImageRect(self.pointer, Int32(image.handle), dst.pointer, sampling.pointer, paint.pointer)
        }
        // void SkCanvas_drawImageRect_2(void *canvas, int image, const void *src, const void *dst, const void *sampling, const void *paint, int constraint); // (SkCanvas *canvas, sk_image_t image, const SkRect *src, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint)

        func drawImageRect(image: SkImage, src: SkRect, dst: SkRect, sampling: SkSamplingOptions, paint: SkPaint, constraint: SkCanvasSrcRectConstraint) {
            SkCanvas_drawImageRect_2(self.pointer, Int32(image.handle), src.pointer, dst.pointer, sampling.pointer, paint.pointer, Int32(constraint.rawValue))
        }
        // void SkCanvas_drawImageRect_3(void *canvas, const void *image, const void *dst, const void *sampling, const void *paint); // (SkCanvas *canvas, const SkImage *image, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint)

        func drawImageRect_3(image: SkImage, dst: SkRect, sampling: SkSamplingOptions, paint: SkPaint) {
            SkCanvas_drawImageRect_3(self.pointer, image.pointer, dst.pointer, sampling.pointer, paint.pointer)
        }
        // void SkCanvas_drawImageRect_4(void *canvas, const void *image, const void *src, const void *dst, const void *sampling, const void *paint, int constraint); // (SkCanvas *canvas, const SkImage *image, const SkRect *src, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint)

        func drawImageRect_4(image: SkImage, src: SkRect, dst: SkRect, sampling: SkSamplingOptions, paint: SkPaint, constraint: SkCanvasSrcRectConstraint) {
            SkCanvas_drawImageRect_4(self.pointer, image.pointer, src.pointer, dst.pointer, sampling.pointer, paint.pointer, Int32(constraint.rawValue))
        }
        // void SkCanvas_drawIRect(void *canvas, const void *rect, const void *paint); // (SkCanvas *canvas, const SkIRect *rect, const SkPaint *paint)

        func drawIRect(rect: SkIRect, paint: SkPaint) {
            SkCanvas_drawIRect(self.pointer, rect.pointer, paint.pointer)
        }
        // void SkCanvas_drawLine(void *canvas, int p0, int p1, const void *paint); // (SkCanvas *canvas, sk_point_t p0, sk_point_t p1, const SkPaint *paint)

        func drawLine(p0: SkPoint, p1: SkPoint, paint: SkPaint) {
            SkCanvas_drawLine(self.pointer, Int32(p0.handle), Int32(p1.handle), paint.pointer)
        }
        // void SkCanvas_drawLine_2(void *canvas, float x0, float y0, float x1, float y1, const void *paint); // (SkCanvas *canvas, SkScalar x0, SkScalar y0, SkScalar x1, SkScalar y1, const SkPaint *paint)

        func drawLine(x0: Float, y0: Float, x1: Float, y1: Float, paint: SkPaint) {
            SkCanvas_drawLine_2(self.pointer, x0, y0, x1, y1, paint.pointer)
        }
        // void SkCanvas_drawMesh(void *canvas, const void *mesh, int blender, const void *paint); // (SkCanvas *canvas, const SkMesh *mesh, sk_blender_t blender, const SkPaint *paint)

        func drawMesh(mesh: SkMesh, blender: SkBlender, paint: SkPaint) {
            SkCanvas_drawMesh(self.pointer, mesh.pointer, blender.handle, paint.pointer)
        }
        // void SkCanvas_drawOval(void *canvas, const void *oval, const void *paint); // (SkCanvas *canvas, const SkRect *oval, const SkPaint *paint)
        
        func drawOval(oval: SkRect, paint: SkPaint) {
            SkCanvas_drawOval(self.pointer, oval.pointer, paint.pointer)
        }
        // void SkCanvas_drawPaint(void *canvas, const void *paint); // (SkCanvas *canvas, const SkPaint *paint)

        func drawPaint(paint: SkPaint) {
            SkCanvas_drawPaint(self.pointer, paint.pointer)
        }
        // void SkCanvas_drawPatch(void *canvas, const void * cubics, const unsigned int colors[4], const void * texCoords, int mode, const void *paint); // (SkCanvas *canvas, const SkPoint cubics[12], const SkColor colors[4], const SkPoint texCoords[4], SkBlendMode mode, const SkPaint *paint)

        func drawPatch(cubics: [SkPoint], colors: [SkColor], texCoords: [SkPoint], mode: SkBlendMode, paint: SkPaint) {
            cubics.withUnsafeBufferPointer { cubicsPointer in
                colors.withUnsafeBufferPointer { colorsPointer in
                    texCoords.withUnsafeBufferPointer { texCoordsPointer in
                        SkCanvas_drawPatch(self.pointer, cubicsPointer.baseAddress, colorsPointer.baseAddress, texCoordsPointer.baseAddress, Int32(mode.rawValue), paint.pointer)
                    }
                }
            }
        }
        // void SkCanvas_drawPath(void *canvas, const void *path, const void *paint); // (SkCanvas *canvas, const SkPath *path, const SkPaint *paint)

        func drawPath(path: SkPath, paint: SkPaint) {
            SkCanvas_drawPath(self.pointer, path.pointer, paint.pointer)
        }
        // void SkCanvas_drawPicture(void *canvas, int picture); // (SkCanvas *canvas, sk_picture_t picture)

        func drawPicture(picture: SkPicture) {
            SkCanvas_drawPicture(self.pointer, picture.handle)
        }
        // void SkCanvas_drawPicture_2(void *canvas, int picture, const void *matrix, const void *paint); // (SkCanvas *canvas, sk_picture_t picture, const SkMatrix *matrix, const SkPaint *paint)

        func drawPicture(picture: SkPicture, matrix: SkMatrix, paint: SkPaint) {
            SkCanvas_drawPicture_2(self.pointer, picture.handle, matrix.pointer, paint.pointer)
        }

        // void SkCanvas_drawPicture_3(void *canvas, const void *picture); // (SkCanvas *canvas, const SkPicture *picture)

        func drawPicture_2(picture: SkPicture) {
            SkCanvas_drawPicture_3(self.pointer, picture.pointer)
        }
        // void SkCanvas_drawPicture_4(void *canvas, const void *picture, const void *matrix, const void *paint); // (SkCanvas *canvas, const SkPicture *picture, const SkMatrix *matrix, const SkPaint *paint)

        func drawPicture_2(picture: SkPicture, matrix: SkMatrix, paint: SkPaint) {
            SkCanvas_drawPicture_4(self.pointer, picture.pointer, matrix.pointer, paint.pointer)
        }
        // void SkCanvas_drawPoint(void *canvas, int p, const void *paint); // (SkCanvas *canvas, sk_point_t p, const SkPaint *paint)

        func drawPoint(p: SkPoint, paint: SkPaint) {
            SkCanvas_drawPoint(self.pointer, Int32(p.handle), paint.pointer)
        }
        // void SkCanvas_drawPoint_2(void *canvas, float x, float y, const void *paint); // (SkCanvas *canvas, SkScalar x, SkScalar y, const SkPaint *paint)
        func drawPoint_2(x: Float, y: Float, paint: SkPaint) {
            SkCanvas_drawPoint_2(self.pointer, x, y, paint.pointer)
        }
        // void SkCanvas_drawPoints(void *canvas, int mode, unsigned long count, const void * pts, const void *paint); // (SkCanvas *canvas, SkCanvas::PointMode mode, size_t count, const SkPoint pts[], const SkPaint *paint)
        // void SkCanvas_drawRect(void *canvas, int rect, const void *paint); // (SkCanvas *canvas, sk_rect_t rect, const SkPaint *paint)
        func drawRect(rect: SkRect, paint: SkPaint) {
            SkCanvas_drawRect(self.pointer, Int32(rect.handle), paint.pointer)
        }
        // void SkCanvas_drawRegion(void *canvas, const void *region, const void *paint); // (SkCanvas *canvas, const SkRegion *region, const SkPaint *paint)

        func drawRegion(region: SkRegion, paint: SkPaint) {
            SkCanvas_drawRegion(self.pointer, region.pointer, paint.pointer)
        }
        // void SkCanvas_drawRoundRect(void *canvas, const void *rect, float rx, float ry, const void *paint); // (SkCanvas *canvas, const SkRect *rect, SkScalar rx, SkScalar ry, const SkPaint *paint)

        func drawRoundRect(rect: SkRect, rx: Float, ry: Float, paint: SkPaint) {
            SkCanvas_drawRoundRect(self.pointer, rect.pointer, rx, ry, paint.pointer)
        }
        // void SkCanvas_drawRRect(void *canvas, const void *rrect, const void *paint); // (SkCanvas *canvas, const SkRRect *rrect, const SkPaint *paint)

        func drawRRect(rrect: SkRRect, paint: SkPaint) {
            SkCanvas_drawRRect(self.pointer, rrect.pointer, paint.pointer)
        }
        // void SkCanvas_drawSimpleText(void *canvas, const void *text, unsigned long byteLength, int encoding, float x, float y, const void *font, const void *paint); // (SkCanvas *canvas, const void *text, size_t byteLength, SkTextEncoding encoding, SkScalar x, SkScalar y, const SkFont *font, const SkPaint *paint)

        func drawSimpleText(text: UnsafeRawPointer, byteLength: UInt, encoding: SkTextEncoding, x: Float, y: Float, font: SkFont, paint: SkPaint) {
            SkCanvas_drawSimpleText(self.pointer, text, byteLength, Int32(encoding.rawValue), x, y, font.pointer, paint.pointer)
        }
        // void SkCanvas_drawString(void *canvas, const char * str, float x, float y, const void *font, const void *paint); // (SkCanvas *canvas, const char str[], SkScalar x, SkScalar y, const SkFont *font, const SkPaint *paint)

        func drawString(str: String, x: Float, y: Float, font: SkFont, paint: SkPaint) {
            SkCanvas_drawString(self.pointer, str, x, y, font.pointer, paint.pointer)
        }

        // void SkCanvas_drawString_2(void *canvas, const void *str, float x, float y, const void *font, const void *paint); // (SkCanvas *canvas, const SkString *str, SkScalar x, SkScalar y, const SkFont *font, const SkPaint *paint)

        func drawString(str: SkString, x: Float, y: Float, font: SkFont, paint: SkPaint) {
            SkCanvas_drawString_2(self.pointer, str.pointer, x, y, font.pointer, paint.pointer)
        }

        // void SkCanvas_drawTextBlob(void *canvas, int text_blob, float x, float y, const void *paint); // (SkCanvas *canvas, sk_text_blob_t text_blob, SkScalar x, SkScalar y, const SkPaint *paint)

        func drawTextBlob(textBlob: SkTextBlob, x: Float, y: Float, paint: SkPaint) {
            SkCanvas_drawTextBlob(self.pointer, textBlob.handle, x, y, paint.pointer)
        }

        // void SkCanvas_drawTextBlob_2(void *canvas, const void *blob, float x, float y, const void *paint); // (SkCanvas *canvas, const SkTextBlob *blob, SkScalar x, SkScalar y, const SkPaint *paint)

        func drawTextBlob(blob: SkTextBlob, x: Float, y: Float, paint: SkPaint) {
            SkCanvas_drawTextBlob_2(self.pointer, blob.pointer, x, y, paint.pointer)
        }

        // void SkCanvas_drawVertices(void *canvas, int vertices, int mode, const void *paint); // (SkCanvas *canvas, sk_vertices_t vertices, SkBlendMode mode, const SkPaint *paint)
        // void SkCanvas_drawVertices_2(void *canvas, const void *vertices, int mode, const void *paint); // (SkCanvas *canvas, const SkVertices *vertices, SkBlendMode mode, const SkPaint *paint)
        // void SkCanvas_experimental_DrawEdgeAAImageSet(void *canvas, const void * imageSet, int cnt, const void * dstClips, const void * preViewMatrices, const void *sampling, const void *paint, int constraint); // (SkCanvas *canvas, const SkCanvas::ImageSetEntry imageSet[], int cnt, const SkPoint dstClips[], const SkMatrix preViewMatrices[], const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint)
        // void SkCanvas_experimental_DrawEdgeAAQuad(void *canvas, const void *rect, const void * clip, int aaFlags, const void * color, int mode); // (SkCanvas *canvas, const SkRect *rect, const SkPoint clip[4], SkCanvas::QuadAAFlags aaFlags, const SkColor4f *color, SkBlendMode mode)
        // void SkCanvas_experimental_DrawEdgeAAQuad_2(void *canvas, const void *rect, const void * clip, int aaFlags, unsigned int color, int mode); // (SkCanvas *canvas, const SkRect *rect, const SkPoint clip[4], SkCanvas::QuadAAFlags aaFlags, SkColor color, SkBlendMode mode)
        // int SkCanvas_getBaseLayerSize(void *canvas); // (SkCanvas *canvas) -> sk_i_size_t

        func getBaseLayerSize() -> SkISize {
            let handle = SkCanvas_getBaseLayerSize(self.pointer)
            let pointer = static_sk_i_size_get_ptr(handle)
            return SkISize(pointer: pointer, handle: handle)
        }
        // int SkCanvas_getBaseProps(void *canvas); // (SkCanvas *canvas) -> sk_surface_props_t

        func getBaseProps() -> SkSurfaceProps {
            let handle = SkCanvas_getBaseProps(self.pointer)
            let pointer = static_sk_surface_props_get_ptr(handle)
            return SkSurfaceProps(pointer: pointer, handle: handle)
        }
        // int SkCanvas_getDeviceClipBounds(void *canvas); // (SkCanvas *canvas) -> sk_i_rect_t

        func getDeviceClipBounds() -> SkIRect {
            let handle = SkCanvas_getDeviceClipBounds(self.pointer)
            let pointer = static_sk_i_rect_get_ptr(handle)
            return SkIRect(pointer: pointer, handle: handle)
        }

        // bool SkCanvas_getDeviceClipBounds_2(void *canvas, void *bounds); // (SkCanvas *canvas, SkIRect *bounds) -> bool

        func getDeviceClipBounds(bounds: SkIRect) -> Bool {
            return SkCanvas_getDeviceClipBounds_2(self.pointer, bounds.pointer)
        }
        // int SkCanvas_getLocalClipBounds(void *canvas); // (SkCanvas *canvas) -> sk_rect_t

        func getLocalClipBounds() -> SkRect {
            let handle = SkCanvas_getLocalClipBounds(self.pointer)
            let pointer = static_sk_rect_get_ptr(handle)
            return SkRect(pointer: pointer, handle: handle)
        }
        // bool SkCanvas_getLocalClipBounds_2(void *canvas, void *bounds); // (SkCanvas *canvas, SkRect *bounds) -> bool

        func getLocalClipBounds(bounds: SkRect) -> Bool {
            return SkCanvas_getLocalClipBounds_2(self.pointer, bounds.pointer)
        }
        // int SkCanvas_getLocalToDevice(void *canvas); // (SkCanvas *canvas) -> sk_m_44_t

        func getLocalToDevice() -> SkM44 {
            let handle = SkCanvas_getLocalToDevice(self.pointer)
            let pointer = static_sk_m_44_get_ptr(handle)
            return SkM44(pointer: pointer, handle: handle)
        }
        // int SkCanvas_getLocalToDeviceAs3x3(void *canvas); // (SkCanvas *canvas) -> sk_matrix_t

        func getLocalToDeviceAs3x3() -> SkMatrix {
            let handle = SkCanvas_getLocalToDeviceAs3x3(self.pointer)
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }
        // bool SkCanvas_getProps(void *canvas, void *props); // (SkCanvas *canvas, SkSurfaceProps *props) -> bool

        func getProps(props: SkSurfaceProps) -> Bool {
            return SkCanvas_getProps(self.pointer, props.pointer)
        }
        // int SkCanvas_getSaveCount(void *canvas); // (SkCanvas *canvas) -> int

        func getSaveCount() -> Int {
            return Int(SkCanvas_getSaveCount(self.pointer))
        }
        // void * SkCanvas_getSurface(void *canvas); // (SkCanvas *canvas) -> SkSurface *

        func getSurface() -> SkSurface {
            let pointer = SkCanvas_getSurface(self.pointer)
            return SkSurface(pointer: pointer, handle: -1)
        }
        // int SkCanvas_getTopProps(void *canvas); // (SkCanvas *canvas) -> sk_surface_props_t

        func getTopProps() -> SkSurfaceProps {
            let handle = SkCanvas_getTopProps(self.pointer)
            let pointer = static_sk_surface_props_get_ptr(handle)
            return SkSurfaceProps(pointer: pointer, handle: handle)
        }
        // int SkCanvas_getTotalMatrix(void *canvas); // (SkCanvas *canvas) -> sk_matrix_t

        func getTotalMatrix() -> SkMatrix {
            let handle = SkCanvas_getTotalMatrix(self.pointer)
            let pointer = static_sk_matrix_get_ptr(handle)
            return SkMatrix(pointer: pointer, handle: handle)
        }
        // int SkCanvas_imageInfo(void *canvas); // (SkCanvas *canvas) -> sk_image_info_t

        func imageInfo() -> SkImageInfo {
            let handle = SkCanvas_imageInfo(self.pointer)
            let pointer = static_sk_image_info_get_ptr(handle)
            return SkImageInfo(pointer: pointer, handle: handle)
        }
        // bool SkCanvas_isClipEmpty(void *canvas); // (SkCanvas *canvas) -> bool

        func isClipEmpty() -> Bool {
            return SkCanvas_isClipEmpty(self.pointer)
        }
        // bool SkCanvas_isClipRect(void *canvas); // (SkCanvas *canvas) -> bool

        func isClipRect() -> Bool {
            return SkCanvas_isClipRect(self.pointer)
        }
        // int SkCanvas_makeSurface(void *canvas, const void *info, const void *props); // (SkCanvas *canvas, const SkImageInfo *info, const SkSurfaceProps *props) -> sk_surface_t

        func makeSurface(info: SkImageInfo, props: SkSurfaceProps) -> SkSurface {
            let handle = SkCanvas_makeSurface(self.pointer, info.pointer, props.pointer)
            let pointer = static_sk_surface_get(handle)
            return SkSurface(pointer: pointer, handle: handle)
        }
        // bool SkCanvas_peekPixels(void *canvas, void *pixmap); // (SkCanvas *canvas, SkPixmap *pixmap) -> bool

        func peekPixels(pixmap: SkPixmap) -> Bool {
            return SkCanvas_peekPixels(self.pointer, pixmap.pointer)
        }
        // void SkCanvas_private_draw_shadow_rec(void *canvas, const void *path, const void *rec); // (SkCanvas *canvas, const SkPath *path, const SkDrawShadowRec *rec)
        // bool SkCanvas_quickReject(void *canvas, const void *path); // (SkCanvas *canvas, const SkPath *path) -> bool

        func quickReject(path: SkPath) -> Bool {
            return SkCanvas_quickReject(self.pointer, path.pointer)
        }
        // bool SkCanvas_quickReject_2(void *canvas, const void *rect); // (SkCanvas *canvas, const SkRect *rect) -> bool

        func quickReject(rect: SkRect) -> Bool {
            return SkCanvas_quickReject_2(self.pointer, rect.pointer)
        }
        // bool SkCanvas_readPixels(void *canvas, const void *bitmap, int srcX, int srcY); // (SkCanvas *canvas, const SkBitmap *bitmap, int srcX, int srcY) -> bool
        
        func readPixels(bitmap: SkBitmap, srcX: Int, srcY: Int) -> Bool {
            return SkCanvas_readPixels(self.pointer, bitmap.pointer, Int32(srcX), Int32(srcY))
        }
        
        // bool SkCanvas_readPixels_2(void *canvas, const void *dstInfo, void *dstPixels, unsigned long dstRowBytes, int srcX, int srcY); // (SkCanvas *canvas, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY) -> bool

        func readPixels(dstInfo: SkImageInfo, dstPixels: UnsafeMutableRawPointer, dstRowBytes: UInt, srcX: Int, srcY: Int) -> Bool {
            return SkCanvas_readPixels_2(self.pointer, dstInfo.pointer, dstPixels, dstRowBytes, Int32(srcX), Int32(srcY))
        }
        // bool SkCanvas_readPixels_3(void *canvas, const void *pixmap, int srcX, int srcY); // (SkCanvas *canvas, const SkPixmap *pixmap, int srcX, int srcY) -> bool

        func readPixels(pixmap: SkPixmap, srcX: Int, srcY: Int) -> Bool {
            return SkCanvas_readPixels_3(self.pointer, pixmap.pointer, Int32(srcX), Int32(srcY))
        }
        // void * SkCanvas_recorder(void *canvas); // (SkCanvas *canvas) -> skgpu::graphite::Recorder *
        // void * SkCanvas_recordingContext(void *canvas); // (SkCanvas *canvas) -> GrRecordingContext *
        // void SkCanvas_resetMatrix(void *canvas); // (SkCanvas *canvas)

        func resetMatrix() {
            SkCanvas_resetMatrix(self.pointer)
        }
        // void SkCanvas_restore(void *canvas); // (SkCanvas *canvas)

        func restore() {
            SkCanvas_restore(self.pointer)
        }
        // void SkCanvas_restoreToCount(void *canvas, int saveCount); // (SkCanvas *canvas, int saveCount)
        
        func restoreToCount(saveCount: Int) {
            SkCanvas_restoreToCount(self.pointer, Int32(saveCount))
        }
        // void SkCanvas_rotate(void *canvas, float degrees); // (SkCanvas *canvas, SkScalar degrees)

        func rotate(degrees: Float) {
            SkCanvas_rotate(self.pointer, degrees)
        }
        // void SkCanvas_rotate_2(void *canvas, float degrees, float px, float py); // (SkCanvas *canvas, SkScalar degrees, SkScalar px, SkScalar py)

        func rotate(degrees: Float, px: Float, py: Float) {
            SkCanvas_rotate_2(self.pointer, degrees, px, py)
        }
        // int SkCanvas_save(void *canvas); // (SkCanvas *canvas) -> int

        func save() -> Int {
            return Int(SkCanvas_save(self.pointer))
        }
        // int SkCanvas_saveLayer(void *canvas, const void *layerRec); // (SkCanvas *canvas, const SkCanvas::SaveLayerRec *layerRec) -> int
        // int SkCanvas_saveLayer_2(void *canvas, const void *bounds, const void *paint); // (SkCanvas *canvas, const SkRect *bounds, const SkPaint *paint) -> int

        func saveLayer(bounds: SkRect, paint: SkPaint) -> Int {
            return Int(SkCanvas_saveLayer_2(self.pointer, bounds.pointer, paint.pointer))
        }
        // int SkCanvas_saveLayer_3(void *canvas, const void *bounds, const void *paint); // (SkCanvas *canvas, const SkRect *bounds, const SkPaint *paint) -> int

        func saveLayer_2(bounds: SkRect, paint: SkPaint) -> Int {
            return Int(SkCanvas_saveLayer_3(self.pointer, bounds.pointer, paint.pointer))
        }
        // int SkCanvas_saveLayerAlpha(void *canvas, const void *bounds, unsigned int alpha); // (SkCanvas *canvas, const SkRect *bounds, U8CPU alpha) -> int

        func saveLayerAlpha(bounds: SkRect, alpha: UInt8) -> Int {
            return Int(SkCanvas_saveLayerAlpha(self.pointer, bounds.pointer, UInt32(alpha)))
        }
        // int SkCanvas_saveLayerAlphaf(void *canvas, const void *bounds, float alpha); // (SkCanvas *canvas, const SkRect *bounds, float alpha) -> int

        func saveLayerAlphaf(bounds: SkRect, alpha: Float) -> Int {
            return Int(SkCanvas_saveLayerAlphaf(self.pointer, bounds.pointer, alpha))
        }
        // void SkCanvas_scale(void *canvas, float sx, float sy); // (SkCanvas *canvas, SkScalar sx, SkScalar sy)

        func scale(sx: Float, sy: Float) {
            SkCanvas_scale(self.pointer, sx, sy)
        }

        // void SkCanvas_setMatrix(void *canvas, const void *matrix); // (SkCanvas *canvas, const SkM44 *matrix)

        func setMatrix(matrix: SkM44) {
            SkCanvas_setMatrix(self.pointer, matrix.pointer)
        }
        // void SkCanvas_setMatrix_2(void *canvas, const void *matrix); // (SkCanvas *canvas, const SkMatrix *matrix)

        func setMatrix(matrix: SkMatrix) {
            SkCanvas_setMatrix_2(self.pointer, matrix.pointer)
        }
        // void SkCanvas_skew(void *canvas, float sx, float sy); // (SkCanvas *canvas, SkScalar sx, SkScalar sy)

        func skew(sx: Float, sy: Float) {
            SkCanvas_skew(self.pointer, sx, sy)
        }
        // void SkCanvas_temporary_internal_getRgnClip(void *canvas, void *region); // (SkCanvas *canvas, SkRegion *region)

        func temporary_internal_getRgnClip(region: SkRegion) {
            SkCanvas_temporary_internal_getRgnClip(self.pointer, region.pointer)
        }
        // void SkCanvas_translate(void *canvas, float dx, float dy); // (SkCanvas *canvas, SkScalar dx, SkScalar dy)

        func translate(dx: Float, dy: Float) {
            SkCanvas_translate(self.pointer, dx, dy)
        }
        // bool SkCanvas_writePixels(void *canvas, const void *bitmap, int x, int y); // (SkCanvas *canvas, const SkBitmap *bitmap, int x, int y) -> bool

        func writePixels(bitmap: SkBitmap, x: Int, y: Int) -> Bool {
            return SkCanvas_writePixels(self.pointer, bitmap.pointer, Int32(x), Int32(y))
        }
        // bool SkCanvas_writePixels_2(void *canvas, const void *info, const void *pixels, unsigned long rowBytes, int x, int y); // (SkCanvas *canvas, const SkImageInfo *info, const void *pixels, size_t rowBytes, int x, int y) -> bool

        func writePixels(info: SkImageInfo, pixels: UnsafeRawPointer, rowBytes: UInt, x: Int, y: Int) -> Bool {
            return SkCanvas_writePixels_2(self.pointer, info.pointer, pixels, rowBytes, Int32(x), Int32(y))
        }
        // // static

        init(pointer: SkCanvasMutablePointer?, handle: sk_canvas_t) {
            self.pointer = pointer
            self.handle = handle
        }
        // int SkCanvas_MakeRasterDirect(const void *info, void *pixels, unsigned long rowBytes, const void *props); // (const SkImageInfo *info, void *pixels, size_t rowBytes, const SkSurfaceProps *props) -> sk_canvas_t

        static func MakeRasterDirect(info: SkImageInfo, pixels: UnsafeMutableRawPointer, rowBytes: UInt, props: SkSurfaceProps) -> SkCanvas {
            let handle = SkCanvas_MakeRasterDirect(info.pointer, pixels, rowBytes, props.pointer)
            let pointer = static_sk_canvas_get(handle)
            return SkCanvas(pointer: pointer, handle: handle)
        }
        // int SkCanvas_MakeRasterDirectN32(int width, int height, void *pixels, unsigned long rowBytes); // (int width, int height, SkPMColor *pixels, size_t rowBytes) -> sk_canvas_t}

        static func MakeRasterDirectN32(width: Int, height: Int, pixels: UnsafeMutableRawPointer, rowBytes: UInt) -> SkCanvas {
            let handle = SkCanvas_MakeRasterDirectN32(Int32(width), Int32(height), pixels, rowBytes)
            let pointer = static_sk_canvas_get(handle)
            return SkCanvas(pointer: pointer, handle: handle)
        }

    }
}