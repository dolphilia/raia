//
// Created by dolphilia on 2024/01/11.
//

#include "sk_un_pre_multiply.h"

extern "C" {

void SkUnPreMultiply_delete(SkUnPreMultiply * unPreMultiply) {
    delete unPreMultiply;
}

// static

const SkUnPreMultiply::Scale * SkUnPreMultiply_GetScaleTable() {
    return SkUnPreMultiply::GetScaleTable();
}

SkUnPreMultiply::Scale SkUnPreMultiply_GetScale(U8CPU alpha) {
    return SkUnPreMultiply::GetScale(alpha);
}

U8CPU SkUnPreMultiply_ApplyScale(SkUnPreMultiply::Scale scale, U8CPU component) {
    return SkUnPreMultiply::ApplyScale(scale, component);
}

SkColor SkUnPreMultiply_PMColorToColor(SkPMColor c) {
    return SkUnPreMultiply::PMColorToColor(c);
}

}