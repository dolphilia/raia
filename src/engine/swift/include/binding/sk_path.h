//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_PATH_H
#define RAIA_SKIA_SK_PATH_H

#ifdef __cplusplus
extern "C" {
#endif

//SkPath & operator=(const SkPath &path)
void *SkPath_new(); // () -> SkPath *
void *SkPath_new_2(const void *path); // (const SkPath *path) -> SkPath *
void SkPath_delete(void *path); // (SkPath *path)
bool SkPath_isInterpolatable(void *path, const void *compare); // (SkPath *path, const SkPath *compare) -> bool
bool SkPath_interpolate(void *path, const void *ending, float weight, void *out); // (SkPath *path, const SkPath *ending, SkScalar weight, SkPath *out) -> bool
int SkPath_getFillType(void *path); // (SkPath *path) -> SkPathFillType
void SkPath_setFillType(void *path, int ft); // (SkPath *path, SkPathFillType ft)
bool SkPath_isInverseFillType(void *path); // (SkPath *path) -> bool
void SkPath_toggleInverseFillType(void *path); // (SkPath *path)
bool SkPath_isConvex(void *path); // (SkPath *path) -> bool
bool SkPath_isOval(void *path, void *bounds); // (SkPath *path, SkRect *bounds) -> bool
bool SkPath_isRRect(void *path, void *rrect); // (SkPath *path, SkRRect *rrect) -> bool
void *SkPath_reset(void *path); // (SkPath *path) -> SkPath *
void *SkPath_rewind(void *path); // (SkPath *path) -> SkPath *
bool SkPath_isEmpty(void *path); // (SkPath *path) -> bool
bool SkPath_isLastContourClosed(void *path); // (SkPath *path) -> bool
bool SkPath_isFinite(void *path); // (SkPath *path) -> bool
bool SkPath_isVolatile(void *path); // (SkPath *path) -> bool
void *SkPath_setIsVolatile(void *path, bool isVolatile); // (SkPath *path, bool isVolatile) -> SkPath *
bool SkPath_isLine(void *path, void * line); // (SkPath *path, SkPoint line[2]) -> bool
int SkPath_countPoints(void *path); // (SkPath *path) -> int
int SkPath_getPoint(void *path, int index); // (SkPath *path, int index) -> sk_point_t
int SkPath_getPoints(void *path, void * points, int max); // (SkPath *path, SkPoint points[], int max) -> int
int SkPath_countVerbs(void *path); // (SkPath *path) -> int
int SkPath_getVerbs(void *path, void * verbs, int max); // (SkPath *path, uint8_t verbs[], int max) -> int
unsigned long SkPath_approximateBytesUsed(void *path); // (SkPath *path) -> size_t
void SkPath_swap(void *path, void *other); // (SkPath *path, SkPath *other)
const void *SkPath_getBounds(void *path); // (SkPath *path) -> const SkRect *
void SkPath_updateBoundsCache(void *path); // (SkPath *path)
int SkPath_computeTightBounds(void *path); // (SkPath *path) -> sk_rect_t
bool SkPath_conservativelyContainsRect(void *path, const void *rect); // (SkPath *path, const SkRect *rect) -> bool
void SkPath_incReserve(void *path, int extraPtCount); // (SkPath *path, int extraPtCount)
void *SkPath_moveTo(void *path, float x, float y); // (SkPath *path, SkScalar x, SkScalar y) -> SkPath *
void *SkPath_moveTo_2(void *path, const void *p); // (SkPath *path, const SkPoint *p) -> SkPath *
void *SkPath_rMoveTo(void *path, float dx, float dy); // (SkPath *path, SkScalar dx, SkScalar dy) -> SkPath *
void *SkPath_lineTo(void *path, float x, float y); // (SkPath *path, SkScalar x, SkScalar y) -> SkPath *
void *SkPath_lineTo_2(void *path, const void *p); // (SkPath *path, const SkPoint *p) -> SkPath *
void *SkPath_rLineTo(void *path, float dx, float dy); // (SkPath *path, SkScalar dx, SkScalar dy) -> SkPath *
void *SkPath_quadTo(void *path, float x1, float y1, float x2, float y2); // (SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2) -> SkPath *
void *SkPath_quadTo_2(void *path, const void *p1, const void *p2); // (SkPath *path, const SkPoint *p1, const SkPoint *p2) -> SkPath *
void *SkPath_rQuadTo(void *path, float dx1, float dy1, float dx2, float dy2); // (SkPath *path, SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2) -> SkPath *
void *SkPath_conicTo(void *path, float x1, float y1, float x2, float y2, float w); // (SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar w) -> SkPath *
void *SkPath_conicTo_2(void *path, const void *p1, const void *p2, float w); // (SkPath *path, const SkPoint *p1, const SkPoint *p2, SkScalar w) -> SkPath *
void *SkPath_rConicTo(void *path, float dx1, float dy1, float dx2, float dy2, float w); // (SkPath *path, SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2, SkScalar w) -> SkPath *
void *SkPath_cubicTo(void *path, float x1, float y1, float x2, float y2, float x3, float y3); // (SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar x3, SkScalar y3) -> SkPath *
void *SkPath_cubicTo_2(void *path, const void *p1, const void *p2, const void *p3); // (SkPath *path, const SkPoint *p1, const SkPoint *p2, const SkPoint *p3) -> SkPath *
void *SkPath_rCubicTo(void *path, float dx1, float dy1, float dx2, float dy2, float dx3, float dy3); // (SkPath *path, SkScalar dx1, SkScalar dy1, SkScalar dx2, SkScalar dy2, SkScalar dx3, SkScalar dy3) -> SkPath *
void *SkPath_arcTo(void *path, const void *oval, float startAngle, float sweepAngle, bool forceMoveTo); // (SkPath *path, const SkRect *oval, SkScalar startAngle, SkScalar sweepAngle, bool forceMoveTo) -> SkPath *
void *SkPath_arcTo_2(void *path, float x1, float y1, float x2, float y2, float radius); // (SkPath *path, SkScalar x1, SkScalar y1, SkScalar x2, SkScalar y2, SkScalar radius) -> SkPath *
void *SkPath_arcTo_3(void *path, int p1, int p2, float radius); // (SkPath *path, sk_point_t p1, sk_point_t p2, SkScalar radius) -> SkPath *
void *SkPath_arcTo_4(void *path, float rx, float ry, float xAxisRotate, int largeArc, int sweep, float x, float y); // (SkPath *path, SkScalar rx, SkScalar ry, SkScalar xAxisRotate, SkPath::ArcSize largeArc, SkPathDirection sweep, SkScalar x, SkScalar y) -> SkPath *
void *SkPath_arcTo_5(void *path, int r, float xAxisRotate, int largeArc, int sweep, int xy); // (SkPath *path, sk_point_t r, SkScalar xAxisRotate, SkPath::ArcSize largeArc, SkPathDirection sweep, sk_point_t xy) -> SkPath *
void *SkPath_rArcTo(void *path, float rx, float ry, float xAxisRotate, int largeArc, int sweep, float dx, float dy); // (SkPath *path, SkScalar rx, SkScalar ry, SkScalar xAxisRotate, SkPath::ArcSize largeArc, SkPathDirection sweep, SkScalar dx, SkScalar dy) -> SkPath *
void *SkPath_close(void *path); // (SkPath *path) -> SkPath *
bool SkPath_isRect(void *path, void *rect, void *isClosed, void *direction); // (SkPath *path, SkRect *rect, bool *isClosed, SkPathDirection *direction) -> bool
void *SkPath_addRect(void *path, const void *rect, int dir, unsigned start); // (SkPath *path, const SkRect *rect, SkPathDirection dir, unsigned start) -> SkPath *
void *SkPath_addRect_2(void *path, const void *rect, int dir); // (SkPath *path, const SkRect *rect, SkPathDirection dir) -> SkPath *
void *SkPath_addRect_3(void *path, float left, float top, float right, float bottom, int dir); // (SkPath *path, SkScalar left, SkScalar top, SkScalar right, SkScalar bottom, SkPathDirection dir) -> SkPath *
void *SkPath_addOval(void *path, const void *oval, int dir); // (SkPath *path, const SkRect *oval, SkPathDirection dir) -> SkPath *
void *SkPath_addOval_2(void *path, const void *oval, int dir, unsigned start); // (SkPath *path, const SkRect *oval, SkPathDirection dir, unsigned start) -> SkPath *
void *SkPath_addCircle(void *path, float x, float y, float radius, int dir); // (SkPath *path, SkScalar x, SkScalar y, SkScalar radius, SkPathDirection dir) -> SkPath *
void *SkPath_addArc(void *path, const void *oval, float startAngle, float sweepAngle); // (SkPath *path, const SkRect *oval, SkScalar startAngle, SkScalar sweepAngle) -> SkPath *
void *SkPath_addRoundRect(void *path, const void *rect, float rx, float ry, int dir); // (SkPath *path, const SkRect *rect, SkScalar rx, SkScalar ry, SkPathDirection dir) -> SkPath *
void *SkPath_addRoundRect_2(void *path, const void *rect, const void * radii, int dir); // (SkPath *path, const SkRect *rect, const SkScalar radii[], SkPathDirection dir) -> SkPath *
void *SkPath_addRRect(void *path, const void *rrect, int dir); // (SkPath *path, const SkRRect *rrect, SkPathDirection dir) -> SkPath *
void *SkPath_addRRect_2(void *path, const void *rrect, int dir, unsigned start); // (SkPath *path, const SkRRect *rrect, SkPathDirection dir, unsigned start) -> SkPath *
void *SkPath_addPoly(void *path, const void * pts, int count, bool close); // (SkPath *path, const SkPoint pts[], int count, bool close) -> SkPath *
void *SkPath_addPoly_2(void *path, const void *list, bool close); // (SkPath *path, const std::initializer_list<SkPoint> *list, bool close) -> SkPath *
void *SkPath_addPath(void *path, const void *src, float dx, float dy, int mode); // (SkPath *path, const SkPath *src, SkScalar dx, SkScalar dy, SkPath::AddPathMode mode) -> SkPath *
void *SkPath_addPath_2(void *path, const void *src, int modeSkPath); // (SkPath *path, const SkPath *src, SkPath::AddPathMode modeSkPath) -> SkPath *
void *SkPath_addPath_3(void *path, const void *src, const void *matrix, int mode); // (SkPath *path, const SkPath *src, const SkMatrix *matrix, SkPath::AddPathMode mode) -> SkPath *
void *SkPath_reverseAddPath(void *path, const void *src); // (SkPath *path, const SkPath *src) -> SkPath *
void SkPath_offset(void *path, float dx, float dy, void *dst); // (SkPath *path, SkScalar dx, SkScalar dy, SkPath *dst)
void SkPath_offset_2(void *path, float dx, float dy); // (SkPath *path, SkScalar dx, SkScalar dy)
void SkPath_transform(void *path, const void *matrix, void *dst, int pc); // (SkPath *path, const SkMatrix *matrix, SkPath *dst, SkApplyPerspectiveClip pc)
void SkPath_transform_2(void *path, const void *matrix, int pc); // (SkPath *path, const SkMatrix *matrix, SkApplyPerspectiveClip pc)
int SkPath_makeTransform(void *path, const void *m, int pc); // (SkPath *path, const SkMatrix *m, SkApplyPerspectiveClip pc) -> sk_path_t
int SkPath_makeScale(void *path, float sx, float sy); // (SkPath *path, SkScalar sx, SkScalar sy) -> sk_path_t
bool SkPath_getLastPt(void *path, void *lastPt); // (SkPath *path, SkPoint *lastPt) -> bool
void SkPath_setLastPt(void *path, float x, float y); // (SkPath *path, SkScalar x, SkScalar y)
void SkPath_setLastPt_2(void *path, const void *p); // (SkPath *path, const SkPoint *p)
unsigned int SkPath_getSegmentMasks(void *path); // (SkPath *path) -> uint32_t
bool SkPath_contains(void *path, float x, float y); // (SkPath *path, SkScalar x, SkScalar y) -> bool
void SkPath_dump(void *path, void *stream, bool dumpAsHex); // (SkPath *path, SkWStream *stream, bool dumpAsHex)
void SkPath_dump_2(void *path); // (SkPath *path)
void SkPath_dumpHex(void *path); // (SkPath *path)
void SkPath_dumpArrays(void *path, void *stream, bool dumpAsHex); // (SkPath *path, SkWStream *stream, bool dumpAsHex)
void SkPath_dumpArrays_2(void *path); // (SkPath *path)
unsigned long SkPath_writeToMemory(void *path, void *buffer); // (SkPath *path, void *buffer) -> size_t
int SkPath_serialize(void *path); // (SkPath *path) -> sk_data_t
unsigned long SkPath_readFromMemory(void *path, const void *buffer, unsigned long length); // (SkPath *path, const void *buffer, size_t length) -> size_t
unsigned int SkPath_getGenerationID(void *path); // (SkPath *path) -> uint32_t
bool SkPath_isValid(void *path); // (SkPath *path) -> bool

// static

int SkPath_Make(const void * point, int pointCount, const void * i, int verbCount, const void * v, int conicWeightCount, int type, bool isVolatile); // (const SkPoint point[], int pointCount, const uint8_t i[], int verbCount, const SkScalar v[], int conicWeightCount, SkPathFillType type, bool isVolatile) -> sk_path_t
int SkPath_Rect(const void *rect, int dir, unsigned startIndex); // (const SkRect *rect, SkPathDirection dir, unsigned startIndex) -> sk_path_t
int SkPath_Oval(const void *rect, int dir); // (const SkRect *rect, SkPathDirection dir) -> sk_path_t
int SkPath_Oval_2(const void *rect, int dir, unsigned startIndex); // (const SkRect *rect, SkPathDirection dir, unsigned startIndex) -> sk_path_t
int SkPath_Circle(float center_x, float center_y, float radius, int dir); // (SkScalar center_x, SkScalar center_y, SkScalar radius, SkPathDirection dir) -> sk_path_t
int SkPath_RRect(const void *rrect, int dir); // (const SkRRect *rrect, SkPathDirection dir) -> sk_path_t
int SkPath_RRect_2(const void *rrect, int dir, unsigned startIndex); // (const SkRRect *rrect, SkPathDirection dir, unsigned startIndex) -> sk_path_t
int SkPath_RRect_3(const void *bounds, float rx, float ry, int dir); // (const SkRect *bounds, SkScalar rx, SkScalar ry, SkPathDirection dir) -> sk_path_t
int SkPath_Polygon(const void * pts, int count, bool isClosed, int type, bool isVolatile); // (const SkPoint pts[], int count, bool isClosed, SkPathFillType type, bool isVolatile) -> sk_path_t
int SkPath_Polygon_2(const void *list, bool isClosed, int fillType, bool isVolatile); // (const std::initializer_list<SkPoint> *list, bool isClosed, SkPathFillType fillType, bool isVolatile) -> sk_path_t
int SkPath_Line(int a, int b); // (sk_point_t a, sk_point_t b) -> sk_path_t
bool SkPath_IsLineDegenerate(const void *p1, const void *p2, bool exact); // (const SkPoint *p1, const SkPoint *p2, bool exact) -> bool
bool SkPath_IsQuadDegenerate(const void *p1, const void *p2, const void *p3, bool exact); // (const SkPoint *p1, const SkPoint *p2, const SkPoint *p3, bool exact) -> bool
bool SkPath_IsCubicDegenerate(const void *p1, const void *p2, const void *p3, const void *p4, bool exact); // (const SkPoint *p1, const SkPoint *p2, const SkPoint *p3, const SkPoint *p4, bool exact) -> bool
int SkPath_ConvertConicToQuads(const void *p0, const void *p1, const void *p2, float w, void * pts, int pow2); // (const SkPoint *p0, const SkPoint *p1, const SkPoint *p2, SkScalar w, SkPoint pts[], int pow2) -> int

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_PATH_H
