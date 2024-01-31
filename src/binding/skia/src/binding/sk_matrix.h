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
void SkMatrix_delete(SkMatrix *matrix);
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
int SkMatrix_set(SkMatrix *matrix, int index, SkScalar value);
int SkMatrix_setScaleX(SkMatrix *matrix, SkScalar v);
int SkMatrix_setScaleY(SkMatrix *matrix, SkScalar v);
int SkMatrix_setSkewY(SkMatrix *matrix, SkScalar v);
int SkMatrix_setSkewX(SkMatrix *matrix, SkScalar v);
int SkMatrix_setTranslateX(SkMatrix *matrix, SkScalar v);
int SkMatrix_setTranslateY(SkMatrix *matrix, SkScalar v);
int SkMatrix_setPerspX(SkMatrix *matrix, SkScalar v);
int SkMatrix_setPerspY(SkMatrix *matrix, SkScalar v);
int SkMatrix_setAll(SkMatrix *matrix, SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar scaleY, SkScalar transY, SkScalar persp0, SkScalar persp1, SkScalar persp2);
void SkMatrix_get9(SkMatrix *matrix, SkScalar buffer[9]);
int SkMatrix_set9(SkMatrix *matrix, const SkScalar buffer[9]);
int SkMatrix_reset(SkMatrix *matrix);
int SkMatrix_setIdentity(SkMatrix *matrix);
int SkMatrix_setTranslate(SkMatrix *matrix, SkScalar dx, SkScalar dy);
int SkMatrix_setTranslate_2(SkMatrix *matrix, const SkVector *v);
int SkMatrix_setScale(SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py);
int SkMatrix_setScale_2(SkMatrix *matrix, SkScalar sx, SkScalar sy);
int SkMatrix_setRotate(SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py);
int SkMatrix_setRotate_2(SkMatrix *matrix, SkScalar degrees);
int SkMatrix_setSinCos(SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue, SkScalar px, SkScalar py);
int SkMatrix_setSinCos_2(SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue);
int SkMatrix_setRSXform(SkMatrix *matrix, const SkRSXform *rsxForm);
int SkMatrix_setSkew(SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py);
int SkMatrix_setSkew_2(SkMatrix *matrix, SkScalar kx, SkScalar ky);
int SkMatrix_setConcat(SkMatrix *matrix, const SkMatrix *a, const SkMatrix *b);
int SkMatrix_preTranslate(SkMatrix *matrix, SkScalar dx, SkScalar dy);
int SkMatrix_preScale(SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py);
int SkMatrix_preScale_2(SkMatrix *matrix, SkScalar sx, SkScalar sy);
int SkMatrix_preRotate(SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py);
int SkMatrix_preRotate_2(SkMatrix *matrix, SkScalar degrees);
int SkMatrix_preSkew(SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py);
int SkMatrix_preSkew_2(SkMatrix *matrix, SkScalar kx, SkScalar ky);
int SkMatrix_preConcat(SkMatrix *matrix, const SkMatrix *other);
int SkMatrix_postTranslate(SkMatrix *matrix, SkScalar dx, SkScalar dy);
int SkMatrix_postScale(SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py);
int SkMatrix_postScale_2(SkMatrix *matrix, SkScalar sx, SkScalar sy);
int SkMatrix_postRotate(SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py);
int SkMatrix_postRotate_2(SkMatrix *matrix, SkScalar degrees);
int SkMatrix_postSkew(SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py);
int SkMatrix_postSkew_2(SkMatrix *matrix, SkScalar kx, SkScalar ky);
int SkMatrix_postConcat(SkMatrix *matrix, const SkMatrix *other);
bool SkMatrix_setRectToRect(SkMatrix *matrix, const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit stf);
bool SkMatrix_setPolyToPoly(SkMatrix *matrix, const SkPoint src[], const SkPoint dst[], int count);
bool SkMatrix_invert(SkMatrix *matrix, SkMatrix *inverse);
bool SkMatrix_asAffine(SkMatrix *matrix, SkScalar affine[6]);
int SkMatrix_setAffine(SkMatrix *matrix, const SkScalar affine[6]);
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
int SkMatrix_mapRect_3(SkMatrix *matrix, const SkRect *src, SkApplyPerspectiveClip pc);
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
int SkMatrix_Scale(SkScalar sx, SkScalar sy);
int SkMatrix_Translate(SkScalar dx, SkScalar dy);
int SkMatrix_Translate_2(SkVector t);
int SkMatrix_Translate_3(SkIVector t);
int SkMatrix_RotateDeg(SkScalar deg);
int SkMatrix_RotateDeg_2(SkScalar deg, SkPoint pt);
int SkMatrix_RotateRad(SkScalar rad);
int SkMatrix_Skew(SkScalar kx, SkScalar ky);
int SkMatrix_RectToRect(const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit mode);
int SkMatrix_MakeAll(SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar scaleY, SkScalar transY, SkScalar pers0, SkScalar pers1, SkScalar pers2);
int SkMatrix_MakeRectToRect(const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit stf);
void SkMatrix_SetAffineIdentity(SkScalar affine[6]);
int SkMatrix_I();
int SkMatrix_InvalidMatrix();
int SkMatrix_Concat(const SkMatrix *a, const SkMatrix *b);
}

#endif //RAIA_SKIA_SK_MATRIX_H
