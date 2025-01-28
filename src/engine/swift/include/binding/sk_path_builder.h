//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_PATH_BUILDER_H
#define RAIA_SKIA_SK_PATH_BUILDER_H

#ifdef __cplusplus
extern "C" {
#endif

// SkPathBuilder & operator=(const SkPath &)
// SkPathBuilder & operator=(const SkPathBuilder &)

void *SkPathBuilder_new(); // () -> SkPathBuilder *
void *SkPathBuilder_new_2(int type); // (SkPathFillType type) -> SkPathBuilder *
void *SkPathBuilder_new_3(const void *path); // (const SkPath *path) -> SkPathBuilder *
void *SkPathBuilder_new_4(const void *builder); // (const SkPathBuilder *builder) -> SkPathBuilder *
void SkPathBuilder_delete(void *path_builder); // (SkPathBuilder *path_builder)
int SkPathBuilder_fillType(void *path_builder); // (SkPathBuilder *path_builder) -> SkPathFillType
int SkPathBuilder_computeBounds(void *path_builder); // (SkPathBuilder *path_builder) -> sk_rect_t
int SkPathBuilder_snapshot(void *path_builder); // (SkPathBuilder *path_builder) -> sk_path_t
int SkPathBuilder_detach(void *path_builder); // (SkPathBuilder *path_builder) -> sk_path_t
void *SkPathBuilder_setFillType(void *path_builder, int ft); // (SkPathBuilder *path_builder, SkPathFillType ft) -> SkPathBuilder *
void *SkPathBuilder_setIsVolatile(void *path_builder, bool isVolatile); // (SkPathBuilder *path_builder, bool isVolatile) -> SkPathBuilder *
void *SkPathBuilder_reset(void *path_builder); // (SkPathBuilder *path_builder) -> SkPathBuilder *
void *SkPathBuilder_moveTo(void *path_builder, int pt); // (SkPathBuilder *path_builder, sk_point_t pt) -> SkPathBuilder *
void *SkPathBuilder_moveTo_2(void *path_builder, float x, float y); // (SkPathBuilder *path_builder, SkScalar x, SkScalar y) -> SkPathBuilder *
void *SkPathBuilder_lineTo(void *path_builder, int pt); // (SkPathBuilder *path_builder, sk_point_t pt) -> SkPathBuilder *
void *SkPathBuilder_lineTo_2(void *path_builder, float x, float y); // (SkPathBuilder *path_builder, SkScalar x, SkScalar y) -> SkPathBuilder *
void *SkPathBuilder_quadTo(void *path_builder, int pt1, int pt2); // (SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2) -> SkPathBuilder *
void *SkPathBuilder_quadTo_2(void *path_builder, float x1, float y1, float x2, float y2); // (SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2) -> SkPathBuilder *
void *SkPathBuilder_quadTo_3(void *path_builder, const void * pts); // (SkPathBuilder *path_builder, const SkPoint pts[2]) -> SkPathBuilder *
void *SkPathBuilder_conicTo(void *path_builder, int pt1, int pt2, float w); // (SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2, SkScalar w) -> SkPathBuilder *
void *SkPathBuilder_conicTo_2(void *path_builder, float x1, float y1, float x2, float y2, float w); // (SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w) -> SkPathBuilder *
void *SkPathBuilder_conicTo_3(void *path_builder, const void * pts, float w); // (SkPathBuilder *path_builder, const SkPoint pts[2], SkScalar w) -> SkPathBuilder *
void *SkPathBuilder_cubicTo(void *path_builder, int pt1, int pt2, int pt3); // (SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2, sk_point_t pt3) -> SkPathBuilder *
void *SkPathBuilder_cubicTo_2(void *path_builder, float x1, float y1, float x2, float y2, float x3, float y3); // (SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3) -> SkPathBuilder *
void *SkPathBuilder_cubicTo_3(void *path_builder, const void * pts); // (SkPathBuilder *path_builder, const SkPoint pts[3]) -> SkPathBuilder *
void *SkPathBuilder_close(void *path_builder); // (SkPathBuilder *path_builder) -> SkPathBuilder *
void *SkPathBuilder_polylineTo(void *path_builder, const void * pts, int count); // (SkPathBuilder *path_builder, const SkPoint pts[], int count) -> SkPathBuilder *
void *SkPathBuilder_polylineTo_2(void *path_builder, const void *list); // (SkPathBuilder *path_builder, const std::initializer_list<SkPoint> *list) -> SkPathBuilder *
void *SkPathBuilder_rLineTo(void *path_builder, int pt); // (SkPathBuilder *path_builder, sk_point_t pt) -> SkPathBuilder *
void *SkPathBuilder_rLineTo_2(void *path_builder, float x, float y); // (SkPathBuilder *path_builder, SkScalar x, SkScalar y) -> SkPathBuilder *
void *SkPathBuilder_rQuadTo(void *path_builder, int pt1, int pt2); // (SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2) -> SkPathBuilder *
void *SkPathBuilder_rQuadTo_2(void *path_builder, float x1, float y1, float x2, float y2); // (SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2) -> SkPathBuilder *
void *SkPathBuilder_rConicTo(void *path_builder, int p1, int p2, float w); // (SkPathBuilder *path_builder, sk_point_t p1, sk_point_t p2, SkScalar w) -> SkPathBuilder *
void *SkPathBuilder_rConicTo_2(void *path_builder, float x1, float y1, float x2, float y2, float w); // (SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w) -> SkPathBuilder *
void *SkPathBuilder_rCubicTo(void *path_builder, int pt1, int pt2, int pt3); // (SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2, sk_point_t pt3) -> SkPathBuilder *
void *SkPathBuilder_rCubicTo_2(void *path_builder, float x1, float y1, float x2, float y2, float x3, float y3); // (SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3) -> SkPathBuilder *
void *SkPathBuilder_arcTo(void *path_builder, const void *oval, float startAngleDeg, float sweepAngleDeg, bool forceMoveTo); // (SkPathBuilder *path_builder, const SkRect *oval, SkScalar startAngleDeg, SkScalar sweepAngleDeg, bool forceMoveTo) -> SkPathBuilder *
void *SkPathBuilder_arcTo_2(void *path_builder, int p1, int p2, float radius); // (SkPathBuilder *path_builder, sk_point_t p1, sk_point_t p2, SkScalar radius) -> SkPathBuilder *
void *SkPathBuilder_arcTo_3(void *path_builder, int r, float xAxisRotate, int largeArc, int sweep, int xy); // (SkPathBuilder *path_builder, sk_point_t r, SkScalar xAxisRotate, SkPathBuilder::ArcSize largeArc, SkPathDirection sweep, sk_point_t xy) -> SkPathBuilder *
void *SkPathBuilder_addArc(void *path_builder, const void *oval, float startAngleDeg, float sweepAngleDeg); // (SkPathBuilder *path_builder, const SkRect *oval, SkScalar startAngleDeg, SkScalar sweepAngleDeg) -> SkPathBuilder *
void *SkPathBuilder_addRect(void *path_builder, const void *rect, int dir, unsigned startIndex); // (SkPathBuilder *path_builder, const SkRect *rect, SkPathDirection dir, unsigned startIndex) -> SkPathBuilder *
void *SkPathBuilder_addRect_2(void *path_builder, const void *rect, int dir); // (SkPathBuilder *path_builder, const SkRect *rect, SkPathDirection dir) -> SkPathBuilder *
void *SkPathBuilder_addOval(void *path_builder, const void *rect, int dir, unsigned startIndex); // (SkPathBuilder *path_builder, const SkRect *rect, SkPathDirection dir, unsigned startIndex) -> SkPathBuilder *
void *SkPathBuilder_addOval_2(void *path_builder, const void *rect, int dir); // (SkPathBuilder *path_builder, const SkRect *rect, SkPathDirection dir) -> SkPathBuilder *
void *SkPathBuilder_addRRect(void *path_builder, const void *rect, int dir, unsigned startIndex); // (SkPathBuilder *path_builder, const SkRRect *rect, SkPathDirection dir, unsigned startIndex) -> SkPathBuilder *
void *SkPathBuilder_addRRect_2(void *path_builder, const void *rrect, int dir); // (SkPathBuilder *path_builder, const SkRRect *rrect, SkPathDirection dir) -> SkPathBuilder *
void *SkPathBuilder_addCircle(void *path_builder, float center_x, float center_y, float radius, int dir); // (SkPathBuilder *path_builder, SkScalar center_x, SkScalar center_y, SkScalar radius, SkPathDirection dir) -> SkPathBuilder *
void *SkPathBuilder_addPolygon(void *path_builder, const void * pts, int count, bool isClosed); // (SkPathBuilder *path_builder, const SkPoint pts[], int count, bool isClosed) -> SkPathBuilder *
void *SkPathBuilder_addPolygon_2(void *path_builder, const void *list, bool isClosed); // (SkPathBuilder *path_builder, const std::initializer_list<SkPoint> *list, bool isClosed) -> SkPathBuilder *
void *SkPathBuilder_addPath(void *path_builder, const void *path); // (SkPathBuilder *path_builder, const SkPath *path) -> SkPathBuilder *
void SkPathBuilder_incReserve(void *path_builder, int extraPtCount, int extraVerbCount); // (SkPathBuilder *path_builder, int extraPtCount, int extraVerbCount)
void SkPathBuilder_incReserve_2(void *path_builder, int extraPtCount); // (SkPathBuilder *path_builder, int extraPtCount)
void *SkPathBuilder_offset(void *path_builder, float dx, float dy); // (SkPathBuilder *path_builder, SkScalar dx, SkScalar dy) -> SkPathBuilder *
void *SkPathBuilder_toggleInverseFillType(void *path_builder); // (SkPathBuilder *path_builder) -> SkPathBuilder *

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_PATH_BUILDER_H
