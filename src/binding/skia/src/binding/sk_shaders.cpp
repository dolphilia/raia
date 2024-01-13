//
// Created by dolphilia on 2024/01/13.
//

#include "sk_shaders.h"

extern "C" {

void SkShaders_Empty(const char *sk_shader_key_out) {
    static_sk_shader_set(sk_shader_key_out, SkShaders::Empty());
}

void SkShaders_Color(const char *sk_shader_key_out, SkColor color) {
    static_sk_shader_set(sk_shader_key_out, SkShaders::Color(color));
}

void SkShaders_Color_2(const char *sk_shader_key_out, const char *sk_color_space_key_in, const SkColor4f &color4f) {
    static_sk_shader_set(sk_shader_key_out, SkShaders::Color(color4f, static_sk_color_space_move(sk_color_space_key_in)));
}

void SkShaders_Blend(const char *sk_shader_key_out, const char *sk_shader_key_in, const char *sk_shader_key_in_2, SkBlendMode mode) {
    static_sk_shader_set(sk_shader_key_out, SkShaders::Blend(mode, static_sk_shader_move(sk_shader_key_in), static_sk_shader_move(sk_shader_key_in_2)));
}

void SkShaders_Blend_2(const char *sk_shader_key_out, const char *sk_blender_key_in, const char *sk_shader_key_in, const char *sk_shader_key_in_2) {
    static_sk_shader_set(sk_shader_key_out, SkShaders::Blend(static_sk_blender_move(sk_blender_key_in), static_sk_shader_move(sk_shader_key_in), static_sk_shader_move(sk_shader_key_in_2)));
}

void SkShaders_CoordClamp(const char *sk_shader_key_out, const char *sk_shader_key_in, const SkRect *subset) {
    static_sk_shader_set(sk_shader_key_out, SkShaders::CoordClamp(static_sk_shader_move(sk_shader_key_in), *subset));
}

//sk_sp< SkShader > SkShaders_MakeFractalNoise(SkScalar baseFrequencyX, SkScalar baseFrequencyY, int numOctaves, SkScalar seed, const SkISize *tileSize) {
//    return SkShaders::MakeFractalNoise(baseFrequencyX, baseFrequencyY, numOctaves, seed, tileSize);
//}

//sk_sp< SkShader > SkShaders_MakeTurbulence(SkScalar baseFrequencyX, SkScalar baseFrequencyY, int numOctaves, SkScalar seed, const SkISize *tileSize) {
//    return SkShaders::MakeTurbulence(baseFrequencyX, baseFrequencyY, numOctaves, seed, tileSize);
//}

}