//
// Created by dolphilia on 2024/01/09.
//

#include "sk_matrix.h"

extern "C" {

// SkScalar operator[](int index)
// SkScalar & operator[](int index)

SkMatrix *SkMatrix_new(SkMatrix *matrix) {
    return new SkMatrix(*matrix);
}

void SkMatrix_delete(SkMatrix *matrix) {
    delete matrix;
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

sk_matrix_t SkMatrix_set(SkMatrix *matrix, int index, SkScalar value) {
    return static_sk_matrix_make(matrix->set(index, value));
}

sk_matrix_t SkMatrix_setScaleX(SkMatrix *matrix, SkScalar v) {
    return static_sk_matrix_make(matrix->setScaleX(v));
}

sk_matrix_t SkMatrix_setScaleY(SkMatrix *matrix, SkScalar v) {
    return static_sk_matrix_make(matrix->setScaleY(v));
}

sk_matrix_t SkMatrix_setSkewY(SkMatrix *matrix, SkScalar v) {
    return static_sk_matrix_make(matrix->setSkewY(v));
}

sk_matrix_t SkMatrix_setSkewX(SkMatrix *matrix, SkScalar v) {
    return static_sk_matrix_make(matrix->setSkewX(v));
}

sk_matrix_t SkMatrix_setTranslateX(SkMatrix *matrix, SkScalar v) {
    return static_sk_matrix_make(matrix->setTranslateX(v));
}

sk_matrix_t SkMatrix_setTranslateY(SkMatrix *matrix, SkScalar v) {
    return static_sk_matrix_make(matrix->setTranslateY(v));
}

sk_matrix_t SkMatrix_setPerspX(SkMatrix *matrix, SkScalar v) {
    return static_sk_matrix_make(matrix->setPerspX(v));
}

sk_matrix_t SkMatrix_setPerspY(SkMatrix *matrix, SkScalar v) {
    return static_sk_matrix_make(matrix->setPerspY(v));
}

sk_matrix_t SkMatrix_setAll(SkMatrix *matrix, SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar scaleY, SkScalar transY, SkScalar persp0, SkScalar persp1, SkScalar persp2) {
    return static_sk_matrix_make(matrix->setAll(scaleX, skewX, transX, skewY, scaleY, transY, persp0, persp1, persp2));
}

void SkMatrix_get9(SkMatrix *matrix, SkScalar buffer[9]) {
    matrix->get9(buffer);
}

sk_matrix_t SkMatrix_set9(SkMatrix *matrix, const SkScalar buffer[9]) {
    return static_sk_matrix_make(matrix->set9(buffer));
}

sk_matrix_t SkMatrix_reset(SkMatrix *matrix) {
    return static_sk_matrix_make(matrix->reset());
}

sk_matrix_t SkMatrix_setIdentity(SkMatrix *matrix) {
    return static_sk_matrix_make(matrix->setIdentity());
}

sk_matrix_t SkMatrix_setTranslate(SkMatrix *matrix, SkScalar dx, SkScalar dy) {
    return static_sk_matrix_make(matrix->setTranslate(dx, dy));
}

sk_matrix_t SkMatrix_setTranslate_2(SkMatrix *matrix, const SkVector *v) {
    return static_sk_matrix_make(matrix->setTranslate(*v));
}

sk_matrix_t SkMatrix_setScale(SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) {
    return static_sk_matrix_make(matrix->setScale(sx, sy, px, py));
}

sk_matrix_t SkMatrix_setScale_2(SkMatrix *matrix, SkScalar sx, SkScalar sy) {
    return static_sk_matrix_make(matrix->setScale(sx, sy));
}

sk_matrix_t SkMatrix_setRotate(SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py) {
    return static_sk_matrix_make(matrix->setRotate(degrees, px, py));
}

sk_matrix_t SkMatrix_setRotate_2(SkMatrix *matrix, SkScalar degrees) {
    return static_sk_matrix_make(matrix->setRotate(degrees));
}

sk_matrix_t SkMatrix_setSinCos(SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue, SkScalar px, SkScalar py) {
    return static_sk_matrix_make(matrix->setSinCos(sinValue, cosValue, px, py));
}

sk_matrix_t SkMatrix_setSinCos_2(SkMatrix *matrix, SkScalar sinValue, SkScalar cosValue) {
    return static_sk_matrix_make(matrix->setSinCos(sinValue, cosValue));
}

sk_matrix_t SkMatrix_setRSXform(SkMatrix *matrix, const SkRSXform *rsxForm) {
    return static_sk_matrix_make(matrix->setRSXform(*rsxForm));
}

sk_matrix_t SkMatrix_setSkew(SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py) {
    return static_sk_matrix_make(matrix->setSkew(kx, ky, px, py));
}

sk_matrix_t SkMatrix_setSkew_2(SkMatrix *matrix, SkScalar kx, SkScalar ky) {
    return static_sk_matrix_make(matrix->setSkew(kx, ky));
}

sk_matrix_t SkMatrix_setConcat(SkMatrix *matrix, const SkMatrix *a, const SkMatrix *b) {
    return static_sk_matrix_make(matrix->setConcat(*a, *b));
}

sk_matrix_t SkMatrix_preTranslate(SkMatrix *matrix, SkScalar dx, SkScalar dy) {
    return static_sk_matrix_make(matrix->preTranslate(dx, dy));
}

sk_matrix_t SkMatrix_preScale(SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) {
    return static_sk_matrix_make(matrix->preScale(sx, sy, px, py));
}

sk_matrix_t SkMatrix_preScale_2(SkMatrix *matrix, SkScalar sx, SkScalar sy) {
    return static_sk_matrix_make(matrix->preScale(sx, sy));
}

sk_matrix_t SkMatrix_preRotate(SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py) {
    return static_sk_matrix_make(matrix->preRotate(degrees, px, py));
}

sk_matrix_t SkMatrix_preRotate_2(SkMatrix *matrix, SkScalar degrees) {
    return static_sk_matrix_make(matrix->preRotate(degrees));
}

sk_matrix_t SkMatrix_preSkew(SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py) {
    return static_sk_matrix_make(matrix->preSkew(kx, ky, px, py));
}

sk_matrix_t SkMatrix_preSkew_2(SkMatrix *matrix, SkScalar kx, SkScalar ky) {
    return static_sk_matrix_make(matrix->preSkew(kx, ky));
}

sk_matrix_t SkMatrix_preConcat(SkMatrix *matrix, const SkMatrix *other) {
    return static_sk_matrix_make(matrix->preConcat(*other));
}

sk_matrix_t SkMatrix_postTranslate(SkMatrix *matrix, SkScalar dx, SkScalar dy) {
    return static_sk_matrix_make(matrix->postTranslate(dx, dy));
}

sk_matrix_t SkMatrix_postScale(SkMatrix *matrix, SkScalar sx, SkScalar sy, SkScalar px, SkScalar py) {
    return static_sk_matrix_make(matrix->postScale(sx, sy, px, py));
}

sk_matrix_t SkMatrix_postScale_2(SkMatrix *matrix, SkScalar sx, SkScalar sy) {
    return static_sk_matrix_make(matrix->postScale(sx, sy));
}

sk_matrix_t SkMatrix_postRotate(SkMatrix *matrix, SkScalar degrees, SkScalar px, SkScalar py) {
    return static_sk_matrix_make(matrix->postRotate(degrees, px, py));
}

sk_matrix_t SkMatrix_postRotate_2(SkMatrix *matrix, SkScalar degrees) {
    return static_sk_matrix_make(matrix->postRotate(degrees));
}

sk_matrix_t SkMatrix_postSkew(SkMatrix *matrix, SkScalar kx, SkScalar ky, SkScalar px, SkScalar py) {
    return static_sk_matrix_make(matrix->postSkew(kx, ky, px, py));
}

sk_matrix_t SkMatrix_postSkew_2(SkMatrix *matrix, SkScalar kx, SkScalar ky) {
    return static_sk_matrix_make(matrix->postSkew(kx, ky));
}

sk_matrix_t SkMatrix_postConcat(SkMatrix *matrix, const SkMatrix *other) {
    return static_sk_matrix_make(matrix->postConcat(*other));
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

sk_matrix_t SkMatrix_setAffine(SkMatrix *matrix, const SkScalar affine[6]) {
    return static_sk_matrix_make(matrix->setAffine(affine));
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

sk_point_t SkMatrix_mapPoint(SkMatrix *matrix, sk_point_t pt) {
    return static_sk_point_make(matrix->mapPoint(static_sk_point_get(pt)));
}

void SkMatrix_mapXY(SkMatrix *matrix, SkScalar x, SkScalar y, SkPoint *result) {
    matrix->mapXY(x, y, result);
}

sk_point_t SkMatrix_mapXY_2(SkMatrix *matrix, SkScalar x, SkScalar y) {
    return static_sk_point_make(matrix->mapXY(x, y));
}

sk_point_t SkMatrix_mapOrigin(SkMatrix *matrix) {
    return static_sk_point_make(matrix->mapOrigin());
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

sk_point_t SkMatrix_mapVector_2(SkMatrix *matrix, SkScalar dx, SkScalar dy) {
    return static_sk_point_make(matrix->mapVector(dx, dy));
}

bool SkMatrix_mapRect(SkMatrix *matrix, SkRect *dst, const SkRect *src, SkApplyPerspectiveClip pc) {
    return matrix->mapRect(dst, *src, pc);
}

bool SkMatrix_mapRect_2(SkMatrix *matrix, SkRect *rect, SkApplyPerspectiveClip pc) {
    return matrix->mapRect(rect, pc);
}

sk_rect_t SkMatrix_mapRect_3(SkMatrix *matrix, const SkRect *src, SkApplyPerspectiveClip pc) {
    return static_sk_rect_make(matrix->mapRect(*src, pc));
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

sk_matrix_t SkMatrix_Scale(SkScalar sx, SkScalar sy) {
    return static_sk_matrix_make(SkMatrix::Scale(sx, sy));
}

sk_matrix_t SkMatrix_Translate(SkScalar dx, SkScalar dy) {
    return static_sk_matrix_make(SkMatrix::Translate(dx, dy));
}

sk_matrix_t SkMatrix_Translate_2(sk_point_t t) {
    return static_sk_matrix_make(SkMatrix::Translate(static_sk_point_get(t)));
}

sk_matrix_t SkMatrix_Translate_3(sk_i_point_t t) {
    return static_sk_matrix_make(SkMatrix::Translate(static_sk_i_point_get(t)));
}

sk_matrix_t SkMatrix_RotateDeg(SkScalar deg) {
    return static_sk_matrix_make(SkMatrix::RotateDeg(deg));
}

sk_matrix_t SkMatrix_RotateDeg_2(SkScalar deg, sk_point_t pt) {
    return static_sk_matrix_make(SkMatrix::RotateDeg(deg, static_sk_point_get(pt)));
}

sk_matrix_t SkMatrix_RotateRad(SkScalar rad) {
    return static_sk_matrix_make(SkMatrix::RotateRad(rad));
}

sk_matrix_t SkMatrix_Skew(SkScalar kx, SkScalar ky) {
    return static_sk_matrix_make(SkMatrix::Skew(kx, ky));
}

sk_matrix_t SkMatrix_RectToRect(const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit mode) {
    return static_sk_matrix_make(SkMatrix::RectToRect(*src, *dst, mode));
}

sk_matrix_t SkMatrix_MakeAll(SkScalar scaleX, SkScalar skewX, SkScalar transX, SkScalar skewY, SkScalar scaleY, SkScalar transY, SkScalar pers0, SkScalar pers1, SkScalar pers2) {
    return static_sk_matrix_make(SkMatrix::MakeAll(scaleX, skewX, transX, skewY, scaleY, transY, pers0, pers1, pers2));
}

sk_matrix_t SkMatrix_MakeRectToRect(const SkRect *src, const SkRect *dst, SkMatrix::ScaleToFit stf) {
    return static_sk_matrix_make(SkMatrix::MakeRectToRect(*src, *dst, stf));
}

void SkMatrix_SetAffineIdentity(SkScalar affine[6]) {
    SkMatrix::SetAffineIdentity(affine);
}

sk_matrix_t SkMatrix_I() {
    return static_sk_matrix_make(SkMatrix::I());
}

sk_matrix_t SkMatrix_InvalidMatrix() {
    return static_sk_matrix_make(SkMatrix::InvalidMatrix());
}

sk_matrix_t SkMatrix_Concat(const SkMatrix *a, const SkMatrix *b) {
    return static_sk_matrix_make(SkMatrix::Concat(*a, *b));
}

}