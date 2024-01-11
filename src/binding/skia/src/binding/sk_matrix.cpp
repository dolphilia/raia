//
// Created by dolphilia on 2024/01/09.
//

#include "sk_matrix.h"

extern "C" {

// SkScalar operator[](int index)
// SkScalar & operator[](int index)

SkMatrix *SkMatrix_new(SkMatrix *matrix) {
    return new SkMatrix();
}

SkMatrix::TypeMask SkMatrix_getType(SkMatrix *matrix) {
    return matrix->getType();
}

bool SkMatrix_isIdentity(SkMatrix *matrix) {
    return matrix->isIdentity();
}

bool SkMatrix_isScaleTranslate(SkMatrix *matrix) {
    return matrix->isScaleTranslate();
}

bool SkMatrix_isTranslate(SkMatrix *matrix) {
    return matrix->isTranslate();
}

bool SkMatrix_rectStaysRect(SkMatrix *matrix) {
    return matrix->rectStaysRect();
}

bool SkMatrix_preservesAxisAlignment(SkMatrix *matrix) {
    return matrix->preservesAxisAlignment();
}

bool SkMatrix_hasPerspective(SkMatrix *matrix) {
    return matrix->hasPerspective();
}

bool SkMatrix_isSimilarity(SkMatrix *matrix, SkScalar tol) {
    return matrix->isSimilarity(tol);
}

bool SkMatrix_preservesRightAngles(SkMatrix *matrix, SkScalar tol) {
    return matrix->preservesRightAngles(tol);
}

SkScalar SkMatrix_get(SkMatrix *matrix, int index) {
    return matrix->get(index);
}

SkScalar SkMatrix_rc(SkMatrix *matrix, int r, int c) {
    return matrix->rc(r, c);
}

SkScalar SkMatrix_getScaleX(SkMatrix *matrix) {
    return matrix->getScaleX();
}

SkScalar SkMatrix_getScaleY(SkMatrix *matrix) {
    return matrix->getScaleY();
}

SkScalar SkMatrix_getSkewY(SkMatrix *matrix) {
    return matrix->getSkewY();
}

SkScalar SkMatrix_getSkewX(SkMatrix *matrix) {
    return matrix->getSkewX();
}

SkScalar SkMatrix_getTranslateX(SkMatrix *matrix) {
    return matrix->getTranslateX();
}

SkScalar SkMatrix_getTranslateY(SkMatrix *matrix) {
    return matrix->getTranslateY();
}

SkScalar SkMatrix_getPerspX(SkMatrix *matrix) {
    return matrix->getPerspX();
}

SkScalar SkMatrix_getPerspY(SkMatrix *matrix) {
    return matrix->getPerspY();
}

void SkMatrix_set(const char *sk_matrix_key_out, SkMatrix *matrix, int index, SkScalar value) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->set(index, value));
}

void SkMatrix_setScaleX(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar v) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setScaleX(v));
}

void SkMatrix_setScaleY(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar v) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setScaleY(v));
}

void SkMatrix_setSkewY(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar v) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setSkewY(v));
}

void SkMatrix_setSkewX(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar v) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setSkewX(v));
}

void SkMatrix_setTranslateX(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar v) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setTranslateX(v));
}

void SkMatrix_setTranslateY(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar v) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setTranslateY(v));
}

void SkMatrix_setPerspX(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar v) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setPerspX(v));
}

void SkMatrix_setPerspY(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar v) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setPerspY(v));
}

void SkMatrix_setAll(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar scaleY, SkScalar transY, SkScalar persp0, SkScalar persp1, SkScalar persp2) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setAll(scaleX, skewX, transX, skewY, scaleY, transY, persp0, persp1, persp2));
}

void SkMatrix_get9(SkMatrix *matrix, SkScalar buffer[9]) {
    matrix->get9(buffer);
}

void SkMatrix_set9(const char *sk_matrix_key_out, SkMatrix *matrix, const SkScalar buffer[9]) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->set9(buffer));
}

