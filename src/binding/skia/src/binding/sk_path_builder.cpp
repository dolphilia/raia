//
// Created by dolphilia on 2024/01/09.
//

#include "sk_path_builder.h"

extern "C" {

// SkPathBuilder & operator=(const SkPath &)
// SkPathBuilder & operator=(const SkPathBuilder &)

SkPathBuilder *SkPathBuilder_new() {
    return new SkPathBuilder();
}

SkPathBuilder *SkPathBuilder_new_2(SkPathFillType type) {
    return new SkPathBuilder(type);
}

SkPathBuilder *SkPathBuilder_new_3(const SkPath *path) {
    return new SkPathBuilder(*path);
}

SkPathBuilder *SkPathBuilder_new_4(const SkPathBuilder *builder) {
    return new SkPathBuilder(*builder);
}

void SkPathBuilder_delete(SkPathBuilder *path_builder) {
    delete path_builder;
}

SkPathFillType SkPathBuilder_fillType(SkPathBuilder *path_builder) {
    return path_builder->fillType();
}

sk_rect_t SkPathBuilder_computeBounds(SkPathBuilder *path_builder) {
    return static_sk_rect_make(path_builder->computeBounds());
}

sk_path_t SkPathBuilder_snapshot(SkPathBuilder *path_builder) {
    return static_sk_path_make(path_builder->snapshot());
}

sk_path_t SkPathBuilder_detach(SkPathBuilder *path_builder) {
    return static_sk_path_make(path_builder->detach());
}

SkPathBuilder * SkPathBuilder_setFillType(SkPathBuilder *path_builder, SkPathFillType ft) {
    return &path_builder->setFillType(ft);
}

SkPathBuilder * SkPathBuilder_setIsVolatile(SkPathBuilder *path_builder, bool isVolatile) {
    return &path_builder->setIsVolatile(isVolatile);
}

SkPathBuilder * SkPathBuilder_reset(SkPathBuilder *path_builder) {
    return &path_builder->reset();
}

SkPathBuilder * SkPathBuilder_moveTo(SkPathBuilder *path_builder, sk_point_t pt) {
    return &path_builder->moveTo(static_sk_point_get(pt));
}

SkPathBuilder * SkPathBuilder_moveTo_2(SkPathBuilder *path_builder, SkScalar x, SkScalar y) {
    return &path_builder->moveTo(x, y);
}

SkPathBuilder * SkPathBuilder_lineTo(SkPathBuilder *path_builder, sk_point_t pt) {
    return &path_builder->lineTo(static_sk_point_get(pt));
}

SkPathBuilder * SkPathBuilder_lineTo_2(SkPathBuilder *path_builder, SkScalar x, SkScalar y) {
    return &path_builder->lineTo(x, y);
}

SkPathBuilder * SkPathBuilder_quadTo(SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2) {
    return &path_builder->quadTo(static_sk_point_get(pt1), static_sk_point_get(pt2));
}

SkPathBuilder * SkPathBuilder_quadTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2) {
    return &path_builder->quadTo(x1, y1, x2, y2);
}

SkPathBuilder * SkPathBuilder_quadTo_3(SkPathBuilder *path_builder, const SkPoint pts[2]) {
    return &path_builder->quadTo(pts);
}

SkPathBuilder * SkPathBuilder_conicTo(SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2, SkScalar w) {
    return &path_builder->conicTo(static_sk_point_get(pt1), static_sk_point_get(pt2), w);
}

SkPathBuilder * SkPathBuilder_conicTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w) {
    return &path_builder->conicTo(x1, y1, x2, y2, w);
}

SkPathBuilder * SkPathBuilder_conicTo_3(SkPathBuilder *path_builder, const SkPoint pts[2], SkScalar w) {
    return &path_builder->conicTo(pts, w);
}

SkPathBuilder * SkPathBuilder_cubicTo(SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2, sk_point_t pt3) {
    return &path_builder->cubicTo(static_sk_point_get(pt1), static_sk_point_get(pt2), static_sk_point_get(pt3));
}

SkPathBuilder * SkPathBuilder_cubicTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3) {
    return &path_builder->cubicTo(x1, y1, x2, y2, x3, y3);
}

SkPathBuilder * SkPathBuilder_cubicTo_3(SkPathBuilder *path_builder, const SkPoint pts[3]) {
    return &path_builder->cubicTo(pts);
}

SkPathBuilder * SkPathBuilder_close(SkPathBuilder *path_builder) {
    return &path_builder->close();
}

SkPathBuilder * SkPathBuilder_polylineTo(SkPathBuilder *path_builder, const SkPoint pts[], int count) {
    return &path_builder->polylineTo(pts, count);
}

SkPathBuilder * SkPathBuilder_polylineTo_2(SkPathBuilder *path_builder, const std::initializer_list<SkPoint> *list) {
    return &path_builder->polylineTo(*list);
}

SkPathBuilder * SkPathBuilder_rLineTo(SkPathBuilder *path_builder, sk_point_t pt) {
    return &path_builder->rLineTo(static_sk_point_get(pt));
}

SkPathBuilder * SkPathBuilder_rLineTo_2(SkPathBuilder *path_builder, SkScalar x, SkScalar y) {
    return &path_builder->rLineTo(x, y);
}

SkPathBuilder * SkPathBuilder_rQuadTo(SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2) {
    return &path_builder->rQuadTo(static_sk_point_get(pt1), static_sk_point_get(pt2));
}

