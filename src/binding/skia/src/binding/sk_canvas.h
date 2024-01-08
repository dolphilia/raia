//
// Created by dolphilia on 2024/01/06.
//

#ifndef RAIA_SKIA_SK_CANVAS_H
#define RAIA_SKIA_SK_CANVAS_H

#include "include/core/SkCanvas.h"
#include "../static/static_sk_canvas.h"
#include "../static/static_sk_surface.h"
#include "../static/static_sk_vertices.h"
#include "../static/static_sk_text_blob.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_picture.h"
#include "../static/static_sk_blender.h"
#include "../static/static_sk_image.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_shader.h"
#include "../static/static_sk_surface_props.h"
#include "../static/static_sk_i_rect.h"
#include "../static/static_sk_m_44.h"
#include "../static/static_sk_matrix.h"
#include "../static/static_sk_image_info.h"

extern "C" {
SkCanvas *SkCanvas_new();
SkCanvas *SkCanvas_new_2(int width, int height, const SkSurfaceProps *props);
SkCanvas *SkCanvas_new_3(SkBitmap *bitmap);
SkCanvas *SkCanvas_new_4(const SkBitmap *bitmap, const SkSurfaceProps *props);
void SkCanvas_delete(SkCanvas *canvas);
void *SkCanvas_accessTopLayerPixels(SkCanvas *canvas, SkImageInfo *info, size_t *rowBytes, SkIPoint *origin);
SkRasterHandleAllocator::Handle SkCanvas_accessTopRasterHandle(SkCanvas *canvas);
void SkCanvas_androidFramework_setDeviceClipRestriction(SkCanvas *canvas, const SkIRect *rect);
void SkCanvas_clear(SkCanvas *canvas, const SkColor4f *color);
void SkCanvas_clear_2(SkCanvas *canvas, SkColor color);
void SkCanvas_clipIRect(SkCanvas *canvas, const SkIRect *irect, SkClipOp op);
void SkCanvas_clipPath(SkCanvas *canvas, const SkPath *path, bool doAntiAlias);
void SkCanvas_clipPath_2(SkCanvas *canvas, const SkPath *path, SkClipOp op);
void SkCanvas_clipPath_3(SkCanvas *canvas, const SkPath *path, SkClipOp op, bool doAntiAlias);
void SkCanvas_clipRect(SkCanvas *canvas, const SkRect *rect, bool doAntiAlias);
void SkCanvas_clipRect_2(SkCanvas *canvas, const SkRect *rect, SkClipOp op);
void SkCanvas_clipRect_3(SkCanvas *canvas, const SkRect *rect, SkClipOp op, bool doAntiAlias);
void SkCanvas_clipRegion(SkCanvas *canvas, const SkRegion *deviceRgn, SkClipOp op);
void SkCanvas_clipRRect(SkCanvas *canvas, const SkRRect *rrect, bool doAntiAlias);
void SkCanvas_clipRRect_2(SkCanvas *canvas, const SkRRect *rrect, SkClipOp op);
void SkCanvas_clipRRect_3(SkCanvas *canvas, const SkRRect *rrect, SkClipOp op, bool doAntiAlias);
void SkCanvas_clipShader(const char *sk_shader_key_in, SkCanvas *canvas, SkClipOp op);
void SkCanvas_concat(SkCanvas *canvas, const SkM44 *m44);
void SkCanvas_concat_2(SkCanvas *canvas, const SkMatrix *matrix);
void SkCanvas_discard(SkCanvas *canvas);
void SkCanvas_drawAnnotation(const char *sk_data_key_in, SkCanvas *canvas, const SkRect *rect, const char key[]);
void SkCanvas_drawAnnotation_2(SkCanvas *canvas, const SkRect *rect, const char key[], SkData *value);
void SkCanvas_drawArc(SkCanvas *canvas, const SkRect *oval, SkScalar startAngle, SkScalar sweepAngle, bool useCenter, const SkPaint *paint);
void SkCanvas_drawAtlas(SkCanvas *canvas, const SkImage *atlas, const SkRSXform xform[], const SkRect tex[], const SkColor colors[], int count, SkBlendMode mode, const SkSamplingOptions *sampling, const SkRect *cullRect, const SkPaint *paint);
void SkCanvas_drawCircle(SkCanvas *canvas, SkPoint center, SkScalar radius, const SkPaint *paint);
void SkCanvas_drawCircle_2(SkCanvas *canvas, SkScalar cx, SkScalar cy, SkScalar radius, const SkPaint *paint);
void SkCanvas_drawColor(SkCanvas *canvas, const SkColor4f *color, SkBlendMode mode);
void SkCanvas_drawColor_2(SkCanvas *canvas, SkColor color, SkBlendMode mode);
void SkCanvas_drawDrawable(SkCanvas *canvas, SkDrawable *drawable, const SkMatrix *matrix);
void SkCanvas_drawDrawable_2(SkCanvas *canvas, SkDrawable *drawable, SkScalar x, SkScalar y);
void SkCanvas_drawDRRect(SkCanvas *canvas, const SkRRect *outer, const SkRRect *inner, const SkPaint *paint);
void SkCanvas_drawGlyphs(SkCanvas *canvas, int count, const SkGlyphID glyphs[], const SkPoint positions[], const uint32_t clusters[], int textByteCount, const char utf8text[], SkPoint origin, const SkFont *font, const SkPaint *paint);
void SkCanvas_drawGlyphs_2(SkCanvas *canvas, int count, const SkGlyphID glyphs[], const SkPoint positions[], SkPoint origin, const SkFont *font, const SkPaint *paint);
void SkCanvas_drawGlyphs_3(SkCanvas *canvas, int count, const SkGlyphID glyphs[], const SkRSXform xforms[], SkPoint origin, const SkFont *font, const SkPaint *paint);
void SkCanvas_drawImage(const char *sk_image_key_in, SkCanvas *canvas, SkScalar left, SkScalar top);
void SkCanvas_drawImage_2(const char *sk_image_key_in, SkCanvas *canvas, SkScalar x, SkScalar y, const SkSamplingOptions *sampling, const SkPaint *paint);
void SkCanvas_drawImage_3(SkCanvas *canvas, const SkImage *image, SkScalar x, SkScalar y, const SkSamplingOptions *sampling, const SkPaint *paint);
void SkCanvas_drawImage_4(SkCanvas *canvas, const SkImage *image, SkScalar left, SkScalar top);
void SkCanvas_drawImageLattice(SkCanvas *canvas, const SkImage *image, const SkCanvas::Lattice *lattice, const SkRect *dst);
void SkCanvas_drawImageLattice_2(SkCanvas *canvas, const SkImage *image, const SkCanvas::Lattice *lattice, const SkRect *dst, SkFilterMode filter, const SkPaint *paint);
void SkCanvas_drawImageNine(SkCanvas *canvas, const SkImage *image, const SkIRect *center, const SkRect *dst, SkFilterMode filter, const SkPaint *paint);
void SkCanvas_drawImageRect(const char *sk_image_key_in, SkCanvas *canvas, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint);
void SkCanvas_drawImageRect_2(const char *sk_image_key_in, SkCanvas *canvas, const SkRect *src, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint);
void SkCanvas_drawImageRect_3(SkCanvas *canvas, const SkImage *image, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint);
void SkCanvas_drawImageRect_4(SkCanvas *canvas, const SkImage *image, const SkRect *src, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint);
void SkCanvas_drawIRect(SkCanvas *canvas, const SkIRect *rect, const SkPaint *paint);
void SkCanvas_drawLine(SkCanvas *canvas, SkPoint p0, SkPoint p1, const SkPaint *paint);
void SkCanvas_drawLine_2(SkCanvas *canvas, SkScalar x0, SkScalar y0, SkScalar x1, SkScalar y1, const SkPaint *paint);
void SkCanvas_drawMesh(const char *sk_blender_key_in, SkCanvas *canvas, const SkMesh *mesh, const SkPaint *paint);
void SkCanvas_drawOval(SkCanvas *canvas, const SkRect *oval, const SkPaint *paint);
void SkCanvas_drawPaint(SkCanvas *canvas, const SkPaint *paint);
void SkCanvas_drawPatch(SkCanvas *canvas, const SkPoint cubics[12], const SkColor colors[4], const SkPoint texCoords[4], SkBlendMode mode, const SkPaint *paint);
void SkCanvas_drawPath(SkCanvas *canvas, const SkPath *path, const SkPaint *paint);
void SkCanvas_drawPicture(const char *sk_picture_key_in, SkCanvas *canvas);
void SkCanvas_drawPicture_2(const char *sk_picture_key_in, SkCanvas *canvas, const SkMatrix *matrix, const SkPaint *paint);
void SkCanvas_drawPicture_3(SkCanvas *canvas, const SkPicture *picture);
void SkCanvas_drawPicture_4(SkCanvas *canvas, const SkPicture *picture, const SkMatrix *matrix, const SkPaint *paint);
void SkCanvas_drawPoint(SkCanvas *canvas, SkPoint p, const SkPaint *paint);
void SkCanvas_drawPoint_2(SkCanvas *canvas, SkScalar x, SkScalar y, const SkPaint *paint);
void SkCanvas_drawPoints(SkCanvas *canvas, SkCanvas::PointMode mode, size_t count, const SkPoint pts[], const SkPaint *paint);
void SkCanvas_drawRect(const char *sk_rect_key_in, SkCanvas *canvas, const SkPaint *paint);
void SkCanvas_drawRegion(SkCanvas *canvas, const SkRegion *region, const SkPaint *paint);
void SkCanvas_drawRoundRect(SkCanvas *canvas, const SkRect *rect, SkScalar rx, SkScalar ry, const SkPaint *paint);
void SkCanvas_drawRRect(SkCanvas *canvas, const SkRRect *rrect, const SkPaint *paint);
void SkCanvas_drawSimpleText(SkCanvas *canvas, const void *text, size_t byteLength, SkTextEncoding encoding, SkScalar x, SkScalar y, const SkFont *font, const SkPaint *paint);
void SkCanvas_drawString(SkCanvas *canvas, const char str[], SkScalar x, SkScalar y, const SkFont *font, const SkPaint *paint);
void SkCanvas_drawString_2(SkCanvas *canvas, const SkString *str, SkScalar x, SkScalar y, const SkFont *font, const SkPaint *paint);
void SkCanvas_drawTextBlob(const char *sk_text_blob_key_in, SkCanvas *canvas, SkScalar x, SkScalar y, const SkPaint *paint);
void SkCanvas_drawTextBlob_2(SkCanvas *canvas, const SkTextBlob *blob, SkScalar x, SkScalar y, const SkPaint *paint);
void SkCanvas_drawVertices(const char *sk_vertices_key_in, SkCanvas *canvas, SkBlendMode mode, const SkPaint *paint);
void SkCanvas_drawVertices_2(SkCanvas *canvas, const SkVertices *vertices, SkBlendMode mode, const SkPaint *paint);
void SkCanvas_experimental_DrawEdgeAAImageSet(SkCanvas *canvas, const SkCanvas::ImageSetEntry imageSet[], int cnt, const SkPoint dstClips[], const SkMatrix preViewMatrices[], const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint);
void SkCanvas_experimental_DrawEdgeAAQuad(SkCanvas *canvas, const SkRect *rect, const SkPoint clip[4], SkCanvas::QuadAAFlags aaFlags, const SkColor4f *color, SkBlendMode mode);
void SkCanvas_experimental_DrawEdgeAAQuad_2(SkCanvas *canvas, const SkRect *rect, const SkPoint clip[4], SkCanvas::QuadAAFlags aaFlags, SkColor color, SkBlendMode mode);
SkISize SkCanvas_getBaseLayerSize(SkCanvas *canvas);
void SkCanvas_getBaseProps(const char *sk_surface_props_key_out, SkCanvas *canvas);
void SkCanvas_getDeviceClipBounds(const char *sk_i_rect_key_out, SkCanvas *canvas);
bool SkCanvas_getDeviceClipBounds_2(SkCanvas *canvas, SkIRect *bounds);
void SkCanvas_getLocalClipBounds(const char *sk_rect_key_out, SkCanvas *canvas);
bool SkCanvas_getLocalClipBounds_2(SkCanvas *canvas, SkRect *bounds);
void SkCanvas_getLocalToDevice(const char *sk_m_44_key_out, SkCanvas *canvas);
void SkCanvas_getLocalToDeviceAs3x3(const char *sk_matrix_key_out, SkCanvas *canvas);
bool SkCanvas_getProps(SkCanvas *canvas, SkSurfaceProps *props);
int SkCanvas_getSaveCount(SkCanvas *canvas);
SkSurface *SkCanvas_getSurface(SkCanvas *canvas);
void SkCanvas_getTopProps(const char *sk_surface_props_key_out, SkCanvas *canvas);
void SkCanvas_getTotalMatrix(const char *sk_matrix_key_out, SkCanvas *canvas);
void SkCanvas_imageInfo(const char *sk_image_info_key_out, SkCanvas *canvas);
bool SkCanvas_isClipEmpty(SkCanvas *canvas);
bool SkCanvas_isClipRect(SkCanvas *canvas);
void SkCanvas_makeSurface(const char *sk_surface_key_out, SkCanvas *canvas, const SkImageInfo *info, const SkSurfaceProps *props);
bool SkCanvas_peekPixels(SkCanvas *canvas, SkPixmap *pixmap);
void SkCanvas_private_draw_shadow_rec(SkCanvas *canvas, const SkPath *path, const SkDrawShadowRec *rec);
bool SkCanvas_quickReject(SkCanvas *canvas, const SkPath *path);
bool SkCanvas_quickReject_2(SkCanvas *canvas, const SkRect *rect);
bool SkCanvas_readPixels(SkCanvas *canvas, const SkBitmap *bitmap, int srcX, int srcY);
bool SkCanvas_readPixels_2(SkCanvas *canvas, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY);
bool SkCanvas_readPixels_3(SkCanvas *canvas, const SkPixmap *pixmap, int srcX, int srcY);
skgpu::graphite::Recorder *SkCanvas_recorder(SkCanvas *canvas);
GrRecordingContext *SkCanvas_recordingContext(SkCanvas *canvas);
void SkCanvas_resetMatrix(SkCanvas *canvas);
void SkCanvas_restore(SkCanvas *canvas);
void SkCanvas_restoreToCount(SkCanvas *canvas, int saveCount);
void SkCanvas_rotate(SkCanvas *canvas, SkScalar degrees);
void SkCanvas_rotate_2(SkCanvas *canvas, SkScalar degrees, SkScalar px, SkScalar py);
int SkCanvas_save(SkCanvas *canvas);
int SkCanvas_saveLayer(SkCanvas *canvas, const SkCanvas::SaveLayerRec *layerRec);
int SkCanvas_saveLayer_2(SkCanvas *canvas, const SkRect *bounds, const SkPaint *paint);
int SkCanvas_saveLayer_3(SkCanvas *canvas, const SkRect *bounds, const SkPaint *paint);
int SkCanvas_saveLayerAlpha(SkCanvas *canvas, const SkRect *bounds, U8CPU alpha);
int SkCanvas_saveLayerAlphaf(SkCanvas *canvas, const SkRect *bounds, float alpha);
void SkCanvas_scale(SkCanvas *canvas, SkScalar sx, SkScalar sy);
void SkCanvas_setMatrix(SkCanvas *canvas, const SkM44 *matrix);
void SkCanvas_setMatrix_2(SkCanvas *canvas, const SkMatrix *matrix);
void SkCanvas_skew(SkCanvas *canvas, SkScalar sx, SkScalar sy);
void SkCanvas_temporary_internal_getRgnClip(SkCanvas *canvas, SkRegion *region);
void SkCanvas_translate(SkCanvas *canvas, SkScalar dx, SkScalar dy);
bool SkCanvas_writePixels(SkCanvas *canvas, const SkBitmap *bitmap, int x, int y);
bool SkCanvas_writePixels_2(SkCanvas *canvas, const SkImageInfo *info, const void *pixels, size_t rowBytes, int x, int y);
// static
void SkCanvas_MakeRasterDirect(const char *sk_canvas_key_out, const SkImageInfo *info, void *pixels, size_t rowBytes, const SkSurfaceProps *props);
void SkCanvas_MakeRasterDirectN32(const char *sk_canvas_key_out, int width, int height, SkPMColor *pixels, size_t rowBytes);
}

#endif //RAIA_SKIA_SK_CANVAS_H
