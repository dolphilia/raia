//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_M_44_H
#define RAIA_SKIA_SK_M_44_H

#include "include/core/SkM44.h"
#include "../static/static_sk_m_44.h"
#include "../static/static_sk_matrix.h"

extern "C" {
//SkM44 & operator=(const SkM44 &src)
//bool operator==(const SkM44 &other)
//bool operator!=(const SkM44 &other)
//SkV4 operator*(const SkV4 &v)
//SkV3 operator*(SkV3 v)
SkM44 *SkM44_new(const SkM44 *src);
SkM44 *SkM44_new_2(const SkMatrix *src);
SkM44 *SkM44_new_3();
SkM44 *SkM44_new_4(const SkM44 *a, const SkM44 *b);
SkM44 *SkM44_new_5(SkScalar m0, SkScalar m4, SkScalar m8, SkScalar m12, SkScalar m1, SkScalar m5, SkScalar m9, SkScalar m13, SkScalar m2, SkScalar m6, SkScalar m10, SkScalar m14, SkScalar m3, SkScalar m7, SkScalar m11, SkScalar m15);
void SkM44_delete(SkM44 *m44);
void SkM44_getColMajor(SkM44 *m44, SkScalar v[]);
void SkM44_getRowMajor(SkM44 *m44, SkScalar v[]);
SkScalar SkM44_rc(SkM44 *m44, int r, int c);
void SkM44_setRC(SkM44 *m44, int r, int c, SkScalar value);
SkV4 SkM44_row(SkM44 *m44, int i);
SkV4 SkM44_col(SkM44 *m44, int i);
void SkM44_setRow(SkM44 *m44, int i, const SkV4 *v);
void SkM44_setCol(SkM44 *m44, int i, const SkV4 *v);
int SkM44_setIdentity(SkM44 *m44);
int SkM44_setTranslate(SkM44 *m44, SkScalar x, SkScalar y, SkScalar z);
int SkM44_setScale(SkM44 *m44, SkScalar x, SkScalar y, SkScalar z);
int SkM44_setRotateUnitSinCos(SkM44 *m44, SkV3 axis, SkScalar sinAngle, SkScalar cosAngle);
int SkM44_setRotateUnit(SkM44 *m44, SkV3 axis, SkScalar radians);
int SkM44_setRotate(SkM44 *m44, SkV3 axis, SkScalar radians);
int SkM44_setConcat(SkM44 *m44, const SkM44 *a, const SkM44 *b);
int SkM44_preConcat(SkM44 *m44, const SkM44 *m);
int SkM44_preConcat_2(SkM44 *m44, const SkMatrix *matrix);
int SkM44_postConcat(SkM44 *m44, const SkM44 *m);
void SkM44_normalizePerspective(SkM44 *m44);
bool SkM44_isFinite(SkM44 *m44);
bool SkM44_invert(SkM44 *m44, SkM44 *inverse);
int SkM44_transpose(SkM44 *m44);
void SkM44_dump(SkM44 *m44);
SkV4 SkM44_map(SkM44 *m44, float x, float y, float z, float w);
int SkM44_asM33(SkM44 *m44);
int SkM44_preTranslate(SkM44 *m44, SkScalar x, SkScalar y, SkScalar z);
int SkM44_postTranslate(SkM44 *m44, SkScalar x, SkScalar y, SkScalar z);
int SkM44_preScale(SkM44 *m44, SkScalar x, SkScalar y);
int SkM44_preScale_2(SkM44 *m44, SkScalar x, SkScalar y, SkScalar z);
// static
int SkM44_Rows(const SkV4 *r0, const SkV4 *r1, const SkV4 *r2, const SkV4 *r3);
int SkM44_Cols(const SkV4 *c0, const SkV4 *c1, const SkV4 *c2, const SkV4 *c3);
int SkM44_RowMajor(const SkScalar r[16]);
int SkM44_ColMajor(const SkScalar c[16]);
int SkM44_Translate(SkScalar x, SkScalar y, SkScalar z);
int SkM44_Scale(SkScalar x, SkScalar y, SkScalar z);
int SkM44_Rotate(SkV3 axis, SkScalar radians);
int SkM44_RectToRect(const SkRect *src, const SkRect *dst);
int SkM44_LookAt(const SkV3 *eye, const SkV3 *center, const SkV3 *up);
int SkM44_Perspective(float near, float far, float angle);
}

#endif //RAIA_SKIA_SK_M_44_H
