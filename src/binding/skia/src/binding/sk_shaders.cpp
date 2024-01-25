//
// Created by dolphilia on 2024/01/13.
//

#include "sk_shaders.h"

extern "C" {

int SkShaders_Empty() {
    return static_sk_shader_make(SkShaders::Empty());
}

int SkShaders_Color(SkColor color) {
    return static_sk_shader_make(SkShaders::Color(color));
}

int SkShaders_Color_2(int sk_color_space_key_in, const SkColor4f &color4f) {
    return static_sk_shader_make(SkShaders::Color(color4f, static_sk_color_space_move(sk_color_space_key_in)));
}

int SkShaders_Blend(int sk_shader_key_in, int sk_shader_key_in_2, SkBlendMode mode) {
    return static_sk_shader_make(SkShaders::Blend(mode, static_sk_shader_move(sk_shader_key_in), static_sk_shader_move(sk_shader_key_in_2)));
}

int SkShaders_Blend_2(int sk_blender_key_in, int sk_shader_key_in, int sk_shader_key_in_2) {
    return static_sk_shader_make(SkShaders::Blend(static_sk_blender_move(sk_blender_key_in), static_sk_shader_move(sk_shader_key_in), static_sk_shader_move(sk_shader_key_in_2)));
}

int SkShaders_CoordClamp(int sk_shader_key_in, const SkRect *subset) {
    return static_sk_shader_make(SkShaders::CoordClamp(static_sk_shader_move(sk_shader_key_in), *subset));
}

//sk_sp< SkShader > SkShaders_MakeFractalNoise(SkScalar baseFrequencyX, SkScalar baseFrequencyY, int numOctaves, SkScalar seed, const SkISize *tileSize) {
//    return SkShaders::MakeFractalNoise(baseFrequencyX, baseFrequencyY, numOctaves, seed, tileSize);
//}

//sk_sp< SkShader > SkShaders_MakeTurbulence(SkScalar baseFrequencyX, SkScalar baseFrequencyY, int numOctaves, SkScalar seed, const SkISize *tileSize) {
//    return SkShaders::MakeTurbulence(baseFrequencyX, baseFrequencyY, numOctaves, seed, tileSize);
//}

}