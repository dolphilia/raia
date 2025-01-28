//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_MATRIX_H
#define RAIA_SKIA_SK_MATRIX_H

#ifdef __cplusplus
extern "C" {
#endif

// SkScalar operator[](int index)
// SkScalar & operator[](int index)

void *SkMatrix_new(void *matrix); // (SkMatrix *matrix) -> SkMatrix *
void SkMatrix_delete(void *matrix); // (SkMatrix *matrix)
int SkMatrix_getType(void *matrix); // (SkMatrix *matrix) -> SkMatrix::TypeMask
bool SkMatrix_isIdentity(void *matrix); // (SkMatrix *matrix) -> bool
bool SkMatrix_isScaleTranslate(void *matrix); // (SkMatrix *matrix) -> bool
bool SkMatrix_isTranslate(void *matrix); // (SkMatrix *matrix) -> bool
bool SkMatrix_rectStaysRect(void *matrix); // (SkMatrix *matrix) -> bool
bool SkMatrix_preservesAxisAlignment(void *matrix); // (SkMatrix *matrix) -> bool
bool SkMatrix_hasPerspective(void *matrix); // (SkMatrix *matrix) -> bool
bool SkMatrix_isSimilarity(void *matrix, float tol); // (SkMatrix *matrix, SkScalar tol) -> bool
bool SkMatrix_preservesRightAngles(void *matrix, float tol); // (SkMatrix *matrix, SkScalar tol) -> bool
float SkMatrix_get(void *matrix, int index); // (SkMatrix *matrix, int index) -> SkScalar
float SkMatrix_rc(void *matrix, int r, int c); // (SkMatrix *matrix, int r, int c) -> SkScalar
float SkMatrix_getScaleX(void *matrix); // (SkMatrix *matrix) -> SkScalar
float SkMatrix_getScaleY(void *matrix); // (SkMatrix *matrix) -> SkScalar
float SkMatrix_getSkewY(void *matrix); // (SkMatrix *matrix) -> SkScalar
float SkMatrix_getSkewX(void *matrix); // (SkMatrix *matrix) -> SkScalar
float SkMatrix_getTranslateX(void *matrix); // (SkMatrix *matrix) -> SkScalar
float SkMatrix_getTranslateY(void *matrix); // (SkMatrix *matrix) -> SkScalar
float SkMatrix_getPerspX(void *matrix); // (SkMatrix *matrix) -> SkScalar
float SkMatrix_getPerspY(void *matrix); // (SkMatrix *matrix) -> SkScalar
int SkMatrix_set(void *matrix, int index, float value); // (SkMatrix *matrix, int index, SkScalar value) -> sk_matrix_t
int SkMatrix_setScaleX(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
int SkMatrix_setScaleY(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
int SkMatrix_setSkewY(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
int SkMatrix_setSkewX(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
int SkMatrix_setTranslateX(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
int SkMatrix_setTranslateY(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
int SkMatrix_setPerspX(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
int SkMatrix_setPerspY(void *matrix, float v); // (SkMatrix *matrix, SkScalar v) -> sk_matrix_t
int SkMatrix_setAll(void *matrix, float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float persp0, float persp1, float persp2); // (SkMatrix *matrix, SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar scaleY, SkScalar transY, SkScalar persp0, SkScalar persp1, SkScalar persp2) -> sk_matrix_t
void SkMatrix_get9(void *matrix, void * buffer); // (SkMatrix *matrix, SkScalar buffer[9])
int SkMatrix_set9(void *matrix, const void * buffer); // (SkMatrix *matrix, const SkScalar buffer[9]) -> sk_matrix_t
int SkMatrix_reset(void *matrix); // (SkMatrix *matrix) -> sk_matrix_t
int SkMatrix_setIdentity(void *matrix); // (SkMatrix *matrix) -> sk_matrix_t
int SkMatrix_setTranslate(void *matrix, float dx, float dy); // (SkMatrix *matrix, SkScalar dx, SkScalar dy) -> sk_matrix_t
int SkMatrix_setTranslate_2(void *matrix, const void *v); // (SkMatrix *matrix, const SkVector *v) -> sk_matrix_t
int SkMatrix_setScale(void *matrix, float sx, float sy, float px, float py); // (SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) -> sk_matrix_t
int SkMatrix_setScale_2(void *matrix, float sx, float sy); // (SkMatrix *matrix, SkScalar sx, SkScalar sy) -> sk_matrix_t
int SkMatrix_setRotate(void *matrix, float degrees, float px, float py); // (SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py) -> sk_matrix_t
int SkMatrix_setRotate_2(void *matrix, float degrees); // (SkMatrix *matrix, SkScalar degrees) -> sk_matrix_t
int SkMatrix_setSinCos(void *matrix, float sinValue, float cosValue, float px, float py); // (SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue, SkScalar px, SkScalar py) -> sk_matrix_t
int SkMatrix_setSinCos_2(void *matrix, float sinValue, float cosValue); // (SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue) -> sk_matrix_t
int SkMatrix_setRSXform(void *matrix, const void *rsxForm); // (SkMatrix *matrix, const SkRSXform *rsxForm) -> sk_matrix_t
int SkMatrix_setSkew(void *matrix, float kx, float ky, float px, float py); // (SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py) -> sk_matrix_t
int SkMatrix_setSkew_2(void *matrix, float kx, float ky); // (SkMatrix *matrix, SkScalar kx, SkScalar ky) -> sk_matrix_t
int SkMatrix_setConcat(void *matrix, const void *a, const void *b); // (SkMatrix *matrix, const SkMatrix *a, const SkMatrix *b) -> sk_matrix_t
int SkMatrix_preTranslate(void *matrix, float dx, float dy); // (SkMatrix *matrix, SkScalar dx, SkScalar dy) -> sk_matrix_t
int SkMatrix_preScale(void *matrix, float sx, float sy, float px, float py); // (SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) -> sk_matrix_t
int SkMatrix_preScale_2(void *matrix, float sx, float sy); // (SkMatrix *matrix, SkScalar sx, SkScalar sy) -> sk_matrix_t
int SkMatrix_preRotate(void *matrix, float degrees, float px, float py); // (SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py) -> sk_matrix_t
int SkMatrix_preRotate_2(void *matrix, float degrees); // (SkMatrix *matrix, SkScalar degrees) -> sk_matrix_t
int SkMatrix_preSkew(void *matrix, float kx, float ky, float px, float py); // (SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py) -> sk_matrix_t
int SkMatrix_preSkew_2(void *matrix, float kx, float ky); // (SkMatrix *matrix, SkScalar kx, SkScalar ky) -> sk_matrix_t
int SkMatrix_preConcat(void *matrix, const void *other); // (SkMatrix *matrix, const SkMatrix *other) -> sk_matrix_t
int SkMatrix_postTranslate(void *matrix, float dx, float dy); // (SkMatrix *matrix, SkScalar dx, SkScalar dy) -> sk_matrix_t
int SkMatrix_postScale(void *matrix, float sx, float sy, float px, float py); // (SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) -> sk_matrix_t
int SkMatrix_postScale_2(void *matrix, float sx, float sy); // (SkMatrix *matrix, SkScalar sx, SkScalar sy) -> sk_matrix_t
int SkMatrix_postRotate(void *matrix, float degrees, float px, float py); // (SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py) -> sk_matrix_t
int SkMatrix_postRotate_2(void *matrix, float degrees); // (SkMatrix *matrix, SkScalar degrees) -> sk_matrix_t
int SkMatrix_postSkew(void *matrix, float kx, float ky, float px, float py); // (SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py) -> sk_matrix_t
int SkMatrix_postSkew_2(void *matrix, float kx, float ky); // (SkMatrix *matrix, SkScalar kx, SkScalar ky) -> sk_matrix_t
int SkMatrix_postConcat(void *matrix, const void *other); // (SkMatrix *matrix, const SkMatrix *other) -> sk_matrix_t
bool SkMatrix_setRectToRect(void *matrix, const void * src, const void * dst, int stf); // (SkMatrix *matrix, const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit stf) -> bool
bool SkMatrix_setPolyToPoly(void *matrix, const void * src, const void * dst, int count); // (SkMatrix *matrix, const SkPoint src[], const SkPoint dst[], int count) -> bool
bool SkMatrix_invert(void *matrix, void * inverse); // (SkMatrix *matrix, SkMatrix *inverse) -> bool
bool SkMatrix_asAffine(void *matrix, void * affine); // (SkMatrix *matrix, SkScalar affine[6]) -> bool
int SkMatrix_setAffine(void *matrix, const void * affine); // (SkMatrix *matrix, const SkScalar affine[6]) -> sk_matrix_t
void SkMatrix_normalizePerspective(void *matrix); // (SkMatrix *matrix)
void SkMatrix_mapPoints(void *matrix, void * dst, const void * src, int count); // (SkMatrix *matrix, SkPoint dst[], const SkPoint src[], int count)
void SkMatrix_mapPoints_2(void *matrix, void * pts, int count); // (SkMatrix *matrix, SkPoint pts[], int count)
void SkMatrix_mapHomogeneousPoints(void *matrix, void * dst, const void * src, int count); // (SkMatrix *matrix, SkPoint3 dst[], const SkPoint3 src[], int count)
void SkMatrix_mapHomogeneousPoints_2(void *matrix, void * dst, const void * src, int count); // (SkMatrix *matrix, SkPoint3 dst[], const SkPoint src[], int count)
int SkMatrix_mapPoint(void *matrix, int pt); // (SkMatrix *matrix, sk_point_t pt) -> sk_point_t
void SkMatrix_mapXY(void *matrix, float x, float y, void * result); // (SkMatrix *matrix, SkScalar x, SkScalar y, SkPoint *result)
int SkMatrix_mapXY_2(void *matrix, float x, float y); // (SkMatrix *matrix, SkScalar x, SkScalar y) -> sk_point_t
int SkMatrix_mapOrigin(void *matrix); // (SkMatrix *matrix) -> sk_point_t
void SkMatrix_mapVectors(void *matrix, void * dst, const void * src, int count); // (SkMatrix *matrix, SkVector dst[], const SkVector src[], int count)
void SkMatrix_mapVectors_2(void *matrix, void * vecs, int count); // (SkMatrix *matrix, SkVector vecs[], int count)
void SkMatrix_mapVector(void *matrix, float dx, float dy, void * result); // (SkMatrix *matrix, SkScalar dx, SkScalar dy, SkVector *result)
int SkMatrix_mapVector_2(void *matrix, float dx, float dy); // (SkMatrix *matrix, SkScalar dx, SkScalar dy) -> sk_point_t
bool SkMatrix_mapRect(void *matrix, void *dst, const void *src, int pc); // (SkMatrix *matrix, SkRect *dst, const SkRect *src, SkApplyPerspectiveClip pc) -> bool
bool SkMatrix_mapRect_2(void *matrix, void *rect, int pc); // (SkMatrix *matrix, SkRect *rect, SkApplyPerspectiveClip pc) -> bool
int SkMatrix_mapRect_3(void *matrix, const void *src, int pc); // (SkMatrix *matrix, const SkRect *src, SkApplyPerspectiveClip pc) -> sk_matrix_t
void SkMatrix_mapRectToQuad(void *matrix, void * dst, const void *rect); // (SkMatrix *matrix, SkPoint dst[4], const SkRect *rect)
void SkMatrix_mapRectScaleTranslate(void *matrix, void *dst, const void *src); // (SkMatrix *matrix, SkRect *dst, const SkRect *src)
float SkMatrix_mapRadius(void *matrix, float radius); // (SkMatrix *matrix, SkScalar radius) -> SkScalar
void SkMatrix_dump(void *matrix); // (SkMatrix *matrix)
float SkMatrix_getMinScale(void *matrix); // (SkMatrix *matrix) -> SkScalar
float SkMatrix_getMaxScale(void *matrix); // (SkMatrix *matrix) -> SkScalar
bool SkMatrix_getMinMaxScales(void *matrix, void * scaleFactors); // (SkMatrix *matrix, SkScalar scaleFactors[2]) -> bool
bool SkMatrix_decomposeScale(void *matrix, void * scale, void * remaining); // (SkMatrix *matrix, SkSize *scale, SkMatrix *remaining) -> bool
void SkMatrix_dirtyMatrixTypeCache(void *matrix); // (SkMatrix *matrix)
void SkMatrix_setScaleTranslate(void *matrix, float sx, float sy, float tx, float ty); // (SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar tx, SkScalar ty)
bool SkMatrix_isFinite(void *matrix); // (SkMatrix *matrix) -> bool

// static

int SkMatrix_Scale(float sx, float sy); // (SkScalar sx, SkScalar sy) -> sk_matrix_t
int SkMatrix_Translate(float dx, float dy); // (SkScalar dx, SkScalar dy) -> sk_matrix_t
int SkMatrix_Translate_2(int t); // (sk_point_t t) -> sk_matrix_t
int SkMatrix_Translate_3(int t); // (sk_i_point_t t) -> sk_matrix_t
int SkMatrix_RotateDeg(float deg); // (SkScalar deg) -> sk_matrix_t
int SkMatrix_RotateDeg_2(float deg, int pt); // (SkScalar deg, sk_point_t pt) -> sk_matrix_t
int SkMatrix_RotateRad(float rad); // (SkScalar rad) -> sk_matrix_t
int SkMatrix_Skew(float kx, float ky); // (SkScalar kx, SkScalar ky) -> sk_matrix_t
int SkMatrix_RectToRect(const void *src, const void *dst, int mode); // (const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit mode) -> sk_matrix_t
int SkMatrix_MakeAll(float scaleX, float skewX, float transX, float skewY, float scaleY, float transY, float pers0, float pers1, float pers2); // (SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar scaleY, SkScalar transY, SkScalar pers0, SkScalar pers1, SkScalar pers2) -> sk_matrix_t
int SkMatrix_MakeRectToRect(const void *src, const void *dst, int stf); // (const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit stf) -> sk_matrix_t
void SkMatrix_SetAffineIdentity(void * affine); // (SkScalar affine[6])
int SkMatrix_I(); // () -> sk_matrix_t
int SkMatrix_InvalidMatrix(); // () -> sk_matrix_t
int SkMatrix_Concat(const void *a, const void *b); // (const SkMatrix *a, const SkMatrix *b) -> sk_matrix_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_MATRIX_H
