//
// Created by dolphilia on 2024/01/06.
//

#ifndef RAIA_SKIA_SK_CANVAS_H
#define RAIA_SKIA_SK_CANVAS_H

#ifdef __cplusplus
extern "C" {
#endif

void * SkCanvas_new(); // () -> SkCanvas *
void * SkCanvas_new_2(int width, int height, const void *props); // (int width, int height, const SkSurfaceProps *props) -> SkCanvas *
void * SkCanvas_new_3(void *bitmap); // (SkBitmap *bitmap) -> SkCanvas *
void * SkCanvas_new_4(const void *bitmap, const void *props); // (const SkBitmap *bitmap, const SkSurfaceProps *props) -> SkCanvas *
void SkCanvas_delete(void *canvas); // (SkCanvas *canvas)
void * SkCanvas_accessTopLayerPixels(void *canvas, void *info, void *rowBytes, void *origin); // (SkCanvas *canvas, SkImageInfo *info, size_t *rowBytes, SkIPoint *origin) -> void *
void * SkCanvas_accessTopRasterHandle(void *canvas); // (SkCanvas *canvas) -> SkRasterHandleAllocator::Handle
void SkCanvas_androidFramework_setDeviceClipRestriction(void *canvas, const void *rect); // (SkCanvas *canvas, const SkIRect *rect)
void SkCanvas_clear(void *canvas, const void *color); // (SkCanvas *canvas, const SkColor4f *color)
void SkCanvas_clear_2(void *canvas, unsigned int color); // (SkCanvas *canvas, SkColor color)
void SkCanvas_clipIRect(void *canvas, const void *irect, int op); // (SkCanvas *canvas, const SkIRect *irect, SkClipOp op)
void SkCanvas_clipPath(void *canvas, const void *path, bool doAntiAlias); // (SkCanvas *canvas, const SkPath *path, bool doAntiAlias)
void SkCanvas_clipPath_2(void *canvas, const void *path, int op); // (SkCanvas *canvas, const SkPath *path, SkClipOp op)
void SkCanvas_clipPath_3(void *canvas, const void *path, int op, bool doAntiAlias); // (SkCanvas *canvas, const SkPath *path, SkClipOp op, bool doAntiAlias)
void SkCanvas_clipRect(void *canvas, const void *rect, bool doAntiAlias); // (SkCanvas *canvas, const SkRect *rect, bool doAntiAlias)
void SkCanvas_clipRect_2(void *canvas, const void *rect, int op); // (SkCanvas *canvas, const SkRect *rect, SkClipOp op)
void SkCanvas_clipRect_3(void *canvas, const void *rect, int op, bool doAntiAlias); // (SkCanvas *canvas, const SkRect *rect, SkClipOp op, bool doAntiAlias)
void SkCanvas_clipRegion(void *canvas, const void *deviceRgn, int op); // (SkCanvas *canvas, const SkRegion *deviceRgn, SkClipOp op)
void SkCanvas_clipRRect(void *canvas, const void *rrect, bool doAntiAlias); // (SkCanvas *canvas, const SkRRect *rrect, bool doAntiAlias)
void SkCanvas_clipRRect_2(void *canvas, const void *rrect, int op); // (SkCanvas *canvas, const SkRRect *rrect, SkClipOp op)
void SkCanvas_clipRRect_3(void *canvas, const void *rrect, int op, bool doAntiAlias); // (SkCanvas *canvas, const SkRRect *rrect, SkClipOp op, bool doAntiAlias)
void SkCanvas_clipShader(void *canvas, int shader, int op); // (SkCanvas *canvas, sk_shader_t shader, SkClipOp op)
void SkCanvas_concat(void *canvas, const void * m44); // (SkCanvas *canvas, const SkM44 *m44)
void SkCanvas_concat_2(void *canvas, const void * matrix); // (SkCanvas *canvas, const SkMatrix *matrix)
void SkCanvas_discard(void *canvas); // (SkCanvas *canvas)
void SkCanvas_drawAnnotation(void *canvas, const void *rect, const char * key, int data); // (SkCanvas *canvas, const SkRect *rect, const char key[], sk_data_t data)
void SkCanvas_drawAnnotation_2(void *canvas, const void *rect, const char * key, void *value); // (SkCanvas *canvas, const SkRect *rect, const char key[], SkData *value)
void SkCanvas_drawArc(void *canvas, const void *oval, float startAngle, float sweepAngle, bool useCenter, const void *paint); // (SkCanvas *canvas, const SkRect *oval, SkScalar startAngle, SkScalar sweepAngle, bool useCenter, const SkPaint *paint)
void SkCanvas_drawAtlas(void *canvas, const void *atlas, const void * xform, const void * tex, const void * colors, int count, int mode, const void *sampling, const void *cullRect, const void *paint); // (SkCanvas *canvas, const SkImage *atlas, const SkRSXform xform[], const SkRect tex[], const SkColor colors[], int count, SkBlendMode mode, const SkSamplingOptions *sampling, const SkRect *cullRect, const SkPaint *paint)
void SkCanvas_drawCircle(void *canvas, int center, float radius, const void *paint); // (SkCanvas *canvas, sk_point_t center, SkScalar radius, const SkPaint *paint)
void SkCanvas_drawCircle_2(void *canvas, float cx, float cy, float radius, const void *paint); // (SkCanvas *canvas, SkScalar cx, SkScalar cy, SkScalar radius, const SkPaint *paint)
void SkCanvas_drawColor(void *canvas, const void * color, int mode); // (SkCanvas *canvas, const SkColor4f *color, SkBlendMode mode)
void SkCanvas_drawColor_2(void *canvas, unsigned int color, int mode); // (SkCanvas *canvas, SkColor color, SkBlendMode mode)
void SkCanvas_drawDrawable(void *canvas, void *drawable, const void *matrix); // (SkCanvas *canvas, SkDrawable *drawable, const SkMatrix *matrix)
void SkCanvas_drawDrawable_2(void *canvas, void *drawable, float x, float y); // (SkCanvas *canvas, SkDrawable *drawable, SkScalar x, SkScalar y)
void SkCanvas_drawDRRect(void *canvas, const void *outer, const void *inner, const void *paint); // (SkCanvas *canvas, const SkRRect *outer, const SkRRect *inner, const SkPaint *paint)
void SkCanvas_drawGlyphs(void *canvas, int count, const void * glyphs, const void * positions, const void * clusters, int textByteCount, const char * utf8text, int origin, const void *font, const void *paint); // (SkCanvas *canvas, int count, const SkGlyphID glyphs[], const SkPoint positions[], const uint32_t clusters[], int textByteCount, const char utf8text[], sk_point_t origin, const SkFont *font, const SkPaint *paint)
void SkCanvas_drawGlyphs_2(void *canvas, int count, const void * glyphs, const void * positions, int origin, const void *font, const void *paint); // (SkCanvas *canvas, int count, const SkGlyphID glyphs[], const SkPoint positions[], sk_point_t origin, const SkFont *font, const SkPaint *paint)
void SkCanvas_drawGlyphs_3(void *canvas, int count, const void * glyphs, const void * xforms, int origin, const void *font, const void *paint); // (SkCanvas *canvas, int count, const SkGlyphID glyphs[], const SkRSXform xforms[], sk_point_t origin, const SkFont *font, const SkPaint *paint)
void SkCanvas_drawImage(void *canvas, int image, float left, float top); // (SkCanvas *canvas, sk_image_t image, SkScalar left, SkScalar top)
void SkCanvas_drawImage_2(void *canvas, int image, float x, float y, const void *sampling, const void *paint); // (SkCanvas *canvas, sk_image_t image, SkScalar x, SkScalar y, const SkSamplingOptions *sampling, const SkPaint *paint)
void SkCanvas_drawImage_3(void *canvas, const void *image, float x, float y, const void *sampling, const void *paint); // (SkCanvas *canvas, const SkImage *image, SkScalar x, SkScalar y, const SkSamplingOptions *sampling, const SkPaint *paint)
void SkCanvas_drawImage_4(void *canvas, const void *image, float left, float top); // (SkCanvas *canvas, const SkImage *image, SkScalar left, SkScalar top)
void SkCanvas_drawImageLattice(void *canvas, const void *image, const void *lattice, const void *dst); // (SkCanvas *canvas, const SkImage *image, const SkCanvas::Lattice *lattice, const SkRect *dst)
void SkCanvas_drawImageLattice_2(void *canvas, const void *image, const void *lattice, const void *dst, int filter, const void *paint); // (SkCanvas *canvas, const SkImage *image, const SkCanvas::Lattice *lattice, const SkRect *dst, SkFilterMode filter, const SkPaint *paint)
void SkCanvas_drawImageNine(void *canvas, const void *image, const void *center, const void *dst, int filter, const void *paint); // (SkCanvas *canvas, const SkImage *image, const SkIRect *center, const SkRect *dst, SkFilterMode filter, const SkPaint *paint)
void SkCanvas_drawImageRect(void *canvas, int image, const void *dst, const void *sampling, const void *paint); // (SkCanvas *canvas, sk_image_t image, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint)
void SkCanvas_drawImageRect_2(void *canvas, int image, const void *src, const void *dst, const void *sampling, const void *paint, int constraint); // (SkCanvas *canvas, sk_image_t image, const SkRect *src, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint)
void SkCanvas_drawImageRect_3(void *canvas, const void *image, const void *dst, const void *sampling, const void *paint); // (SkCanvas *canvas, const SkImage *image, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint)
void SkCanvas_drawImageRect_4(void *canvas, const void *image, const void *src, const void *dst, const void *sampling, const void *paint, int constraint); // (SkCanvas *canvas, const SkImage *image, const SkRect *src, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint)
void SkCanvas_drawIRect(void *canvas, const void *rect, const void *paint); // (SkCanvas *canvas, const SkIRect *rect, const SkPaint *paint)
void SkCanvas_drawLine(void *canvas, int p0, int p1, const void *paint); // (SkCanvas *canvas, sk_point_t p0, sk_point_t p1, const SkPaint *paint)
void SkCanvas_drawLine_2(void *canvas, float x0, float y0, float x1, float y1, const void *paint); // (SkCanvas *canvas, SkScalar x0, SkScalar y0, SkScalar x1, SkScalar y1, const SkPaint *paint)
void SkCanvas_drawMesh(void *canvas, const void *mesh, int blender, const void *paint); // (SkCanvas *canvas, const SkMesh *mesh, sk_blender_t blender, const SkPaint *paint)
void SkCanvas_drawOval(void *canvas, const void *oval, const void *paint); // (SkCanvas *canvas, const SkRect *oval, const SkPaint *paint)
void SkCanvas_drawPaint(void *canvas, const void *paint); // (SkCanvas *canvas, const SkPaint *paint)
void SkCanvas_drawPatch(void *canvas, const void * cubics, const unsigned int colors[4], const void * texCoords, int mode, const void *paint); // (SkCanvas *canvas, const SkPoint cubics[12], const SkColor colors[4], const SkPoint texCoords[4], SkBlendMode mode, const SkPaint *paint)
void SkCanvas_drawPath(void *canvas, const void *path, const void *paint); // (SkCanvas *canvas, const SkPath *path, const SkPaint *paint)
void SkCanvas_drawPicture(void *canvas, int picture); // (SkCanvas *canvas, sk_picture_t picture)
void SkCanvas_drawPicture_2(void *canvas, int picture, const void *matrix, const void *paint); // (SkCanvas *canvas, sk_picture_t picture, const SkMatrix *matrix, const SkPaint *paint)
void SkCanvas_drawPicture_3(void *canvas, const void *picture); // (SkCanvas *canvas, const SkPicture *picture)
void SkCanvas_drawPicture_4(void *canvas, const void *picture, const void *matrix, const void *paint); // (SkCanvas *canvas, const SkPicture *picture, const SkMatrix *matrix, const SkPaint *paint)
void SkCanvas_drawPoint(void *canvas, int p, const void *paint); // (SkCanvas *canvas, sk_point_t p, const SkPaint *paint)
void SkCanvas_drawPoint_2(void *canvas, float x, float y, const void *paint); // (SkCanvas *canvas, SkScalar x, SkScalar y, const SkPaint *paint)
void SkCanvas_drawPoints(void *canvas, int mode, unsigned long count, const void * pts, const void *paint); // (SkCanvas *canvas, SkCanvas::PointMode mode, size_t count, const SkPoint pts[], const SkPaint *paint)
void SkCanvas_drawRect(void *canvas, int rect, const void *paint); // (SkCanvas *canvas, sk_rect_t rect, const SkPaint *paint)
void SkCanvas_drawRegion(void *canvas, const void *region, const void *paint); // (SkCanvas *canvas, const SkRegion *region, const SkPaint *paint)
void SkCanvas_drawRoundRect(void *canvas, const void *rect, float rx, float ry, const void *paint); // (SkCanvas *canvas, const SkRect *rect, SkScalar rx, SkScalar ry, const SkPaint *paint)
void SkCanvas_drawRRect(void *canvas, const void *rrect, const void *paint); // (SkCanvas *canvas, const SkRRect *rrect, const SkPaint *paint)
void SkCanvas_drawSimpleText(void *canvas, const void *text, unsigned long byteLength, int encoding, float x, float y, const void *font, const void *paint); // (SkCanvas *canvas, const void *text, size_t byteLength, SkTextEncoding encoding, SkScalar x, SkScalar y, const SkFont *font, const SkPaint *paint)
void SkCanvas_drawString(void *canvas, const char * str, float x, float y, const void *font, const void *paint); // (SkCanvas *canvas, const char str[], SkScalar x, SkScalar y, const SkFont *font, const SkPaint *paint)
void SkCanvas_drawString_2(void *canvas, const void *str, float x, float y, const void *font, const void *paint); // (SkCanvas *canvas, const SkString *str, SkScalar x, SkScalar y, const SkFont *font, const SkPaint *paint)
void SkCanvas_drawTextBlob(void *canvas, int text_blob, float x, float y, const void *paint); // (SkCanvas *canvas, sk_text_blob_t text_blob, SkScalar x, SkScalar y, const SkPaint *paint)
void SkCanvas_drawTextBlob_2(void *canvas, const void *blob, float x, float y, const void *paint); // (SkCanvas *canvas, const SkTextBlob *blob, SkScalar x, SkScalar y, const SkPaint *paint)
void SkCanvas_drawVertices(void *canvas, int vertices, int mode, const void *paint); // (SkCanvas *canvas, sk_vertices_t vertices, SkBlendMode mode, const SkPaint *paint)
void SkCanvas_drawVertices_2(void *canvas, const void *vertices, int mode, const void *paint); // (SkCanvas *canvas, const SkVertices *vertices, SkBlendMode mode, const SkPaint *paint)
void SkCanvas_experimental_DrawEdgeAAImageSet(void *canvas, const void * imageSet, int cnt, const void * dstClips, const void * preViewMatrices, const void *sampling, const void *paint, int constraint); // (SkCanvas *canvas, const SkCanvas::ImageSetEntry imageSet[], int cnt, const SkPoint dstClips[], const SkMatrix preViewMatrices[], const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint)
void SkCanvas_experimental_DrawEdgeAAQuad(void *canvas, const void *rect, const void * clip, int aaFlags, const void * color, int mode); // (SkCanvas *canvas, const SkRect *rect, const SkPoint clip[4], SkCanvas::QuadAAFlags aaFlags, const SkColor4f *color, SkBlendMode mode)
void SkCanvas_experimental_DrawEdgeAAQuad_2(void *canvas, const void *rect, const void * clip, int aaFlags, unsigned int color, int mode); // (SkCanvas *canvas, const SkRect *rect, const SkPoint clip[4], SkCanvas::QuadAAFlags aaFlags, SkColor color, SkBlendMode mode)
int SkCanvas_getBaseLayerSize(void *canvas); // (SkCanvas *canvas) -> sk_i_size_t
int SkCanvas_getBaseProps(void *canvas); // (SkCanvas *canvas) -> sk_surface_props_t
int SkCanvas_getDeviceClipBounds(void *canvas); // (SkCanvas *canvas) -> sk_i_rect_t
bool SkCanvas_getDeviceClipBounds_2(void *canvas, void *bounds); // (SkCanvas *canvas, SkIRect *bounds) -> bool
int SkCanvas_getLocalClipBounds(void *canvas); // (SkCanvas *canvas) -> sk_rect_t
bool SkCanvas_getLocalClipBounds_2(void *canvas, void *bounds); // (SkCanvas *canvas, SkRect *bounds) -> bool
int SkCanvas_getLocalToDevice(void *canvas); // (SkCanvas *canvas) -> sk_m_44_t
int SkCanvas_getLocalToDeviceAs3x3(void *canvas); // (SkCanvas *canvas) -> sk_matrix_t
bool SkCanvas_getProps(void *canvas, void *props); // (SkCanvas *canvas, SkSurfaceProps *props) -> bool
int SkCanvas_getSaveCount(void *canvas); // (SkCanvas *canvas) -> int
void * SkCanvas_getSurface(void *canvas); // (SkCanvas *canvas) -> SkSurface *
int SkCanvas_getTopProps(void *canvas); // (SkCanvas *canvas) -> sk_surface_props_t
int SkCanvas_getTotalMatrix(void *canvas); // (SkCanvas *canvas) -> sk_matrix_t
int SkCanvas_imageInfo(void *canvas); // (SkCanvas *canvas) -> sk_image_info_t
bool SkCanvas_isClipEmpty(void *canvas); // (SkCanvas *canvas) -> bool
bool SkCanvas_isClipRect(void *canvas); // (SkCanvas *canvas) -> bool
int SkCanvas_makeSurface(void *canvas, const void *info, const void *props); // (SkCanvas *canvas, const SkImageInfo *info, const SkSurfaceProps *props) -> sk_surface_t
bool SkCanvas_peekPixels(void *canvas, void *pixmap); // (SkCanvas *canvas, SkPixmap *pixmap) -> bool
void SkCanvas_private_draw_shadow_rec(void *canvas, const void *path, const void *rec); // (SkCanvas *canvas, const SkPath *path, const SkDrawShadowRec *rec)
bool SkCanvas_quickReject(void *canvas, const void *path); // (SkCanvas *canvas, const SkPath *path) -> bool
bool SkCanvas_quickReject_2(void *canvas, const void *rect); // (SkCanvas *canvas, const SkRect *rect) -> bool
bool SkCanvas_readPixels(void *canvas, const void *bitmap, int srcX, int srcY); // (SkCanvas *canvas, const SkBitmap *bitmap, int srcX, int srcY) -> bool
bool SkCanvas_readPixels_2(void *canvas, const void *dstInfo, void *dstPixels, unsigned long dstRowBytes, int srcX, int srcY); // (SkCanvas *canvas, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY) -> bool
bool SkCanvas_readPixels_3(void *canvas, const void *pixmap, int srcX, int srcY); // (SkCanvas *canvas, const SkPixmap *pixmap, int srcX, int srcY) -> bool
void * SkCanvas_recorder(void *canvas); // (SkCanvas *canvas) -> skgpu::graphite::Recorder *
void * SkCanvas_recordingContext(void *canvas); // (SkCanvas *canvas) -> GrRecordingContext *
void SkCanvas_resetMatrix(void *canvas); // (SkCanvas *canvas)
void SkCanvas_restore(void *canvas); // (SkCanvas *canvas)
void SkCanvas_restoreToCount(void *canvas, int saveCount); // (SkCanvas *canvas, int saveCount)
void SkCanvas_rotate(void *canvas, float degrees); // (SkCanvas *canvas, SkScalar degrees)
void SkCanvas_rotate_2(void *canvas, float degrees, float px, float py); // (SkCanvas *canvas, SkScalar degrees, SkScalar px, SkScalar py)
int SkCanvas_save(void *canvas); // (SkCanvas *canvas) -> int
int SkCanvas_saveLayer(void *canvas, const void *layerRec); // (SkCanvas *canvas, const SkCanvas::SaveLayerRec *layerRec) -> int
int SkCanvas_saveLayer_2(void *canvas, const void *bounds, const void *paint); // (SkCanvas *canvas, const SkRect *bounds, const SkPaint *paint) -> int
int SkCanvas_saveLayer_3(void *canvas, const void *bounds, const void *paint); // (SkCanvas *canvas, const SkRect *bounds, const SkPaint *paint) -> int
int SkCanvas_saveLayerAlpha(void *canvas, const void *bounds, unsigned int alpha); // (SkCanvas *canvas, const SkRect *bounds, U8CPU alpha) -> int
int SkCanvas_saveLayerAlphaf(void *canvas, const void *bounds, float alpha); // (SkCanvas *canvas, const SkRect *bounds, float alpha) -> int
void SkCanvas_scale(void *canvas, float sx, float sy); // (SkCanvas *canvas, SkScalar sx, SkScalar sy)
void SkCanvas_setMatrix(void *canvas, const void *matrix); // (SkCanvas *canvas, const SkM44 *matrix)
void SkCanvas_setMatrix_2(void *canvas, const void *matrix); // (SkCanvas *canvas, const SkMatrix *matrix)
void SkCanvas_skew(void *canvas, float sx, float sy); // (SkCanvas *canvas, SkScalar sx, SkScalar sy)
void SkCanvas_temporary_internal_getRgnClip(void *canvas, void *region); // (SkCanvas *canvas, SkRegion *region)
void SkCanvas_translate(void *canvas, float dx, float dy); // (SkCanvas *canvas, SkScalar dx, SkScalar dy)
bool SkCanvas_writePixels(void *canvas, const void *bitmap, int x, int y); // (SkCanvas *canvas, const SkBitmap *bitmap, int x, int y) -> bool
bool SkCanvas_writePixels_2(void *canvas, const void *info, const void *pixels, unsigned long rowBytes, int x, int y); // (SkCanvas *canvas, const SkImageInfo *info, const void *pixels, size_t rowBytes, int x, int y) -> bool
// static
int SkCanvas_MakeRasterDirect(const void *info, void *pixels, unsigned long rowBytes, const void *props); // (const SkImageInfo *info, void *pixels, size_t rowBytes, const SkSurfaceProps *props) -> sk_canvas_t
int SkCanvas_MakeRasterDirectN32(int width, int height, void *pixels, unsigned long rowBytes); // (int width, int height, SkPMColor *pixels, size_t rowBytes) -> sk_canvas_t}

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_CANVAS_H
