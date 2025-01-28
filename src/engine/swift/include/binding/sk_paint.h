//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_PAINT_H
#define RAIA_SKIA_SK_PAINT_H

#ifdef __cplusplus
extern "C" {
#endif

//SkPaint & operator=(const SkPaint &paint)
//SkPaint & operator=(SkPaint &&paint)

void *SkPaint_new(); // () -> SkPaint *
void *SkPaint_new_2(const void *color, void *colorSpace); // (const SkColor4f *color, SkColorSpace *colorSpace) -> SkPaint *
void *SkPaint_new_3(const void *paint); // (const SkPaint *paint) -> SkPaint *
void SkPaint_delete(void *paint); // (SkPaint *paint)
void SkPaint_reset(void *paint); // (SkPaint *paint)
bool SkPaint_isAntiAlias(void *paint); // (SkPaint *paint) -> bool
void SkPaint_setAntiAlias(void *paint, bool aa); // (SkPaint *paint, bool aa)
bool SkPaint_isDither(void *paint); // (SkPaint *paint) -> bool
void SkPaint_setDither(void *paint, bool dither); // (SkPaint *paint, bool dither)
int SkPaint_getStyle(void *paint); // (SkPaint *paint) -> SkPaint::Style
void SkPaint_setStyle(void *paint, int style); // (SkPaint *paint, SkPaint::Style style)
void SkPaint_setStroke(void *paint, bool v); // (SkPaint *paint, bool v)
unsigned int SkPaint_getColor(void *paint); // (SkPaint *paint) -> SkColor
int SkPaint_getColor4f(void *paint); // (SkPaint *paint) -> sk_color_4f_t
void SkPaint_setColor(void *paint, unsigned int color); // (SkPaint *paint, SkColor color)
void SkPaint_setColor_2(void *paint, const void *color, void *colorSpace); // (SkPaint *paint, const SkColor4f *color, SkColorSpace *colorSpace)
void SkPaint_setColor4f(void *paint, const void *color, void *colorSpace); // (SkPaint *paint, const SkColor4f *color, SkColorSpace *colorSpace)
float SkPaint_getAlphaf(void *paint); // (SkPaint *paint) -> float
unsigned char SkPaint_getAlpha(void *paint); // (SkPaint *paint) -> uint8_t
void SkPaint_setAlphaf(void *paint, float a); // (SkPaint *paint, float a)
void SkPaint_setAlpha(void *paint, unsigned int a); // (SkPaint *paint, U8CPU a)
void SkPaint_setARGB(void *paint, unsigned int a, unsigned int r, unsigned int g, unsigned int b); // (SkPaint *paint, U8CPU a, U8CPU r, U8CPU g, U8CPU b)
float SkPaint_getStrokeWidth(void *paint); // (SkPaint *paint) -> SkScalar
void SkPaint_setStrokeWidth(void *paint, float width); // (SkPaint *paint, SkScalar width)
float SkPaint_getStrokeMiter(void *paint); // (SkPaint *paint) -> SkScalar
void SkPaint_setStrokeMiter(void *paint, float miter); // (SkPaint *paint, SkScalar miter)
int SkPaint_getStrokeCap(void *paint); // (SkPaint *paint) -> SkPaint::Cap
void SkPaint_setStrokeCap(void *paint, int cap); // (SkPaint *paint, SkPaint::Cap cap)
int SkPaint_getStrokeJoin(void *paint); // (SkPaint *paint) -> SkPaint::Join
void SkPaint_setStrokeJoin(void *paint, int join); // (SkPaint *paint, SkPaint::Join join)
void * SkPaint_getShader(void *paint); // (SkPaint *paint) -> SkShader *
int SkPaint_refShader(void *paint); // (SkPaint *paint) -> sk_shader_t
void SkPaint_setShader(void *paint, int shader); // (SkPaint *paint, sk_shader_t shader)
void * SkPaint_getColorFilter(void *paint); // (SkPaint *paint) -> SkColorFilter *
int SkPaint_refColorFilter(void *paint); // (SkPaint *paint) -> sk_color_filter_t
void SkPaint_setColorFilter(void *paint, int color_filter); // (SkPaint *paint, sk_color_filter_t color_filter)
int SkPaint_asBlendMode(void *paint); // (SkPaint *paint) -> int
int SkPaint_getBlendMode_or(void *paint, int defaultMode); // (SkPaint *paint, SkBlendMode defaultMode) -> SkBlendMode
bool SkPaint_isSrcOver(void *paint); // (SkPaint *paint) -> bool
void SkPaint_setBlendMode(void *paint, int mode); // (SkPaint *paint, SkBlendMode mode)
void * SkPaint_getBlender(void *paint); // (SkPaint *paint) -> SkBlender *
int SkPaint_refBlender(void *paint); // (SkPaint *paint) -> sk_blender_t
void SkPaint_setBlender(void *paint, int blender); // (SkPaint *paint, sk_blender_t blender)
void * SkPaint_getPathEffect(void *paint); // (SkPaint *paint) -> SkPathEffect *
int SkPaint_refPathEffect(void *paint); // (SkPaint *paint) -> sk_path_effect_t
void SkPaint_setPathEffect(void *paint, int path_effect); // (SkPaint *paint, sk_path_effect_t path_effect)
void * SkPaint_getMaskFilter(void *paint); // (SkPaint *paint) -> SkMaskFilter *
int SkPaint_refMaskFilter(void *paint); // (SkPaint *paint) -> sk_mask_filter_t
void SkPaint_setMaskFilter(void *paint, int mask_filter); // (SkPaint *paint, sk_mask_filter_t mask_filter)
void * SkPaint_getImageFilter(void *paint); // (SkPaint *paint) -> SkImageFilter *
int SkPaint_refImageFilter(void *paint); // (SkPaint *paint) -> sk_image_filter_t
void SkPaint_setImageFilter(void *paint, int image_filter); // (SkPaint *paint, sk_image_filter_t image_filter)
bool SkPaint_nothingToDraw(void *paint); // (SkPaint *paint) -> bool
bool SkPaint_canComputeFastBounds(void *paint); // (SkPaint *paint) -> bool
const void * SkPaint_computeFastBounds(void *paint, const void *orig, void *storage); // (SkPaint *paint, const SkRect *orig, SkRect *storage) -> const SkRect *
const void * SkPaint_computeFastStrokeBounds(void *paint, const void *orig, void *storage); // (SkPaint *paint, const SkRect *orig, SkRect *storage) -> const SkRect *
const void * SkPaint_doComputeFastBounds(void *paint, const void *orig, void *storage, int style); // (SkPaint *paint, const SkRect *orig, SkRect *storage, SkPaint::Style style) -> const SkRect *

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_PAINT_H
