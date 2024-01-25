//
// Created by dolphilia on 2024/01/09.
//

#include "sk_m_44.h"

extern "C" {

//SkM44 & operator=(const SkM44 &src)
//bool operator==(const SkM44 &other)
//bool operator!=(const SkM44 &other)
//SkV4 operator*(const SkV4 &v)
//SkV3 operator*(SkV3 v)

SkM44 *SkM44_new(const SkM44 *src) {
    return new SkM44(*src);
}

SkM44 *SkM44_new_2(const SkMatrix *src) {
    return new SkM44(*src);
}

SkM44 *SkM44_new_3() {
    return new SkM44();
}

SkM44 *SkM44_new_4(const SkM44 *a, const SkM44*b) {
    return new SkM44(*a, *b);
}

SkM44 *SkM44_new_5(SkScalar m0, SkScalar m4, SkScalar m8, SkScalar m12, SkScalar m1, SkScalar m5, SkScalar m9, SkScalar m13, SkScalar m2, SkScalar m6, SkScalar m10, SkScalar m14, SkScalar m3, SkScalar m7, SkScalar m11, SkScalar m15) {
    return new SkM44(m0, m4, m8, m12, m1, m5, m9, m13, m2, m6, m10, m14, m3, m7, m11, m15);
}

void SkM44_getColMajor(SkM44 *m44, SkScalar v[]) {
    m44->getColMajor(v);
}

void SkM44_getRowMajor(SkM44 *m44, SkScalar v[]) {
    m44->getRowMajor(v);
}

SkScalar SkM44_rc(SkM44 *m44, int r, int c) {
    return m44->rc(r, c);
}

void SkM44_setRC(SkM44 *m44, int r, int c, SkScalar value) {
    m44->setRC(r, c, value);
}

SkV4 SkM44_row(SkM44 *m44, int i) {
    return m44->row(i);
}

SkV4 SkM44_col(SkM44 *m44, int i) {
    return m44->col(i);
}

void SkM44_setRow(SkM44 *m44, int i, const SkV4 *v) {
    m44->setRow(i, *v);
}

void SkM44_setCol(SkM44 *m44, int i, const SkV4 *v) {
    m44->setCol(i, *v);
}

void SkM44_setIdentity(int sk_m_44_key_out, SkM44 *m44) {
    static_sk_m_44_set(sk_m_44_key_out, m44->setIdentity());
}

void SkM44_setTranslate(int sk_m_44_key_out, SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) {
    static_sk_m_44_set(sk_m_44_key_out, m44->setTranslate(x, y, z));
}

void SkM44_setScale(int sk_m_44_key_out, SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) {
    static_sk_m_44_set(sk_m_44_key_out, m44->setScale(x, y, z));
}

void SkM44_setRotateUnitSinCos(int sk_m_44_key_out, SkM44 *m44, SkV3 axis, SkScalar sinAngle, SkScalar cosAngle) {
    static_sk_m_44_set(sk_m_44_key_out, m44->setRotateUnitSinCos(axis, sinAngle, cosAngle));
}

void SkM44_setRotateUnit(int sk_m_44_key_out, SkM44 *m44, SkV3 axis, SkScalar radians) {
    static_sk_m_44_set(sk_m_44_key_out, m44->setRotateUnit(axis, radians));
}

void SkM44_setRotate(int sk_m_44_key_out, SkM44 *m44, SkV3 axis, SkScalar radians) {
    static_sk_m_44_set(sk_m_44_key_out, m44->setRotate(axis, radians));
}

void SkM44_setConcat(int sk_m_44_key_out, SkM44 *m44, const SkM44 *a, const SkM44 *b) {
    static_sk_m_44_set(sk_m_44_key_out, m44->setConcat(*a, *b));
}

void SkM44_preConcat(int sk_m_44_key_out, SkM44 *m44, const SkM44 *m) {
    static_sk_m_44_set(sk_m_44_key_out, m44->preConcat(*m));
}

void SkM44_preConcat_2(int sk_m_44_key_out, SkM44 *m44, const SkMatrix *matrix) {
    static_sk_m_44_set(sk_m_44_key_out, m44->preConcat(*matrix));
}

void SkM44_postConcat(int sk_m_44_key_out, SkM44 *m44, const SkM44 *m) {
    static_sk_m_44_set(sk_m_44_key_out, m44->postConcat(*m));
}

void SkM44_normalizePerspective(SkM44 *m44) {
    m44->normalizePerspective();
}

bool SkM44_isFinite(SkM44 *m44) {
    return m44->isFinite();
}

bool SkM44_invert(SkM44 *m44, SkM44 *inverse) {
    return m44->invert(inverse);
}

void SkM44_transpose(int sk_m_44_key_out, SkM44 *m44) {
    static_sk_m_44_set(sk_m_44_key_out, m44->transpose());
}

void SkM44_dump(SkM44 *m44) {
    m44->dump();
}

SkV4 SkM44_map(SkM44 *m44, float x, float y, float z, float w) {
    return m44->map(x, y, z, w);
}

void SkM44_asM33(int sk_matrix_key_out, SkM44 *m44) {
    static_sk_matrix_set(sk_matrix_key_out, m44->asM33());
}

void SkM44_preTranslate(int sk_m_44_key_out, SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) {
    static_sk_m_44_set(sk_m_44_key_out, m44->preTranslate(x, y, z));
}

void SkM44_postTranslate(int sk_m_44_key_out, SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) {
    static_sk_m_44_set(sk_m_44_key_out, m44->postTranslate(x, y, z));
}

void SkM44_preScale(int sk_m_44_key_out, SkM44 *m44, SkScalar x, SkScalar y) {
    static_sk_m_44_set(sk_m_44_key_out, m44->preScale(x, y));
}

void SkM44_preScale_2(int sk_m_44_key_out, SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) {
    static_sk_m_44_set(sk_m_44_key_out, m44->preScale(x, y, z));
}

// static

void SkM44_Rows(int sk_m_44_key_out, const SkV4 *r0, const SkV4 *r1, const SkV4 *r2, const SkV4 *r3) {
    static_sk_m_44_set(sk_m_44_key_out, SkM44::Rows(*r0, *r1, *r2, *r3));
}

void SkM44_Cols(int sk_m_44_key_out, const SkV4 *c0, const SkV4 *c1, const SkV4 *c2, const SkV4 *c3) {
    static_sk_m_44_set(sk_m_44_key_out, SkM44::Cols(*c0, *c1, *c2, *c3));
}

void SkM44_RowMajor(int sk_m_44_key_out, const SkScalar r[16]) {
    static_sk_m_44_set(sk_m_44_key_out, SkM44::RowMajor(r));
}

void SkM44_ColMajor(int sk_m_44_key_out, const SkScalar c[16]) {
    static_sk_m_44_set(sk_m_44_key_out, SkM44::ColMajor(c));
}

void SkM44_Translate(int sk_m_44_key_out, SkScalar x, SkScalar y, SkScalar z) {
    static_sk_m_44_set(sk_m_44_key_out, SkM44::Translate(x, y, z));
}

void SkM44_Scale(int sk_m_44_key_out, SkScalar x, SkScalar y, SkScalar z) {
    static_sk_m_44_set(sk_m_44_key_out, SkM44::Scale(x, y, z));
}

void SkM44_Rotate(int sk_m_44_key_out, SkV3 axis, SkScalar radians) {
    static_sk_m_44_set(sk_m_44_key_out, SkM44::Rotate(axis, radians));
}

void SkM44_RectToRect(int sk_m_44_key_out, const SkRect *src, const SkRect *dst) {
    static_sk_m_44_set(sk_m_44_key_out, SkM44::RectToRect(*src, *dst));
}

void SkM44_LookAt(int sk_m_44_key_out, const SkV3 *eye, const SkV3 *center, const SkV3 *up) {
    static_sk_m_44_set(sk_m_44_key_out, SkM44::LookAt(*eye, *center, *up));
}

void SkM44_Perspective(int sk_m_44_key_out, float near, float far, float angle) {
    static_sk_m_44_set(sk_m_44_key_out, SkM44::Perspective(near, far, angle));
}

}