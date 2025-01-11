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
#include "export_api.h"

extern "C" {
//SkPaint & operator=(const SkPaint &paint)
//SkPaint & operator=(SkPaint &&paint)
RAIA_API SkPaint *SkPaint_new();
RAIA_API SkPaint *SkPaint_new_2(const SkColor4f *color, SkColorSpace *colorSpace);
RAIA_API SkPaint *SkPaint_new_3(const SkPaint *paint);
RAIA_API void SkPaint_delete(SkPaint *paint);
RAIA_API void SkPaint_reset(SkPaint *paint);
RAIA_API bool SkPaint_isAntiAlias(SkPaint *paint);
RAIA_API void SkPaint_setAntiAlias(SkPaint *paint, bool aa);
RAIA_API bool SkPaint_isDither(SkPaint *paint);
RAIA_API void SkPaint_setDither(SkPaint *paint, bool dither);
RAIA_API SkPaint::Style SkPaint_getStyle(SkPaint *paint);
RAIA_API void SkPaint_setStyle(SkPaint *paint, SkPaint::Style style);
RAIA_API void SkPaint_setStroke(SkPaint *paint, bool v);
RAIA_API SkColor SkPaint_getColor(SkPaint *paint);
RAIA_API sk_color_4f_t SkPaint_getColor4f(SkPaint *paint);
RAIA_API void SkPaint_setColor(SkPaint *paint, SkColor color);
RAIA_API void SkPaint_setColor_2(SkPaint *paint, const SkColor4f *color, SkColorSpace *colorSpace);
RAIA_API void SkPaint_setColor4f(SkPaint *paint, const SkColor4f *color, SkColorSpace *colorSpace);
RAIA_API float SkPaint_getAlphaf(SkPaint *paint);
RAIA_API uint8_t SkPaint_getAlpha(SkPaint *paint);
RAIA_API void SkPaint_setAlphaf(SkPaint *paint, float a);
RAIA_API void SkPaint_setAlpha(SkPaint *paint, U8CPU a);
RAIA_API void SkPaint_setARGB(SkPaint *paint, U8CPU a, U8CPU r, U8CPU g, U8CPU b);
RAIA_API SkScalar SkPaint_getStrokeWidth(SkPaint *paint);
RAIA_API void SkPaint_setStrokeWidth(SkPaint *paint, SkScalar width);
RAIA_API SkScalar SkPaint_getStrokeMiter(SkPaint *paint);
RAIA_API void SkPaint_setStrokeMiter(SkPaint *paint, SkScalar miter);
RAIA_API SkPaint::Cap SkPaint_getStrokeCap(SkPaint *paint);
RAIA_API void SkPaint_setStrokeCap(SkPaint *paint, SkPaint::Cap cap);
RAIA_API SkPaint::Join SkPaint_getStrokeJoin(SkPaint *paint);
RAIA_API void SkPaint_setStrokeJoin(SkPaint *paint, SkPaint::Join join);
RAIA_API SkShader * SkPaint_getShader(SkPaint *paint);
RAIA_API sk_shader_t SkPaint_refShader(SkPaint *paint);
RAIA_API void SkPaint_setShader(SkPaint *paint, sk_shader_t shader);
RAIA_API SkColorFilter * SkPaint_getColorFilter(SkPaint *paint);
RAIA_API sk_color_filter_t SkPaint_refColorFilter(SkPaint *paint);
RAIA_API void SkPaint_setColorFilter(SkPaint *paint, sk_color_filter_t color_filter);
RAIA_API int SkPaint_asBlendMode(SkPaint *paint);
RAIA_API SkBlendMode SkPaint_getBlendMode_or(SkPaint *paint, SkBlendMode defaultMode);
RAIA_API bool SkPaint_isSrcOver(SkPaint *paint);
RAIA_API void SkPaint_setBlendMode(SkPaint *paint, SkBlendMode mode);
RAIA_API SkBlender * SkPaint_getBlender(SkPaint *paint);
RAIA_API sk_blender_t SkPaint_refBlender(SkPaint *paint);
RAIA_API void SkPaint_setBlender(SkPaint *paint, sk_blender_t blender);
RAIA_API SkPathEffect * SkPaint_getPathEffect(SkPaint *paint);
RAIA_API sk_path_effect_t SkPaint_refPathEffect(SkPaint *paint);
RAIA_API void SkPaint_setPathEffect(SkPaint *paint, sk_path_effect_t path_effect);
RAIA_API SkMaskFilter * SkPaint_getMaskFilter(SkPaint *paint);
RAIA_API sk_mask_filter_t SkPaint_refMaskFilter(SkPaint *paint);
RAIA_API void SkPaint_setMaskFilter(SkPaint *paint, sk_mask_filter_t mask_filter);
RAIA_API SkImageFilter * SkPaint_getImageFilter(SkPaint *paint);
RAIA_API sk_image_filter_t SkPaint_refImageFilter(SkPaint *paint);
RAIA_API void SkPaint_setImageFilter(SkPaint *paint, sk_image_filter_t image_filter);
RAIA_API bool SkPaint_nothingToDraw(SkPaint *paint);
RAIA_API bool SkPaint_canComputeFastBounds(SkPaint *paint);
RAIA_API const SkRect * SkPaint_computeFastBounds(SkPaint *paint, const SkRect *orig, SkRect *storage);
RAIA_API const SkRect * SkPaint_computeFastStrokeBounds(SkPaint *paint, const SkRect *orig, SkRect *storage);
RAIA_API const SkRect * SkPaint_doComputeFastBounds(SkPaint *paint, const SkRect *orig, SkRect *storage, SkPaint::Style style);
}

#endif //RAIA_SKIA_SK_PAINT_H
