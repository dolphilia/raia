//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_MATRIX_H
#define RAIA_SKIA_SK_COLOR_MATRIX_H

#ifdef __cplusplus
extern "C" {
#endif

void *SkColorMatrix_new(); // () -> SkColorMatrix *
void *SkColorMatrix_new_2(float m00, float m01, float m02, float m03, float m04, float m10, float m11, float m12, float m13, float m14, float m20, float m21, float m22, float m23, float m24, float m30, float m31, float m32, float m33, float m34); // (float m00, float m01, float m02, float m03, float m04, float m10, float m11, float m12, float m13, float m14, float m20, float m21, float m22, float m23, float m24, float m30, float m31, float m32, float m33, float m34) -> SkColorMatrix *
void SkColorMatrix_delete(void *color_matrix); // (SkColorMatrix *color_matrix)
void SkColorMatrix_setIdentity(void *color_matrix); // (SkColorMatrix *color_matrix)
void SkColorMatrix_setScale(void *color_matrix, float rScale, float gScale, float bScale, float aScale); // (SkColorMatrix *color_matrix, float rScale, float gScale, float bScale, float aScale)
void SkColorMatrix_postTranslate(void *color_matrix, float dr, float dg, float db, float da); // (SkColorMatrix *color_matrix, float dr, float dg, float db, float da)
void SkColorMatrix_setConcat(void *color_matrix, const void *a, const void *b); // (SkColorMatrix *color_matrix, const SkColorMatrix *a, const SkColorMatrix *b)
void SkColorMatrix_preConcat(void *color_matrix, const void *mat); // (SkColorMatrix *color_matrix, const SkColorMatrix *mat)
void SkColorMatrix_postConcat(void *color_matrix, const void *mat); // (SkColorMatrix *color_matrix, const SkColorMatrix *mat)
void SkColorMatrix_setSaturation(void *color_matrix, float sat); // (SkColorMatrix *color_matrix, float sat)
void SkColorMatrix_setRowMajor(void *color_matrix, const float src[20]); // (SkColorMatrix *color_matrix, const float src[20])
void SkColorMatrix_getRowMajor(void *color_matrix, float dst[20]); // (SkColorMatrix *color_matrix, float dst[20])

// static

int SkColorMatrix_RGBtoYUV(int color_space); // (SkYUVColorSpace color_space) -> sk_color_matrix_t
int SkColorMatrix_YUVtoRGB(int color_space); // (SkYUVColorSpace color_space) -> sk_color_matrix_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_COLOR_MATRIX_H
