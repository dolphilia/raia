//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_REGION_H
#define RAIA_SKIA_SK_REGION_H

#include "include/core/SkRegion.h"
#include "export_api.h"

extern "C" {
//SkRegion & operator=(const SkRegion &region)
//bool operator==(const SkRegion &other)
//bool operator!=(const SkRegion &other)
RAIA_API SkRegion *SkRegion_new();
RAIA_API SkRegion *SkRegion_new_2(const SkRegion *region);
RAIA_API SkRegion *SkRegion_new_3(const SkIRect *rect);
RAIA_API void SkRegion_delete(SkRegion *region);
RAIA_API bool SkRegion_set(SkRegion *region, const SkRegion *src);
RAIA_API void SkRegion_swap(SkRegion *region, SkRegion *other);
RAIA_API bool SkRegion_isEmpty(SkRegion *region);
RAIA_API bool SkRegion_isRect(SkRegion *region);
RAIA_API bool SkRegion_isComplex(SkRegion *region);
RAIA_API const SkIRect * SkRegion_getBounds(SkRegion *region);
RAIA_API int SkRegion_computeRegionComplexity(SkRegion *region);
RAIA_API bool SkRegion_getBoundaryPath(SkRegion *region, SkPath *path);
RAIA_API bool SkRegion_setEmpty(SkRegion *region);
RAIA_API bool SkRegion_setRect(SkRegion *region, const SkIRect *rect);
RAIA_API bool SkRegion_setRects(SkRegion *region, const SkIRect rects[], int count);
RAIA_API bool SkRegion_setRegion(SkRegion *region, const SkRegion *region_2);
RAIA_API bool SkRegion_setPath(SkRegion *region, const SkPath *path, const SkRegion *clip);
RAIA_API bool SkRegion_intersects(SkRegion *region, const SkIRect *rect);
RAIA_API bool SkRegion_intersects_2(SkRegion *region, const SkRegion *other);
RAIA_API bool SkRegion_contains(SkRegion *region, int32_t x, int32_t y);
RAIA_API bool SkRegion_contains_2(SkRegion *region, const SkIRect *other);
RAIA_API bool SkRegion_contains_3(SkRegion *region, const SkRegion *other);
RAIA_API bool SkRegion_quickContains(SkRegion *region, const SkIRect *r);
RAIA_API bool SkRegion_quickReject(SkRegion *region, const SkIRect *rect);
RAIA_API bool SkRegion_quickReject_2(SkRegion *region, const SkRegion *rgn);
RAIA_API void SkRegion_translate(SkRegion *region, int dx, int dy);
RAIA_API void SkRegion_translate_2(SkRegion *region, int dx, int dy, SkRegion *dst);
RAIA_API bool SkRegion_op(SkRegion *region, const SkIRect *rect, SkRegion::Op op);
RAIA_API bool SkRegion_op_2(SkRegion *region, const SkRegion *rgn, SkRegion::Op op);
RAIA_API bool SkRegion_op_3(SkRegion *region, const SkIRect *rect, const SkRegion *rgn, SkRegion::Op op);
RAIA_API bool SkRegion_op_4(SkRegion *region, const SkRegion *rgn, const SkIRect *rect, SkRegion::Op op);
RAIA_API bool SkRegion_op_5(SkRegion *region, const SkRegion *rgna, const SkRegion *rgnb, SkRegion::Op op);
RAIA_API size_t SkRegion_writeToMemory(SkRegion *region, void *buffer);
RAIA_API size_t SkRegion_readFromMemory(SkRegion *region, const void *buffer, size_t length);
}

#endif //RAIA_SKIA_SK_REGION_H