void SkMatrix_reset(const char *sk_matrix_key_out, SkMatrix *matrix) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->reset());
}

void SkMatrix_setIdentity(const char *sk_matrix_key_out, SkMatrix *matrix) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setIdentity());
}

void SkMatrix_setTranslate(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar dx, SkScalar dy) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setTranslate(dx, dy));
}

void SkMatrix_setTranslate_2(const char *sk_matrix_key_out, SkMatrix *matrix, const SkVector *v) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setTranslate(*v));
}

void SkMatrix_setScale(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setScale(sx, sy, px, py));
}

void SkMatrix_setScale_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar sx, SkScalar sy) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setScale(sx, sy));
}

void SkMatrix_setRotate(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setRotate(degrees, px, py));
}

void SkMatrix_setRotate_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar degrees) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setRotate(degrees));
}

void SkMatrix_setSinCos(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue, SkScalar px, SkScalar py) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setSinCos(sinValue, cosValue, px, py));
}

void SkMatrix_setSinCos_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setSinCos(sinValue, cosValue));
}

void SkMatrix_setRSXform(const char *sk_matrix_key_out, SkMatrix *matrix, const SkRSXform *rsxForm) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setRSXform(*rsxForm));
}

void SkMatrix_setSkew(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setSkew(kx, ky, px, py));
}

void SkMatrix_setSkew_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar kx, SkScalar ky) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setSkew(kx, ky));
}

void SkMatrix_setConcat(const char *sk_matrix_key_out, SkMatrix *matrix, const SkMatrix *a, const SkMatrix *b) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setConcat(*a, *b));
}

void SkMatrix_preTranslate(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar dx, SkScalar dy) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->preTranslate(dx, dy));
}

void SkMatrix_preScale(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->preScale(sx, sy, px, py));
}

void SkMatrix_preScale_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar sx, SkScalar sy) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->preScale(sx, sy));
}

void SkMatrix_preRotate(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->preRotate(degrees, px, py));
}

void SkMatrix_preRotate_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar degrees) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->preRotate(degrees));
}

void SkMatrix_preSkew(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->preSkew(kx, ky, px, py));
}

void SkMatrix_preSkew_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar kx, SkScalar ky) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->preSkew(kx, ky));
}

void SkMatrix_preConcat(const char *sk_matrix_key_out, SkMatrix *matrix, const SkMatrix *other) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->preConcat(*other));
}

void SkMatrix_postTranslate(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar dx, SkScalar dy) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->postTranslate(dx, dy));
}

void SkMatrix_postScale(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->postScale(sx, sy, px, py));
}

void SkMatrix_postScale_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar sx, SkScalar sy) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->postScale(sx, sy));
}

void SkMatrix_postRotate(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->postRotate(degrees, px, py));
}

void SkMatrix_postRotate_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar degrees) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->postRotate(degrees));
}

void SkMatrix_postSkew(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->postSkew(kx, ky, px, py));
}

void SkMatrix_postSkew_2(const char *sk_matrix_key_out, SkMatrix *matrix, SkScalar kx, SkScalar ky) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->postSkew(kx, ky));
}

void SkMatrix_postConcat(const char *sk_matrix_key_out, SkMatrix *matrix, const SkMatrix *other) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->postConcat(*other));
}

bool SkMatrix_setRectToRect(SkMatrix *matrix, const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit stf) {
    return matrix->setRectToRect(*src, *dst, stf);
}

bool SkMatrix_setPolyToPoly(SkMatrix *matrix, const SkPoint src[], const SkPoint dst[], int count) {
    return matrix->setPolyToPoly(src, dst, count);
}

bool SkMatrix_invert(SkMatrix *matrix, SkMatrix *inverse) {
    return matrix->invert(inverse);
}

bool SkMatrix_asAffine(SkMatrix *matrix, SkScalar affine[6]) {
    return matrix->asAffine(affine);
}

