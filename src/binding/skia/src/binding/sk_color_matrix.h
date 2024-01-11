//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_MATRIX_H
#define RAIA_SKIA_SK_COLOR_MATRIX_H

#include "include/effects/SkColorMatrix.h"

extern "C" {
SkColorMatrix *SkColorMatrix_new();
SkColorMatrix *SkColorMatrix_new_2(float m00, float m01, float m02, float m03, float m04, float m10, float m11, float m12, float m13, float m14, float m20, float m21, float m22, float m23, float m24, float m30, float m31, float m32, float m33, float m34);
void SkColorMatrix_setIdentity(SkColorMatrix *color_matrix);
void SkColorMatrix_setScale(SkColorMatrix *color_matrix, float rScale, float gScale, float bScale, float aScale);
void SkColorMatrix_postTranslate(SkColorMatrix *color_matrix, float dr, float dg, float db, float da);
void SkColorMatrix_setConcat(SkColorMatrix *color_matrix, const SkColorMatrix *a, const SkColorMatrix *b);
void SkColorMatrix_preConcat(SkColorMatrix *color_matrix, const SkColorMatrix *mat);
void SkColorMatrix_postConcat(SkColorMatrix *color_matrix, const SkColorMatrix *mat);
void SkColorMatrix_setSaturation(SkColorMatrix *color_matrix, float sat);
void SkColorMatrix_setRowMajor(SkColorMatrix *color_matrix, const float src[20]);
void SkColorMatrix_getRowMajor(SkColorMatrix *color_matrix, float dst[20]);
// static
void SkColorMatrix_RGBtoYUV(const char *sk_color_matrix_key_out, SkYUVColorSpace color_space);
void SkColorMatrix_YUVtoRGB(const char *sk_color_matrix_key_out, SkYUVColorSpace color_space);
}

#endif //RAIA_SKIA_SK_COLOR_MATRIX_H