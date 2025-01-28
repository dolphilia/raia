//
// Created by dolphilia on 2024/01/10.
//

#ifndef RAIA_SKIA_SK_REGION_H
#define RAIA_SKIA_SK_REGION_H

#ifdef __cplusplus
extern "C" {
#endif

//SkRegion & operator=(const SkRegion &region)
//bool operator==(const SkRegion &other)
//bool operator!=(const SkRegion &other)

void *SkRegion_new(); // () -> SkRegion *
void *SkRegion_new_2(const void *region); // (const SkRegion *region) -> SkRegion *
void *SkRegion_new_3(const void *rect); // (const SkIRect *rect) -> SkRegion *
void SkRegion_delete(void *region); // (SkRegion *region)
bool SkRegion_set(void *region, const void *src); // (SkRegion *region, const SkRegion *src) -> bool
void SkRegion_swap(void *region, void *other); // (SkRegion *region, SkRegion *other)
bool SkRegion_isEmpty(void *region); // (SkRegion *region) -> bool
bool SkRegion_isRect(void *region); // (SkRegion *region) -> bool
bool SkRegion_isComplex(void *region); // (SkRegion *region) -> bool
const void *SkRegion_getBounds(void *region); // (SkRegion *region) -> const SkIRect *
int SkRegion_computeRegionComplexity(void *region); // (SkRegion *region) -> int
bool SkRegion_getBoundaryPath(void *region, void *path); // (SkRegion *region, SkPath *path) -> bool
bool SkRegion_setEmpty(void *region); // (SkRegion *region) -> bool
bool SkRegion_setRect(void *region, const void *rect); // (SkRegion *region, const SkIRect *rect) -> bool
bool SkRegion_setRects(void *region, const void * rects, int count); // (SkRegion *region, const SkIRect rects[], int count) -> bool
bool SkRegion_setRegion(void *region, const void *region_2); // (SkRegion *region, const SkRegion *region_2) -> bool
bool SkRegion_setPath(void *region, const void *path, const void *clip); // (SkRegion *region, const SkPath *path, const SkRegion *clip) -> bool
bool SkRegion_intersects(void *region, const void *rect); // (SkRegion *region, const SkIRect *rect) -> bool
bool SkRegion_intersects_2(void *region, const void *other); // (SkRegion *region, const SkRegion *other) -> bool
bool SkRegion_contains(void *region, int x, int y); // (SkRegion *region, int32_t x, int32_t y) -> bool
bool SkRegion_contains_2(void *region, const void *other); // (SkRegion *region, const SkIRect *other) -> bool
bool SkRegion_contains_3(void *region, const void *other); // (SkRegion *region, const SkRegion *other) -> bool
bool SkRegion_quickContains(void *region, const void *r); // (SkRegion *region, const SkIRect *r) -> bool
bool SkRegion_quickReject(void *region, const void *rect); // (SkRegion *region, const SkIRect *rect) -> bool
bool SkRegion_quickReject_2(void *region, const void *rgn); // (SkRegion *region, const SkRegion *rgn) -> bool
void SkRegion_translate(void *region, int dx, int dy); // (SkRegion *region, int dx, int dy)
void SkRegion_translate_2(void *region, int dx, int dy, void *dst); // (SkRegion *region, int dx, int dy, SkRegion *dst)
bool SkRegion_op(void *region, const void *rect, int op); // (SkRegion *region, const SkIRect *rect, SkRegion::Op op) -> bool
bool SkRegion_op_2(void *region, const void *rgn, int op); // (SkRegion *region, const SkRegion *rgn, SkRegion::Op op) -> bool
bool SkRegion_op_3(void *region, const void *rect, const void *rgn, int op); // (SkRegion *region, const SkIRect *rect, const SkRegion *rgn, SkRegion::Op op) -> bool
bool SkRegion_op_4(void *region, const void *rgn, const void *rect, int op); // (SkRegion *region, const SkRegion *rgn, const SkIRect *rect, SkRegion::Op op) -> bool
bool SkRegion_op_5(void *region, const void *rgna, const void *rgnb, int op); // (SkRegion *region, const SkRegion *rgna, const SkRegion *rgnb, SkRegion::Op op) -> bool
unsigned long SkRegion_writeToMemory(void *region, void *buffer); // (SkRegion *region, void *buffer) -> size_t
unsigned long SkRegion_readFromMemory(void *region, const void *buffer, unsigned long length); // (SkRegion *region, const void *buffer, size_t length) -> size_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_REGION_H
