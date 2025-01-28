//
// Created by dolphilia on 2024/01/29.
//

#ifndef RAIA_SKIA_SK_PERLIN_NOISE_SHADER_H
#define RAIA_SKIA_SK_PERLIN_NOISE_SHADER_H

#ifdef __cplusplus
extern "C" {
#endif

// static

int SkPerlinNoiseShader_MakeFractalNoise(float baseFrequencyX, float baseFrequencyY, int numOctaves, float seed, const void *tileSize); // (SkScalar baseFrequencyX, SkScalar baseFrequencyY, int numOctaves, SkScalar seed, const SkISize *tileSize) -> sk_shader_t
int SkPerlinNoiseShader_MakeTurbulence(float baseFrequencyX, float baseFrequencyY, int numOctaves, float seed, const void *tileSize); // (SkScalar baseFrequencyX, SkScalar baseFrequencyY, int numOctaves, SkScalar seed, const SkISize *tileSize) -> sk_shader_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_PERLIN_NOISE_SHADER_H
