//
// Created by dolphilia on 2024/01/09.
//

#include "sk_i_size.h"

extern "C" {

void SkISize_delete(SkISize *i_size) {
    delete i_size;
}

void SkISize_set(SkISize *i_size, int32_t w, int32_t h) {
    i_size->set(w, h);
}

bool SkISize_isZero(SkISize *i_size) {
    return i_size->isZero();
}

bool SkISize_isEmpty(SkISize *i_size) {
    return i_size->isEmpty();
}

void SkISize_setEmpty(SkISize *i_size) {
    return i_size->setEmpty();
}

int32_t SkISize_width(SkISize *i_size) {
    return i_size->width();
}

int32_t SkISize_height(SkISize *i_size) {
    return i_size->height();
}

int64_t SkISize_area(SkISize *i_size) {
    return i_size->area();
}

bool SkISize_equals(SkISize *i_size, int32_t w, int32_t h) {
    return i_size->equals(w, h);
}

// static

SkISize SkISize_Make(int32_t w, int32_t h) {
    return SkISize::Make(w, h);
}

SkISize SkISize_MakeEmpty() {
    return SkISize::MakeEmpty();
}

}