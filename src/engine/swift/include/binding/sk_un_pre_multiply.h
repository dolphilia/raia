//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_UN_PRE_MULTIPLY_H
#define RAIA_SKIA_SK_UN_PRE_MULTIPLY_H

#include "include/core/SkUnPreMultiply.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkUnPreMultiply_delete(SkUnPreMultiply * unPreMultiply);
// static
RAIA_API const SkUnPreMultiply::Scale * SkUnPreMultiply_GetScaleTable();
RAIA_API SkUnPreMultiply::Scale SkUnPreMultiply_GetScale(U8CPU alpha);
RAIA_API U8CPU SkUnPreMultiply_ApplyScale(SkUnPreMultiply::Scale scale, U8CPU component);
RAIA_API SkColor SkUnPreMultiply_PMColorToColor(SkPMColor c);
}

#endif //RAIA_SKIA_SK_UN_PRE_MULTIPLY_H
