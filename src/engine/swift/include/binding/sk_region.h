//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_REGION_H
#define RAIA_SKIA_SK_REGION_H

#include "include/core/SkRegion.h"

extern "C" {
//SkRegion & operator=(const SkRegion &region)
//bool operator==(const SkRegion &other)
//bool operator!=(const SkRegion &other)
SkRegion *SkRegion_new();
SkRegion *SkRegion_new_2(const SkRegion *region);
SkRegion *SkRegion_new_3(const SkIRect *rect);
void SkRegion_delete(SkRegion *region);
bool SkRegion_set(SkRegion *region, const SkRegion *src);
void SkRegion_swap(SkRegion *region, SkRegion *other);
bool SkRegion_isEmpty(SkRegion *region);
bool SkRegion_isRect(SkRegion *region);
bool SkRegion_isComplex(SkRegion *region);
const SkIRect * SkRegion_getBounds(SkRegion *region);
int SkRegion_computeRegionComplexity(SkRegion *region);
bool SkRegion_getBoundaryPath(SkRegion *region, SkPath *path);
bool SkRegion_setEmpty(SkRegion *region);
bool SkRegion_setRect(SkRegion *region, const SkIRect *rect);
bool SkRegion_setRects(SkRegion *region, const SkIRect rects[], int count);
bool SkRegion_setRegion(SkRegion *region, const SkRegion *region_2);
bool SkRegion_setPath(SkRegion *region, const SkPath *path, const SkRegion *clip);
bool SkRegion_intersects(SkRegion *region, const SkIRect *rect);
bool SkRegion_intersects_2(SkRegion *region, const SkRegion *other);
bool SkRegion_contains(SkRegion *region, int32_t x, int32_t y);
bool SkRegion_contains_2(SkRegion *region, const SkIRect *other);
bool SkRegion_contains_3(SkRegion *region, const SkRegion *other);
bool SkRegion_quickContains(SkRegion *region, const SkIRect *r);
bool SkRegion_quickReject(SkRegion *region, const SkIRect *rect);
bool SkRegion_quickReject_2(SkRegion *region, const SkRegion *rgn);
void SkRegion_translate(SkRegion *region, int dx, int dy);
void SkRegion_translate_2(SkRegion *region, int dx, int dy, SkRegion *dst);
bool SkRegion_op(SkRegion *region, const SkIRect *rect, SkRegion::Op op);
bool SkRegion_op_2(SkRegion *region, const SkRegion *rgn, SkRegion::Op op);
bool SkRegion_op_3(SkRegion *region, const SkIRect *rect, const SkRegion *rgn, SkRegion::Op op);
bool SkRegion_op_4(SkRegion *region, const SkRegion *rgn, const SkIRect *rect, SkRegion::Op op);
bool SkRegion_op_5(SkRegion *region, const SkRegion *rgna, const SkRegion *rgnb, SkRegion::Op op);
size_t SkRegion_writeToMemory(SkRegion *region, void *buffer);
size_t SkRegion_readFromMemory(SkRegion *region, const void *buffer, size_t length);
}

#endif //RAIA_SKIA_SK_REGION_H
