//
// Created by dolphilia on 2024/01/06.
//

#include "sk_canvas.h"

extern "C" {

SkCanvas *SkCanvas_new() {
    return new SkCanvas();
}

SkCanvas *SkCanvas_new_2(int width, int height, const SkSurfaceProps *props) {
    return new SkCanvas(width, height, props);
}

SkCanvas *SkCanvas_new_3(SkBitmap *bitmap) {
    return new SkCanvas(*bitmap);
}

SkCanvas *SkCanvas_new_4(const SkBitmap *bitmap, const SkSurfaceProps *props) {
    return new SkCanvas(*bitmap, *props);
}

void SkCanvas_delete(SkCanvas *canvas) {
    delete canvas;
}

void *SkCanvas_accessTopLayerPixels(SkCanvas *canvas, SkImageInfo *info, size_t *rowBytes, SkIPoint *origin) {
    return canvas->accessTopLayerPixels(info, rowBytes, origin);
}

SkRasterHandleAllocator::Handle SkCanvas_accessTopRasterHandle(SkCanvas *canvas) {
    return canvas->accessTopRasterHandle();
}

void SkCanvas_androidFramework_setDeviceClipRestriction(SkCanvas *canvas, const SkIRect *rect) {
    canvas->androidFramework_setDeviceClipRestriction(*rect);
}

void SkCanvas_clear(SkCanvas *canvas, const SkColor4f *color) {
    canvas->clear(*color);
}

void SkCanvas_clear_2(SkCanvas *canvas, SkColor color) {
    canvas->clear(color);
}

void SkCanvas_clipIRect(SkCanvas *canvas, const SkIRect *irect, SkClipOp op) {
    canvas->clipIRect(*irect, op);
}

void SkCanvas_clipPath(SkCanvas *canvas, const SkPath *path, bool doAntiAlias) {
    canvas->clipPath(*path, doAntiAlias);
}

void SkCanvas_clipPath_2(SkCanvas *canvas, const SkPath *path, SkClipOp op) {
    canvas->clipPath(*path, op);
}

void SkCanvas_clipPath_3(SkCanvas *canvas, const SkPath *path, SkClipOp op, bool doAntiAlias) {
    canvas->clipPath(*path, op, doAntiAlias);
}

void SkCanvas_clipRect(SkCanvas *canvas, const SkRect *rect, bool doAntiAlias) {
    canvas->clipRect(*rect, doAntiAlias);
}

void SkCanvas_clipRect_2(SkCanvas *canvas, const SkRect *rect, SkClipOp op) {
    canvas->clipRect(*rect, op);
}

void SkCanvas_clipRect_3(SkCanvas *canvas, const SkRect *rect, SkClipOp op, bool doAntiAlias) {
    canvas->clipRect(*rect, op, doAntiAlias);
}

void SkCanvas_clipRegion(SkCanvas *canvas, const SkRegion *deviceRgn, SkClipOp op) {
    canvas->clipRegion(*deviceRgn, op);
}

void SkCanvas_clipRRect(SkCanvas *canvas, const SkRRect *rrect, bool doAntiAlias) {
    canvas->clipRRect(*rrect, doAntiAlias);
}

void SkCanvas_clipRRect_2(SkCanvas *canvas, const SkRRect *rrect, SkClipOp op) {
    canvas->clipRRect(*rrect, op);
}

void SkCanvas_clipRRect_3(SkCanvas *canvas, const SkRRect *rrect, SkClipOp op, bool doAntiAlias) {
    canvas->clipRRect(*rrect, op, doAntiAlias);
}

void SkCanvas_clipShader(int sk_shader_key_in, SkCanvas *canvas, SkClipOp op) {
    canvas->clipShader(static_sk_shader_move(sk_shader_key_in), op);
}

void SkCanvas_concat(SkCanvas *canvas, const SkM44 *m44) {
    canvas->concat(*m44);
}

void SkCanvas_concat_2(SkCanvas *canvas, const SkMatrix *matrix) {
    canvas->concat(*matrix);
}

// virtual void SkCanvas_didConcat44(SkCanvas *canvas, const SkM44 *) {} // protected
// virtual void SkCanvas_didRestore(SkCanvas *canvas) {} // protected
// virtual void SkCanvas_didScale(SkCanvas *canvas, SkScalar SkScalar) {} // protected
// virtual void SkCanvas_didTranslate(SkCanvas *canvas, SkScalar SkScalar) {} // protected

void SkCanvas_discard(SkCanvas *canvas) {
    canvas->discard();
}

void SkCanvas_drawAnnotation(int sk_data_key_in, SkCanvas *canvas, const SkRect *rect, const char key[]) {
    canvas->drawAnnotation(*rect, key, static_sk_data_move(sk_data_key_in));
}

void SkCanvas_drawAnnotation_2(SkCanvas *canvas, const SkRect *rect, const char key[], SkData *value) {
    canvas->drawAnnotation(*rect, key, value);
}

void SkCanvas_drawArc(SkCanvas *canvas, const SkRect *oval, SkScalar startAngle, SkScalar sweepAngle, bool useCenter,
                      const SkPaint *paint) {
    canvas->drawArc(*oval, startAngle, sweepAngle, useCenter, *paint);
}

void SkCanvas_drawAtlas(SkCanvas *canvas, const SkImage *atlas, const SkRSXform xform[], const SkRect tex[],
                        const SkColor colors[], int count, SkBlendMode mode, const SkSamplingOptions *sampling,
                        const SkRect *cullRect, const SkPaint *paint) {
    canvas->drawAtlas(atlas, xform, tex, colors, count, mode, *sampling, cullRect, paint);
}

void SkCanvas_drawCircle(SkCanvas *canvas, SkPoint center, SkScalar radius, const SkPaint *paint) {
    canvas->drawCircle(center, radius, *paint);
}

void SkCanvas_drawCircle_2(SkCanvas *canvas, SkScalar cx, SkScalar cy, SkScalar radius, const SkPaint *paint) {
    canvas->drawCircle(cx, cy, radius, *paint);
}

void SkCanvas_drawColor(SkCanvas *canvas, const SkColor4f *color, SkBlendMode mode) {
    canvas->drawColor(*color, mode);
}

void SkCanvas_drawColor_2(SkCanvas *canvas, SkColor color, SkBlendMode mode) {
    canvas->drawColor(color, mode);
}

void SkCanvas_drawDrawable(SkCanvas *canvas, SkDrawable *drawable, const SkMatrix *matrix) {
    canvas->drawDrawable(drawable, matrix);
}

void SkCanvas_drawDrawable_2(SkCanvas *canvas, SkDrawable *drawable, SkScalar x, SkScalar y) {
    canvas->drawDrawable(drawable, x, y);
}

void SkCanvas_drawDRRect(SkCanvas *canvas, const SkRRect *outer, const SkRRect *inner, const SkPaint *paint) {
    canvas->drawDRRect(*outer, *inner, *paint);
}

void SkCanvas_drawGlyphs(SkCanvas *canvas, int count, const SkGlyphID glyphs[], const SkPoint positions[],
                         const uint32_t clusters[], int textByteCount, const char utf8text[], SkPoint origin,
                         const SkFont *font, const SkPaint *paint) {
    canvas->drawGlyphs(count, glyphs, positions, clusters, textByteCount, utf8text, origin, *font, *paint);
}

void
SkCanvas_drawGlyphs_2(SkCanvas *canvas, int count, const SkGlyphID glyphs[], const SkPoint positions[], SkPoint origin,
                      const SkFont *font, const SkPaint *paint) {
    canvas->drawGlyphs(count, glyphs, positions, origin, *font, *paint);
}

void
SkCanvas_drawGlyphs_3(SkCanvas *canvas, int count, const SkGlyphID glyphs[], const SkRSXform xforms[], SkPoint origin,
                      const SkFont *font, const SkPaint *paint) {
    canvas->drawGlyphs(count, glyphs, xforms, origin, *font, *paint);
}

void SkCanvas_drawImage(int sk_image_key_in, SkCanvas *canvas, SkScalar left, SkScalar top) {
    canvas->drawImage(static_sk_image_move(sk_image_key_in), left, top);
}

void SkCanvas_drawImage_2(int sk_image_key_in, SkCanvas *canvas, SkScalar x, SkScalar y,
                          const SkSamplingOptions *sampling, const SkPaint *paint) {
    canvas->drawImage(static_sk_image_move(sk_image_key_in), x, y, *sampling, paint);
}

void
SkCanvas_drawImage_3(SkCanvas *canvas, const SkImage *image, SkScalar x, SkScalar y, const SkSamplingOptions *sampling,
                     const SkPaint *paint) {
    canvas->drawImage(image, x, y, *sampling, paint);
}

void SkCanvas_drawImage_4(SkCanvas *canvas, const SkImage *image, SkScalar left, SkScalar top) {
    canvas->drawImage(image, left, top);
}

void
SkCanvas_drawImageLattice(SkCanvas *canvas, const SkImage *image, const SkCanvas::Lattice *lattice, const SkRect *dst) {
    canvas->drawImageLattice(image, *lattice, *dst);
}

void
SkCanvas_drawImageLattice_2(SkCanvas *canvas, const SkImage *image, const SkCanvas::Lattice *lattice, const SkRect *dst,
                            SkFilterMode filter, const SkPaint *paint) {
    canvas->drawImageLattice(image, *lattice, *dst, filter, paint);
}

void SkCanvas_drawImageNine(SkCanvas *canvas, const SkImage *image, const SkIRect *center, const SkRect *dst,
                            SkFilterMode filter, const SkPaint *paint) {
    canvas->drawImageNine(image, *center, *dst, filter, paint);
}

void SkCanvas_drawImageRect(int sk_image_key_in, SkCanvas *canvas, const SkRect *dst,
                            const SkSamplingOptions *sampling, const SkPaint *paint) {
    canvas->drawImageRect(static_sk_image_move(sk_image_key_in), *dst, *sampling, paint);
}

void SkCanvas_drawImageRect_2(int sk_image_key_in, SkCanvas *canvas, const SkRect *src, const SkRect *dst,
                              const SkSamplingOptions *sampling, const SkPaint *paint,
                              SkCanvas::SrcRectConstraint constraint) {
    canvas->drawImageRect(static_sk_image_move(sk_image_key_in), *src, *dst, *sampling, paint, constraint);
}

void
SkCanvas_drawImageRect_3(SkCanvas *canvas, const SkImage *image, const SkRect *dst, const SkSamplingOptions *sampling,
                         const SkPaint *paint) {
    canvas->drawImageRect(image, *dst, *sampling, paint);
}

void SkCanvas_drawImageRect_4(SkCanvas *canvas, const SkImage *image, const SkRect *src, const SkRect *dst,
                              const SkSamplingOptions *sampling, const SkPaint *paint,
                              SkCanvas::SrcRectConstraint constraint) {
    canvas->drawImageRect(image, *src, *dst, *sampling, paint, constraint);
}

void SkCanvas_drawIRect(SkCanvas *canvas, const SkIRect *rect, const SkPaint *paint) {
    canvas->drawIRect(*rect, *paint);
}

void SkCanvas_drawLine(SkCanvas *canvas, SkPoint p0, SkPoint p1, const SkPaint *paint) {
    canvas->drawLine(p0, p1, *paint);
}

void SkCanvas_drawLine_2(SkCanvas *canvas, SkScalar x0, SkScalar y0, SkScalar x1, SkScalar y1, const SkPaint *paint) {
    canvas->drawLine(x0, y0, x1, y1, *paint);
}

void SkCanvas_drawMesh(int sk_blender_key_in, SkCanvas *canvas, const SkMesh *mesh, const SkPaint *paint) {
    canvas->drawMesh(*mesh, static_sk_blender_move(sk_blender_key_in), *paint);
}

void SkCanvas_drawOval(SkCanvas *canvas, const SkRect *oval, const SkPaint *paint) {
    canvas->drawOval(*oval, *paint);
}

void SkCanvas_drawPaint(SkCanvas *canvas, const SkPaint *paint) {
    canvas->drawPaint(*paint);
}

void SkCanvas_drawPatch(SkCanvas *canvas, const SkPoint cubics[12], const SkColor colors[4], const SkPoint texCoords[4],
                        SkBlendMode mode, const SkPaint *paint) {
    canvas->drawPatch(cubics, colors, texCoords, mode, *paint);
}

void SkCanvas_drawPath(SkCanvas *canvas, const SkPath *path, const SkPaint *paint) {
    canvas->drawPath(*path, *paint);
}

void SkCanvas_drawPicture(int sk_picture_key_in, SkCanvas *canvas) {
    canvas->drawPicture(static_sk_picture_move(sk_picture_key_in));
}

void
SkCanvas_drawPicture_2(int sk_picture_key_in, SkCanvas *canvas, const SkMatrix *matrix, const SkPaint *paint) {
    canvas->drawPicture(static_sk_picture_move(sk_picture_key_in), matrix, paint);
}

void SkCanvas_drawPicture_3(SkCanvas *canvas, const SkPicture *picture) {
    canvas->drawPicture(picture);
}

void SkCanvas_drawPicture_4(SkCanvas *canvas, const SkPicture *picture, const SkMatrix *matrix, const SkPaint *paint) {
    canvas->drawPicture(picture, matrix, paint);
}

void SkCanvas_drawPoint(SkCanvas *canvas, SkPoint p, const SkPaint *paint) {
    canvas->drawPoint(p, *paint);
}

void SkCanvas_drawPoint_2(SkCanvas *canvas, SkScalar x, SkScalar y, const SkPaint *paint) {
    canvas->drawPoint(x, y, *paint);
}

void SkCanvas_drawPoints(SkCanvas *canvas, SkCanvas::PointMode mode, size_t count, const SkPoint pts[],
                         const SkPaint *paint) {
    canvas->drawPoints(mode, count, pts, *paint);
}

void SkCanvas_drawRect(int sk_rect_key_in, SkCanvas *canvas, const SkPaint *paint) {
    canvas->drawRect(static_sk_rect_get(sk_rect_key_in), *paint);
}

void SkCanvas_drawRegion(SkCanvas *canvas, const SkRegion *region, const SkPaint *paint) {
    canvas->drawRegion(*region, *paint);
}

void SkCanvas_drawRoundRect(SkCanvas *canvas, const SkRect *rect, SkScalar rx, SkScalar ry, const SkPaint *paint) {
    canvas->drawRoundRect(*rect, rx, ry, *paint);
}

void SkCanvas_drawRRect(SkCanvas *canvas, const SkRRect *rrect, const SkPaint *paint) {
    canvas->drawRRect(*rrect, *paint);
}

void SkCanvas_drawSimpleText(SkCanvas *canvas, const void *text, size_t byteLength, SkTextEncoding encoding, SkScalar x,
                             SkScalar y, const SkFont *font, const SkPaint *paint) {
    canvas->drawSimpleText(text, byteLength, encoding, x, y, *font, *paint);
}

void SkCanvas_drawString(SkCanvas *canvas, const char str[], SkScalar x, SkScalar y, const SkFont *font,
                         const SkPaint *paint) {
    canvas->drawString(str, x, y, *font, *paint);
}

void SkCanvas_drawString_2(SkCanvas *canvas, const SkString *str, SkScalar x, SkScalar y, const SkFont *font,
                           const SkPaint *paint) {
    canvas->drawString(*str, x, y, *font, *paint);
}

void
SkCanvas_drawTextBlob(int sk_text_blob_key_in, SkCanvas *canvas, SkScalar x, SkScalar y, const SkPaint *paint) {
    canvas->drawTextBlob(static_sk_text_blob_move(sk_text_blob_key_in), x, y, *paint);
}

void SkCanvas_drawTextBlob_2(SkCanvas *canvas, const SkTextBlob *blob, SkScalar x, SkScalar y, const SkPaint *paint) {
    canvas->drawTextBlob(blob, x, y, *paint);
}

void SkCanvas_drawVertices(int sk_vertices_key_in, SkCanvas *canvas, SkBlendMode mode, const SkPaint *paint) {
    canvas->drawVertices(static_sk_vertices_move(sk_vertices_key_in), mode, *paint);
}

void SkCanvas_drawVertices_2(SkCanvas *canvas, const SkVertices *vertices, SkBlendMode mode, const SkPaint *paint) {
    canvas->drawVertices(vertices, mode, *paint);
}

void SkCanvas_experimental_DrawEdgeAAImageSet(SkCanvas *canvas, const SkCanvas::ImageSetEntry imageSet[], int cnt,
                                              const SkPoint dstClips[], const SkMatrix preViewMatrices[],
                                              const SkSamplingOptions *sampling, const SkPaint *paint,
                                              SkCanvas::SrcRectConstraint constraint) {
    canvas->experimental_DrawEdgeAAImageSet(imageSet, cnt, dstClips, preViewMatrices, *sampling, paint, constraint);
}

void SkCanvas_experimental_DrawEdgeAAQuad(SkCanvas *canvas, const SkRect *rect, const SkPoint clip[4],
                                          SkCanvas::QuadAAFlags aaFlags, const SkColor4f *color, SkBlendMode mode) {
    canvas->experimental_DrawEdgeAAQuad(*rect, clip, aaFlags, *color, mode);
}

void SkCanvas_experimental_DrawEdgeAAQuad_2(SkCanvas *canvas, const SkRect *rect, const SkPoint clip[4],
                                            SkCanvas::QuadAAFlags aaFlags, SkColor color, SkBlendMode mode) {
    canvas->experimental_DrawEdgeAAQuad(*rect, clip, aaFlags, color, mode);
}

SkISize SkCanvas_getBaseLayerSize(SkCanvas *canvas) { // virtual
    return canvas->getBaseLayerSize();
}

void SkCanvas_getBaseProps(int sk_surface_props_key_out, SkCanvas *canvas) {
    static_sk_surface_props_set(sk_surface_props_key_out, canvas->getBaseProps());
}

void SkCanvas_getDeviceClipBounds(int sk_i_rect_key_out, SkCanvas *canvas) {
    static_sk_i_rect_set(sk_i_rect_key_out, canvas->getDeviceClipBounds());
}

bool SkCanvas_getDeviceClipBounds_2(SkCanvas *canvas, SkIRect *bounds) {
    return canvas->getDeviceClipBounds(bounds);
}

void SkCanvas_getLocalClipBounds(int sk_rect_key_out, SkCanvas *canvas) {
    static_sk_rect_set(sk_rect_key_out ,canvas->getLocalClipBounds());
}

bool SkCanvas_getLocalClipBounds_2(SkCanvas *canvas, SkRect *bounds) {
    return canvas->getLocalClipBounds(bounds);
}

void SkCanvas_getLocalToDevice(int sk_m_44_key_out, SkCanvas *canvas) {
    static_sk_m_44_set(sk_m_44_key_out, canvas->getLocalToDevice());
}

void SkCanvas_getLocalToDeviceAs3x3(int sk_matrix_key_out, SkCanvas *canvas) {
    static_sk_matrix_set(sk_matrix_key_out, canvas->getLocalToDeviceAs3x3());
}

bool SkCanvas_getProps(SkCanvas *canvas, SkSurfaceProps *props) {
    return canvas->getProps(props);
}

int SkCanvas_getSaveCount(SkCanvas *canvas) {
    return canvas->getSaveCount();
}

SkSurface *SkCanvas_getSurface(SkCanvas *canvas) {
    return canvas->getSurface();
}

void SkCanvas_getTopProps(int sk_surface_props_key_out, SkCanvas *canvas) {
    static_sk_surface_props_set(sk_surface_props_key_out, canvas->getTopProps());
}

void SkCanvas_getTotalMatrix(int sk_matrix_key_out, SkCanvas *canvas) {
    static_sk_matrix_set(sk_matrix_key_out, canvas->getTotalMatrix());
}

void SkCanvas_imageInfo(int sk_image_info_key_out, SkCanvas *canvas) {
    static_sk_image_info_set(sk_image_info_key_out, canvas->imageInfo());
}

bool SkCanvas_isClipEmpty(SkCanvas *canvas) {
    return canvas->isClipEmpty();
}

bool SkCanvas_isClipRect(SkCanvas *canvas) {
    return canvas->isClipRect();
}

void SkCanvas_makeSurface(int sk_surface_key_out, SkCanvas *canvas, const SkImageInfo *info,
                          const SkSurfaceProps *props) {
    static_sk_surface_set(sk_surface_key_out, canvas->makeSurface(*info, props));
}

bool SkCanvas_peekPixels(SkCanvas *canvas, SkPixmap *pixmap) {
    return canvas->peekPixels(pixmap);
}

void SkCanvas_private_draw_shadow_rec(SkCanvas *canvas, const SkPath *path, const SkDrawShadowRec *rec) {
    canvas->private_draw_shadow_rec(*path, *rec);
}

bool SkCanvas_quickReject(SkCanvas *canvas, const SkPath *path) {
    return canvas->quickReject(*path);
}

bool SkCanvas_quickReject_2(SkCanvas *canvas, const SkRect *rect) {
    return canvas->quickReject(*rect);
}

bool SkCanvas_readPixels(SkCanvas *canvas, const SkBitmap *bitmap, int srcX, int srcY) {
    return canvas->readPixels(*bitmap, srcX, srcY);
}

bool SkCanvas_readPixels_2(SkCanvas *canvas, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX,
                           int srcY) {
    return canvas->readPixels(*dstInfo, dstPixels, dstRowBytes, srcX, srcY);
}

bool SkCanvas_readPixels_3(SkCanvas *canvas, const SkPixmap *pixmap, int srcX, int srcY) {
    return canvas->readPixels(*pixmap, srcX, srcY);
}

skgpu::graphite::Recorder *SkCanvas_recorder(SkCanvas *canvas) {
    return canvas->recorder();
}

GrRecordingContext *SkCanvas_recordingContext(SkCanvas *canvas) {
    return canvas->recordingContext();
}

void SkCanvas_resetMatrix(SkCanvas *canvas) {
    canvas->resetMatrix();
}

void SkCanvas_restore(SkCanvas *canvas) {
    canvas->restore();
}

void SkCanvas_restoreToCount(SkCanvas *canvas, int saveCount) {
    canvas->restoreToCount(saveCount);
}

void SkCanvas_rotate(SkCanvas *canvas, SkScalar degrees) {
    canvas->rotate(degrees);
}

void SkCanvas_rotate_2(SkCanvas *canvas, SkScalar degrees, SkScalar px, SkScalar py) {
    canvas->rotate(degrees, px, py);
}

int SkCanvas_save(SkCanvas *canvas) {
    return canvas->save();
}

int SkCanvas_saveLayer(SkCanvas *canvas, const SkCanvas::SaveLayerRec *layerRec) {
    return canvas->saveLayer(*layerRec);
}

int SkCanvas_saveLayer_2(SkCanvas *canvas, const SkRect *bounds, const SkPaint *paint) {
    return canvas->saveLayer(*bounds, paint);
}

int SkCanvas_saveLayer_3(SkCanvas *canvas, const SkRect *bounds, const SkPaint *paint) {
    return canvas->saveLayer(bounds, paint);
}

int SkCanvas_saveLayerAlpha(SkCanvas *canvas, const SkRect *bounds, U8CPU alpha) {
    return canvas->saveLayerAlpha(bounds, alpha);
}

int SkCanvas_saveLayerAlphaf(SkCanvas *canvas, const SkRect *bounds, float alpha) {
    return canvas->saveLayerAlphaf(bounds, alpha);
}

void SkCanvas_scale(SkCanvas *canvas, SkScalar sx, SkScalar sy) {
    canvas->scale(sx, sy);
}

void SkCanvas_setMatrix(SkCanvas *canvas, const SkM44 *matrix) {
    canvas->setMatrix(*matrix);
}

void SkCanvas_setMatrix_2(SkCanvas *canvas, const SkMatrix *matrix) {
    canvas->setMatrix(*matrix);
}

void SkCanvas_skew(SkCanvas *canvas, SkScalar sx, SkScalar sy) {
    canvas->skew(sx, sy);
}

void SkCanvas_temporary_internal_getRgnClip(SkCanvas *canvas, SkRegion *region) {
    canvas->temporary_internal_getRgnClip(region);
}

void SkCanvas_translate(SkCanvas *canvas, SkScalar dx, SkScalar dy) {
    canvas->translate(dx, dy);
}

bool SkCanvas_writePixels(SkCanvas *canvas, const SkBitmap *bitmap, int x, int y) {
    return canvas->writePixels(*bitmap, x, y);
}

bool
SkCanvas_writePixels_2(SkCanvas *canvas, const SkImageInfo *info, const void *pixels, size_t rowBytes, int x, int y) {
    return canvas->writePixels(*info, pixels, rowBytes, x, y);
}

// static

void SkCanvas_MakeRasterDirect(int sk_canvas_key_out, const SkImageInfo *info, void *pixels, size_t rowBytes,
                               const SkSurfaceProps *props) {
    static_sk_canvas_set(sk_canvas_key_out, SkCanvas::MakeRasterDirect(*info, pixels, rowBytes, props));
}

void
SkCanvas_MakeRasterDirectN32(int sk_canvas_key_out, int width, int height, SkPMColor *pixels, size_t rowBytes) {
    static_sk_canvas_set(sk_canvas_key_out, SkCanvas::MakeRasterDirectN32(width, height, pixels, rowBytes));
}

}