//
// Created by dolphilia on 2024/01/08.
//

#include "sk_gradient_shader.h"

extern "C" {

// static

int SkGradientShader_MakeLinear(const SkPoint pts[2], const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeLinear(pts, colors, pos, count, mode, flags, localMatrix));
}

int SkGradientShader_MakeLinear_2(int sk_color_space_key_in, const SkPoint pts[2], const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeLinear(pts, colors, static_sk_color_space_move(sk_color_space_key_in), pos, count, mode, *interpolation, localMatrix));
}

int SkGradientShader_MakeLinear_3(int sk_color_space_key_in, const SkPoint pts[2], const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeLinear(pts, colors, static_sk_color_space_move(sk_color_space_key_in), pos, count, mode, flags, localMatrix));
}

int SkGradientShader_MakeRadial(const SkPoint *center, SkScalar radius, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeRadial(*center, radius, colors, pos, count, mode, flags, localMatrix));
}

int SkGradientShader_MakeRadial_2(int sk_color_space_key_in, const SkPoint *center, SkScalar radius, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeRadial(*center, radius, colors, static_sk_color_space_move(sk_color_space_key_in), pos, count, mode, *interpolation, localMatrix));
}

int SkGradientShader_MakeRadial_3(int sk_color_space_key_in, const SkPoint *center, SkScalar radius, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeRadial(*center, radius, colors, static_sk_color_space_move(sk_color_space_key_in), pos, count, mode, flags, localMatrix));
}

int SkGradientShader_MakeTwoPointConical(const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeTwoPointConical(*start, startRadius, *end, endRadius, colors, pos, count, mode, flags, localMatrix));
}

int SkGradientShader_MakeTwoPointConical_2(int sk_color_space_key_in, const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeTwoPointConical(*start, startRadius, *end, endRadius, colors, static_sk_color_space_move(sk_color_space_key_in), pos, count, mode, *interpolation, localMatrix));
}

int SkGradientShader_MakeTwoPointConical_3(int sk_color_space_key_in, const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor4f colors[],  const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeTwoPointConical(*start, startRadius, *end, endRadius, colors, static_sk_color_space_move(sk_color_space_key_in), pos, count, mode, flags, localMatrix));
}

int SkGradientShader_MakeSweep(SkScalar cx, SkScalar cy, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeSweep(cx, cy, colors, pos, count, mode, startAngle, endAngle, flags, localMatrix));
}

int SkGradientShader_MakeSweep_2(SkScalar cx, SkScalar cy, const SkColor colors[], const SkScalar pos[], int count, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeSweep(cx, cy, colors, pos, count, flags, localMatrix));
}

int SkGradientShader_MakeSweep_3(int sk_color_space_key_in, SkScalar cx, SkScalar cy, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeSweep(cx, cy, colors, static_sk_color_space_move(sk_color_space_key_in), pos, count, mode, startAngle, endAngle, *interpolation, localMatrix));
}

int SkGradientShader_MakeSweep_4(int sk_color_space_key_in, SkScalar cx, SkScalar cy, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeSweep(cx, cy, colors, static_sk_color_space_move(sk_color_space_key_in), pos, count, mode, startAngle, endAngle, flags, localMatrix));
}

int SkGradientShader_MakeSweep_5(int sk_color_space_key_in, SkScalar cx, SkScalar cy, const SkColor4f colors[], const SkScalar pos[], int count, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeSweep(cx, cy, colors, static_sk_color_space_move(sk_color_space_key_in), pos, count, flags, localMatrix));
}

}