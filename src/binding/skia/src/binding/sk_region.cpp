//
// Created by dolphilia on 2024/01/10.
//

#include "sk_region.h"

extern "C" {

//SkRegion & operator=(const SkRegion &region)
//bool operator==(const SkRegion &other)
//bool operator!=(const SkRegion &other)

SkRegion *SkRegion_new() {
    return new SkRegion();
}

SkRegion *SkRegion_new_2(const SkRegion *region) {
    return new SkRegion(*region);
}

SkRegion *SkRegion_new_3(const SkIRect *rect) {
    return new SkRegion(*rect);
}

void SkRegion_delete(SkRegion *region) {
    delete region;
}

bool SkRegion_set(SkRegion *region, const SkRegion *src) {
    return region->set(*src);
}

void SkRegion_swap(SkRegion *region, SkRegion *other) {
    return region->swap(*other);
}

bool SkRegion_isEmpty(SkRegion *region) {
    return region->isEmpty();
}

bool SkRegion_isRect(SkRegion *region) {
    return region->isRect();
}

bool SkRegion_isComplex(SkRegion *region) {
    return region->isComplex();
}

const SkIRect * SkRegion_getBounds(SkRegion *region) {
    return &region->getBounds();
}

int SkRegion_computeRegionComplexity(SkRegion *region) {
    return region->computeRegionComplexity();
}

bool SkRegion_getBoundaryPath(SkRegion *region, SkPath *path) {
    return region->getBoundaryPath(path);
}

bool SkRegion_setEmpty(SkRegion *region) {
    return region->setEmpty();
}

bool SkRegion_setRect(SkRegion *region, const SkIRect *rect) {
    return region->setRect(*rect);
}

bool SkRegion_setRects(SkRegion *region, const SkIRect rects[], int count) {
    return region->setRects(rects, count);
}

bool SkRegion_setRegion(SkRegion *region, const SkRegion *region_2) {
    return region->setRegion(*region_2);
}

bool SkRegion_setPath(SkRegion *region, const SkPath *path, const SkRegion *clip) {
    return region->setPath(*path, *clip);
}

bool SkRegion_intersects(SkRegion *region, const SkIRect *rect) {
    return region->intersects(*rect);
}

bool SkRegion_intersects_2(SkRegion *region, const SkRegion *other) {
    return region->intersects(*other);
}

bool SkRegion_contains(SkRegion *region, int32_t x, int32_t y) {
    return region->contains(x, y);
}

bool SkRegion_contains_2(SkRegion *region, const SkIRect *other) {
    return region->contains(*other);
}

bool SkRegion_contains_3(SkRegion *region, const SkRegion *other) {
    return region->contains(*other);
}

bool SkRegion_quickContains(SkRegion *region, const SkIRect *r) {
    return region->quickContains(*r);
}

bool SkRegion_quickReject(SkRegion *region, const SkIRect *rect) {
    return region->quickReject(*rect);
}

bool SkRegion_quickReject_2(SkRegion *region, const SkRegion *rgn) {
    return region->quickReject(*rgn);
}

void SkRegion_translate(SkRegion *region, int dx, int dy) {
    region->translate(dx, dy);
}

void SkRegion_translate_2(SkRegion *region, int dx, int dy, SkRegion *dst) {
    region->translate(dx, dy, dst);
}

bool SkRegion_op(SkRegion *region, const SkIRect *rect, SkRegion::Op op) {
    return region->op(*rect, op);
}

bool SkRegion_op_2(SkRegion *region, const SkRegion *rgn, SkRegion::Op op) {
    return region->op(*rgn, op);
}

bool SkRegion_op_3(SkRegion *region, const SkIRect *rect, const SkRegion *rgn, SkRegion::Op op) {
    return region->op(*rect, *rgn, op);
}

bool SkRegion_op_4(SkRegion *region, const SkRegion *rgn, const SkIRect *rect, SkRegion::Op op) {
    return region->op(*rgn, *rect, op);
}

bool SkRegion_op_5(SkRegion *region, const SkRegion *rgna, const SkRegion *rgnb, SkRegion::Op op) {
    return region->op(*rgna, *rgnb, op);
}

size_t SkRegion_writeToMemory(SkRegion *region, void *buffer) {
    return region->writeToMemory(buffer);
}

size_t SkRegion_readFromMemory(SkRegion *region, const void *buffer, size_t length) {
    return region->readFromMemory(buffer, length);
}

}