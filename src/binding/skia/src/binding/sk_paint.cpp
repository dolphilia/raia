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

SkPaint *SkPaint_new_2(const SkColor4f &color, SkColorSpace *colorSpace) {
    return new SkPaint(color, colorSpace);
}

SkPaint *SkPaint_new_3(const SkPaint &paint) {
    return new SkPaint(paint);
}

SkPaint *SkPaint_new_4(SkPaint &&paint) { //@TODO
    return new SkPaint(paint);
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

void SkPaint_setColor_2(SkPaint *paint, const SkColor4f &color, SkColorSpace *colorSpace) {
    paint->setColor(color, colorSpace);
}

void SkPaint_setColor4f(SkPaint *paint, const SkColor4f &color, SkColorSpace *colorSpace) {
    paint->setColor4f(color, colorSpace);
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

void SkPaint_refShader(const char *sk_shader_key_out, SkPaint *paint) {
    static_sk_shader_set(sk_shader_key_out, paint->refShader());
}

void SkPaint_setShader(SkPaint *paint, sk_sp<SkShader> shader) {
    paint->setShader(std::move(shader));
}

SkColorFilter * SkPaint_getColorFilter(SkPaint *paint) {
    return paint->getColorFilter();
}

void SkPaint_refColorFilter(const char *sk_color_filter_key_out, SkPaint *paint) {
    static_sk_color_filter_set(sk_color_filter_key_out, paint->refColorFilter());
}

void SkPaint_setColorFilter(SkPaint *paint, sk_sp<SkColorFilter> colorFilter) {
    paint->setColorFilter(std::move(colorFilter));
}

void SkPaint_asBlendMode(const char *sk_blend_mode_key_out, SkPaint *paint) {
    static_optional_sk_blend_mode_set(sk_blend_mode_key_out, paint->asBlendMode());
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

void SkPaint_refBlender(const char *sk_blender_key_out, SkPaint *paint) {
    static_sk_blender_set(sk_blender_key_out, paint->refBlender());
}

void SkPaint_setBlender(SkPaint *paint, sk_sp<SkBlender> blender) {
    paint->setBlender(std::move(blender));
}

SkPathEffect * SkPaint_getPathEffect(SkPaint *paint) {
    return paint->getPathEffect();
}

void SkPaint_refPathEffect(const char *sk_path_effect_key_out, SkPaint *paint) {
    static_sk_path_effect_set(sk_path_effect_key_out, paint->refPathEffect());
}

void SkPaint_setPathEffect(SkPaint *paint, sk_sp<SkPathEffect> pathEffect) {
    paint->setPathEffect(std::move(pathEffect));
}

SkMaskFilter * SkPaint_getMaskFilter(SkPaint *paint) {
    return paint->getMaskFilter();
}

void SkPaint_refMaskFilter(const char *sk_mask_filter_key_out, SkPaint *paint) {
    static_sk_mask_filter_set(sk_mask_filter_key_out, paint->refMaskFilter());
}

void SkPaint_setMaskFilter(SkPaint *paint, sk_sp<SkMaskFilter> maskFilter) {
    paint->setMaskFilter(std::move(maskFilter));
}

SkImageFilter * SkPaint_getImageFilter(SkPaint *paint) {
    return paint->getImageFilter();
}

void SkPaint_refImageFilter(const char *sk_image_filter_key_out, SkPaint *paint) {
    static_sk_image_filter_set(sk_image_filter_key_out, paint->refImageFilter());
}

void SkPaint_setImageFilter(SkPaint *paint, sk_sp<SkImageFilter> imageFilter) {
    paint->setImageFilter(std::move(imageFilter));
}

bool SkPaint_nothingToDraw(SkPaint *paint) {
    return paint->nothingToDraw();
}

bool SkPaint_canComputeFastBounds(SkPaint *paint) {
    return paint->canComputeFastBounds();
}

const SkRect * SkPaint_computeFastBounds(SkPaint *paint, const SkRect &orig, SkRect *storage) {
    return &paint->computeFastBounds(orig, storage);
}

const SkRect * SkPaint_computeFastStrokeBounds(SkPaint *paint, const SkRect &orig, SkRect *storage) {
    return &paint->computeFastStrokeBounds(orig, storage);
}

const SkRect * SkPaint_doComputeFastBounds(SkPaint *paint, const SkRect &orig, SkRect *storage, SkPaint::Style style) {
    return &paint->doComputeFastBounds(orig, storage, style);
}

}