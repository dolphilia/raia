//
// Created by dolphilia on 2024/01/29.
//

#ifndef RAIA_SKIA_SK_PERLIN_NOISE_SHADER_H
#define RAIA_SKIA_SK_PERLIN_NOISE_SHADER_H

#include "include/effects/SkPerlinNoiseShader.h"
#include "../static/static_sk_shader.h"

extern "C" {
sk_shader_t SkPerlinNoiseShader_MakeFractalNoise(SkScalar baseFrequencyX, SkScalar baseFrequencyY, int numOctaves, SkScalar seed, const SkISize *tileSize);
sk_shader_t SkPerlinNoiseShader_MakeTurbulence(SkScalar baseFrequencyX, SkScalar baseFrequencyY, int numOctaves, SkScalar seed, const SkISize *tileSize);
}

#endif //RAIA_SKIA_SK_PERLIN_NOISE_SHADER_H
