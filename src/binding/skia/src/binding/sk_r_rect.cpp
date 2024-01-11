//
// Created by dolphilia on 2024/01/10.
//

#include "sk_r_rect.h"

extern "C" {

//SkRRect & operator=(const SkRRect &rrect)

SkRRect *SkRRect_new() {
    return new SkRRect();
}

SkRRect *SkRRect_new_2(const SkRRect &rrect) {
    return new SkRRect(rrect);
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

SkVector SkRRect_getSimpleRadii(SkRRect *rrect) {
    return rrect->getSimpleRadii();
}

void SkRRect_setEmpty(SkRRect *rrect) {
    rrect->setEmpty();
}

void SkRRect_setRect(SkRRect *rrect, const SkRect &rect) {
    rrect->setRect(rect);
}

void SkRRect_setOval(SkRRect *rrect, const SkRect &oval) {
    rrect->setOval(oval);
}

void SkRRect_setRectXY(SkRRect *rrect, const SkRect &rect, SkScalar xRad, SkScalar yRad) {
    rrect->setRectXY(rect, xRad, yRad);
}

void SkRRect_setNinePatch(SkRRect *rrect, const SkRect &rect, SkScalar leftRad, SkScalar topRad, SkScalar rightRad, SkScalar bottomRad) {
    rrect->setNinePatch(rect, leftRad, topRad, rightRad, bottomRad);
}

void SkRRect_setRectRadii(SkRRect *rrect, const SkRect &rect, const SkVector radii[4]) {
    rrect->setRectRadii(rect, radii);
}

const SkRect * SkRRect_rect(SkRRect *rrect) {
    return &rrect->rect();
}

SkVector SkRRect_radii(SkRRect *rrect, SkRRect::Corner corner) {
    return rrect->radii(corner);
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

void SkRRect_makeOffset(const char *sk_r_rect_key_out, SkRRect *rrect, SkScalar dx, SkScalar dy) {
    static_sk_r_rect_set(sk_r_rect_key_out, rrect->makeOffset(dx, dy));
}

bool SkRRect_contains(SkRRect *rrect, const SkRect &rect) {
    return rrect->contains(rect);
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

bool SkRRect_transform(SkRRect *rrect, const SkMatrix &matrix, SkRRect *dst) {
    return rrect->transform(matrix, dst);
}

void SkRRect_dump(SkRRect *rrect, bool asHex) {
    rrect->dump(asHex);
}

void SkRRect_dumpToString(const char *sk_string_key_out, SkRRect *rrect, bool asHex) {
    static_sk_string_set(sk_string_key_out, rrect->dumpToString(asHex));
}

void SkRRect_dump_2(SkRRect *rrect) {
    rrect->dump();
}

void SkRRect_dumpHex(SkRRect *rrect) {
    rrect->dumpHex();
}

// static

void SkRRect_MakeEmpty(const char *sk_r_rect_key_out) {
    static_sk_r_rect_set(sk_r_rect_key_out, SkRRect::MakeEmpty());
}

void SkRRect_MakeRect(const char *sk_r_rect_key_out, const SkRect &r) {
    static_sk_r_rect_set(sk_r_rect_key_out, SkRRect::MakeRect(r));
}

void SkRRect_MakeOval(const char *sk_r_rect_key_out, const SkRect &oval) {
    static_sk_r_rect_set(sk_r_rect_key_out, SkRRect::MakeOval(oval));
}

void SkRRect_MakeRectXY(const char *sk_r_rect_key_out, const SkRect &rect, SkScalar xRad, SkScalar yRad) {
    static_sk_r_rect_set(sk_r_rect_key_out, SkRRect::MakeRectXY(rect, xRad, yRad));
}

}