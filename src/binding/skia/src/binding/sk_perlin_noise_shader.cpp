//
// Created by dolphilia on 2024/01/29.
//

#include "sk_perlin_noise_shader.h"

extern "C" {

sk_shader_t SkPerlinNoiseShader_MakeFractalNoise(SkScalar baseFrequencyX, SkScalar baseFrequencyY, int numOctaves, SkScalar seed, const SkISize *tileSize) {
    return static_sk_shader_make(SkShaders::MakeFractalNoise(baseFrequencyX, baseFrequencyY, numOctaves, seed, tileSize));
}

sk_shader_t SkPerlinNoiseShader_MakeTurbulence(SkScalar baseFrequencyX, SkScalar baseFrequencyY, int numOctaves, SkScalar seed, const SkISize *tileSize) {
    return static_sk_shader_make(SkShaders::MakeTurbulence(baseFrequencyX, baseFrequencyY, numOctaves, seed, tileSize));
}

}