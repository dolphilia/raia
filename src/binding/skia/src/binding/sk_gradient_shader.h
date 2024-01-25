//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_GRADIENT_SHADER_H
#define RAIA_SKIA_SK_GRADIENT_SHADER_H

#include "include/effects/SkGradientShader.h"
#include "../static/static_sk_shader.h"
#include "../static/static_sk_color_space.h"

extern "C" {
// static
void SkGradientShader_MakeLinear(int sk_shader_key_out, const SkPoint pts[2], const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix);
void SkGradientShader_MakeLinear_2(int sk_shader_key_out, int sk_color_space_key_in, const SkPoint pts[2], const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix);
void SkGradientShader_MakeLinear_3(int sk_shader_key_out, int sk_color_space_key_in, const SkPoint pts[2], const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix);
void SkGradientShader_MakeRadial(int sk_shader_key_out, const SkPoint *center, SkScalar radius, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix);
void SkGradientShader_MakeRadial_2(int sk_shader_key_out, int sk_color_space_key_in, const SkPoint *center, SkScalar radius, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix);
void SkGradientShader_MakeRadial_3(int sk_shader_key_out, int sk_color_space_key_in, const SkPoint *center, SkScalar radius, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix);
void SkGradientShader_MakeTwoPointConical(int sk_shader_key_out, const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix);
void SkGradientShader_MakeTwoPointConical_2(int sk_shader_key_out, int sk_color_space_key_in, const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix);
void SkGradientShader_MakeTwoPointConical_3(int sk_shader_key_out, int sk_color_space_key_in, const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor4f colors[],  const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix);
void SkGradientShader_MakeSweep(int sk_shader_key_out, SkScalar cx, SkScalar cy, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, uint32_t flags, const SkMatrix *localMatrix);
void SkGradientShader_MakeSweep_2(int sk_shader_key_out, SkScalar cx, SkScalar cy, const SkColor colors[], const SkScalar pos[], int count, uint32_t flags, const SkMatrix *localMatrix);
void SkGradientShader_MakeSweep_3(int sk_shader_key_out, int sk_color_space_key_in, SkScalar cx, SkScalar cy, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix);
void SkGradientShader_MakeSweep_4(int sk_shader_key_out, int sk_color_space_key_in, SkScalar cx, SkScalar cy, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, uint32_t flags, const SkMatrix *localMatrix);
void SkGradientShader_MakeSweep_5(int sk_shader_key_out, int sk_color_space_key_in, SkScalar cx, SkScalar cy, const SkColor4f colors[], const SkScalar pos[], int count, uint32_t flags, const SkMatrix *localMatrix);
}

#endif //RAIA_SKIA_SK_GRADIENT_SHADER_H