SkPathBuilder * SkPathBuilder_rQuadTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2) {
    return &path_builder->rQuadTo(x1, y1, x2, y2);
}

SkPathBuilder * SkPathBuilder_rConicTo(SkPathBuilder *path_builder, sk_point_t p1, sk_point_t p2, SkScalar w) {
    return &path_builder->rConicTo(static_sk_point_get(p1), static_sk_point_get(p2), w);
}

SkPathBuilder * SkPathBuilder_rConicTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w) {
    return &path_builder->rConicTo(x1, y1, x2, y2, w);
}

SkPathBuilder * SkPathBuilder_rCubicTo(SkPathBuilder *path_builder, sk_point_t pt1, sk_point_t pt2, sk_point_t pt3) {
    return &path_builder->rCubicTo(static_sk_point_get(pt1), static_sk_point_get(pt2), static_sk_point_get(pt3));
}

SkPathBuilder * SkPathBuilder_rCubicTo_2(SkPathBuilder *path_builder, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3) {
    return &path_builder->rCubicTo(x1, y1, x2, y2, x3, y3);
}

SkPathBuilder * SkPathBuilder_arcTo(SkPathBuilder *path_builder, const SkRect *oval, SkScalar startAngleDeg, SkScalar sweepAngleDeg, bool forceMoveTo) {
    return &path_builder->arcTo(*oval, startAngleDeg, sweepAngleDeg, forceMoveTo);
}

SkPathBuilder * SkPathBuilder_arcTo_2(SkPathBuilder *path_builder, sk_point_t p1, sk_point_t p2, SkScalar radius) {
    return &path_builder->arcTo(static_sk_point_get(p1), static_sk_point_get(p2), radius);
}

SkPathBuilder * SkPathBuilder_arcTo_3(SkPathBuilder *path_builder, sk_point_t r, SkScalar xAxisRotate, SkPathBuilder::ArcSize largeArc, SkPathDirection sweep, sk_point_t xy) {
    return &path_builder->arcTo(static_sk_point_get(r), xAxisRotate, largeArc, sweep, static_sk_point_get(xy));
}

SkPathBuilder * SkPathBuilder_addArc(SkPathBuilder *path_builder, const SkRect *oval, SkScalar startAngleDeg, SkScalar sweepAngleDeg) {
    return &path_builder->addArc(*oval, startAngleDeg, sweepAngleDeg);
}

SkPathBuilder * SkPathBuilder_addRect(SkPathBuilder *path_builder, const SkRect *rect, SkPathDirection dir, unsigned startIndex) {
    return &path_builder->addRect(*rect, dir, startIndex);
}

SkPathBuilder * SkPathBuilder_addRect_2(SkPathBuilder *path_builder, const SkRect *rect, SkPathDirection dir) {
    return &path_builder->addRect(*rect, dir);
}

SkPathBuilder * SkPathBuilder_addOval(SkPathBuilder *path_builder, const SkRect *rect, SkPathDirection dir, unsigned startIndex) {
    return &path_builder->addOval(*rect, dir, startIndex);
}

SkPathBuilder * SkPathBuilder_addOval_2(SkPathBuilder *path_builder, const SkRect *rect, SkPathDirection dir) {
    return &path_builder->addOval(*rect, dir);
}

SkPathBuilder * SkPathBuilder_addRRect(SkPathBuilder *path_builder, const SkRRect *rect, SkPathDirection dir, unsigned startIndex) {
    return &path_builder->addRRect(*rect, dir, startIndex);
}

SkPathBuilder * SkPathBuilder_addRRect_2(SkPathBuilder *path_builder, const SkRRect *rrect, SkPathDirection dir) {
    return &path_builder->addRRect(*rrect, dir);
}

SkPathBuilder * SkPathBuilder_addCircle(SkPathBuilder *path_builder, SkScalar center_x, SkScalar center_y, SkScalar radius, SkPathDirection dir) {
    return &path_builder->addCircle(center_x, center_y, radius, dir);
}

SkPathBuilder * SkPathBuilder_addPolygon(SkPathBuilder *path_builder, const SkPoint pts[], int count, bool isClosed) {
    return &path_builder->addPolygon(pts, count, isClosed);
}

SkPathBuilder * SkPathBuilder_addPolygon_2(SkPathBuilder *path_builder, const std::initializer_list<SkPoint> *list, bool isClosed) {
    return &path_builder->addPolygon(*list, isClosed);
}

SkPathBuilder * SkPathBuilder_addPath(SkPathBuilder *path_builder, const SkPath *path) {
    return &path_builder->addPath(*path);
}

void SkPathBuilder_incReserve(SkPathBuilder *path_builder, int extraPtCount, int extraVerbCount) {
    path_builder->incReserve(extraPtCount, extraVerbCount);
}

void SkPathBuilder_incReserve_2(SkPathBuilder *path_builder, int extraPtCount) {
    path_builder->incReserve(extraPtCount);
}

SkPathBuilder * SkPathBuilder_offset(SkPathBuilder *path_builder, SkScalar dx, SkScalar dy) {
    return &path_builder->offset(dx, dy);
}

SkPathBuilder * SkPathBuilder_toggleInverseFillType(SkPathBuilder *path_builder) {
    return &path_builder->toggleInverseFillType();
}

}