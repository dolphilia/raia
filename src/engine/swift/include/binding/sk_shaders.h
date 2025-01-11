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
#include "export_api.h"

extern "C" {
RAIA_API sk_shader_t SkShaders_Empty();
RAIA_API sk_shader_t SkShaders_Color(SkColor color);
RAIA_API sk_shader_t SkShaders_Color_2(const SkColor4f *color4f, sk_color_space_t color_space);
RAIA_API sk_shader_t SkShaders_Blend(SkBlendMode mode, sk_shader_t dst, sk_shader_t src);
RAIA_API sk_shader_t SkShaders_Blend_2(sk_blender_t value, sk_shader_t dst, sk_shader_t src);
RAIA_API sk_shader_t SkShaders_CoordClamp(sk_shader_t shader, const SkRect *subset);
//sk_sp< SkShader > SkShaders_MakeFractalNoise(SkScalar baseFrequencyX, SkScalar baseFrequencyY, int numOctaves, SkScalar seed, const SkISize *tileSize);
//sk_sp< SkShader > SkShaders_MakeTurbulence(SkScalar baseFrequencyX, SkScalar baseFrequencyY, int numOctaves, SkScalar seed, const SkISize *tileSize);
}

#endif //RAIA_SKIA_SK_SHADERS_H
