//
// Created by dolphilia on 2024/01/08.
//

#include "sk_color_matrix.h"

extern "C" {

SkColorMatrix *SkColorMatrix_new() {
    return new SkColorMatrix();
}

SkColorMatrix *SkColorMatrix_new_2(float m00, float m01, float m02, float m03, float m04, float m10, float m11, float m12, float m13, float m14, float m20, float m21, float m22, float m23, float m24, float m30, float m31, float m32, float m33, float m34) {
    return new SkColorMatrix(m00, m01, m02, m03, m04, m10, m11, m12, m13, m14, m20, m21, m22, m23, m24, m30, m31, m32, m33, m34);
}

void SkColorMatrix_delete(SkColorMatrix *color_matrix) {
    delete color_matrix;
}

void SkColorMatrix_setIdentity(SkColorMatrix *color_matrix) {
    color_matrix->setIdentity();
}

void SkColorMatrix_setScale(SkColorMatrix *color_matrix, float rScale, float gScale, float bScale, float aScale) {
    color_matrix->setScale(rScale, gScale, bScale, aScale);
}

void SkColorMatrix_postTranslate(SkColorMatrix *color_matrix, float dr, float dg, float db, float da) {
    color_matrix->postTranslate(dr, dg, db, da);
}

void SkColorMatrix_setConcat(SkColorMatrix *color_matrix, const SkColorMatrix *a, const SkColorMatrix *b) {
    color_matrix->setConcat(*a, *b);
}

void SkColorMatrix_preConcat(SkColorMatrix *color_matrix, const SkColorMatrix *mat) {
    color_matrix->preConcat(*mat);
}

void SkColorMatrix_postConcat(SkColorMatrix *color_matrix, const SkColorMatrix *mat) {
    color_matrix->postConcat(*mat);
}

void SkColorMatrix_setSaturation(SkColorMatrix *color_matrix, float sat) {
    color_matrix->setSaturation(sat);
}

void SkColorMatrix_setRowMajor(SkColorMatrix *color_matrix, const float src[20]) {
    color_matrix->setRowMajor(src);
}

void SkColorMatrix_getRowMajor(SkColorMatrix *color_matrix, float dst[20]) {
    color_matrix->getRowMajor(dst);
}

// static

sk_color_matrix_t SkColorMatrix_RGBtoYUV(SkYUVColorSpace color_space) {
    return static_sk_color_matrix_make(SkColorMatrix::RGBtoYUV(color_space));
}

sk_color_matrix_t SkColorMatrix_YUVtoRGB(SkYUVColorSpace color_space) {
    return static_sk_color_matrix_make(SkColorMatrix::YUVtoRGB(color_space));
}

}