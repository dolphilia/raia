//
// Created by dolphilia on 2024/01/09.
//

#include "sk_path.h"

extern "C" {

//SkPath & operator=(const SkPath &path)

SkPath *SkPath_new() {
    return new SkPath();
}

SkPath *SkPath_new_2(const SkPath *path) {
    return new SkPath(*path);
}

void SkPath_delete(SkPath *path) {
    delete path;
}

bool SkPath_isInterpolatable(SkPath *path, const SkPath *compare) {
    return path->isInterpolatable(*compare);
}

bool SkPath_interpolate(SkPath *path, const SkPath *ending, SkScalar weight, SkPath *out) {
    return path->interpolate(*ending, weight, out);
}

SkPathFillType SkPath_getFillType(SkPath *path) {
    return path->getFillType();
}

void SkPath_setFillType(SkPath *path, SkPathFillType ft) {
    path->setFillType(ft);
}

bool SkPath_isInverseFillType(SkPath *path) {
    return path->isInverseFillType();
}

void SkPath_toggleInverseFillType(SkPath *path) {
    path->toggleInverseFillType();
}

bool SkPath_isConvex(SkPath *path) {
    return path->isConvex();
}

bool SkPath_isOval(SkPath *path, SkRect *bounds) {
    return path->isOval(bounds);
}

bool SkPath_isRRect(SkPath *path, SkRRect *rrect) {
    return path->isRRect(rrect);
}

SkPath * SkPath_reset(SkPath *path) {
    return &path->reset();
}

SkPath * SkPath_rewind(SkPath *path) {
    return &path->rewind();
}

bool SkPath_isEmpty(SkPath *path) {
    return path->isEmpty();
}

bool SkPath_isLastContourClosed(SkPath *path) {
    return path->isLastContourClosed();
}

bool SkPath_isFinite(SkPath *path) {
    return path->isFinite();
}

bool SkPath_isVolatile(SkPath *path) {
    return path->isVolatile();
}

SkPath * SkPath_setIsVolatile(SkPath *path, bool isVolatile) {
    return &path->setIsVolatile(isVolatile);
}

bool SkPath_isLine(SkPath *path, SkPoint line[2]) {
    return path->isLine(line);
}

int SkPath_countPoints(SkPath *path) {
    return path->countPoints();
}

sk_point_t SkPath_getPoint(SkPath *path, int index) {
    return static_sk_point_make(path->getPoint(index));
}

int SkPath_getPoints(SkPath *path, SkPoint points[], int max) {
    return path->getPoints(points, max);
}

int SkPath_countVerbs(SkPath *path) {
    return path->countVerbs();
}

int SkPath_getVerbs(SkPath *path, uint8_t verbs[], int max) {
    return path->getVerbs(verbs, max);
}

size_t SkPath_approximateBytesUsed(SkPath *path) {
    return path->approximateBytesUsed();
}

void SkPath_swap(SkPath *path, SkPath *other) {
    path->swap(*other);
}

const SkRect * SkPath_getBounds(SkPath *path) {
    return &path->getBounds();
}

void SkPath_updateBoundsCache(SkPath *path) {
    path->updateBoundsCache();
}

sk_rect_t SkPath_computeTightBounds(SkPath *path) {
    return static_sk_rect_make(path->computeTightBounds());
}

bool SkPath_conservativelyContainsRect(SkPath *path, const SkRect *rect) {
    return path->conservativelyContainsRect(*rect);
}

void SkPath_incReserve(SkPath *path, int extraPtCount) {
    path->incReserve(extraPtCount);
}

SkPath * SkPath_moveTo(SkPath *path, SkScalar x, SkScalar y) {
    return &path->moveTo(x, y);
}

SkPath * SkPath_moveTo_2(SkPath *path, const SkPoint *p) {
    return &path->moveTo(*p);
}

SkPath * SkPath_rMoveTo(SkPath *path, SkScalar dx, SkScalar dy) {
    return &path->rMoveTo(dx, dy);
}

SkPath * SkPath_lineTo(SkPath *path, SkScalar x, SkScalar y) {
    return &path->lineTo(x, y);
}

SkPath * SkPath_lineTo_2(SkPath *path, const SkPoint *p) {
    return &path->lineTo(*p);
}

SkPath * SkPath_rLineTo(SkPath *path, SkScalar dx, SkScalar dy) {
    return &path->rLineTo(dx, dy);
}

SkPath * SkPath_quadTo(SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2) {
    return &path->quadTo(x1, y1, x2, y2);
}

SkPath * SkPath_quadTo_2(SkPath *path, const SkPoint *p1, const SkPoint *p2) {
    return &path->quadTo(*p1, *p2);
}

SkPath * SkPath_rQuadTo(SkPath *path, SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2) {
    return &path->rQuadTo(dx1, dy1, dx2, dy2);
}

SkPath * SkPath_conicTo(SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w) {
    return &path->conicTo(x1, y1, x2, y2, w);
}

SkPath * SkPath_conicTo_2(SkPath *path, const SkPoint *p1, const SkPoint *p2, SkScalar w) {
    return &path->conicTo(*p1, *p2, w);
}

SkPath * SkPath_rConicTo(SkPath *path, SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2, SkScalar w) {
    return &path->rConicTo(dx1, dy1, dx2, dy2, w);
}

SkPath * SkPath_cubicTo(SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3) {
    return &path->cubicTo(x1, y1, x2, y2, x3, y3);
}

SkPath * SkPath_cubicTo_2(SkPath *path, const SkPoint *p1, const SkPoint *p2, const SkPoint *p3) {
    return &path->cubicTo(*p1, *p2, *p3);
}

SkPath * SkPath_rCubicTo(SkPath *path, SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2, SkScalar dx3, SkScalar dy3) {
    return &path->rCubicTo(dx1, dy1, dx2, dy2, dx3, dy3);
}

SkPath * SkPath_arcTo(SkPath *path, const SkRect *oval, SkScalar startAngle, SkScalar sweepAngle, bool forceMoveTo) {
    return &path->arcTo(*oval, startAngle, sweepAngle, forceMoveTo);
}

SkPath * SkPath_arcTo_2(SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar radius) {
    return &path->arcTo(x1, y1, x2, y2, radius);
}

SkPath * SkPath_arcTo_3(SkPath *path, sk_point_t p1, sk_point_t p2, SkScalar radius) {
    return &path->arcTo(static_sk_point_get(p1), static_sk_point_get(p2), radius);
}

SkPath * SkPath_arcTo_4(SkPath *path, SkScalar rx, SkScalar ry, SkScalar xAxisRotate, SkPath::ArcSize largeArc, SkPathDirection sweep, SkScalar x, SkScalar y) {
    return &path->arcTo(rx, ry, xAxisRotate, largeArc, sweep, x, y);
}

SkPath * SkPath_arcTo_5(SkPath *path, sk_point_t r, SkScalar xAxisRotate, SkPath::ArcSize largeArc, SkPathDirection sweep, sk_point_t xy) {
    return &path->arcTo(static_sk_point_get(r), xAxisRotate, largeArc, sweep, static_sk_point_get(xy));
}

SkPath * SkPath_rArcTo(SkPath *path, SkScalar rx, SkScalar ry, SkScalar xAxisRotate, SkPath::ArcSize largeArc, SkPathDirection sweep, SkScalar dx, SkScalar dy) {
    return &path->arcTo(rx, ry, xAxisRotate, largeArc, sweep, dx, dy);
}

SkPath * SkPath_close(SkPath *path) {
    return &path->close();
}

bool SkPath_isRect(SkPath *path, SkRect *rect, bool *isClosed, SkPathDirection *direction) {
    return path->isRect(rect, isClosed, direction);
}

SkPath * SkPath_addRect(SkPath *path, const SkRect *rect, SkPathDirection dir, unsigned start) {
    return &path->addRect(*rect, dir, start);
}

SkPath * SkPath_addRect_2(SkPath *path, const SkRect *rect, SkPathDirection dir) {
    return &path->addRect(*rect, dir);
}

SkPath * SkPath_addRect_3(SkPath *path, SkScalar left, SkScalar top, SkScalar right, SkScalar bottom, SkPathDirection dir) {
    return &path->addRect(left, top, right, bottom, dir);
}

SkPath * SkPath_addOval(SkPath *path, const SkRect *oval, SkPathDirection dir) {
    return &path->addOval(*oval, dir);
}

SkPath * SkPath_addOval_2(SkPath *path, const SkRect *oval, SkPathDirection dir, unsigned start) {
    return &path->addOval(*oval, dir, start);
}

SkPath * SkPath_addCircle(SkPath *path, SkScalar x, SkScalar y, SkScalar radius, SkPathDirection dir) {
    return &path->addCircle(x, y, radius, dir);
}

SkPath * SkPath_addArc(SkPath *path, const SkRect *oval, SkScalar startAngle, SkScalar sweepAngle) {
    return &path->addArc(*oval, startAngle, sweepAngle);
}

SkPath * SkPath_addRoundRect(SkPath *path, const SkRect *rect, SkScalar rx, SkScalar ry, SkPathDirection dir) {
    return &path->addRoundRect(*rect, rx, ry, dir);
}

SkPath * SkPath_addRoundRect_2(SkPath *path, const SkRect *rect, const SkScalar radii[], SkPathDirection dir) {
    return &path->addRoundRect(*rect, radii, dir);
}

SkPath * SkPath_addRRect(SkPath *path, const SkRRect *rrect, SkPathDirection dir) {
    return &path->addRRect(*rrect, dir);
}

SkPath * SkPath_addRRect_2(SkPath *path, const SkRRect *rrect, SkPathDirection dir, unsigned start) {
    return &path->addRRect(*rrect, dir, start);
}

SkPath * SkPath_addPoly(SkPath *path, const SkPoint pts[], int count, bool close) {
    return &path->addPoly(pts, count, close);
}

SkPath * SkPath_addPoly_2(SkPath *path, const std::initializer_list<SkPoint> *list, bool close) {
    return &path->addPoly(*list, close);
}

SkPath * SkPath_addPath(SkPath *path, const SkPath *src, SkScalar dx, SkScalar dy, SkPath::AddPathMode mode) {
    return &path->addPath(*src, dx, dy, mode);
}

SkPath * SkPath_addPath_2(SkPath *path, const SkPath *src, SkPath::AddPathMode modeSkPath) {
    return &path->addPath(*src, modeSkPath);
}

SkPath * SkPath_addPath_3(SkPath *path, const SkPath *src, const SkMatrix *matrix, SkPath::AddPathMode mode) {
    return &path->addPath(*src, *matrix, mode);
}

SkPath * SkPath_reverseAddPath(SkPath *path, const SkPath *src) {
    return &path->reverseAddPath(*src);
}

void SkPath_offset(SkPath *path, SkScalar dx, SkScalar dy, SkPath *dst) {
    path->offset(dx, dy, dst);
}

void SkPath_offset_2(SkPath *path, SkScalar dx, SkScalar dy) {
    path->offset(dx, dy);
}

void SkPath_transform(SkPath *path, const SkMatrix *matrix, SkPath *dst, SkApplyPerspectiveClip pc) {
    path->transform(*matrix, dst, pc);
}

void SkPath_transform_2(SkPath *path, const SkMatrix *matrix, SkApplyPerspectiveClip pc) {
    path->transform(*matrix, pc);
}

sk_path_t SkPath_makeTransform(SkPath *path, const SkMatrix *m, SkApplyPerspectiveClip pc) {
    return static_sk_path_make(path->makeTransform(*m, pc));
}

sk_path_t SkPath_makeScale(SkPath *path, SkScalar sx, SkScalar sy) {
    return static_sk_path_make(path->makeScale(sx, sy));
}

bool SkPath_getLastPt(SkPath *path, SkPoint *lastPt) {
    return path->getLastPt(lastPt);
}

void SkPath_setLastPt(SkPath *path, SkScalar x, SkScalar y) {
    path->setLastPt(x, y);
}

void SkPath_setLastPt_2(SkPath *path, const SkPoint *p) {
    path->setLastPt(*p);
}

uint32_t SkPath_getSegmentMasks(SkPath *path) {
    return path->getSegmentMasks();
}

bool SkPath_contains(SkPath *path, SkScalar x, SkScalar y) {
    return path->contains(x, y);
}

void SkPath_dump(SkPath *path, SkWStream *stream, bool dumpAsHex) {
    path->dump(stream, dumpAsHex);
}

void SkPath_dump_2(SkPath *path) {
    path->dump();
}

void SkPath_dumpHex(SkPath *path) {
    path->dumpHex();
}

void SkPath_dumpArrays(SkPath *path, SkWStream *stream, bool dumpAsHex) {
    path->dumpArrays(stream, dumpAsHex);
}

void SkPath_dumpArrays_2(SkPath *path) {
    path->dumpArrays();
}

size_t SkPath_writeToMemory(SkPath *path, void *buffer) {
    return path->writeToMemory(buffer);
}

sk_data_t SkPath_serialize(SkPath *path) {
    return static_sk_data_make(path->serialize());
}

size_t SkPath_readFromMemory(SkPath *path, const void *buffer, size_t length) {
    return path->readFromMemory(buffer, length);
}

uint32_t SkPath_getGenerationID(SkPath *path) {
    return path->getGenerationID();
}

bool SkPath_isValid(SkPath *path) {
    return path->isValid();
}


// static

sk_path_t SkPath_Make(const SkPoint point[], int pointCount, const uint8_t i[], int verbCount, const SkScalar v[], int conicWeightCount, SkPathFillType type, bool isVolatile) {
    return static_sk_path_make(SkPath::Make(point, pointCount, i, verbCount, v, conicWeightCount, type, isVolatile));
}

sk_path_t SkPath_Rect(const SkRect *rect, SkPathDirection dir, unsigned startIndex) {
    return static_sk_path_make(SkPath::Rect(*rect, dir, startIndex));
}

sk_path_t SkPath_Oval(const SkRect *rect, SkPathDirection dir) {
    return static_sk_path_make(SkPath::Oval(*rect, dir));
}

sk_path_t SkPath_Oval_2(const SkRect *rect, SkPathDirection dir, unsigned startIndex) {
    return static_sk_path_make(SkPath::Oval(*rect, dir, startIndex));
}

sk_path_t SkPath_Circle(SkScalar center_x, SkScalar center_y, SkScalar radius, SkPathDirection dir) {
    return static_sk_path_make(SkPath::Circle(center_x, center_y, radius, dir));
}

sk_path_t SkPath_RRect(const SkRRect *rrect, SkPathDirection dir) {
    return static_sk_path_make(SkPath::RRect(*rrect, dir));
}

sk_path_t SkPath_RRect_2(const SkRRect *rrect, SkPathDirection dir, unsigned startIndex) {
    return static_sk_path_make(SkPath::RRect(*rrect, dir, startIndex));
}

sk_path_t SkPath_RRect_3(const SkRect *bounds, SkScalar rx, SkScalar ry, SkPathDirection dir) {
    return static_sk_path_make(SkPath::RRect(*bounds, rx, ry, dir));
}

sk_path_t SkPath_Polygon(const SkPoint pts[], int count, bool isClosed, SkPathFillType type, bool isVolatile) {
    return static_sk_path_make(SkPath::Polygon(pts, count, isClosed, type, isVolatile));
}

sk_path_t SkPath_Polygon_2(const std::initializer_list<SkPoint> *list, bool isClosed, SkPathFillType fillType, bool isVolatile) {
    return static_sk_path_make(SkPath::Polygon(*list, isClosed, fillType, isVolatile));
}

sk_path_t SkPath_Line(sk_point_t a, sk_point_t b) {
    return static_sk_path_make(SkPath::Line(static_sk_point_get(a), static_sk_point_get(b)));
}

bool SkPath_IsLineDegenerate(const SkPoint *p1, const SkPoint *p2, bool exact) {
    return SkPath::IsLineDegenerate(*p1, *p2, exact);
}

bool SkPath_IsQuadDegenerate(const SkPoint *p1, const SkPoint *p2, const SkPoint *p3, bool exact) {
    return SkPath::IsQuadDegenerate(*p1, *p2, *p3, exact);
}

bool SkPath_IsCubicDegenerate(const SkPoint *p1, const SkPoint *p2, const SkPoint *p3, const SkPoint *p4, bool exact) {
    return SkPath::IsCubicDegenerate(*p1, *p2, *p3, *p4, exact);
}

int SkPath_ConvertConicToQuads(const SkPoint *p0, const SkPoint *p1, const SkPoint *p2, SkScalar w, SkPoint pts[], int pow2) {
    return SkPath::ConvertConicToQuads(*p0, *p1, *p2, w, pts, pow2);
}

}