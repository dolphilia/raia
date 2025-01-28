//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_UN_PRE_MULTIPLY_H
#define RAIA_SKIA_SK_UN_PRE_MULTIPLY_H

#ifdef __cplusplus
extern "C" {
#endif

void SkUnPreMultiply_delete(void *unPreMultiply); // (SkUnPreMultiply *unPreMultiply)

// static

const void * SkUnPreMultiply_GetScaleTable(); // () -> const SkUnPreMultiply::Scale *
unsigned int SkUnPreMultiply_GetScale(unsigned int alpha); // (U8CPU alpha) -> SkUnPreMultiply::Scale
unsigned int SkUnPreMultiply_ApplyScale(unsigned int scale, unsigned int component); // (SkUnPreMultiply::Scale scale, U8CPU component) -> U8CPU
unsigned int SkUnPreMultiply_PMColorToColor(unsigned int c); // (SkPMColor c) -> SkColor

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_UN_PRE_MULTIPLY_H
