//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_PATH_H
#define RAIA_SKIA_SK_PATH_H

#include "include/core/SkPath.h"
#include "../static/static_sk_data.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_point.h"
#include "export_api.h"

extern "C" {
//SkPath & operator=(const SkPath &path)
RAIA_API SkPath *SkPath_new();
RAIA_API SkPath *SkPath_new_2(const SkPath *path);
RAIA_API void SkPath_delete(SkPath *path);
RAIA_API bool SkPath_isInterpolatable(SkPath *path, const SkPath *compare);
RAIA_API bool SkPath_interpolate(SkPath *path, const SkPath *ending, SkScalar weight, SkPath *out);
RAIA_API SkPathFillType SkPath_getFillType(SkPath *path);
RAIA_API void SkPath_setFillType(SkPath *path, SkPathFillType ft);
RAIA_API bool SkPath_isInverseFillType(SkPath *path);
RAIA_API void SkPath_toggleInverseFillType(SkPath *path);
RAIA_API bool SkPath_isConvex(SkPath *path);
RAIA_API bool SkPath_isOval(SkPath *path, SkRect *bounds);
RAIA_API bool SkPath_isRRect(SkPath *path, SkRRect *rrect);
RAIA_API SkPath * SkPath_reset(SkPath *path);
RAIA_API SkPath * SkPath_rewind(SkPath *path);
RAIA_API bool SkPath_isEmpty(SkPath *path);
RAIA_API bool SkPath_isLastContourClosed(SkPath *path);
RAIA_API bool SkPath_isFinite(SkPath *path);
RAIA_API bool SkPath_isVolatile(SkPath *path);
RAIA_API SkPath * SkPath_setIsVolatile(SkPath *path, bool isVolatile);
RAIA_API bool SkPath_isLine(SkPath *path, SkPoint line[2]);
RAIA_API int SkPath_countPoints(SkPath *path);
RAIA_API sk_point_t SkPath_getPoint(SkPath *path, int index);
RAIA_API int SkPath_getPoints(SkPath *path, SkPoint points[], int max);
RAIA_API int SkPath_countVerbs(SkPath *path);
RAIA_API int SkPath_getVerbs(SkPath *path, uint8_t verbs[], int max);
RAIA_API size_t SkPath_approximateBytesUsed(SkPath *path);
RAIA_API void SkPath_swap(SkPath *path, SkPath *other);
RAIA_API const SkRect * SkPath_getBounds(SkPath *path);
RAIA_API void SkPath_updateBoundsCache(SkPath *path);
RAIA_API sk_rect_t SkPath_computeTightBounds(SkPath *path);
RAIA_API bool SkPath_conservativelyContainsRect(SkPath *path, const SkRect *rect);
RAIA_API void SkPath_incReserve(SkPath *path, int extraPtCount);
RAIA_API SkPath * SkPath_moveTo(SkPath *path, SkScalar x, SkScalar y);
RAIA_API SkPath * SkPath_moveTo_2(SkPath *path, const SkPoint *p);
RAIA_API SkPath * SkPath_rMoveTo(SkPath *path, SkScalar dx, SkScalar dy);
RAIA_API SkPath * SkPath_lineTo(SkPath *path, SkScalar x, SkScalar y);
RAIA_API SkPath * SkPath_lineTo_2(SkPath *path, const SkPoint *p);
RAIA_API SkPath * SkPath_rLineTo(SkPath *path, SkScalar dx, SkScalar dy);
RAIA_API SkPath * SkPath_quadTo(SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2);
RAIA_API SkPath * SkPath_quadTo_2(SkPath *path, const SkPoint *p1, const SkPoint *p2);
RAIA_API SkPath * SkPath_rQuadTo(SkPath *path, SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2);
RAIA_API SkPath * SkPath_conicTo(SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w);
RAIA_API SkPath * SkPath_conicTo_2(SkPath *path, const SkPoint *p1, const SkPoint *p2, SkScalar w);
RAIA_API SkPath * SkPath_rConicTo(SkPath *path, SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2, SkScalar w);
RAIA_API SkPath * SkPath_cubicTo(SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3);
RAIA_API SkPath * SkPath_cubicTo_2(SkPath *path, const SkPoint *p1, const SkPoint *p2, const SkPoint *p3);
RAIA_API SkPath * SkPath_rCubicTo(SkPath *path, SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2, SkScalar dx3, SkScalar dy3);
RAIA_API SkPath * SkPath_arcTo(SkPath *path, const SkRect *oval, SkScalar startAngle, SkScalar sweepAngle, bool forceMoveTo);
RAIA_API SkPath * SkPath_arcTo_2(SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar radius);
RAIA_API SkPath * SkPath_arcTo_3(SkPath *path, sk_point_t p1, sk_point_t p2, SkScalar radius);
RAIA_API SkPath * SkPath_arcTo_4(SkPath *path, SkScalar rx, SkScalar ry, SkScalar xAxisRotate, SkPath::ArcSize largeArc, SkPathDirection sweep, SkScalar x, SkScalar y);
RAIA_API SkPath * SkPath_arcTo_5(SkPath *path, sk_point_t r, SkScalar xAxisRotate, SkPath::ArcSize largeArc, SkPathDirection sweep, sk_point_t xy);
RAIA_API SkPath * SkPath_rArcTo(SkPath *path, SkScalar rx, SkScalar ry, SkScalar xAxisRotate, SkPath::ArcSize largeArc, SkPathDirection sweep, SkScalar dx, SkScalar dy);
RAIA_API SkPath * SkPath_close(SkPath *path);
RAIA_API bool SkPath_isRect(SkPath *path, SkRect *rect, bool *isClosed, SkPathDirection *direction);
RAIA_API SkPath * SkPath_addRect(SkPath *path, const SkRect *rect, SkPathDirection dir, unsigned start);
RAIA_API SkPath * SkPath_addRect_2(SkPath *path, const SkRect *rect, SkPathDirection dir);
RAIA_API SkPath * SkPath_addRect_3(SkPath *path, SkScalar left, SkScalar top, SkScalar right, SkScalar bottom, SkPathDirection dir);
RAIA_API SkPath * SkPath_addOval(SkPath *path, const SkRect *oval, SkPathDirection dir);
RAIA_API SkPath * SkPath_addOval_2(SkPath *path, const SkRect *oval, SkPathDirection dir, unsigned start);
RAIA_API SkPath * SkPath_addCircle(SkPath *path, SkScalar x, SkScalar y, SkScalar radius, SkPathDirection dir);
RAIA_API SkPath * SkPath_addArc(SkPath *path, const SkRect *oval, SkScalar startAngle, SkScalar sweepAngle);
RAIA_API SkPath * SkPath_addRoundRect(SkPath *path, const SkRect *rect, SkScalar rx, SkScalar ry, SkPathDirection dir);
RAIA_API SkPath * SkPath_addRoundRect_2(SkPath *path, const SkRect *rect, const SkScalar radii[], SkPathDirection dir);
RAIA_API SkPath * SkPath_addRRect(SkPath *path, const SkRRect *rrect, SkPathDirection dir);
RAIA_API SkPath * SkPath_addRRect_2(SkPath *path, const SkRRect *rrect, SkPathDirection dir, unsigned start);
RAIA_API SkPath * SkPath_addPoly(SkPath *path, const SkPoint pts[], int count, bool close);
RAIA_API SkPath * SkPath_addPoly_2(SkPath *path, const std::initializer_list<SkPoint> *list, bool close);
RAIA_API SkPath * SkPath_addPath(SkPath *path, const SkPath *src, SkScalar dx, SkScalar dy, SkPath::AddPathMode mode);
RAIA_API SkPath * SkPath_addPath_2(SkPath *path, const SkPath *src, SkPath::AddPathMode modeSkPath);
RAIA_API SkPath * SkPath_addPath_3(SkPath *path, const SkPath *src, const SkMatrix *matrix, SkPath::AddPathMode mode);
RAIA_API SkPath * SkPath_reverseAddPath(SkPath *path, const SkPath *src);
RAIA_API void SkPath_offset(SkPath *path, SkScalar dx, SkScalar dy, SkPath *dst);
RAIA_API void SkPath_offset_2(SkPath *path, SkScalar dx, SkScalar dy);
RAIA_API void SkPath_transform(SkPath *path, const SkMatrix *matrix, SkPath *dst, SkApplyPerspectiveClip pc);
RAIA_API void SkPath_transform_2(SkPath *path, const SkMatrix *matrix, SkApplyPerspectiveClip pc);
RAIA_API sk_path_t SkPath_makeTransform(SkPath *path, const SkMatrix *m, SkApplyPerspectiveClip pc);
RAIA_API sk_path_t SkPath_makeScale(SkPath *path, SkScalar sx, SkScalar sy);
RAIA_API bool SkPath_getLastPt(SkPath *path, SkPoint *lastPt);
RAIA_API void SkPath_setLastPt(SkPath *path, SkScalar x, SkScalar y);
RAIA_API void SkPath_setLastPt_2(SkPath *path, const SkPoint *p);
RAIA_API uint32_t SkPath_getSegmentMasks(SkPath *path);
RAIA_API bool SkPath_contains(SkPath *path, SkScalar x, SkScalar y);
RAIA_API void SkPath_dump(SkPath *path, SkWStream *stream, bool dumpAsHex);
RAIA_API void SkPath_dump_2(SkPath *path);
RAIA_API void SkPath_dumpHex(SkPath *path);
RAIA_API void SkPath_dumpArrays(SkPath *path, SkWStream *stream, bool dumpAsHex);
RAIA_API void SkPath_dumpArrays_2(SkPath *path);
RAIA_API size_t SkPath_writeToMemory(SkPath *path, void *buffer);
RAIA_API sk_data_t SkPath_serialize(SkPath *path);
RAIA_API size_t SkPath_readFromMemory(SkPath *path, const void *buffer, size_t length);
RAIA_API uint32_t SkPath_getGenerationID(SkPath *path);
RAIA_API bool SkPath_isValid(SkPath *path);
// static
RAIA_API sk_path_t SkPath_Make(const SkPoint point[], int pointCount, const uint8_t i[], int verbCount, const SkScalar v[], int conicWeightCount, SkPathFillType type, bool isVolatile);
RAIA_API sk_path_t SkPath_Rect(const SkRect *rect, SkPathDirection dir, unsigned startIndex);
RAIA_API sk_path_t SkPath_Oval(const SkRect *rect, SkPathDirection dir);
RAIA_API sk_path_t SkPath_Oval_2(const SkRect *rect, SkPathDirection dir, unsigned startIndex);
RAIA_API sk_path_t SkPath_Circle(SkScalar center_x, SkScalar center_y, SkScalar radius, SkPathDirection dir);
RAIA_API sk_path_t SkPath_RRect(const SkRRect *rrect, SkPathDirection dir);
RAIA_API sk_path_t SkPath_RRect_2(const SkRRect *rrect, SkPathDirection dir, unsigned startIndex);
RAIA_API sk_path_t SkPath_RRect_3(const SkRect *bounds, SkScalar rx, SkScalar ry, SkPathDirection dir);
RAIA_API sk_path_t SkPath_Polygon(const SkPoint pts[], int count, bool isClosed, SkPathFillType type, bool isVolatile);
RAIA_API sk_path_t SkPath_Polygon_2(const std::initializer_list<SkPoint> *list, bool isClosed, SkPathFillType fillType, bool isVolatile);
RAIA_API sk_path_t SkPath_Line(sk_point_t a, sk_point_t b);
RAIA_API bool SkPath_IsLineDegenerate(const SkPoint *p1, const SkPoint *p2, bool exact);
RAIA_API bool SkPath_IsQuadDegenerate(const SkPoint *p1, const SkPoint *p2, const SkPoint *p3, bool exact);
RAIA_API bool SkPath_IsCubicDegenerate(const SkPoint *p1, const SkPoint *p2, const SkPoint *p3, const SkPoint *p4, bool exact);
RAIA_API int SkPath_ConvertConicToQuads(const SkPoint *p0, const SkPoint *p1, const SkPoint *p2, SkScalar w, SkPoint pts[], int pow2);
}

#endif //RAIA_SKIA_SK_PATH_H