void SkMatrix_setAffine(const char *sk_matrix_key_out, SkMatrix *matrix, const SkScalar affine[6]) {
    static_sk_matrix_set(sk_matrix_key_out, matrix->setAffine(affine));
}

void SkMatrix_normalizePerspective(SkMatrix *matrix) {
    matrix->normalizePerspective();
}

void SkMatrix_mapPoints(SkMatrix *matrix, SkPoint dst[], const SkPoint src[], int count) {
    matrix->mapPoints(dst, src, count);
}

void SkMatrix_mapPoints_2(SkMatrix *matrix, SkPoint pts[], int count) {
    matrix->mapPoints(pts, count);
}

void SkMatrix_mapHomogeneousPoints(SkMatrix *matrix, SkPoint3 dst[], const SkPoint3 src[], int count) {
    matrix->mapHomogeneousPoints(dst, src, count);
}

void SkMatrix_mapHomogeneousPoints_2(SkMatrix *matrix, SkPoint3 dst[], const SkPoint src[], int count) {
    matrix->mapHomogeneousPoints(dst, src, count);
}

SkPoint SkMatrix_mapPoint(SkMatrix *matrix, SkPoint pt) {
    return matrix->mapPoint(pt);
}

void SkMatrix_mapXY(SkMatrix *matrix, SkScalar x, SkScalar y, SkPoint *result) {
    matrix->mapXY(x, y, result);
}

SkPoint SkMatrix_mapXY_2(SkMatrix *matrix, SkScalar x, SkScalar y) {
    return matrix->mapXY(x, y);
}

SkPoint SkMatrix_mapOrigin(SkMatrix *matrix) {
    return matrix->mapOrigin();
}

void SkMatrix_mapVectors(SkMatrix *matrix, SkVector dst[], const SkVector src[], int count) {
    matrix->mapVectors(dst, src, count);
}

void SkMatrix_mapVectors_2(SkMatrix *matrix, SkVector vecs[], int count) {
    matrix->mapVectors(vecs, count);
}

void SkMatrix_mapVector(SkMatrix *matrix, SkScalar dx, SkScalar dy, SkVector *result) {
    matrix->mapVector(dx, dy, result);
}

SkVector SkMatrix_mapVector_2(SkMatrix *matrix, SkScalar dx, SkScalar dy) {
    return matrix->mapVector(dx, dy);
}

bool SkMatrix_mapRect(SkMatrix *matrix, SkRect *dst, const SkRect *src, SkApplyPerspectiveClip pc) {
    return matrix->mapRect(dst, *src, pc);
}

bool SkMatrix_mapRect_2(SkMatrix *matrix, SkRect *rect, SkApplyPerspectiveClip pc) {
    return matrix->mapRect(rect, pc);
}

void SkMatrix_mapRect_3(const char *sk_rect_key_out, SkMatrix *matrix, const SkRect *src, SkApplyPerspectiveClip pc) {
    static_sk_rect_set(sk_rect_key_out, matrix->mapRect(*src, pc));
}

void SkMatrix_mapRectToQuad(SkMatrix *matrix, SkPoint dst[4], const SkRect *rect) {
    matrix->mapRectToQuad(dst, *rect);
}

void SkMatrix_mapRectScaleTranslate(SkMatrix *matrix, SkRect *dst, const SkRect *src) {
    matrix->mapRectScaleTranslate(dst, *src);
}

SkScalar SkMatrix_mapRadius(SkMatrix *matrix, SkScalar radius) {
    return matrix->mapRadius(radius);
}

void SkMatrix_dump(SkMatrix *matrix) {
    matrix->dump();
}

SkScalar SkMatrix_getMinScale(SkMatrix *matrix) {
    return matrix->getMinScale();
}

SkScalar SkMatrix_getMaxScale(SkMatrix *matrix) {
    return matrix->getMaxScale();
}

