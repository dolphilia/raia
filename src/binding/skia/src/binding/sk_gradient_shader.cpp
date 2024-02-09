//
// Created by dolphilia on 2024/01/08.
//

#include "sk_gradient_shader.h"

extern "C" {

void SkGradientShader_delete(SkGradientShader * gradientShader) {
    delete gradientShader;
}

// static

sk_shader_t SkGradientShader_MakeLinear(const SkPoint pts[2], const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeLinear(pts, colors, pos, count, mode, flags, localMatrix));
}

sk_shader_t SkGradientShader_MakeLinear_2(const SkPoint pts[2], const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeLinear(pts, colors, static_sk_color_space_move(color_space), pos, count, mode, *interpolation, localMatrix));
}

sk_shader_t SkGradientShader_MakeLinear_3(const SkPoint pts[2], const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeLinear(pts, colors, static_sk_color_space_move(color_space), pos, count, mode, flags, localMatrix));
}

sk_shader_t SkGradientShader_MakeRadial(const SkPoint *center, SkScalar radius, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeRadial(*center, radius, colors, pos, count, mode, flags, localMatrix));
}

sk_shader_t SkGradientShader_MakeRadial_2(const SkPoint *center, SkScalar radius, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeRadial(*center, radius, colors, static_sk_color_space_move(color_space), pos, count, mode, *interpolation, localMatrix));
}

sk_shader_t SkGradientShader_MakeRadial_3(const SkPoint *center, SkScalar radius, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeRadial(*center, radius, colors, static_sk_color_space_move(color_space), pos, count, mode, flags, localMatrix));
}

sk_shader_t SkGradientShader_MakeTwoPointConical(const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeTwoPointConical(*start, startRadius, *end, endRadius, colors, pos, count, mode, flags, localMatrix));
}

sk_shader_t SkGradientShader_MakeTwoPointConical_2(const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeTwoPointConical(*start, startRadius, *end, endRadius, colors, static_sk_color_space_move(color_space), pos, count, mode, *interpolation, localMatrix));
}

sk_shader_t SkGradientShader_MakeTwoPointConical_3(const SkPoint *start, SkScalar startRadius, const SkPoint *end, SkScalar endRadius, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeTwoPointConical(*start, startRadius, *end, endRadius, colors, static_sk_color_space_move(color_space), pos, count, mode, flags, localMatrix));
}

sk_shader_t SkGradientShader_MakeSweep(SkScalar cx, SkScalar cy, const SkColor colors[], const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeSweep(cx, cy, colors, pos, count, mode, startAngle, endAngle, flags, localMatrix));
}

sk_shader_t SkGradientShader_MakeSweep_2(SkScalar cx, SkScalar cy, const SkColor colors[], const SkScalar pos[], int count, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeSweep(cx, cy, colors, pos, count, flags, localMatrix));
}

sk_shader_t SkGradientShader_MakeSweep_3(SkScalar cx, SkScalar cy, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, const SkGradientShader::Interpolation *interpolation, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeSweep(cx, cy, colors, static_sk_color_space_move(color_space), pos, count, mode, startAngle, endAngle, *interpolation, localMatrix));
}

sk_shader_t SkGradientShader_MakeSweep_4(SkScalar cx, SkScalar cy, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, SkTileMode mode, SkScalar startAngle, SkScalar endAngle, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeSweep(cx, cy, colors, static_sk_color_space_move(color_space), pos, count, mode, startAngle, endAngle, flags, localMatrix));
}

sk_shader_t SkGradientShader_MakeSweep_5(SkScalar cx, SkScalar cy, const SkColor4f colors[], sk_color_space_t color_space, const SkScalar pos[], int count, uint32_t flags, const SkMatrix *localMatrix) {
    return static_sk_shader_make(SkGradientShader::MakeSweep(cx, cy, colors, static_sk_color_space_move(color_space), pos, count, flags, localMatrix));
}

}