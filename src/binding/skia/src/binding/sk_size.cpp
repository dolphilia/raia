//
// Created by dolphilia on 2024/01/11.
//

#include "sk_size.h"

extern "C" {

void SkSize_set(SkSize *size, SkScalar w, SkScalar h) {
    size->set(w, h);
}

bool SkSize_isZero(SkSize *size) {
    return size->isZero();
}

bool SkSize_isEmpty(SkSize *size) {
    return size->isEmpty();
}

void SkSize_setEmpty(SkSize *size) {
    size->setEmpty();
}

SkScalar SkSize_width(SkSize *size) {
    return size->width();
}

SkScalar SkSize_height(SkSize *size) {
    return size->height();
}

bool SkSize_equals(SkSize *size, SkScalar w, SkScalar h) {
    return size->equals(w, h);
}

SkISize SkSize_toRound(SkSize *size) {
    return size->toRound();
}

SkISize SkSize_toCeil(SkSize *size) {
    return size->toCeil();
}

SkISize SkSize_toFloor(SkSize *size) {
    return size->toFloor();
}

// static

SkSize SkSize_Make(SkScalar w, SkScalar h) {
    return SkSize::Make(w, h);
}

SkSize SkSize_Make_2(const SkISize *src) {
    return SkSize::Make(*src);
}

SkSize SkSize_MakeEmpty() {
    return SkSize::MakeEmpty();
}

}