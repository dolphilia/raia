//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_MATRIX_H
#define RAIA_SKIA_SK_MATRIX_H

#include "include/core/SkMatrix.h"
#include "../static/static_sk_matrix.h"
#include "../static/static_sk_rect.h"
#include "../static/static_sk_point.h"
#include "../static/static_sk_i_point.h"
#include "export_api.h"

extern "C" {
// SkScalar operator[](int index)
// SkScalar & operator[](int index)
RAIA_API SkMatrix *SkMatrix_new(SkMatrix *matrix);
RAIA_API void SkMatrix_delete(SkMatrix *matrix);
RAIA_API SkMatrix::TypeMask SkMatrix_getType(SkMatrix *matrix);
RAIA_API bool SkMatrix_isIdentity(SkMatrix *matrix);
RAIA_API bool SkMatrix_isScaleTranslate(SkMatrix *matrix);
RAIA_API bool SkMatrix_isTranslate(SkMatrix *matrix);
RAIA_API bool SkMatrix_rectStaysRect(SkMatrix *matrix);
RAIA_API bool SkMatrix_preservesAxisAlignment(SkMatrix *matrix);
RAIA_API bool SkMatrix_hasPerspective(SkMatrix *matrix);
RAIA_API bool SkMatrix_isSimilarity(SkMatrix *matrix, SkScalar tol);
RAIA_API bool SkMatrix_preservesRightAngles(SkMatrix *matrix, SkScalar tol);
RAIA_API SkScalar SkMatrix_get(SkMatrix *matrix, int index);
RAIA_API SkScalar SkMatrix_rc(SkMatrix *matrix, int r, int c);
RAIA_API SkScalar SkMatrix_getScaleX(SkMatrix *matrix);
RAIA_API SkScalar SkMatrix_getScaleY(SkMatrix *matrix);
RAIA_API SkScalar SkMatrix_getSkewY(SkMatrix *matrix);
RAIA_API SkScalar SkMatrix_getSkewX(SkMatrix *matrix);
RAIA_API SkScalar SkMatrix_getTranslateX(SkMatrix *matrix);
RAIA_API SkScalar SkMatrix_getTranslateY(SkMatrix *matrix);
RAIA_API SkScalar SkMatrix_getPerspX(SkMatrix *matrix);
RAIA_API SkScalar SkMatrix_getPerspY(SkMatrix *matrix);
RAIA_API sk_matrix_t SkMatrix_set(SkMatrix *matrix, int index, SkScalar value);
RAIA_API sk_matrix_t SkMatrix_setScaleX(SkMatrix *matrix, SkScalar v);
RAIA_API sk_matrix_t SkMatrix_setScaleY(SkMatrix *matrix, SkScalar v);
RAIA_API sk_matrix_t SkMatrix_setSkewY(SkMatrix *matrix, SkScalar v);
RAIA_API sk_matrix_t SkMatrix_setSkewX(SkMatrix *matrix, SkScalar v);
RAIA_API sk_matrix_t SkMatrix_setTranslateX(SkMatrix *matrix, SkScalar v);
RAIA_API sk_matrix_t SkMatrix_setTranslateY(SkMatrix *matrix, SkScalar v);
RAIA_API sk_matrix_t SkMatrix_setPerspX(SkMatrix *matrix, SkScalar v);
RAIA_API sk_matrix_t SkMatrix_setPerspY(SkMatrix *matrix, SkScalar v);
RAIA_API sk_matrix_t SkMatrix_setAll(SkMatrix *matrix, SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar scaleY, SkScalar transY, SkScalar persp0, SkScalar persp1, SkScalar persp2);
RAIA_API void SkMatrix_get9(SkMatrix *matrix, SkScalar buffer[9]);
RAIA_API sk_matrix_t SkMatrix_set9(SkMatrix *matrix, const SkScalar buffer[9]);
RAIA_API sk_matrix_t SkMatrix_reset(SkMatrix *matrix);
RAIA_API sk_matrix_t SkMatrix_setIdentity(SkMatrix *matrix);
RAIA_API sk_matrix_t SkMatrix_setTranslate(SkMatrix *matrix, SkScalar dx, SkScalar dy);
RAIA_API sk_matrix_t SkMatrix_setTranslate_2(SkMatrix *matrix, const SkVector *v);
RAIA_API sk_matrix_t SkMatrix_setScale(SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py);
RAIA_API sk_matrix_t SkMatrix_setScale_2(SkMatrix *matrix, SkScalar sx, SkScalar sy);
RAIA_API sk_matrix_t SkMatrix_setRotate(SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py);
RAIA_API sk_matrix_t SkMatrix_setRotate_2(SkMatrix *matrix, SkScalar degrees);
RAIA_API sk_matrix_t SkMatrix_setSinCos(SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue, SkScalar px, SkScalar py);
RAIA_API sk_matrix_t SkMatrix_setSinCos_2(SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue);
RAIA_API sk_matrix_t SkMatrix_setRSXform(SkMatrix *matrix, const SkRSXform *rsxForm);
RAIA_API sk_matrix_t SkMatrix_setSkew(SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py);
RAIA_API sk_matrix_t SkMatrix_setSkew_2(SkMatrix *matrix, SkScalar kx, SkScalar ky);
RAIA_API sk_matrix_t SkMatrix_setConcat(SkMatrix *matrix, const SkMatrix *a, const SkMatrix *b);
RAIA_API sk_matrix_t SkMatrix_preTranslate(SkMatrix *matrix, SkScalar dx, SkScalar dy);
RAIA_API sk_matrix_t SkMatrix_preScale(SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py);
RAIA_API sk_matrix_t SkMatrix_preScale_2(SkMatrix *matrix, SkScalar sx, SkScalar sy);
RAIA_API sk_matrix_t SkMatrix_preRotate(SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py);
RAIA_API sk_matrix_t SkMatrix_preRotate_2(SkMatrix *matrix, SkScalar degrees);
RAIA_API sk_matrix_t SkMatrix_preSkew(SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py);
RAIA_API sk_matrix_t SkMatrix_preSkew_2(SkMatrix *matrix, SkScalar kx, SkScalar ky);
RAIA_API sk_matrix_t SkMatrix_preConcat(SkMatrix *matrix, const SkMatrix *other);
RAIA_API sk_matrix_t SkMatrix_postTranslate(SkMatrix *matrix, SkScalar dx, SkScalar dy);
RAIA_API sk_matrix_t SkMatrix_postScale(SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py);
RAIA_API sk_matrix_t SkMatrix_postScale_2(SkMatrix *matrix, SkScalar sx, SkScalar sy);
RAIA_API sk_matrix_t SkMatrix_postRotate(SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py);
RAIA_API sk_matrix_t SkMatrix_postRotate_2(SkMatrix *matrix, SkScalar degrees);
RAIA_API sk_matrix_t SkMatrix_postSkew(SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py);
RAIA_API sk_matrix_t SkMatrix_postSkew_2(SkMatrix *matrix, SkScalar kx, SkScalar ky);
RAIA_API sk_matrix_t SkMatrix_postConcat(SkMatrix *matrix, const SkMatrix *other);
RAIA_API bool SkMatrix_setRectToRect(SkMatrix *matrix, const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit stf);
RAIA_API bool SkMatrix_setPolyToPoly(SkMatrix *matrix, const SkPoint src[], const SkPoint dst[], int count);
RAIA_API bool SkMatrix_invert(SkMatrix *matrix, SkMatrix *inverse);
RAIA_API bool SkMatrix_asAffine(SkMatrix *matrix, SkScalar affine[6]);
RAIA_API sk_matrix_t SkMatrix_setAffine(SkMatrix *matrix, const SkScalar affine[6]);
RAIA_API void SkMatrix_normalizePerspective(SkMatrix *matrix);
RAIA_API void SkMatrix_mapPoints(SkMatrix *matrix, SkPoint dst[], const SkPoint src[], int count);
RAIA_API void SkMatrix_mapPoints_2(SkMatrix *matrix, SkPoint pts[], int count);
RAIA_API void SkMatrix_mapHomogeneousPoints(SkMatrix *matrix, SkPoint3 dst[], const SkPoint3 src[], int count);
RAIA_API void SkMatrix_mapHomogeneousPoints_2(SkMatrix *matrix, SkPoint3 dst[], const SkPoint src[], int count);
RAIA_API sk_point_t SkMatrix_mapPoint(SkMatrix *matrix, sk_point_t pt);
RAIA_API void SkMatrix_mapXY(SkMatrix *matrix, SkScalar x, SkScalar y, SkPoint *result);
RAIA_API sk_point_t SkMatrix_mapXY_2(SkMatrix *matrix, SkScalar x, SkScalar y);
RAIA_API sk_point_t SkMatrix_mapOrigin(SkMatrix *matrix);
RAIA_API void SkMatrix_mapVectors(SkMatrix *matrix, SkVector dst[], const SkVector src[], int count);
RAIA_API void SkMatrix_mapVectors_2(SkMatrix *matrix, SkVector vecs[], int count);
RAIA_API void SkMatrix_mapVector(SkMatrix *matrix, SkScalar dx, SkScalar dy, SkVector *result);
RAIA_API sk_point_t SkMatrix_mapVector_2(SkMatrix *matrix, SkScalar dx, SkScalar dy);
RAIA_API bool SkMatrix_mapRect(SkMatrix *matrix, SkRect *dst, const SkRect *src, SkApplyPerspectiveClip pc);
RAIA_API bool SkMatrix_mapRect_2(SkMatrix *matrix, SkRect *rect, SkApplyPerspectiveClip pc);
RAIA_API sk_matrix_t SkMatrix_mapRect_3(SkMatrix *matrix, const SkRect *src, SkApplyPerspectiveClip pc);
RAIA_API void SkMatrix_mapRectToQuad(SkMatrix *matrix, SkPoint dst[4], const SkRect *rect);
RAIA_API void SkMatrix_mapRectScaleTranslate(SkMatrix *matrix, SkRect *dst, const SkRect *src);
RAIA_API SkScalar SkMatrix_mapRadius(SkMatrix *matrix, SkScalar radius);
RAIA_API void SkMatrix_dump(SkMatrix *matrix);
RAIA_API SkScalar SkMatrix_getMinScale(SkMatrix *matrix);
RAIA_API SkScalar SkMatrix_getMaxScale(SkMatrix *matrix);
RAIA_API bool SkMatrix_getMinMaxScales(SkMatrix *matrix, SkScalar scaleFactors[2]);
RAIA_API bool SkMatrix_decomposeScale(SkMatrix *matrix, SkSize *scale, SkMatrix *remaining);
RAIA_API void SkMatrix_dirtyMatrixTypeCache(SkMatrix *matrix);
RAIA_API void SkMatrix_setScaleTranslate(SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar tx, SkScalar ty);
RAIA_API bool SkMatrix_isFinite(SkMatrix *matrix);
// static
RAIA_API sk_matrix_t SkMatrix_Scale(SkScalar sx, SkScalar sy);
RAIA_API sk_matrix_t SkMatrix_Translate(SkScalar dx, SkScalar dy);
RAIA_API sk_matrix_t SkMatrix_Translate_2(sk_point_t t);
RAIA_API sk_matrix_t SkMatrix_Translate_3(sk_i_point_t t);
RAIA_API sk_matrix_t SkMatrix_RotateDeg(SkScalar deg);
RAIA_API sk_matrix_t SkMatrix_RotateDeg_2(SkScalar deg, sk_point_t pt);
RAIA_API sk_matrix_t SkMatrix_RotateRad(SkScalar rad);
RAIA_API sk_matrix_t SkMatrix_Skew(SkScalar kx, SkScalar ky);
RAIA_API sk_matrix_t SkMatrix_RectToRect(const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit mode);
RAIA_API sk_matrix_t SkMatrix_MakeAll(SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar scaleY, SkScalar transY, SkScalar pers0, SkScalar pers1, SkScalar pers2);
RAIA_API sk_matrix_t SkMatrix_MakeRectToRect(const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit stf);
RAIA_API void SkMatrix_SetAffineIdentity(SkScalar affine[6]);
RAIA_API sk_matrix_t SkMatrix_I();
RAIA_API sk_matrix_t SkMatrix_InvalidMatrix();
RAIA_API sk_matrix_t SkMatrix_Concat(const SkMatrix *a, const SkMatrix *b);
}

#endif //RAIA_SKIA_SK_MATRIX_H
