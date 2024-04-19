//
// Created by dolphilia on 2024/01/13.
//

#include "sk_shaders.h"

extern "C" {

sk_shader_t SkShaders_Empty() {
    return static_sk_shader_make(SkShaders::Empty());
}

sk_shader_t SkShaders_Color(SkColor color) {
    return static_sk_shader_make(SkShaders::Color(color));
}

sk_shader_t SkShaders_Color_2(const SkColor4f *color4f, sk_color_space_t color_space) {
    return static_sk_shader_make(SkShaders::Color(*color4f, static_sk_color_space_move(color_space)));
}

sk_shader_t SkShaders_Blend(SkBlendMode mode, sk_shader_t dst, sk_shader_t src) {
    return static_sk_shader_make(SkShaders::Blend(mode, static_sk_shader_move(dst), static_sk_shader_move(src)));
}

sk_shader_t SkShaders_Blend_2(sk_blender_t value, sk_shader_t dst, sk_shader_t src) {
    return static_sk_shader_make(SkShaders::Blend(static_sk_blender_move(value), static_sk_shader_move(dst), static_sk_shader_move(src)));
}

sk_shader_t SkShaders_CoordClamp(sk_shader_t shader, const SkRect *subset) {
    return static_sk_shader_make(SkShaders::CoordClamp(static_sk_shader_move(shader), *subset));
}

//sk_sp< SkShader > SkShaders_MakeFractalNoise(SkScalar baseFrequencyX, SkScalar baseFrequencyY, int numOctaves, SkScalar seed, const SkISize *tileSize) {
//    return SkShaders::MakeFractalNoise(baseFrequencyX, baseFrequencyY, numOctaves, seed, tileSize);
//}

//sk_sp< SkShader > SkShaders_MakeTurbulence(SkScalar baseFrequencyX, SkScalar baseFrequencyY, int numOctaves, SkScalar seed, const SkISize *tileSize) {
//    return SkShaders::MakeTurbulence(baseFrequencyX, baseFrequencyY, numOctaves, seed, tileSize);
//}

}