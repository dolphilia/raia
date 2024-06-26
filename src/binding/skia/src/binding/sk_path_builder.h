//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_PATH_BUILDER_H
#define RAIA_SKIA_SK_PATH_BUILDER_H

#include "include/core/SkPathBuilder.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_point.h"

extern "C" {
// SkPathBuilder & operator=(const SkPath &)
// SkPathBuilder & operator=(const SkPathBuilder &)
SkPathBuilder *SkPathBuilder_new();
SkPathBuilder *SkPathBuilder_new_2(SkPathFillType type);
SkPathBuilder *SkPathBuilder_new_3(const SkPath *path);
SkPathBuilder *SkPathBuilder_new_4(const SkPathBuilder *builder);
void SkPathBuilder_delete(SkPathBuilder *path_builder);
SkPathFillType SkPathBuilder_fillType(SkPathBuilder *path_builder);
sk_rect_t SkPathBuilder_computeBounds(SkPathBuilder *path_builder);
sk_path_t SkPathBuilder_snapshot(SkPathBuilder *path_builder);
sk_path_t SkPathBuilder_detach(SkPathBuilder *path_builder);
SkPathBuilder * SkPathBuilder_setFillType(SkPathBuilder *path_builder, SkPathFillType ft);
SkPathBuilder * SkPathBuilder_setIsVolatile(SkPathBuilder *path_builder, bool isVolatile);
SkPathBuilder * SkPathBuilder_reset(SkPathBuilder *path_builder);
SkPathBuilder * SkPathBuilder_moveTo(SkPathBuilder *path_builder, sk_point_t pt);
SkPathBuilder * SkPathBuilder_moveTo_2(SkPathBuilder *path_builder, SkScalar x, SkScalar y);
SkPathBuilder * SkPathBuilder_lineTo(SkPathBuilder *path_builder, sk_point_t pt);
SkPathBuilder * SkPathBuilder_lineTo_2(SkPathBuilder *path_builder, SkScalar x, SkScalar y);
SkPathBuilder * SkPathBuilder_quadTo(SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2);
SkPathBuilder * SkPathBuilder_quadTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2);
SkPathBuilder * SkPathBuilder_quadTo_3(SkPathBuilder *path_builder, const SkPoint pts[2]);
SkPathBuilder * SkPathBuilder_conicTo(SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2, SkScalar w);
SkPathBuilder * SkPathBuilder_conicTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w);
SkPathBuilder * SkPathBuilder_conicTo_3(SkPathBuilder *path_builder, const SkPoint pts[2], SkScalar w);
SkPathBuilder * SkPathBuilder_cubicTo(SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2, sk_point_t pt3);
SkPathBuilder * SkPathBuilder_cubicTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3);
SkPathBuilder * SkPathBuilder_cubicTo_3(SkPathBuilder *path_builder, const SkPoint pts[3]);
SkPathBuilder * SkPathBuilder_close(SkPathBuilder *path_builder);
SkPathBuilder * SkPathBuilder_polylineTo(SkPathBuilder *path_builder, const SkPoint pts[], int count);
SkPathBuilder * SkPathBuilder_polylineTo_2(SkPathBuilder *path_builder, const std::initializer_list<SkPoint> *list);
SkPathBuilder * SkPathBuilder_rLineTo(SkPathBuilder *path_builder, sk_point_t pt);
SkPathBuilder * SkPathBuilder_rLineTo_2(SkPathBuilder *path_builder, SkScalar x, SkScalar y);
SkPathBuilder * SkPathBuilder_rQuadTo(SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2);
SkPathBuilder * SkPathBuilder_rQuadTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2);
SkPathBuilder * SkPathBuilder_rConicTo(SkPathBuilder *path_builder, sk_point_t p1, sk_point_t p2, SkScalar w);
SkPathBuilder * SkPathBuilder_rConicTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w);
SkPathBuilder * SkPathBuilder_rCubicTo(SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2, sk_point_t pt3);
SkPathBuilder * SkPathBuilder_rCubicTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3);
SkPathBuilder * SkPathBuilder_arcTo(SkPathBuilder *path_builder, const SkRect *oval, SkScalar startAngleDeg, SkScalar sweepAngleDeg, bool forceMoveTo);
SkPathBuilder * SkPathBuilder_arcTo_2(SkPathBuilder *path_builder, sk_point_t p1, sk_point_t p2, SkScalar radius);
SkPathBuilder * SkPathBuilder_arcTo_3(SkPathBuilder *path_builder, sk_point_t r, SkScalar xAxisRotate, SkPathBuilder::ArcSize largeArc, SkPathDirection sweep, sk_point_t xy);
SkPathBuilder * SkPathBuilder_addArc(SkPathBuilder *path_builder, const SkRect *oval, SkScalar startAngleDeg, SkScalar sweepAngleDeg);
SkPathBuilder * SkPathBuilder_addRect(SkPathBuilder *path_builder, const SkRect *rect, SkPathDirection dir, unsigned startIndex);
SkPathBuilder * SkPathBuilder_addRect_2(SkPathBuilder *path_builder, const SkRect *rect, SkPathDirection dir);
SkPathBuilder * SkPathBuilder_addOval(SkPathBuilder *path_builder, const SkRect *rect, SkPathDirection dir, unsigned startIndex);
SkPathBuilder * SkPathBuilder_addOval_2(SkPathBuilder *path_builder, const SkRect *rect, SkPathDirection dir);
SkPathBuilder * SkPathBuilder_addRRect(SkPathBuilder *path_builder, const SkRRect *rect, SkPathDirection dir, unsigned startIndex);
SkPathBuilder * SkPathBuilder_addRRect_2(SkPathBuilder *path_builder, const SkRRect *rrect, SkPathDirection dir);
SkPathBuilder * SkPathBuilder_addCircle(SkPathBuilder *path_builder, SkScalar center_x, SkScalar center_y, SkScalar radius, SkPathDirection dir);
SkPathBuilder * SkPathBuilder_addPolygon(SkPathBuilder *path_builder, const SkPoint pts[], int count, bool isClosed);
SkPathBuilder * SkPathBuilder_addPolygon_2(SkPathBuilder *path_builder, const std::initializer_list<SkPoint> *list, bool isClosed);
SkPathBuilder * SkPathBuilder_addPath(SkPathBuilder *path_builder, const SkPath *path);
void SkPathBuilder_incReserve(SkPathBuilder *path_builder, int extraPtCount, int extraVerbCount);
void SkPathBuilder_incReserve_2(SkPathBuilder *path_builder, int extraPtCount);
SkPathBuilder * SkPathBuilder_offset(SkPathBuilder *path_builder, SkScalar dx, SkScalar dy);
SkPathBuilder * SkPathBuilder_toggleInverseFillType(SkPathBuilder *path_builder);
}

#endif //RAIA_SKIA_SK_PATH_BUILDER_H
