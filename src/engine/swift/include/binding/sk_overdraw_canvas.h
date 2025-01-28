//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_OVERDRAW_CANVAS_H
#define RAIA_SKIA_SK_OVERDRAW_CANVAS_H

#include "include/core/SkOverdrawCanvas.h"

extern "C" {
void SkOverdrawCanvas_delete(SkOverdrawCanvas *overdraw_canvas);
void SkOverdrawCanvas_onDrawTextBlob(SkOverdrawCanvas *overdraw_canvas, const SkTextBlob *blob, SkScalar scalar1, SkScalar scalar2, const SkPaint *paint);
void SkOverdrawCanvas_onDrawGlyphRunList(SkOverdrawCanvas *overdraw_canvas, const sktext::GlyphRunList *glyphRunList, const SkPaint *paint);
void SkOverdrawCanvas_onDrawPatch(SkOverdrawCanvas *overdraw_canvas, const SkPoint point1[12], const SkColor color[4], const SkPoint point2[4], SkBlendMode mode, const SkPaint *paint);
void SkOverdrawCanvas_onDrawPaint(SkOverdrawCanvas *overdraw_canvas, const SkPaint *paint);
void SkOverdrawCanvas_onDrawBehind(SkOverdrawCanvas *overdraw_canvas, const SkPaint *paint);
void SkOverdrawCanvas_onDrawRect(SkOverdrawCanvas *overdraw_canvas, const SkRect *rect, const SkPaint *paint);
void SkOverdrawCanvas_onDrawRegion(SkOverdrawCanvas *overdraw_canvas, const SkRegion *region, const SkPaint *paint);
void SkOverdrawCanvas_onDrawOval(SkOverdrawCanvas *overdraw_canvas, const SkRect *rect, const SkPaint *paint);
void SkOverdrawCanvas_onDrawArc(SkOverdrawCanvas *overdraw_canvas, const SkRect *rect, SkScalar scalar1, SkScalar scalar2, bool v, const SkPaint *paint);
void SkOverdrawCanvas_onDrawDRRect(SkOverdrawCanvas *overdraw_canvas, const SkRRect *rect1, const SkRRect *rect2, const SkPaint *paint);
void SkOverdrawCanvas_onDrawRRect(SkOverdrawCanvas *overdraw_canvas, const SkRRect *rect, const SkPaint *paint);
void SkOverdrawCanvas_onDrawPoints(SkOverdrawCanvas *overdraw_canvas, SkOverdrawCanvas::PointMode mode, size_t size, const SkPoint point[], const SkPaint *paint);
void SkOverdrawCanvas_onDrawVerticesObject(SkOverdrawCanvas *overdraw_canvas, const SkVertices *vertices, SkBlendMode mode, const SkPaint *paint);
void SkOverdrawCanvas_onDrawPath(SkOverdrawCanvas *overdraw_canvas, const SkPath *path, const SkPaint *paint);
void SkOverdrawCanvas_onDrawImage2(SkOverdrawCanvas *overdraw_canvas, const SkImage *image, SkScalar scalar1, SkScalar scalar2, const SkSamplingOptions *options, const SkPaint *paint);
void SkOverdrawCanvas_onDrawImageRect2(SkOverdrawCanvas *overdraw_canvas, const SkImage *image, const SkRect *rect1, const SkRect *rect2, const SkSamplingOptions *options, const SkPaint *paint, SkOverdrawCanvas::SrcRectConstraint constraint);
void SkOverdrawCanvas_onDrawImageLattice2(SkOverdrawCanvas *overdraw_canvas, const SkImage *image, const SkOverdrawCanvas::Lattice *lattice, const SkRect *rect, SkFilterMode mode, const SkPaint *paint);
void SkOverdrawCanvas_onDrawAtlas2(SkOverdrawCanvas *overdraw_canvas, const SkImage * image, const SkRSXform form[], const SkRect rect1[], const SkColor color[], int v, SkBlendMode mode, const SkSamplingOptions *options, const SkRect *rect2, const SkPaint *paint);
void SkOverdrawCanvas_onDrawDrawable(SkOverdrawCanvas *overdraw_canvas, SkDrawable *drawable, const SkMatrix *matrix);
void SkOverdrawCanvas_onDrawPicture(SkOverdrawCanvas *overdraw_canvas, const SkPicture *picture, const SkMatrix *matrix, const SkPaint *paint);
void SkOverdrawCanvas_onDrawAnnotation(SkOverdrawCanvas *overdraw_canvas, const SkRect *rect, const char key[], SkData *value);
void SkOverdrawCanvas_onDrawShadowRec(SkOverdrawCanvas *overdraw_canvas, const SkPath *path, const SkDrawShadowRec *rec);
void SkOverdrawCanvas_onDrawEdgeAAQuad(SkOverdrawCanvas *overdraw_canvas, const SkRect *rect, const SkPoint point[4], SkCanvas::QuadAAFlags flags, const SkColor4f *color, SkBlendMode mode);
void SkOverdrawCanvas_onDrawEdgeAAImageSet2(SkOverdrawCanvas *overdraw_canvas, const SkOverdrawCanvas::ImageSetEntry entry[], int count, const SkPoint point[], const SkMatrix matrix[], const SkSamplingOptions *options, const SkPaint *paint, SkOverdrawCanvas::SrcRectConstraint constraint);
}

#endif //RAIA_SKIA_SK_OVERDRAW_CANVAS_H
