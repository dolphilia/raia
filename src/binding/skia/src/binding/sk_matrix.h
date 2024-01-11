//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_MATRIX_H
#define RAIA_SKIA_SK_MATRIX_H

#include "include/core/SkMatrix.h"
#include "../static/static_sk_matrix.h"
#include "../static/static_sk_rect.h"

extern "C" {
// SkScalar operator[](int index)
// SkScalar & operator[](int index)
SkMatrix *SkMatrix_new(SkMatrix *matrix);
SkMatrix::TypeMask SkMatrix_getType(SkMatrix *matrix);
bool SkMatrix_isIdentity(SkMatrix *matrix);
bool SkMatrix_isScaleTranslate(SkMatrix *matrix);
bool SkMatrix_isTranslate(SkMatrix *matrix);
bool SkMatrix_rectStaysRect(SkMatrix *matrix);
bool SkMatrix_preservesAxisAlignment(SkMatrix *matrix);
bool SkMatrix_hasPerspective(SkMatrix *matrix);
bool SkMatrix_isSimilarity(SkMatrix *matrix, SkScalar tol);
bool SkMatrix_preservesRightAngles(SkMatrix *matrix, SkScalar tol);
SkScalar SkMatrix_get(SkMatrix *matrix, int index);
SkScalar SkMatrix_rc(SkMatrix *matrix, int r, int c);
SkScalar SkMatrix_getScaleX(SkMatrix *matrix);
SkScalar SkMatrix_getScaleY(SkMatrix *matrix);
SkScalar SkMatrix_getSkewY(SkMatrix *matrix);
SkScalar SkMatrix_getSkewX(SkMatrix *matrix);
SkScalar SkMatrix_getTranslateX(SkMatrix *matrix);
SkScalar SkMatrix_getTranslateY(SkMatrix *matrix);
SkScalar SkMatrix_getPerspX(SkMatrix *matrix);
SkScalar SkMatrix_getPerspY(SkMatrix *matrix);
void SkMatrix_set(const char *sk_matrix_key_out, SkMatrix *matrix, int index, SkScalar value);
void SkMatrix_setScaleX(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar v);
void SkMatrix_setScaleY(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar v);
void SkMatrix_setSkewY(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar v);
void SkMatrix_setSkewX(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar v);
void SkMatrix_setTranslateX(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar v);
void SkMatrix_setTranslateY(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar v);
void SkMatrix_setPerspX(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar v);
void SkMatrix_setPerspY(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar v);
void SkMatrix_setAll(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar scaleY, SkScalar transY, SkScalar persp0, SkScalar persp1, SkScalar persp2);
void SkMatrix_get9(SkMatrix *matrix, SkScalar buffer[9]);
void SkMatrix_set9(const char *sk_matrix_key_out, SkMatrix *matrix, const SkScalar buffer[9]);
void SkMatrix_reset(const char *sk_matrix_key_out, SkMatrix *matrix);
void SkMatrix_setIdentity(const char *sk_matrix_key_out, SkMatrix *matrix);
void SkMatrix_setTranslate(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar dx, SkScalar dy);
void SkMatrix_setTranslate_2(const char *sk_matrix_key_out, SkMatrix *matrix, const SkVector *v);
void SkMatrix_setScale(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py);
void SkMatrix_setScale_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar sx, SkScalar sy);
void SkMatrix_setRotate(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py);
void SkMatrix_setRotate_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar degrees);
void SkMatrix_setSinCos(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue, SkScalar px, SkScalar py);
void SkMatrix_setSinCos_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue);
void SkMatrix_setRSXform(const char *sk_matrix_key_out, SkMatrix *matrix, const SkRSXform *rsxForm);
void SkMatrix_setSkew(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py);
void SkMatrix_setSkew_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar kx, SkScalar ky);
void SkMatrix_setConcat(const char *sk_matrix_key_out, SkMatrix *matrix, const SkMatrix *a, const SkMatrix *b);
void SkMatrix_preTranslate(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar dx, SkScalar dy);
void SkMatrix_preScale(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py);
void SkMatrix_preScale_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar sx, SkScalar sy);
void SkMatrix_preRotate(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py);
void SkMatrix_preRotate_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar degrees);
void SkMatrix_preSkew(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py);
void SkMatrix_preSkew_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar kx, SkScalar ky);
void SkMatrix_preConcat(const char *sk_matrix_key_out, SkMatrix *matrix, const SkMatrix *other);
void SkMatrix_postTranslate(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar dx, SkScalar dy);
void SkMatrix_postScale(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py);
void SkMatrix_postScale_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar sx, SkScalar sy);
void SkMatrix_postRotate(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py);
void SkMatrix_postRotate_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar degrees);
void SkMatrix_postSkew(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py);
void SkMatrix_postSkew_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar kx, SkScalar ky);
void SkMatrix_postConcat(const char *sk_matrix_key_out, SkMatrix *matrix, const SkMatrix *other);
bool SkMatrix_setRectToRect(SkMatrix *matrix, const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit stf);
bool SkMatrix_setPolyToPoly(SkMatrix *matrix, const SkPoint src[], const SkPoint dst[], int count);
bool SkMatrix_invert(SkMatrix *matrix, SkMatrix *inverse);
bool SkMatrix_asAffine(SkMatrix *matrix, SkScalar affine[6]);
void SkMatrix_setAffine(const char *sk_matrix_key_out, SkMatrix *matrix, const SkScalar affine[6]);
void SkMatrix_normalizePerspective(SkMatrix *matrix);
void SkMatrix_mapPoints(SkMatrix *matrix, SkPoint dst[], const SkPoint src[], int count);
void SkMatrix_mapPoints_2(SkMatrix *matrix, SkPoint pts[], int count);
void SkMatrix_mapHomogeneousPoints(SkMatrix *matrix, SkPoint3 dst[], const SkPoint3 src[], int count);
void SkMatrix_mapHomogeneousPoints_2(SkMatrix *matrix, SkPoint3 dst[], const SkPoint src[], int count);
SkPoint SkMatrix_mapPoint(SkMatrix *matrix, SkPoint pt);
void SkMatrix_mapXY(SkMatrix *matrix, SkScalar x, SkScalar y, SkPoint *result);
SkPoint SkMatrix_mapXY_2(SkMatrix *matrix, SkScalar x, SkScalar y);
SkPoint SkMatrix_mapOrigin(SkMatrix *matrix);
void SkMatrix_mapVectors(SkMatrix *matrix, SkVector dst[], const SkVector src[], int count);
void SkMatrix_mapVectors_2(SkMatrix *matrix, SkVector vecs[], int count);
void SkMatrix_mapVector(SkMatrix *matrix, SkScalar dx, SkScalar dy, SkVector *result);
SkVector SkMatrix_mapVector_2(SkMatrix *matrix, SkScalar dx, SkScalar dy);
bool SkMatrix_mapRect(SkMatrix *matrix, SkRect *dst, const SkRect *src, SkApplyPerspectiveClip pc);
bool SkMatrix_mapRect_2(SkMatrix *matrix, SkRect *rect, SkApplyPerspectiveClip pc);
void SkMatrix_mapRect_3(const char *sk_rect_key_out, SkMatrix *matrix, const SkRect *src, SkApplyPerspectiveClip pc);
void SkMatrix_mapRectToQuad(SkMatrix *matrix, SkPoint dst[4], const SkRect *rect);
void SkMatrix_mapRectScaleTranslate(SkMatrix *matrix, SkRect *dst, const SkRect *src);
SkScalar SkMatrix_mapRadius(SkMatrix *matrix, SkScalar radius);
void SkMatrix_dump(SkMatrix *matrix);
SkScalar SkMatrix_getMinScale(SkMatrix *matrix);
SkScalar SkMatrix_getMaxScale(SkMatrix *matrix);
bool SkMatrix_getMinMaxScales(SkMatrix *matrix, SkScalar scaleFactors[2]);
bool SkMatrix_decomposeScale(SkMatrix *matrix, SkSize *scale, SkMatrix *remaining);
void SkMatrix_dirtyMatrixTypeCache(SkMatrix *matrix);
void SkMatrix_setScaleTranslate(SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar tx, SkScalar ty);
bool SkMatrix_isFinite(SkMatrix *matrix);
// static
void SkMatrix_Scale(const char *sk_matrix_key_out, SkScalar sx, SkScalar sy);
void SkMatrix_Translate(const char *sk_matrix_key_out, SkScalar dx, SkScalar dy);
void SkMatrix_Translate_2(const char *sk_matrix_key_out, SkVector t);
void SkMatrix_Translate_3(const char *sk_matrix_key_out, SkIVector t);
void SkMatrix_RotateDeg(const char *sk_matrix_key_out, SkScalar deg);
void SkMatrix_RotateDeg_2(const char *sk_matrix_key_out, SkScalar deg, SkPoint pt);
void SkMatrix_RotateRad(const char *sk_matrix_key_out, SkScalar rad);
void SkMatrix_Skew(const char *sk_matrix_key_out, SkScalar kx, SkScalar ky);
void SkMatrix_RectToRect(const char *sk_matrix_key_out, const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit mode);
void SkMatrix_MakeAll(const char *sk_matrix_key_out, SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar scaleY, SkScalar transY, SkScalar pers0, SkScalar pers1, SkScalar pers2);
void SkMatrix_MakeRectToRect(const char *sk_matrix_key_out, const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit stf);
void SkMatrix_SetAffineIdentity(SkScalar affine[6]);
void SkMatrix_I(const char *sk_matrix_key_out);
void SkMatrix_InvalidMatrix(const char *sk_matrix_key_out);
void SkMatrix_Concat(const char *sk_matrix_key_out, const SkMatrix *a, const SkMatrix *b);
}

#endif //RAIA_SKIA_SK_MATRIX_H
