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
void SkMatrix_set(int sk_matrix_key_out, SkMatrix *matrix, int index, SkScalar value);
void SkMatrix_setScaleX(int sk_matrix_key_out, SkMatrix *matrix, SkScalar v);
void SkMatrix_setScaleY(int sk_matrix_key_out, SkMatrix *matrix, SkScalar v);
void SkMatrix_setSkewY(int sk_matrix_key_out, SkMatrix *matrix, SkScalar v);
void SkMatrix_setSkewX(int sk_matrix_key_out, SkMatrix *matrix, SkScalar v);
void SkMatrix_setTranslateX(int sk_matrix_key_out, SkMatrix *matrix, SkScalar v);
void SkMatrix_setTranslateY(int sk_matrix_key_out, SkMatrix *matrix, SkScalar v);
void SkMatrix_setPerspX(int sk_matrix_key_out, SkMatrix *matrix, SkScalar v);
void SkMatrix_setPerspY(int sk_matrix_key_out, SkMatrix *matrix, SkScalar v);
void SkMatrix_setAll(int sk_matrix_key_out, SkMatrix *matrix, SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar scaleY, SkScalar transY, SkScalar persp0, SkScalar persp1, SkScalar persp2);
void SkMatrix_get9(SkMatrix *matrix, SkScalar buffer[9]);
void SkMatrix_set9(int sk_matrix_key_out, SkMatrix *matrix, const SkScalar buffer[9]);
void SkMatrix_reset(int sk_matrix_key_out, SkMatrix *matrix);
void SkMatrix_setIdentity(int sk_matrix_key_out, SkMatrix *matrix);
void SkMatrix_setTranslate(int sk_matrix_key_out, SkMatrix *matrix, SkScalar dx, SkScalar dy);
void SkMatrix_setTranslate_2(int sk_matrix_key_out, SkMatrix *matrix, const SkVector *v);
void SkMatrix_setScale(int sk_matrix_key_out, SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py);
void SkMatrix_setScale_2(int sk_matrix_key_out, SkMatrix *matrix, SkScalar sx, SkScalar sy);
void SkMatrix_setRotate(int sk_matrix_key_out, SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py);
void SkMatrix_setRotate_2(int sk_matrix_key_out, SkMatrix *matrix, SkScalar degrees);
void SkMatrix_setSinCos(int sk_matrix_key_out, SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue, SkScalar px, SkScalar py);
void SkMatrix_setSinCos_2(int sk_matrix_key_out, SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue);
void SkMatrix_setRSXform(int sk_matrix_key_out, SkMatrix *matrix, const SkRSXform *rsxForm);
void SkMatrix_setSkew(int sk_matrix_key_out, SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py);
void SkMatrix_setSkew_2(int sk_matrix_key_out, SkMatrix *matrix, SkScalar kx, SkScalar ky);
void SkMatrix_setConcat(int sk_matrix_key_out, SkMatrix *matrix, const SkMatrix *a, const SkMatrix *b);
void SkMatrix_preTranslate(int sk_matrix_key_out, SkMatrix *matrix, SkScalar dx, SkScalar dy);
void SkMatrix_preScale(int sk_matrix_key_out, SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py);
void SkMatrix_preScale_2(int sk_matrix_key_out, SkMatrix *matrix, SkScalar sx, SkScalar sy);
void SkMatrix_preRotate(int sk_matrix_key_out, SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py);
void SkMatrix_preRotate_2(int sk_matrix_key_out, SkMatrix *matrix, SkScalar degrees);
void SkMatrix_preSkew(int sk_matrix_key_out, SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py);
void SkMatrix_preSkew_2(int sk_matrix_key_out, SkMatrix *matrix, SkScalar kx, SkScalar ky);
void SkMatrix_preConcat(int sk_matrix_key_out, SkMatrix *matrix, const SkMatrix *other);
void SkMatrix_postTranslate(int sk_matrix_key_out, SkMatrix *matrix, SkScalar dx, SkScalar dy);
void SkMatrix_postScale(int sk_matrix_key_out, SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py);
void SkMatrix_postScale_2(int sk_matrix_key_out, SkMatrix *matrix, SkScalar sx, SkScalar sy);
void SkMatrix_postRotate(int sk_matrix_key_out, SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py);
void SkMatrix_postRotate_2(int sk_matrix_key_out, SkMatrix *matrix, SkScalar degrees);
void SkMatrix_postSkew(int sk_matrix_key_out, SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py);
void SkMatrix_postSkew_2(int sk_matrix_key_out, SkMatrix *matrix, SkScalar kx, SkScalar ky);
void SkMatrix_postConcat(int sk_matrix_key_out, SkMatrix *matrix, const SkMatrix *other);
bool SkMatrix_setRectToRect(SkMatrix *matrix, const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit stf);
bool SkMatrix_setPolyToPoly(SkMatrix *matrix, const SkPoint src[], const SkPoint dst[], int count);
bool SkMatrix_invert(SkMatrix *matrix, SkMatrix *inverse);
bool SkMatrix_asAffine(SkMatrix *matrix, SkScalar affine[6]);
void SkMatrix_setAffine(int sk_matrix_key_out, SkMatrix *matrix, const SkScalar affine[6]);
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
void SkMatrix_mapRect_3(int sk_rect_key_out, SkMatrix *matrix, const SkRect *src, SkApplyPerspectiveClip pc);
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
void SkMatrix_Scale(int sk_matrix_key_out, SkScalar sx, SkScalar sy);
void SkMatrix_Translate(int sk_matrix_key_out, SkScalar dx, SkScalar dy);
void SkMatrix_Translate_2(int sk_matrix_key_out, SkVector t);
void SkMatrix_Translate_3(int sk_matrix_key_out, SkIVector t);
void SkMatrix_RotateDeg(int sk_matrix_key_out, SkScalar deg);
void SkMatrix_RotateDeg_2(int sk_matrix_key_out, SkScalar deg, SkPoint pt);
void SkMatrix_RotateRad(int sk_matrix_key_out, SkScalar rad);
void SkMatrix_Skew(int sk_matrix_key_out, SkScalar kx, SkScalar ky);
void SkMatrix_RectToRect(int sk_matrix_key_out, const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit mode);
void SkMatrix_MakeAll(int sk_matrix_key_out, SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar scaleY, SkScalar transY, SkScalar pers0, SkScalar pers1, SkScalar pers2);
void SkMatrix_MakeRectToRect(int sk_matrix_key_out, const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit stf);
void SkMatrix_SetAffineIdentity(SkScalar affine[6]);
void SkMatrix_I(int sk_matrix_key_out);
void SkMatrix_InvalidMatrix(int sk_matrix_key_out);
void SkMatrix_Concat(int sk_matrix_key_out, const SkMatrix *a, const SkMatrix *b);
}

#endif //RAIA_SKIA_SK_MATRIX_H
