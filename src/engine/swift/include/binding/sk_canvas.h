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
#include "../static/static_sk_point.h"
#include "../static/static_sk_i_size.h"
#include "export_api.h"

extern "C" {
RAIA_API SkCanvas *SkCanvas_new();
RAIA_API SkCanvas *SkCanvas_new_2(int width, int height, const SkSurfaceProps *props);
RAIA_API SkCanvas *SkCanvas_new_3(SkBitmap *bitmap);
RAIA_API SkCanvas *SkCanvas_new_4(const SkBitmap *bitmap, const SkSurfaceProps *props);
RAIA_API void SkCanvas_delete(SkCanvas *canvas);
RAIA_API void *SkCanvas_accessTopLayerPixels(SkCanvas *canvas, SkImageInfo *info, size_t *rowBytes, SkIPoint *origin);
RAIA_API SkRasterHandleAllocator::Handle SkCanvas_accessTopRasterHandle(SkCanvas *canvas);
RAIA_API void SkCanvas_androidFramework_setDeviceClipRestriction(SkCanvas *canvas, const SkIRect *rect);
RAIA_API void SkCanvas_clear(SkCanvas *canvas, const SkColor4f *color);
RAIA_API void SkCanvas_clear_2(SkCanvas *canvas, SkColor color);
RAIA_API void SkCanvas_clipIRect(SkCanvas *canvas, const SkIRect *irect, SkClipOp op);
RAIA_API void SkCanvas_clipPath(SkCanvas *canvas, const SkPath *path, bool doAntiAlias);
RAIA_API void SkCanvas_clipPath_2(SkCanvas *canvas, const SkPath *path, SkClipOp op);
RAIA_API void SkCanvas_clipPath_3(SkCanvas *canvas, const SkPath *path, SkClipOp op, bool doAntiAlias);
RAIA_API void SkCanvas_clipRect(SkCanvas *canvas, const SkRect *rect, bool doAntiAlias);
RAIA_API void SkCanvas_clipRect_2(SkCanvas *canvas, const SkRect *rect, SkClipOp op);
RAIA_API void SkCanvas_clipRect_3(SkCanvas *canvas, const SkRect *rect, SkClipOp op, bool doAntiAlias);
RAIA_API void SkCanvas_clipRegion(SkCanvas *canvas, const SkRegion *deviceRgn, SkClipOp op);
RAIA_API void SkCanvas_clipRRect(SkCanvas *canvas, const SkRRect *rrect, bool doAntiAlias);
RAIA_API void SkCanvas_clipRRect_2(SkCanvas *canvas, const SkRRect *rrect, SkClipOp op);
RAIA_API void SkCanvas_clipRRect_3(SkCanvas *canvas, const SkRRect *rrect, SkClipOp op, bool doAntiAlias);
RAIA_API void SkCanvas_clipShader(SkCanvas *canvas, sk_shader_t shader, SkClipOp op);
RAIA_API void SkCanvas_concat(SkCanvas *canvas, const SkM44 *m44);
RAIA_API void SkCanvas_concat_2(SkCanvas *canvas, const SkMatrix *matrix);
RAIA_API void SkCanvas_discard(SkCanvas *canvas);
RAIA_API void SkCanvas_drawAnnotation(SkCanvas *canvas, const SkRect *rect, const char key[], sk_data_t data);
RAIA_API void SkCanvas_drawAnnotation_2(SkCanvas *canvas, const SkRect *rect, const char key[], SkData *value);
RAIA_API void SkCanvas_drawArc(SkCanvas *canvas, const SkRect *oval, SkScalar startAngle, SkScalar sweepAngle, bool useCenter, const SkPaint *paint);
RAIA_API void SkCanvas_drawAtlas(SkCanvas *canvas, const SkImage *atlas, const SkRSXform xform[], const SkRect tex[], const SkColor colors[], int count, SkBlendMode mode, const SkSamplingOptions *sampling, const SkRect *cullRect, const SkPaint *paint);
RAIA_API void SkCanvas_drawCircle(SkCanvas *canvas, sk_point_t center, SkScalar radius, const SkPaint *paint);
RAIA_API void SkCanvas_drawCircle_2(SkCanvas *canvas, SkScalar cx, SkScalar cy, SkScalar radius, const SkPaint *paint);
RAIA_API void SkCanvas_drawColor(SkCanvas *canvas, const SkColor4f *color, SkBlendMode mode);
RAIA_API void SkCanvas_drawColor_2(SkCanvas *canvas, SkColor color, SkBlendMode mode);
RAIA_API void SkCanvas_drawDrawable(SkCanvas *canvas, SkDrawable *drawable, const SkMatrix *matrix);
RAIA_API void SkCanvas_drawDrawable_2(SkCanvas *canvas, SkDrawable *drawable, SkScalar x, SkScalar y);
RAIA_API void SkCanvas_drawDRRect(SkCanvas *canvas, const SkRRect *outer, const SkRRect *inner, const SkPaint *paint);
RAIA_API void SkCanvas_drawGlyphs(SkCanvas *canvas, int count, const SkGlyphID glyphs[], const SkPoint positions[], const uint32_t clusters[], int textByteCount, const char utf8text[], sk_point_t origin, const SkFont *font, const SkPaint *paint);
RAIA_API void SkCanvas_drawGlyphs_2(SkCanvas *canvas, int count, const SkGlyphID glyphs[], const SkPoint positions[], sk_point_t origin, const SkFont *font, const SkPaint *paint);
RAIA_API void SkCanvas_drawGlyphs_3(SkCanvas *canvas, int count, const SkGlyphID glyphs[], const SkRSXform xforms[], sk_point_t origin, const SkFont *font, const SkPaint *paint);
RAIA_API void SkCanvas_drawImage(SkCanvas *canvas, sk_image_t image, SkScalar left, SkScalar top);
RAIA_API void SkCanvas_drawImage_2(SkCanvas *canvas, sk_image_t image, SkScalar x, SkScalar y, const SkSamplingOptions *sampling, const SkPaint *paint);
RAIA_API void SkCanvas_drawImage_3(SkCanvas *canvas, const SkImage *image, SkScalar x, SkScalar y, const SkSamplingOptions *sampling, const SkPaint *paint);
RAIA_API void SkCanvas_drawImage_4(SkCanvas *canvas, const SkImage *image, SkScalar left, SkScalar top);
RAIA_API void SkCanvas_drawImageLattice(SkCanvas *canvas, const SkImage *image, const SkCanvas::Lattice *lattice, const SkRect *dst);
RAIA_API void SkCanvas_drawImageLattice_2(SkCanvas *canvas, const SkImage *image, const SkCanvas::Lattice *lattice, const SkRect *dst, SkFilterMode filter, const SkPaint *paint);
RAIA_API void SkCanvas_drawImageNine(SkCanvas *canvas, const SkImage *image, const SkIRect *center, const SkRect *dst, SkFilterMode filter, const SkPaint *paint);
RAIA_API void SkCanvas_drawImageRect(SkCanvas *canvas, sk_image_t image, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint);
RAIA_API void SkCanvas_drawImageRect_2(SkCanvas *canvas, sk_image_t image, const SkRect *src, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint);
RAIA_API void SkCanvas_drawImageRect_3(SkCanvas *canvas, const SkImage *image, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint);
RAIA_API void SkCanvas_drawImageRect_4(SkCanvas *canvas, const SkImage *image, const SkRect *src, const SkRect *dst, const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint);
RAIA_API void SkCanvas_drawIRect(SkCanvas *canvas, const SkIRect *rect, const SkPaint *paint);
RAIA_API void SkCanvas_drawLine(SkCanvas *canvas, sk_point_t p0, sk_point_t p1, const SkPaint *paint);
RAIA_API void SkCanvas_drawLine_2(SkCanvas *canvas, SkScalar x0, SkScalar y0, SkScalar x1, SkScalar y1, const SkPaint *paint);
RAIA_API void SkCanvas_drawMesh(SkCanvas *canvas, const SkMesh *mesh, sk_blender_t blender, const SkPaint *paint);
RAIA_API void SkCanvas_drawOval(SkCanvas *canvas, const SkRect *oval, const SkPaint *paint);
RAIA_API void SkCanvas_drawPaint(SkCanvas *canvas, const SkPaint *paint);
RAIA_API void SkCanvas_drawPatch(SkCanvas *canvas, const SkPoint cubics[12], const SkColor colors[4], const SkPoint texCoords[4], SkBlendMode mode, const SkPaint *paint);
RAIA_API void SkCanvas_drawPath(SkCanvas *canvas, const SkPath *path, const SkPaint *paint);
RAIA_API void SkCanvas_drawPicture(SkCanvas *canvas, sk_picture_t picture);
RAIA_API void SkCanvas_drawPicture_2(SkCanvas *canvas, sk_picture_t picture, const SkMatrix *matrix, const SkPaint *paint);
RAIA_API void SkCanvas_drawPicture_3(SkCanvas *canvas, const SkPicture *picture);
RAIA_API void SkCanvas_drawPicture_4(SkCanvas *canvas, const SkPicture *picture, const SkMatrix *matrix, const SkPaint *paint);
RAIA_API void SkCanvas_drawPoint(SkCanvas *canvas, sk_point_t p, const SkPaint *paint);
RAIA_API void SkCanvas_drawPoint_2(SkCanvas *canvas, SkScalar x, SkScalar y, const SkPaint *paint);
RAIA_API void SkCanvas_drawPoints(SkCanvas *canvas, SkCanvas::PointMode mode, size_t count, const SkPoint pts[], const SkPaint *paint);
RAIA_API void SkCanvas_drawRect(SkCanvas *canvas, sk_rect_t rect, const SkPaint *paint);
RAIA_API void SkCanvas_drawRegion(SkCanvas *canvas, const SkRegion *region, const SkPaint *paint);
RAIA_API void SkCanvas_drawRoundRect(SkCanvas *canvas, const SkRect *rect, SkScalar rx, SkScalar ry, const SkPaint *paint);
RAIA_API void SkCanvas_drawRRect(SkCanvas *canvas, const SkRRect *rrect, const SkPaint *paint);
RAIA_API void SkCanvas_drawSimpleText(SkCanvas *canvas, const void *text, size_t byteLength, SkTextEncoding encoding, SkScalar x, SkScalar y, const SkFont *font, const SkPaint *paint);
RAIA_API void SkCanvas_drawString(SkCanvas *canvas, const char str[], SkScalar x, SkScalar y, const SkFont *font, const SkPaint *paint);
RAIA_API void SkCanvas_drawString_2(SkCanvas *canvas, const SkString *str, SkScalar x, SkScalar y, const SkFont *font, const SkPaint *paint);
RAIA_API void SkCanvas_drawTextBlob(SkCanvas *canvas, sk_text_blob_t text_blob, SkScalar x, SkScalar y, const SkPaint *paint);
RAIA_API void SkCanvas_drawTextBlob_2(SkCanvas *canvas, const SkTextBlob *blob, SkScalar x, SkScalar y, const SkPaint *paint);
RAIA_API void SkCanvas_drawVertices(SkCanvas *canvas, sk_vertices_t vertices, SkBlendMode mode, const SkPaint *paint);
RAIA_API void SkCanvas_drawVertices_2(SkCanvas *canvas, const SkVertices *vertices, SkBlendMode mode, const SkPaint *paint);
RAIA_API void SkCanvas_experimental_DrawEdgeAAImageSet(SkCanvas *canvas, const SkCanvas::ImageSetEntry imageSet[], int cnt, const SkPoint dstClips[], const SkMatrix preViewMatrices[], const SkSamplingOptions *sampling, const SkPaint *paint, SkCanvas::SrcRectConstraint constraint);
RAIA_API void SkCanvas_experimental_DrawEdgeAAQuad(SkCanvas *canvas, const SkRect *rect, const SkPoint clip[4], SkCanvas::QuadAAFlags aaFlags, const SkColor4f *color, SkBlendMode mode);
RAIA_API void SkCanvas_experimental_DrawEdgeAAQuad_2(SkCanvas *canvas, const SkRect *rect, const SkPoint clip[4], SkCanvas::QuadAAFlags aaFlags, SkColor color, SkBlendMode mode);
RAIA_API sk_i_size_t SkCanvas_getBaseLayerSize(SkCanvas *canvas);
RAIA_API sk_surface_props_t SkCanvas_getBaseProps(SkCanvas *canvas);
RAIA_API sk_i_rect_t SkCanvas_getDeviceClipBounds(SkCanvas *canvas);
RAIA_API bool SkCanvas_getDeviceClipBounds_2(SkCanvas *canvas, SkIRect *bounds);
RAIA_API sk_rect_t SkCanvas_getLocalClipBounds(SkCanvas *canvas);
RAIA_API bool SkCanvas_getLocalClipBounds_2(SkCanvas *canvas, SkRect *bounds);
RAIA_API sk_m_44_t SkCanvas_getLocalToDevice(SkCanvas *canvas);
RAIA_API sk_matrix_t SkCanvas_getLocalToDeviceAs3x3(SkCanvas *canvas);
RAIA_API bool SkCanvas_getProps(SkCanvas *canvas, SkSurfaceProps *props);
RAIA_API int SkCanvas_getSaveCount(SkCanvas *canvas);
RAIA_API SkSurface *SkCanvas_getSurface(SkCanvas *canvas);
RAIA_API sk_surface_props_t SkCanvas_getTopProps(SkCanvas *canvas);
RAIA_API sk_matrix_t SkCanvas_getTotalMatrix(SkCanvas *canvas);
RAIA_API sk_image_info_t SkCanvas_imageInfo(SkCanvas *canvas);
RAIA_API bool SkCanvas_isClipEmpty(SkCanvas *canvas);
RAIA_API bool SkCanvas_isClipRect(SkCanvas *canvas);
RAIA_API sk_surface_t SkCanvas_makeSurface(SkCanvas *canvas, const SkImageInfo *info, const SkSurfaceProps *props);
RAIA_API bool SkCanvas_peekPixels(SkCanvas *canvas, SkPixmap *pixmap);
RAIA_API void SkCanvas_private_draw_shadow_rec(SkCanvas *canvas, const SkPath *path, const SkDrawShadowRec *rec);
RAIA_API bool SkCanvas_quickReject(SkCanvas *canvas, const SkPath *path);
RAIA_API bool SkCanvas_quickReject_2(SkCanvas *canvas, const SkRect *rect);
RAIA_API bool SkCanvas_readPixels(SkCanvas *canvas, const SkBitmap *bitmap, int srcX, int srcY);
RAIA_API bool SkCanvas_readPixels_2(SkCanvas *canvas, const SkImageInfo *dstInfo, void *dstPixels, size_t dstRowBytes, int srcX, int srcY);
RAIA_API bool SkCanvas_readPixels_3(SkCanvas *canvas, const SkPixmap *pixmap, int srcX, int srcY);
RAIA_API skgpu::graphite::Recorder *SkCanvas_recorder(SkCanvas *canvas);
RAIA_API GrRecordingContext *SkCanvas_recordingContext(SkCanvas *canvas);
RAIA_API void SkCanvas_resetMatrix(SkCanvas *canvas);
RAIA_API void SkCanvas_restore(SkCanvas *canvas);
RAIA_API void SkCanvas_restoreToCount(SkCanvas *canvas, int saveCount);
RAIA_API void SkCanvas_rotate(SkCanvas *canvas, SkScalar degrees);
RAIA_API void SkCanvas_rotate_2(SkCanvas *canvas, SkScalar degrees, SkScalar px, SkScalar py);
RAIA_API int SkCanvas_save(SkCanvas *canvas);
RAIA_API int SkCanvas_saveLayer(SkCanvas *canvas, const SkCanvas::SaveLayerRec *layerRec);
RAIA_API int SkCanvas_saveLayer_2(SkCanvas *canvas, const SkRect *bounds, const SkPaint *paint);
RAIA_API int SkCanvas_saveLayer_3(SkCanvas *canvas, const SkRect *bounds, const SkPaint *paint);
RAIA_API int SkCanvas_saveLayerAlpha(SkCanvas *canvas, const SkRect *bounds, U8CPU alpha);
RAIA_API int SkCanvas_saveLayerAlphaf(SkCanvas *canvas, const SkRect *bounds, float alpha);
RAIA_API void SkCanvas_scale(SkCanvas *canvas, SkScalar sx, SkScalar sy);
RAIA_API void SkCanvas_setMatrix(SkCanvas *canvas, const SkM44 *matrix);
RAIA_API void SkCanvas_setMatrix_2(SkCanvas *canvas, const SkMatrix *matrix);
RAIA_API void SkCanvas_skew(SkCanvas *canvas, SkScalar sx, SkScalar sy);
RAIA_API void SkCanvas_temporary_internal_getRgnClip(SkCanvas *canvas, SkRegion *region);
RAIA_API void SkCanvas_translate(SkCanvas *canvas, SkScalar dx, SkScalar dy);
RAIA_API bool SkCanvas_writePixels(SkCanvas *canvas, const SkBitmap *bitmap, int x, int y);
RAIA_API bool SkCanvas_writePixels_2(SkCanvas *canvas, const SkImageInfo *info, const void *pixels, size_t rowBytes, int x, int y);
// static
RAIA_API sk_canvas_t SkCanvas_MakeRasterDirect(const SkImageInfo *info, void *pixels, size_t rowBytes, const SkSurfaceProps *props);
RAIA_API sk_canvas_t SkCanvas_MakeRasterDirectN32(int width, int height, SkPMColor *pixels, size_t rowBytes);
}

#endif //RAIA_SKIA_SK_CANVAS_H