bool SkMatrix_getMinMaxScales(SkMatrix *matrix, SkScalar scaleFactors[2]) {
    return matrix->getMinMaxScales(scaleFactors);
}

bool SkMatrix_decomposeScale(SkMatrix *matrix, SkSize *scale, SkMatrix *remaining) {
    return matrix->decomposeScale(scale, remaining);
}

void SkMatrix_dirtyMatrixTypeCache(SkMatrix *matrix) {
    matrix->dirtyMatrixTypeCache();
}

void SkMatrix_setScaleTranslate(SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar tx, SkScalar ty) {
    matrix->setScaleTranslate(sx, sy, tx, ty);
}

bool SkMatrix_isFinite(SkMatrix *matrix) {
    return matrix->isFinite();
}


// static

void SkMatrix_Scale(const char *sk_matrix_key_out, SkScalar sx, SkScalar sy) {
    static_sk_matrix_set(sk_matrix_key_out, SkMatrix::Scale(sx, sy));
}

void SkMatrix_Translate(const char *sk_matrix_key_out, SkScalar dx, SkScalar dy) {
    static_sk_matrix_set(sk_matrix_key_out, SkMatrix::Translate(dx, dy));
}

void SkMatrix_Translate_2(const char *sk_matrix_key_out, SkVector t) {
    static_sk_matrix_set(sk_matrix_key_out, SkMatrix::Translate(t));
}

void SkMatrix_Translate_3(const char *sk_matrix_key_out, SkIVector t) {
    static_sk_matrix_set(sk_matrix_key_out, SkMatrix::Translate(t));
}

void SkMatrix_RotateDeg(const char *sk_matrix_key_out, SkScalar deg) {
    static_sk_matrix_set(sk_matrix_key_out, SkMatrix::RotateDeg(deg));
}

void SkMatrix_RotateDeg_2(const char *sk_matrix_key_out, SkScalar deg, SkPoint pt) {
    static_sk_matrix_set(sk_matrix_key_out, SkMatrix::RotateDeg(deg, pt));
}

void SkMatrix_RotateRad(const char *sk_matrix_key_out, SkScalar rad) {
    static_sk_matrix_set(sk_matrix_key_out, SkMatrix::RotateRad(rad));
}

void SkMatrix_Skew(const char *sk_matrix_key_out, SkScalar kx, SkScalar ky) {
    static_sk_matrix_set(sk_matrix_key_out, SkMatrix::Skew(kx, ky));
}

void SkMatrix_RectToRect(const char *sk_matrix_key_out, const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit mode) {
    static_sk_matrix_set(sk_matrix_key_out, SkMatrix::RectToRect(*src, *dst, mode));
}

void SkMatrix_MakeAll(const char *sk_matrix_key_out, SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar scaleY, SkScalar transY, SkScalar pers0, SkScalar pers1, SkScalar pers2) {
    static_sk_matrix_set(sk_matrix_key_out, SkMatrix::MakeAll(scaleX, skewX, transX, skewY, scaleY, transY, pers0, pers1, pers2));
}

void SkMatrix_MakeRectToRect(const char *sk_matrix_key_out, const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit stf) {
    static_sk_matrix_set(sk_matrix_key_out, SkMatrix::MakeRectToRect(*src, *dst, stf));
}

void SkMatrix_SetAffineIdentity(SkScalar affine[6]) {
    SkMatrix::SetAffineIdentity(affine);
}

void SkMatrix_I(const char *sk_matrix_key_out) {
    static_sk_matrix_set(sk_matrix_key_out, SkMatrix::I());
}

void SkMatrix_InvalidMatrix(const char *sk_matrix_key_out) {
    static_sk_matrix_set(sk_matrix_key_out, SkMatrix::InvalidMatrix());
}

void SkMatrix_Concat(const char *sk_matrix_key_out, const SkMatrix *a, const SkMatrix *b) {
    static_sk_matrix_set(sk_matrix_key_out, SkMatrix::Concat(*a, *b));
}

}