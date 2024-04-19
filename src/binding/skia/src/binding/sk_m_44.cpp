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

void SkM44_delete(SkM44 *m44) {
    delete m44;
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

sk_v4_t SkM44_row(SkM44 *m44, int i) {
    return static_sk_v4_make(m44->row(i));
}

sk_v4_t SkM44_col(SkM44 *m44, int i) {
    return static_sk_v4_make(m44->col(i));
}

void SkM44_setRow(SkM44 *m44, int i, const SkV4 *v) {
    m44->setRow(i, *v);
}

void SkM44_setCol(SkM44 *m44, int i, const SkV4 *v) {
    m44->setCol(i, *v);
}

sk_m_44_t SkM44_setIdentity(SkM44 *m44) {
    return static_sk_m_44_make(m44->setIdentity());
}

sk_m_44_t SkM44_setTranslate(SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) {
    return static_sk_m_44_make(m44->setTranslate(x, y, z));
}

sk_m_44_t SkM44_setScale(SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) {
    return static_sk_m_44_make(m44->setScale(x, y, z));
}

sk_m_44_t SkM44_setRotateUnitSinCos(SkM44 *m44, sk_v3_t axis, SkScalar sinAngle, SkScalar cosAngle) {
    return static_sk_m_44_make(m44->setRotateUnitSinCos(static_sk_v3_get(axis), sinAngle, cosAngle));
}

sk_m_44_t SkM44_setRotateUnit(SkM44 *m44, sk_v3_t axis, SkScalar radians) {
    return static_sk_m_44_make(m44->setRotateUnit(static_sk_v3_get(axis), radians));
}

sk_m_44_t SkM44_setRotate(SkM44 *m44, sk_v3_t axis, SkScalar radians) {
    return static_sk_m_44_make(m44->setRotate(static_sk_v3_get(axis), radians));
}

sk_m_44_t SkM44_setConcat(SkM44 *m44, const SkM44 *a, const SkM44 *b) {
    return static_sk_m_44_make(m44->setConcat(*a, *b));
}

sk_m_44_t SkM44_preConcat(SkM44 *m44, const SkM44 *m) {
    return static_sk_m_44_make(m44->preConcat(*m));
}

sk_m_44_t SkM44_preConcat_2(SkM44 *m44, const SkMatrix *matrix) {
    return static_sk_m_44_make(m44->preConcat(*matrix));
}

sk_m_44_t SkM44_postConcat(SkM44 *m44, const SkM44 *m) {
    return static_sk_m_44_make(m44->postConcat(*m));
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

sk_m_44_t SkM44_transpose(SkM44 *m44) {
    return static_sk_m_44_make(m44->transpose());
}

void SkM44_dump(SkM44 *m44) {
    m44->dump();
}

sk_v4_t SkM44_map(SkM44 *m44, float x, float y, float z, float w) {
    return static_sk_v4_make(m44->map(x, y, z, w));
}

sk_matrix_t SkM44_asM33(SkM44 *m44) {
    return static_sk_matrix_make(m44->asM33());
}

sk_m_44_t SkM44_preTranslate(SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) {
    return static_sk_m_44_make(m44->preTranslate(x, y, z));
}

sk_m_44_t SkM44_postTranslate(SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) {
    return static_sk_m_44_make(m44->postTranslate(x, y, z));
}

sk_m_44_t SkM44_preScale(SkM44 *m44, SkScalar x, SkScalar y) {
    return static_sk_m_44_make(m44->preScale(x, y));
}

sk_m_44_t SkM44_preScale_2(SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) {
    return static_sk_m_44_make(m44->preScale(x, y, z));
}

// static

sk_m_44_t SkM44_Rows(const SkV4 *r0, const SkV4 *r1, const SkV4 *r2, const SkV4 *r3) {
    return static_sk_m_44_make(SkM44::Rows(*r0, *r1, *r2, *r3));
}

sk_m_44_t SkM44_Cols(const SkV4 *c0, const SkV4 *c1, const SkV4 *c2, const SkV4 *c3) {
    return static_sk_m_44_make(SkM44::Cols(*c0, *c1, *c2, *c3));
}

sk_m_44_t SkM44_RowMajor(const SkScalar r[16]) {
    return static_sk_m_44_make(SkM44::RowMajor(r));
}

sk_m_44_t SkM44_ColMajor(const SkScalar c[16]) {
    return static_sk_m_44_make(SkM44::ColMajor(c));
}

sk_m_44_t SkM44_Translate(SkScalar x, SkScalar y, SkScalar z) {
    return static_sk_m_44_make(SkM44::Translate(x, y, z));
}

sk_m_44_t SkM44_Scale(SkScalar x, SkScalar y, SkScalar z) {
    return static_sk_m_44_make(SkM44::Scale(x, y, z));
}

sk_m_44_t SkM44_Rotate(sk_v3_t axis, SkScalar radians) {
    return static_sk_m_44_make(SkM44::Rotate(static_sk_v3_get(axis), radians));
}

sk_m_44_t SkM44_RectToRect(const SkRect *src, const SkRect *dst) {
    return static_sk_m_44_make(SkM44::RectToRect(*src, *dst));
}

sk_m_44_t SkM44_LookAt(const SkV3 *eye, const SkV3 *center, const SkV3 *up) {
    return static_sk_m_44_make(SkM44::LookAt(*eye, *center, *up));
}

sk_m_44_t SkM44_Perspective(float near, float far, float angle) {
    return static_sk_m_44_make(SkM44::Perspective(near, far, angle));
}

}