//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_M_44_H
#define RAIA_SKIA_SK_M_44_H

#ifdef __cplusplus
extern "C" {
#endif

//SkM44 & operator=(const SkM44 &src)
//bool operator==(const SkM44 &other)
//bool operator!=(const SkM44 &other)
//SkV4 operator*(const SkV4 &v)
//SkV3 operator*(SkV3 v)

void *SkM44_new(const void *src); // (const SkM44 *src) -> SkM44 *
void *SkM44_new_2(const void *src); // (const SkMatrix *src) -> SkM44 *
void *SkM44_new_3(); // () -> SkM44 *
void *SkM44_new_4(const void *a, const void *b); // (const SkM44 *a, const SkM44 *b) -> SkM44 *
void *SkM44_new_5(float m0, float m4, float m8, float m12, float m1, float m5, float m9, float m13, float m2, float m6, float m10, float m14, float m3, float m7, float m11, float m15); // (SkScalar m0, SkScalar m4, SkScalar m8, SkScalar m12, SkScalar m1, SkScalar m5, SkScalar m9, SkScalar m13, SkScalar m2, SkScalar m6, SkScalar m10, SkScalar m14, SkScalar m3, SkScalar m7, SkScalar m11, SkScalar m15) -> SkM44 *
void SkM44_delete(void *m44); // (SkM44 *m44)
void SkM44_getColMajor(void *m44, void *v); // (SkM44 *m44, SkScalar v[])
void SkM44_getRowMajor(void *m44, void *v); // (SkM44 *m44, SkScalar v[])
float SkM44_rc(void *m44, int r, int c); // (SkM44 *m44, int r, int c) -> SkScalar
void SkM44_setRC(void *m44, int r, int c, float value); // (SkM44 *m44, int r, int c, SkScalar value)
int SkM44_row(void *m44, int i); // (SkM44 *m44, int i) -> sk_v4_t
int SkM44_col(void *m44, int i); // (SkM44 *m44, int i) -> sk_v4_t
void SkM44_setRow(void *m44, int i, const void *v); // (SkM44 *m44, int i, const SkV4 *v)
void SkM44_setCol(void *m44, int i, const void *v); // (SkM44 *m44, int i, const SkV4 *v)
int SkM44_setIdentity(void *m44); // (SkM44 *m44) -> sk_m_44_t
int SkM44_setTranslate(void *m44, float x, float y, float z); // (SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) -> sk_m_44_t
int SkM44_setScale(void *m44, float x, float y, float z); // (SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) -> sk_m_44_t
int SkM44_setRotateUnitSinCos(void *m44, int axis, float sinAngle, float cosAngle); // (SkM44 *m44, sk_v3_t axis, SkScalar sinAngle, SkScalar cosAngle) -> sk_m_44_t
int SkM44_setRotateUnit(void *m44, int axis, float radians); // (SkM44 *m44, sk_v3_t axis, SkScalar radians) -> sk_m_44_t
int SkM44_setRotate(void *m44, int axis, float radians); // (SkM44 *m44, sk_v3_t axis, SkScalar radians) -> sk_m_44_t
int SkM44_setConcat(void *m44, const void *a, const void *b); // (SkM44 *m44, const SkM44 *a, const SkM44 *b) -> sk_m_44_t
int SkM44_preConcat(void *m44, const void *m); // (SkM44 *m44, const SkM44 *m) -> sk_m_44_t
int SkM44_preConcat_2(void *m44, const void *matrix); // (SkM44 *m44, const SkMatrix *matrix) -> sk_m_44_t
int SkM44_postConcat(void *m44, const void *m); // (SkM44 *m44, const SkM44 *m) -> sk_m_44_t
void SkM44_normalizePerspective(void *m44); // (SkM44 *m44)
bool SkM44_isFinite(void *m44); // (SkM44 *m44) -> bool
bool SkM44_invert(void *m44, void *inverse); // (SkM44 *m44, SkM44 *inverse) -> bool
int SkM44_transpose(void *m44); // (SkM44 *m44) -> sk_m_44_t
void SkM44_dump(void *m44); // (SkM44 *m44)
int SkM44_map(void *m44, float x, float y, float z, float w); // (SkM44 *m44, float x, float y, float z, float w) -> sk_v4_t
int SkM44_asM33(void *m44); // (SkM44 *m44) -> sk_matrix_t
int SkM44_preTranslate(void *m44, float x, float y, float z); // (SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) -> sk_m_44_t
int SkM44_postTranslate(void *m44, float x, float y, float z); // (SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) -> sk_m_44_t
int SkM44_preScale(void *m44, float x, float y); // (SkM44 *m44, SkScalar x, SkScalar y) -> sk_m_44_t
int SkM44_preScale_2(void *m44, float x, float y, float z); // (SkM44 *m44, SkScalar x, SkScalar y, SkScalar z) -> sk_m_44_t

// static

int SkM44_Rows(const void *r0, const void *r1, const void *r2, const void *r3); // (const SkV4 *r0, const SkV4 *r1, const SkV4 *r2, const SkV4 *r3) -> sk_m_44_t
int SkM44_Cols(const void *c0, const void *c1, const void *c2, const void *c3); // (const SkV4 *c0, const SkV4 *c1, const SkV4 *c2, const SkV4 *c3) -> sk_m_44_t
int SkM44_RowMajor(const void * r); // (const SkScalar r[16]) -> sk_m_44_t
int SkM44_ColMajor(const void * c); // (const SkScalar c[16]) -> sk_m_44_t
int SkM44_Translate(float x, float y, float z); // (SkScalar x, SkScalar y, SkScalar z) -> sk_m_44_t
int SkM44_Scale(float x, float y, float z); // (SkScalar x, SkScalar y, SkScalar z) -> sk_m_44_t
int SkM44_Rotate(int axis, float radians); // (sk_v3_t axis, SkScalar radians) -> sk_m_44_t
int SkM44_RectToRect(const void *src, const void *dst); // (const SkRect *src, const SkRect *dst) -> sk_m_44_t
int SkM44_LookAt(const void *eye, const void *center, const void *up); // (const SkV3 *eye, const SkV3 *center, const SkV3 *up) -> sk_m_44_t
int SkM44_Perspective(float near, float far, float angle); // (float near, float far, float angle) -> sk_m_44_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_M_44_H
