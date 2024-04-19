//
// Created by dolphilia on 2024/01/10.
//

#include "sk_r_rect.h"

extern "C" {

//SkRRect & operator=(const SkRRect &rrect)

SkRRect *SkRRect_new() {
    return new SkRRect();
}

SkRRect *SkRRect_new_2(const SkRRect *rrect) {
    return new SkRRect(*rrect);
}

void SkRRect_delete(SkRRect *rrect) {
    delete rrect;
}

SkRRect::Type getType(SkRRect *rrect) {
    return rrect->getType();
}

SkRRect::Type type(SkRRect *rrect) {
    return rrect->type();
}

bool SkRRect_isEmpty(SkRRect *rrect) {
    return rrect->isEmpty();
}

bool SkRRect_isRect(SkRRect *rrect) {
    return rrect->isRect();
}

bool SkRRect_isOval(SkRRect *rrect) {
    return rrect->isOval();
}

bool SkRRect_isSimple(SkRRect *rrect) {
    return rrect->isSimple();
}

bool SkRRect_isNinePatch(SkRRect *rrect) {
    return rrect->isNinePatch();
}

bool SkRRect_isComplex(SkRRect *rrect) {
    return rrect->isComplex();
}

SkScalar SkRRect_width(SkRRect *rrect) {
    return rrect->width();
}

SkScalar SkRRect_height(SkRRect *rrect) {
    return rrect->height();
}

sk_point_t SkRRect_getSimpleRadii(SkRRect *rrect) {
    return static_sk_point_make(rrect->getSimpleRadii());
}

void SkRRect_setEmpty(SkRRect *rrect) {
    rrect->setEmpty();
}

void SkRRect_setRect(SkRRect *rrect, const SkRect *rect) {
    rrect->setRect(*rect);
}

void SkRRect_setOval(SkRRect *rrect, const SkRect *oval) {
    rrect->setOval(*oval);
}

void SkRRect_setRectXY(SkRRect *rrect, const SkRect *rect, SkScalar xRad, SkScalar yRad) {
    rrect->setRectXY(*rect, xRad, yRad);
}

void SkRRect_setNinePatch(SkRRect *rrect, const SkRect *rect, SkScalar leftRad, SkScalar topRad, SkScalar rightRad, SkScalar bottomRad) {
    rrect->setNinePatch(*rect, leftRad, topRad, rightRad, bottomRad);
}

void SkRRect_setRectRadii(SkRRect *rrect, const SkRect *rect, const SkVector radii[4]) {
    rrect->setRectRadii(*rect, radii);
}

const SkRect * SkRRect_rect(SkRRect *rrect) {
    return &rrect->rect();
}

sk_point_t SkRRect_radii(SkRRect *rrect, SkRRect::Corner corner) {
    return static_sk_point_make(rrect->radii(corner));
}

const SkRect * SkRRect_getBounds(SkRRect *rrect) {
    return &rrect->getBounds();
}

void SkRRect_inset(SkRRect *rrect, SkScalar dx, SkScalar dy, SkRRect *dst) {
    rrect->inset(dx, dy, dst);
}

void SkRRect_inset_2(SkRRect *rrect, SkScalar dx, SkScalar dy) {
    rrect->inset(dx, dy);
}

void SkRRect_outset(SkRRect *rrect, SkScalar dx, SkScalar dy, SkRRect *dst) {
    rrect->outset(dx, dy, dst);
}

void SkRRect_outset_2(SkRRect *rrect, SkScalar dx, SkScalar dy) {
    rrect->outset(dx, dy);
}

void SkRRect_offset(SkRRect *rrect, SkScalar dx, SkScalar dy) {
    rrect->offset(dx, dy);
}

sk_r_rect_t SkRRect_makeOffset(SkRRect *rrect, SkScalar dx, SkScalar dy) {
    return static_sk_r_rect_make(rrect->makeOffset(dx, dy));
}

bool SkRRect_contains(SkRRect *rrect, const SkRect *rect) {
    return rrect->contains(*rect);
}

bool SkRRect_isValid(SkRRect *rrect) {
    return rrect->isValid();
}

size_t SkRRect_writeToMemory(SkRRect *rrect, void *buffer) {
    return rrect->writeToMemory(buffer);
}

size_t SkRRect_readFromMemory(SkRRect *rrect, const void *buffer, size_t length) {
    return rrect->readFromMemory(buffer, length);
}

bool SkRRect_transform(SkRRect *rrect, const SkMatrix *matrix, SkRRect *dst) {
    return rrect->transform(*matrix, dst);
}

void SkRRect_dump(SkRRect *rrect, bool asHex) {
    rrect->dump(asHex);
}

sk_string_t SkRRect_dumpToString(SkRRect *rrect, bool asHex) {
    return static_sk_string_make(rrect->dumpToString(asHex));
}

void SkRRect_dump_2(SkRRect *rrect) {
    rrect->dump();
}

void SkRRect_dumpHex(SkRRect *rrect) {
    rrect->dumpHex();
}

// static

sk_r_rect_t SkRRect_MakeEmpty() {
    return static_sk_r_rect_make(SkRRect::MakeEmpty());
}

sk_r_rect_t SkRRect_MakeRect(const SkRect *r) {
    return static_sk_r_rect_make(SkRRect::MakeRect(*r));
}

sk_r_rect_t SkRRect_MakeOval(const SkRect *oval) {
    return static_sk_r_rect_make(SkRRect::MakeOval(*oval));
}

sk_r_rect_t SkRRect_MakeRectXY(const SkRect *rect, SkScalar xRad, SkScalar yRad) {
    return static_sk_r_rect_make(SkRRect::MakeRectXY(*rect, xRad, yRad));
}

}