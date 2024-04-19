//
// Created by dolphilia on 2024/01/11.
//

#include "sk_size.h"

extern "C" {

void SkSize_delete(SkSize *size) {
    delete size;
}

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

sk_i_size_t SkSize_toRound(SkSize *size) {
    return static_sk_i_size_make(size->toRound());
}

sk_i_size_t SkSize_toCeil(SkSize *size) {
    return static_sk_i_size_make(size->toCeil());
}

sk_i_size_t SkSize_toFloor(SkSize *size) {
    return static_sk_i_size_make(size->toFloor());
}

// static

sk_size_t SkSize_Make(SkScalar w, SkScalar h) {
    return static_sk_size_make(SkSize::Make(w, h));
}

sk_size_t SkSize_Make_2(const SkISize *src) {
    return static_sk_size_make(SkSize::Make(*src));
}

sk_size_t SkSize_MakeEmpty() {
    return static_sk_size_make(SkSize::MakeEmpty());
}

}