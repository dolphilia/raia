//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_OVERDRAW_CANVAS_H
#define RAIA_SKIA_SK_OVERDRAW_CANVAS_H

#ifdef __cplusplus
extern "C" {
#endif

void SkOverdrawCanvas_delete(void *overdraw_canvas); // (SkOverdrawCanvas *overdraw_canvas)
void SkOverdrawCanvas_onDrawTextBlob(void *overdraw_canvas, const void *blob, float scalar1, float scalar2, const void *paint); // (SkOverdrawCanvas *overdraw_canvas, const SkTextBlob *blob, SkScalar scalar1, SkScalar scalar2, const SkPaint *paint)
void SkOverdrawCanvas_onDrawGlyphRunList(void *overdraw_canvas, const void *glyphRunList, const void *paint); // (SkOverdrawCanvas *overdraw_canvas, const sktext::GlyphRunList *glyphRunList, const SkPaint *paint)
void SkOverdrawCanvas_onDrawPatch(void *overdraw_canvas, const void * point1, const void * color, const void * point2, int mode, const void *paint); // (SkOverdrawCanvas *overdraw_canvas, const SkPoint point1[12], const SkColor color[4], const SkPoint point2[4], SkBlendMode mode, const SkPaint *paint)
void SkOverdrawCanvas_onDrawPaint(void *overdraw_canvas, const void *paint); // (SkOverdrawCanvas *overdraw_canvas, const SkPaint *paint)
void SkOverdrawCanvas_onDrawBehind(void *overdraw_canvas, const void *paint); // (SkOverdrawCanvas *overdraw_canvas, const SkPaint *paint)
void SkOverdrawCanvas_onDrawRect(void *overdraw_canvas, const void *rect, const void *paint); // (SkOverdrawCanvas *overdraw_canvas, const SkRect *rect, const SkPaint *paint)
void SkOverdrawCanvas_onDrawRegion(void *overdraw_canvas, const void *region, const void *paint); // (SkOverdrawCanvas *overdraw_canvas, const SkRegion *region, const SkPaint *paint)
void SkOverdrawCanvas_onDrawOval(void *overdraw_canvas, const void *rect, const void *paint); // (SkOverdrawCanvas *overdraw_canvas, const SkRect *rect, const SkPaint *paint)
void SkOverdrawCanvas_onDrawArc(void *overdraw_canvas, const void *rect, float scalar1, float scalar2, bool v, const void *paint); // (SkOverdrawCanvas *overdraw_canvas, const SkRect *rect, SkScalar scalar1, SkScalar scalar2, bool v, const SkPaint *paint)
void SkOverdrawCanvas_onDrawDRRect(void *overdraw_canvas, const void *rect1, const void *rect2, const void *paint); // (SkOverdrawCanvas *overdraw_canvas, const SkRRect *rect1, const SkRRect *rect2, const SkPaint *paint)
void SkOverdrawCanvas_onDrawRRect(void *overdraw_canvas, const void *rect, const void *paint); // (SkOverdrawCanvas *overdraw_canvas, const SkRRect *rect, const SkPaint *paint)
void SkOverdrawCanvas_onDrawPoints(void *overdraw_canvas, int mode, unsigned long size, const void * point, const void *paint); // (SkOverdrawCanvas *overdraw_canvas, SkOverdrawCanvas::PointMode mode, size_t size, const SkPoint point[], const SkPaint *paint)
void SkOverdrawCanvas_onDrawVerticesObject(void *overdraw_canvas, const void *vertices, int mode, const void *paint); // (SkOverdrawCanvas *overdraw_canvas, const SkVertices *vertices, SkBlendMode mode, const SkPaint *paint)
void SkOverdrawCanvas_onDrawPath(void *overdraw_canvas, const void *path, const void *paint); // (SkOverdrawCanvas *overdraw_canvas, const SkPath *path, const SkPaint *paint)
void SkOverdrawCanvas_onDrawImage2(void *overdraw_canvas, const void *image, float scalar1, float scalar2, const void *options, const void *paint); // (SkOverdrawCanvas *overdraw_canvas, const SkImage *image, SkScalar scalar1, SkScalar scalar2, const SkSamplingOptions *options, const SkPaint *paint)
void SkOverdrawCanvas_onDrawImageRect2(void *overdraw_canvas, const void *image, const void *rect1, const void *rect2, const void *options, const void *paint, int constraint); // (SkOverdrawCanvas *overdraw_canvas, const SkImage *image, const SkRect *rect1, const SkRect *rect2, const SkSamplingOptions *options, const SkPaint *paint, SkOverdrawCanvas::SrcRectConstraint constraint)
void SkOverdrawCanvas_onDrawImageLattice2(void *overdraw_canvas, const void *image, const void *lattice, const void *rect, int mode, const void *paint); // (SkOverdrawCanvas *overdraw_canvas, const SkImage *image, const SkOverdrawCanvas::Lattice *lattice, const SkRect *rect, SkFilterMode mode, const SkPaint *paint)
void SkOverdrawCanvas_onDrawAtlas2(void *overdraw_canvas, const void * image, const void * form, const void * rect1, const void * color, int v, int mode, const void *options, const void *rect2, const void *paint); // (SkOverdrawCanvas *overdraw_canvas, const SkImage *image, const SkRSXform form[], const SkRect rect1[], const SkColor color[], int v, SkBlendMode mode, const SkSamplingOptions *options, const SkRect *rect2, const SkPaint *paint)
void SkOverdrawCanvas_onDrawDrawable(void *overdraw_canvas, void *drawable, const void *matrix); // (SkOverdrawCanvas *overdraw_canvas, SkDrawable *drawable, const SkMatrix *matrix)
void SkOverdrawCanvas_onDrawPicture(void *overdraw_canvas, const void *picture, const void *matrix, const void *paint); // (SkOverdrawCanvas *overdraw_canvas, const SkPicture *picture, const SkMatrix *matrix, const SkPaint *paint)
void SkOverdrawCanvas_onDrawAnnotation(void *overdraw_canvas, const void *rect, const char key[], void *value); // (SkOverdrawCanvas *overdraw_canvas, const SkRect *rect, const char key[], SkData *value)
void SkOverdrawCanvas_onDrawShadowRec(void *overdraw_canvas, const void *path, const void *rec); // (SkOverdrawCanvas *overdraw_canvas, const SkPath *path, const SkDrawShadowRec *rec)
void SkOverdrawCanvas_onDrawEdgeAAQuad(void *overdraw_canvas, const void *rect, const void * point, int flags, const void *color, int mode); // (SkOverdrawCanvas *overdraw_canvas, const SkRect *rect, const SkPoint point[4], SkCanvas::QuadAAFlags flags, const SkColor4f *color, SkBlendMode mode)
void SkOverdrawCanvas_onDrawEdgeAAImageSet2(void *overdraw_canvas, const void * entry, int count, const void * point, const void * matrix, const void *options, const void *paint, int constraint); // (SkOverdrawCanvas *overdraw_canvas, const SkOverdrawCanvas::ImageSetEntry entry[], int count, const SkPoint point[], const SkMatrix matrix[], const SkSamplingOptions *options, const SkPaint *paint, SkOverdrawCanvas::SrcRectConstraint constraint)

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_OVERDRAW_CANVAS_H
