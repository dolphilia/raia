//
// Created by dolphilia on 2024/01/08.
//

#include "sk_gradient_shader.h"

extern "C" {

// static

void SkGradientShader_MakeLinear(const char *sk_shader_key_out, const SkPoint pts[2], const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, SkGradientShader::MakeLinear(pts, colors, pos, count, mode, flags, localMatrix));
}

void SkGradientShader_MakeLinear_2(const char *sk_shader_key_out, const char *sk_color_space_key_in, const SkPoint pts[2], const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, SkGradientShader::MakeLinear(pts, colors, static_sk_color_space_move(sk_color_space_key_in), pos, count, mode, *interpolation, localMatrix));
}

void SkGradientShader_MakeLinear_3(const char *sk_shader_key_out, const char *sk_color_space_key_in, const SkPoint pts[2], const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, SkGradientShader::MakeLinear(pts, colors, static_sk_color_space_move(sk_color_space_key_in), pos, count, mode, flags, localMatrix));
}

void SkGradientShader_MakeRadial(const char *sk_shader_key_out, const SkPoint *center, SkScalar radius, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, SkGradientShader::MakeRadial(*center, radius, colors, pos, count, mode, flags, localMatrix));
}

void SkGradientShader_MakeRadial_2(const char *sk_shader_key_out, const char *sk_color_space_key_in, const SkPoint *center, SkScalar radius, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, SkGradientShader::MakeRadial(*center, radius, colors, static_sk_color_space_move(sk_color_space_key_in), pos, count, mode, *interpolation, localMatrix));
}

void SkGradientShader_MakeRadial_3(const char *sk_shader_key_out, const char *sk_color_space_key_in, const SkPoint *center, SkScalar radius, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, SkGradientShader::MakeRadial(*center, radius, colors, static_sk_color_space_move(sk_color_space_key_in), pos, count, mode, flags, localMatrix));
}

void SkGradientShader_MakeTwoPointConical(const char *sk_shader_key_out, const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, SkGradientShader::MakeTwoPointConical(*start, startRadius, *end, endRadius, colors, pos, count, mode, flags, localMatrix));
}

void SkGradientShader_MakeTwoPointConical_2(const char *sk_shader_key_out, const char *sk_color_space_key_in, const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, SkGradientShader::MakeTwoPointConical(*start, startRadius, *end, endRadius, colors, static_sk_color_space_move(sk_color_space_key_in), pos, count, mode, *interpolation, localMatrix));
}

void SkGradientShader_MakeTwoPointConical_3(const char *sk_shader_key_out, const char *sk_color_space_key_in, const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor4f colors[],  const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, SkGradientShader::MakeTwoPointConical(*start, startRadius, *end, endRadius, colors, static_sk_color_space_move(sk_color_space_key_in), pos, count, mode, flags, localMatrix));
}

void SkGradientShader_MakeSweep(const char *sk_shader_key_out, SkScalar cx, SkScalar cy, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, SkGradientShader::MakeSweep(cx, cy, colors, pos, count, mode, startAngle, endAngle, flags, localMatrix));
}

void SkGradientShader_MakeSweep_2(const char *sk_shader_key_out, SkScalar cx, SkScalar cy, const SkColor colors[], const SkScalar pos[], int count, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, SkGradientShader::MakeSweep(cx, cy, colors, pos, count, flags, localMatrix));
}

void SkGradientShader_MakeSweep_3(const char *sk_shader_key_out, const char *sk_color_space_key_in, SkScalar cx, SkScalar cy, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, SkGradientShader::MakeSweep(cx, cy, colors, static_sk_color_space_move(sk_color_space_key_in), pos, count, mode, startAngle, endAngle, *interpolation, localMatrix));
}

void SkGradientShader_MakeSweep_4(const char *sk_shader_key_out, const char *sk_color_space_key_in, SkScalar cx, SkScalar cy, const SkColor4f colors[], const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, SkGradientShader::MakeSweep(cx, cy, colors, static_sk_color_space_move(sk_color_space_key_in), pos, count, mode, startAngle, endAngle, flags, localMatrix));
}

void SkGradientShader_MakeSweep_5(const char *sk_shader_key_out, const char *sk_color_space_key_in, SkScalar cx, SkScalar cy, const SkColor4f colors[], const SkScalar pos[], int count, uint32_t flags, const SkMatrix *localMatrix) {
    static_sk_shader_set(sk_shader_key_out, SkGradientShader::MakeSweep(cx, cy, colors, static_sk_color_space_move(sk_color_space_key_in), pos, count, flags, localMatrix));
}

}