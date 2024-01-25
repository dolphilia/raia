//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_SK_SHADERS_H
#define RAIA_SKIA_SK_SHADERS_H

#include "include/core/SkColorSpace.h"
#include "include/core/SkBlender.h"
#include "include/core/SkSize.h"
#include "include/core/SkShader.h"
#include "../static/static_sk_shader.h"
#include "../static/static_sk_color_space.h"
#include "../static/static_sk_blender.h"

extern "C" {
void SkShaders_Empty(int sk_shader_key_out);
void SkShaders_Color(int sk_shader_key_out, SkColor color);
void SkShaders_Color_2(int sk_shader_key_out, int sk_color_space_key_in, const SkColor4f &color4f);
void SkShaders_Blend(int sk_shader_key_out, int sk_shader_key_in, int sk_shader_key_in_2, SkBlendMode mode);
void SkShaders_Blend_2(int sk_shader_key_out, int sk_blender_key_in, int sk_shader_key_in, int sk_shader_key_in_2);
void SkShaders_CoordClamp(int sk_shader_key_out, int sk_shader_key_in, const SkRect *subset);
//sk_sp< SkShader > SkShaders_MakeFractalNoise(SkScalar baseFrequencyX, SkScalar baseFrequencyY, int numOctaves, SkScalar seed, const SkISize *tileSize);
//sk_sp< SkShader > SkShaders_MakeTurbulence(SkScalar baseFrequencyX, SkScalar baseFrequencyY, int numOctaves, SkScalar seed, const SkISize *tileSize);
}

#endif //RAIA_SKIA_SK_SHADERS_H
