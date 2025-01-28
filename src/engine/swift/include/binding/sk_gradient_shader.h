//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_GRADIENT_SHADER_H
#define RAIA_SKIA_SK_GRADIENT_SHADER_H

#ifdef __cplusplus
extern "C" {
#endif

void SkGradientShader_delete(void * gradientShader); // (SkGradientShader * gradientShader)

// static

int SkGradientShader_MakeLinear(const void * pts, const void * colors, const void * pos, int count, int mode, unsigned int flags, const void * localMatrix); // (const SkPoint pts[2], const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) -> sk_shader_t
int SkGradientShader_MakeLinear_2(const void * pts, const void * colors, int color_space, const void * pos, int count, int mode, const void *interpolation, const void *localMatrix); // (const SkPoint pts[2], const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) -> sk_shader_t
int SkGradientShader_MakeLinear_3(const void * pts, const void * colors, int color_space, const void * pos, int count, int mode, unsigned int flags, const void *localMatrix); // (const SkPoint pts[2], const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) -> sk_shader_t
int SkGradientShader_MakeRadial(const void *center, float radius, const void * colors, const void * pos, int count, int mode, unsigned int flags, const void *localMatrix); // (const SkPoint *center, SkScalar radius, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) -> sk_shader_t
int SkGradientShader_MakeRadial_2(const void *center, float radius, const void * colors, int color_space, const void * pos, int count, int mode, const void *interpolation, const void *localMatrix); // (const SkPoint *center, SkScalar radius, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) -> sk_shader_t
int SkGradientShader_MakeRadial_3(const void *center, float radius, const void * colors, int color_space, const void * pos, int count, int mode, unsigned int flags, const void *localMatrix); // (const SkPoint *center, SkScalar radius, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) -> sk_shader_t
int SkGradientShader_MakeTwoPointConical(const void *start, float startRadius, const void *end, float endRadius, const void * colors, const void * pos, int count, int mode, unsigned int flags, const void *localMatrix); // (const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) -> sk_shader_t
int SkGradientShader_MakeTwoPointConical_2(const void *start, float startRadius, const void *end, float endRadius, const void * colors, int color_space, const void * pos, int count, int mode, const void *interpolation, const void *localMatrix); // (const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) -> sk_shader_t
int SkGradientShader_MakeTwoPointConical_3(const void *start, float startRadius, const void *end, float endRadius, const void * colors, int color_space, const void * pos, int count, int mode, unsigned int flags, const void *localMatrix); // (const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) -> sk_shader_t
int SkGradientShader_MakeSweep(float cx, float cy, const void * colors, const void * pos, int count, int mode, float startAngle, float endAngle, unsigned int flags, const void *localMatrix); // (SkScalar cx, SkScalar cy, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, uint32_t flags, const SkMatrix *localMatrix) -> sk_shader_t
int SkGradientShader_MakeSweep_2(float cx, float cy, const void * colors, const void * pos, int count, unsigned int flags, const void *localMatrix); // (SkScalar cx, SkScalar cy, const SkColor colors[], const SkScalar pos[], int count, uint32_t flags, const SkMatrix *localMatrix) -> sk_shader_t
int SkGradientShader_MakeSweep_3(float cx, float cy, const void * colors, int color_space, const void * pos, int count, int mode, float startAngle, float endAngle, const void *interpolation, const void *localMatrix); // (SkScalar cx, SkScalar cy, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) -> sk_shader_t
int SkGradientShader_MakeSweep_4(float cx, float cy, const void * colors, int color_space, const void * pos, int count, int mode, float startAngle, float endAngle, unsigned int flags, const void *localMatrix); // (SkScalar cx, SkScalar cy, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, uint32_t flags, const SkMatrix *localMatrix) -> sk_shader_t
int SkGradientShader_MakeSweep_5(float cx, float cy, const void * colors, int color_space, const void * pos, int count, unsigned int flags, const void *localMatrix); // (SkScalar cx, SkScalar cy, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, uint32_t flags, const SkMatrix *localMatrix) -> sk_shader_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_GRADIENT_SHADER_H
