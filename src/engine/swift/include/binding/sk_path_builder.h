//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_PATH_BUILDER_H
#define RAIA_SKIA_SK_PATH_BUILDER_H

#include "include/core/SkPathBuilder.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_point.h"
#include "export_api.h"

extern "C" {
// SkPathBuilder & operator=(const SkPath &)
// SkPathBuilder & operator=(const SkPathBuilder &)
RAIA_API SkPathBuilder *SkPathBuilder_new();
RAIA_API SkPathBuilder *SkPathBuilder_new_2(SkPathFillType type);
RAIA_API SkPathBuilder *SkPathBuilder_new_3(const SkPath *path);
RAIA_API SkPathBuilder *SkPathBuilder_new_4(const SkPathBuilder *builder);
RAIA_API void SkPathBuilder_delete(SkPathBuilder *path_builder);
RAIA_API SkPathFillType SkPathBuilder_fillType(SkPathBuilder *path_builder);
RAIA_API sk_rect_t SkPathBuilder_computeBounds(SkPathBuilder *path_builder);
RAIA_API sk_path_t SkPathBuilder_snapshot(SkPathBuilder *path_builder);
RAIA_API sk_path_t SkPathBuilder_detach(SkPathBuilder *path_builder);
RAIA_API SkPathBuilder * SkPathBuilder_setFillType(SkPathBuilder *path_builder, SkPathFillType ft);
RAIA_API SkPathBuilder * SkPathBuilder_setIsVolatile(SkPathBuilder *path_builder, bool isVolatile);
RAIA_API SkPathBuilder * SkPathBuilder_reset(SkPathBuilder *path_builder);
RAIA_API SkPathBuilder * SkPathBuilder_moveTo(SkPathBuilder *path_builder, sk_point_t pt);
RAIA_API SkPathBuilder * SkPathBuilder_moveTo_2(SkPathBuilder *path_builder, SkScalar x, SkScalar y);
RAIA_API SkPathBuilder * SkPathBuilder_lineTo(SkPathBuilder *path_builder, sk_point_t pt);
RAIA_API SkPathBuilder * SkPathBuilder_lineTo_2(SkPathBuilder *path_builder, SkScalar x, SkScalar y);
RAIA_API SkPathBuilder * SkPathBuilder_quadTo(SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2);
RAIA_API SkPathBuilder * SkPathBuilder_quadTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2);
RAIA_API SkPathBuilder * SkPathBuilder_quadTo_3(SkPathBuilder *path_builder, const SkPoint pts[2]);
RAIA_API SkPathBuilder * SkPathBuilder_conicTo(SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2, SkScalar w);
RAIA_API SkPathBuilder * SkPathBuilder_conicTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w);
RAIA_API SkPathBuilder * SkPathBuilder_conicTo_3(SkPathBuilder *path_builder, const SkPoint pts[2], SkScalar w);
RAIA_API SkPathBuilder * SkPathBuilder_cubicTo(SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2, sk_point_t pt3);
RAIA_API SkPathBuilder * SkPathBuilder_cubicTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3);
RAIA_API SkPathBuilder * SkPathBuilder_cubicTo_3(SkPathBuilder *path_builder, const SkPoint pts[3]);
RAIA_API SkPathBuilder * SkPathBuilder_close(SkPathBuilder *path_builder);
RAIA_API SkPathBuilder * SkPathBuilder_polylineTo(SkPathBuilder *path_builder, const SkPoint pts[], int count);
RAIA_API SkPathBuilder * SkPathBuilder_polylineTo_2(SkPathBuilder *path_builder, const std::initializer_list<SkPoint> *list);
RAIA_API SkPathBuilder * SkPathBuilder_rLineTo(SkPathBuilder *path_builder, sk_point_t pt);
RAIA_API SkPathBuilder * SkPathBuilder_rLineTo_2(SkPathBuilder *path_builder, SkScalar x, SkScalar y);
RAIA_API SkPathBuilder * SkPathBuilder_rQuadTo(SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2);
RAIA_API SkPathBuilder * SkPathBuilder_rQuadTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2);
RAIA_API SkPathBuilder * SkPathBuilder_rConicTo(SkPathBuilder *path_builder, sk_point_t p1, sk_point_t p2, SkScalar w);
RAIA_API SkPathBuilder * SkPathBuilder_rConicTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w);
RAIA_API SkPathBuilder * SkPathBuilder_rCubicTo(SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2, sk_point_t pt3);
RAIA_API SkPathBuilder * SkPathBuilder_rCubicTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3);
RAIA_API SkPathBuilder * SkPathBuilder_arcTo(SkPathBuilder *path_builder, const SkRect *oval, SkScalar startAngleDeg, SkScalar sweepAngleDeg, bool forceMoveTo);
RAIA_API SkPathBuilder * SkPathBuilder_arcTo_2(SkPathBuilder *path_builder, sk_point_t p1, sk_point_t p2, SkScalar radius);
RAIA_API SkPathBuilder * SkPathBuilder_arcTo_3(SkPathBuilder *path_builder, sk_point_t r, SkScalar xAxisRotate, SkPathBuilder::ArcSize largeArc, SkPathDirection sweep, sk_point_t xy);
RAIA_API SkPathBuilder * SkPathBuilder_addArc(SkPathBuilder *path_builder, const SkRect *oval, SkScalar startAngleDeg, SkScalar sweepAngleDeg);
RAIA_API SkPathBuilder * SkPathBuilder_addRect(SkPathBuilder *path_builder, const SkRect *rect, SkPathDirection dir, unsigned startIndex);
RAIA_API SkPathBuilder * SkPathBuilder_addRect_2(SkPathBuilder *path_builder, const SkRect *rect, SkPathDirection dir);
RAIA_API SkPathBuilder * SkPathBuilder_addOval(SkPathBuilder *path_builder, const SkRect *rect, SkPathDirection dir, unsigned startIndex);
RAIA_API SkPathBuilder * SkPathBuilder_addOval_2(SkPathBuilder *path_builder, const SkRect *rect, SkPathDirection dir);
RAIA_API SkPathBuilder * SkPathBuilder_addRRect(SkPathBuilder *path_builder, const SkRRect *rect, SkPathDirection dir, unsigned startIndex);
RAIA_API SkPathBuilder * SkPathBuilder_addRRect_2(SkPathBuilder *path_builder, const SkRRect *rrect, SkPathDirection dir);
RAIA_API SkPathBuilder * SkPathBuilder_addCircle(SkPathBuilder *path_builder, SkScalar center_x, SkScalar center_y, SkScalar radius, SkPathDirection dir);
RAIA_API SkPathBuilder * SkPathBuilder_addPolygon(SkPathBuilder *path_builder, const SkPoint pts[], int count, bool isClosed);
RAIA_API SkPathBuilder * SkPathBuilder_addPolygon_2(SkPathBuilder *path_builder, const std::initializer_list<SkPoint> *list, bool isClosed);
RAIA_API SkPathBuilder * SkPathBuilder_addPath(SkPathBuilder *path_builder, const SkPath *path);
RAIA_API void SkPathBuilder_incReserve(SkPathBuilder *path_builder, int extraPtCount, int extraVerbCount);
RAIA_API void SkPathBuilder_incReserve_2(SkPathBuilder *path_builder, int extraPtCount);
RAIA_API SkPathBuilder * SkPathBuilder_offset(SkPathBuilder *path_builder, SkScalar dx, SkScalar dy);
RAIA_API SkPathBuilder * SkPathBuilder_toggleInverseFillType(SkPathBuilder *path_builder);
}

#endif //RAIA_SKIA_SK_PATH_BUILDER_H
