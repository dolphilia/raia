//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_MATRIX_H
#define RAIA_SKIA_SK_COLOR_MATRIX_H

#include "include/effects/SkColorMatrix.h"
#include "../static/static_sk_color_matrix.h"
#include "export_api.h"

extern "C" {
RAIA_API SkColorMatrix *SkColorMatrix_new();
RAIA_API SkColorMatrix *SkColorMatrix_new_2(float m00, float m01, float m02, float m03, float m04, float m10, float m11, float m12, float m13, float m14, float m20, float m21, float m22, float m23, float m24, float m30, float m31, float m32, float m33, float m34);
RAIA_API void SkColorMatrix_delete(SkColorMatrix *color_matrix);
RAIA_API void SkColorMatrix_setIdentity(SkColorMatrix *color_matrix);
RAIA_API void SkColorMatrix_setScale(SkColorMatrix *color_matrix, float rScale, float gScale, float bScale, float aScale);
RAIA_API void SkColorMatrix_postTranslate(SkColorMatrix *color_matrix, float dr, float dg, float db, float da);
RAIA_API void SkColorMatrix_setConcat(SkColorMatrix *color_matrix, const SkColorMatrix *a, const SkColorMatrix *b);
RAIA_API void SkColorMatrix_preConcat(SkColorMatrix *color_matrix, const SkColorMatrix *mat);
RAIA_API void SkColorMatrix_postConcat(SkColorMatrix *color_matrix, const SkColorMatrix *mat);
RAIA_API void SkColorMatrix_setSaturation(SkColorMatrix *color_matrix, float sat);
RAIA_API void SkColorMatrix_setRowMajor(SkColorMatrix *color_matrix, const float src[20]);
RAIA_API void SkColorMatrix_getRowMajor(SkColorMatrix *color_matrix, float dst[20]);
// static
RAIA_API sk_color_matrix_t SkColorMatrix_RGBtoYUV(SkYUVColorSpace color_space);
RAIA_API sk_color_matrix_t SkColorMatrix_YUVtoRGB(SkYUVColorSpace color_space);
}

#endif //RAIA_SKIA_SK_COLOR_MATRIX_H
