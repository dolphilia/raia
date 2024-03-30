//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_PAINT_H
#define RAIA_SKIA_SK_PAINT_H

#include "include/core/SkPaint.h"
#include "../static/static_sk_shader.h"
#include "../static/static_sk_color_filter.h"
#include "../static/static_sk_blender.h"
#include "../static/static_sk_path_effect.h"
#include "../static/static_sk_mask_filter.h"
#include "../static/static_sk_image_filter.h"
#include "../static/static_sk_blend_mode.h"
#include "../static/static_sk_color_4f.h"

extern "C" {
//SkPaint & operator=(const SkPaint &paint)
//SkPaint & operator=(SkPaint &&paint)
SkPaint *SkPaint_new();
SkPaint *SkPaint_new_2(const SkColor4f *color, SkColorSpace *colorSpace);
SkPaint *SkPaint_new_3(const SkPaint *paint);
void SkPaint_delete(SkPaint *paint);
void SkPaint_reset(SkPaint *paint);
bool SkPaint_isAntiAlias(SkPaint *paint);
void SkPaint_setAntiAlias(SkPaint *paint, bool aa);
bool SkPaint_isDither(SkPaint *paint);
void SkPaint_setDither(SkPaint *paint, bool dither);
SkPaint::Style SkPaint_getStyle(SkPaint *paint);
void SkPaint_setStyle(SkPaint *paint, SkPaint::Style style);
void SkPaint_setStroke(SkPaint *paint, bool v);
SkColor SkPaint_getColor(SkPaint *paint);
sk_color_4f_t SkPaint_getColor4f(SkPaint *paint);
void SkPaint_setColor(SkPaint *paint, SkColor color);
void SkPaint_setColor_2(SkPaint *paint, const SkColor4f *color, SkColorSpace *colorSpace);
void SkPaint_setColor4f(SkPaint *paint, const SkColor4f *color, SkColorSpace *colorSpace);
float SkPaint_getAlphaf(SkPaint *paint);
uint8_t SkPaint_getAlpha(SkPaint *paint);
void SkPaint_setAlphaf(SkPaint *paint, float a);
void SkPaint_setAlpha(SkPaint *paint, U8CPU a);
void SkPaint_setARGB(SkPaint *paint, U8CPU a, U8CPU r, U8CPU g, U8CPU b);
SkScalar SkPaint_getStrokeWidth(SkPaint *paint);
void SkPaint_setStrokeWidth(SkPaint *paint, SkScalar width);
SkScalar SkPaint_getStrokeMiter(SkPaint *paint);
void SkPaint_setStrokeMiter(SkPaint *paint, SkScalar miter);
SkPaint::Cap SkPaint_getStrokeCap(SkPaint *paint);
void SkPaint_setStrokeCap(SkPaint *paint, SkPaint::Cap cap);
SkPaint::Join SkPaint_getStrokeJoin(SkPaint *paint);
void SkPaint_setStrokeJoin(SkPaint *paint, SkPaint::Join join);
SkShader * SkPaint_getShader(SkPaint *paint);
sk_shader_t SkPaint_refShader(SkPaint *paint);
void SkPaint_setShader(SkPaint *paint, sk_shader_t shader);
SkColorFilter * SkPaint_getColorFilter(SkPaint *paint);
sk_color_filter_t SkPaint_refColorFilter(SkPaint *paint);
void SkPaint_setColorFilter(SkPaint *paint, sk_color_filter_t color_filter);
int SkPaint_asBlendMode(SkPaint *paint);
SkBlendMode SkPaint_getBlendMode_or(SkPaint *paint, SkBlendMode defaultMode);
bool SkPaint_isSrcOver(SkPaint *paint);
void SkPaint_setBlendMode(SkPaint *paint, SkBlendMode mode);
SkBlender * SkPaint_getBlender(SkPaint *paint);
sk_blender_t SkPaint_refBlender(SkPaint *paint);
void SkPaint_setBlender(SkPaint *paint, sk_blender_t blender);
SkPathEffect * SkPaint_getPathEffect(SkPaint *paint);
sk_path_effect_t SkPaint_refPathEffect(SkPaint *paint);
void SkPaint_setPathEffect(SkPaint *paint, sk_path_effect_t path_effect);
SkMaskFilter * SkPaint_getMaskFilter(SkPaint *paint);
sk_mask_filter_t SkPaint_refMaskFilter(SkPaint *paint);
void SkPaint_setMaskFilter(SkPaint *paint, sk_mask_filter_t mask_filter);
SkImageFilter * SkPaint_getImageFilter(SkPaint *paint);
sk_image_filter_t SkPaint_refImageFilter(SkPaint *paint);
void SkPaint_setImageFilter(SkPaint *paint, sk_image_filter_t image_filter);
bool SkPaint_nothingToDraw(SkPaint *paint);
bool SkPaint_canComputeFastBounds(SkPaint *paint);
const SkRect * SkPaint_computeFastBounds(SkPaint *paint, const SkRect *orig, SkRect *storage);
const SkRect * SkPaint_computeFastStrokeBounds(SkPaint *paint, const SkRect *orig, SkRect *storage);
const SkRect * SkPaint_doComputeFastBounds(SkPaint *paint, const SkRect *orig, SkRect *storage, SkPaint::Style style);
}

#endif //RAIA_SKIA_SK_PAINT_H
