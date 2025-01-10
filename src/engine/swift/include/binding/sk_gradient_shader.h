//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_GRADIENT_SHADER_H
#define RAIA_SKIA_SK_GRADIENT_SHADER_H

#include "include/effects/SkGradientShader.h"
#include "../static/static_sk_shader.h"
#include "../static/static_sk_color_space.h"

extern "C" {
void SkGradientShader_delete(SkGradientShader * gradientShader);
// static
sk_shader_t SkGradientShader_MakeLinear(const SkPoint pts[2], const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix);
sk_shader_t SkGradientShader_MakeLinear_2(const SkPoint pts[2], const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix);
sk_shader_t SkGradientShader_MakeLinear_3(const SkPoint pts[2], const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix);
sk_shader_t SkGradientShader_MakeRadial(const SkPoint *center, SkScalar radius, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix);
sk_shader_t SkGradientShader_MakeRadial_2(const SkPoint *center, SkScalar radius, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix);
sk_shader_t SkGradientShader_MakeRadial_3(const SkPoint *center, SkScalar radius, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix);
sk_shader_t SkGradientShader_MakeTwoPointConical(const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix);
sk_shader_t SkGradientShader_MakeTwoPointConical_2(const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix);
sk_shader_t SkGradientShader_MakeTwoPointConical_3(const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix);
sk_shader_t SkGradientShader_MakeSweep(SkScalar cx, SkScalar cy, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, uint32_t flags, const SkMatrix *localMatrix);
sk_shader_t SkGradientShader_MakeSweep_2(SkScalar cx, SkScalar cy, const SkColor colors[], const SkScalar pos[], int count, uint32_t flags, const SkMatrix *localMatrix);
sk_shader_t SkGradientShader_MakeSweep_3(SkScalar cx, SkScalar cy, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix);
sk_shader_t SkGradientShader_MakeSweep_4(SkScalar cx, SkScalar cy, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, uint32_t flags, const SkMatrix *localMatrix);
sk_shader_t SkGradientShader_MakeSweep_5(SkScalar cx, SkScalar cy, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, uint32_t flags, const SkMatrix *localMatrix);
}

#endif //RAIA_SKIA_SK_GRADIENT_SHADER_H
