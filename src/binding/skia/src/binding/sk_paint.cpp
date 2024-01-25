//
// Created by dolphilia on 2024/01/09.
//

#include "sk_paint.h"

extern "C" {

//SkPaint & operator=(const SkPaint &paint)
//SkPaint & operator=(SkPaint &&paint)

SkPaint *SkPaint_new() {
    return new SkPaint();
}

SkPaint *SkPaint_new_2(const SkColor4f *color, SkColorSpace *colorSpace) {
    return new SkPaint(*color, colorSpace);
}

SkPaint *SkPaint_new_3(const SkPaint *paint) {
    return new SkPaint(*paint);
}

void SkPaint_delete(SkPaint *paint) {
    delete paint;
}

void SkPaint_reset(SkPaint *paint) {
    paint->reset();
}

bool SkPaint_isAntiAlias(SkPaint *paint) {
    return paint->isAntiAlias();
}

void SkPaint_setAntiAlias(SkPaint *paint, bool aa) {
    paint->setAntiAlias(aa);
}

bool SkPaint_isDither(SkPaint *paint) {
    return paint->isDither();
}

void SkPaint_setDither(SkPaint *paint, bool dither) {
    paint->setDither(dither);
}

SkPaint::Style SkPaint_getStyle(SkPaint *paint) {
    return paint->getStyle();
}

void SkPaint_setStyle(SkPaint *paint, SkPaint::Style style) {
    paint->setStyle(style);
}

void SkPaint_setStroke(SkPaint *paint, bool v) {
    paint->setStroke(v);
}

SkColor SkPaint_getColor(SkPaint *paint) {
    return paint->getColor();
}

SkColor4f SkPaint_getColor4f(SkPaint *paint) {
    return paint->getColor4f();
}

void SkPaint_setColor(SkPaint *paint, SkColor color) {
    paint->setColor(color);
}

void SkPaint_setColor_2(SkPaint *paint, const SkColor4f *color, SkColorSpace *colorSpace) {
    paint->setColor(*color, colorSpace);
}

void SkPaint_setColor4f(SkPaint *paint, const SkColor4f *color, SkColorSpace *colorSpace) {
    paint->setColor4f(*color, colorSpace);
}

float SkPaint_getAlphaf(SkPaint *paint) {
    return paint->getAlphaf();
}

uint8_t SkPaint_getAlpha(SkPaint *paint) {
    return paint->getAlpha();
}

void SkPaint_setAlphaf(SkPaint *paint, float a) {
    paint->setAlphaf(a);
}

void SkPaint_setAlpha(SkPaint *paint, U8CPU a) {
    paint->setAlpha(a);
}

void SkPaint_setARGB(SkPaint *paint, U8CPU a, U8CPU r, U8CPU g, U8CPU b) {
    paint->setARGB(a, r, g, b);
}

SkScalar SkPaint_getStrokeWidth(SkPaint *paint) {
    return paint->getStrokeWidth();
}

void SkPaint_setStrokeWidth(SkPaint *paint, SkScalar width) {
    paint->setStrokeWidth(width);
}

SkScalar SkPaint_getStrokeMiter(SkPaint *paint) {
    return paint->getStrokeMiter();
}

void SkPaint_setStrokeMiter(SkPaint *paint, SkScalar miter) {
    paint->setStrokeMiter(miter);
}

SkPaint::Cap SkPaint_getStrokeCap(SkPaint *paint) {
    return paint->getStrokeCap();
}

void SkPaint_setStrokeCap(SkPaint *paint, SkPaint::Cap cap) {
    paint->setStrokeCap(cap);
}

SkPaint::Join SkPaint_getStrokeJoin(SkPaint *paint) {
    return paint->getStrokeJoin();
}

void SkPaint_setStrokeJoin(SkPaint *paint, SkPaint::Join join) {
    paint->setStrokeJoin(join);
}

SkShader * SkPaint_getShader(SkPaint *paint) {
    return paint->getShader();
}

int SkPaint_refShader(SkPaint *paint) {
    return static_sk_shader_make(paint->refShader());
}

void SkPaint_setShader(int sk_shader_key_in, SkPaint *paint) {
    paint->setShader(static_sk_shader_move(sk_shader_key_in));
}

SkColorFilter * SkPaint_getColorFilter(SkPaint *paint) {
    return paint->getColorFilter();
}

int SkPaint_refColorFilter(SkPaint *paint) {
    return static_sk_color_filter_make(paint->refColorFilter());
}

void SkPaint_setColorFilter(int sk_color_filter_key_in, SkPaint *paint) {
    paint->setColorFilter(static_sk_color_filter_move(sk_color_filter_key_in));
}

int SkPaint_asBlendMode(SkPaint *paint) {
    return static_optional_sk_blend_mode_make(paint->asBlendMode());
}

SkBlendMode SkPaint_getBlendMode_or(SkPaint *paint, SkBlendMode defaultMode) {
    return paint->getBlendMode_or(defaultMode);
}

bool SkPaint_isSrcOver(SkPaint *paint) {
    return paint->isSrcOver();
}

void SkPaint_setBlendMode(SkPaint *paint, SkBlendMode mode) {
    paint->setBlendMode(mode);
}

SkBlender * SkPaint_getBlender(SkPaint *paint) {
    return paint->getBlender();
}

int SkPaint_refBlender(SkPaint *paint) {
    return static_sk_blender_make(paint->refBlender());
}

void SkPaint_setBlender(int sk_blender_key_in, SkPaint *paint) {
    paint->setBlender(static_sk_blender_move(sk_blender_key_in));
}

SkPathEffect * SkPaint_getPathEffect(SkPaint *paint) {
    return paint->getPathEffect();
}

int SkPaint_refPathEffect(SkPaint *paint) {
    return static_sk_path_effect_make(paint->refPathEffect());
}

void SkPaint_setPathEffect(int sk_path_effect_key_in, SkPaint *paint) {
    paint->setPathEffect(static_sk_path_effect_move(sk_path_effect_key_in));
}

SkMaskFilter * SkPaint_getMaskFilter(SkPaint *paint) {
    return paint->getMaskFilter();
}

int SkPaint_refMaskFilter(SkPaint *paint) {
    return static_sk_mask_filter_make(paint->refMaskFilter());
}

void SkPaint_setMaskFilter(int sk_mask_filter_key_in, SkPaint *paint) {
    paint->setMaskFilter(static_sk_mask_filter_move(sk_mask_filter_key_in));
}

SkImageFilter * SkPaint_getImageFilter(SkPaint *paint) {
    return paint->getImageFilter();
}

int SkPaint_refImageFilter(SkPaint *paint) {
    return static_sk_image_filter_make(paint->refImageFilter());
}

void SkPaint_setImageFilter(int sk_image_filter_key_in, SkPaint *paint) {
    paint->setImageFilter(static_sk_image_filter_move(sk_image_filter_key_in));
}

bool SkPaint_nothingToDraw(SkPaint *paint) {
    return paint->nothingToDraw();
}

bool SkPaint_canComputeFastBounds(SkPaint *paint) {
    return paint->canComputeFastBounds();
}

const SkRect * SkPaint_computeFastBounds(SkPaint *paint, const SkRect *orig, SkRect *storage) {
    return &paint->computeFastBounds(*orig, storage);
}

const SkRect * SkPaint_computeFastStrokeBounds(SkPaint *paint, const SkRect *orig, SkRect *storage) {
    return &paint->computeFastStrokeBounds(*orig, storage);
}

const SkRect * SkPaint_doComputeFastBounds(SkPaint *paint, const SkRect *orig, SkRect *storage, SkPaint::Style style) {
    return &paint->doComputeFastBounds(*orig, storage, style);
}

}