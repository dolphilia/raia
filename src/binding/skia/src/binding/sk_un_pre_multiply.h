//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_UN_PRE_MULTIPLY_H
#define RAIA_SKIA_SK_UN_PRE_MULTIPLY_H

#include "include/core/SkUnPreMultiply.h"

extern "C" {
void SkUnPreMultiply_delete(SkUnPreMultiply * unPreMultiply);
// static
const SkUnPreMultiply::Scale * SkUnPreMultiply_GetScaleTable();
SkUnPreMultiply::Scale SkUnPreMultiply_GetScale(U8CPU alpha);
U8CPU SkUnPreMultiply_ApplyScale(SkUnPreMultiply::Scale scale, U8CPU component);
SkColor SkUnPreMultiply_PMColorToColor(SkPMColor c);
}

#endif //RAIA_SKIA_SK_UN_PRE_MULTIPLY_H
