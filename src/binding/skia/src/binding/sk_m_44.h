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
void SkM44_getColMajor(SkM44 *m44, SkScalar v[]);
void SkM44_getRowMajor(SkM44 *m44, SkScalar v[]);
SkScalar SkM44_rc(SkM44 *m44, int r, int c);
void SkM44_setRC(SkM44 *m44, int r, int c, SkScalar value);
SkV4 SkM44_row(SkM44 *m44, int i);
SkV4 SkM44_col(SkM44 *m44, int i);
void SkM44_setRow(SkM44 *m44, int i, const SkV4 *v);
void SkM44_setCol(SkM44 *m44, int i, const SkV4 *v);
void SkM44_setIdentity(const char* sk_m_44_key_out, SkM44 *m44);
void SkM44_setTranslate(const char* sk_m_44_key_out, SkM44 *m44, SkScalar x, SkScalar y, SkScalar z);
void SkM44_setScale(const char* sk_m_44_key_out, SkM44 *m44, SkScalar x, SkScalar y, SkScalar z);
void SkM44_setRotateUnitSinCos(const char* sk_m_44_key_out, SkM44 *m44, SkV3 axis, SkScalar sinAngle, SkScalar cosAngle);
void SkM44_setRotateUnit(const char* sk_m_44_key_out, SkM44 *m44, SkV3 axis, SkScalar radians);
void SkM44_setRotate(const char* sk_m_44_key_out, SkM44 *m44, SkV3 axis, SkScalar radians);
void SkM44_setConcat(const char* sk_m_44_key_out, SkM44 *m44, const SkM44 *a, const SkM44 *b);
void SkM44_preConcat(const char* sk_m_44_key_out, SkM44 *m44, const SkM44 *m);
void SkM44_preConcat_2(const char* sk_m_44_key_out, SkM44 *m44, const SkMatrix *matrix);
void SkM44_postConcat(const char* sk_m_44_key_out, SkM44 *m44, const SkM44 *m);
void SkM44_normalizePerspective(SkM44 *m44);
bool SkM44_isFinite(SkM44 *m44);
bool SkM44_invert(SkM44 *m44, SkM44 *inverse);
void SkM44_transpose(const char* sk_m_44_key_out, SkM44 *m44);
void SkM44_dump(SkM44 *m44);
SkV4 SkM44_map(SkM44 *m44, float x, float y, float z, float w);
void SkM44_asM33(const char* sk_matrix_key_out, SkM44 *m44);
void SkM44_preTranslate(const char* sk_m_44_key_out, SkM44 *m44, SkScalar x, SkScalar y, SkScalar z);
void SkM44_postTranslate(const char* sk_m_44_key_out, SkM44 *m44, SkScalar x, SkScalar y, SkScalar z);
void SkM44_preScale(const char* sk_m_44_key_out, SkM44 *m44, SkScalar x, SkScalar y);
void SkM44_preScale_2(const char* sk_m_44_key_out, SkM44 *m44, SkScalar x, SkScalar y, SkScalar z);
// static
void SkM44_Rows(const char* sk_m_44_key_out, const SkV4 *r0, const SkV4 *r1, const SkV4 *r2, const SkV4 *r3);
void SkM44_Cols(const char* sk_m_44_key_out, const SkV4 *c0, const SkV4 *c1, const SkV4 *c2, const SkV4 *c3);
void SkM44_RowMajor(const char* sk_m_44_key_out, const SkScalar r[16]);
void SkM44_ColMajor(const char* sk_m_44_key_out, const SkScalar c[16]);
void SkM44_Translate(const char* sk_m_44_key_out, SkScalar x, SkScalar y, SkScalar z);
void SkM44_Scale(const char* sk_m_44_key_out, SkScalar x, SkScalar y, SkScalar z);
void SkM44_Rotate(const char* sk_m_44_key_out, SkV3 axis, SkScalar radians);
void SkM44_RectToRect(const char* sk_m_44_key_out, const SkRect *src, const SkRect *dst);
void SkM44_LookAt(const char* sk_m_44_key_out, const SkV3 *eye, const SkV3 *center, const SkV3 *up);
void SkM44_Perspective(const char* sk_m_44_key_out, float near, float far, float angle);
}

#endif //RAIA_SKIA_SK_M_44_H
