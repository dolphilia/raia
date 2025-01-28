//
// Created by dolphilia on 2024/01/13.
//

#ifndef RAIA_SKIA_SK_SHADERS_H
#define RAIA_SKIA_SK_SHADERS_H

#ifdef __cplusplus
extern "C" {
#endif

int SkShaders_Empty(); // () -> sk_shader_t
int SkShaders_Color(unsigned int color); // (SkColor color) -> sk_shader_t
int SkShaders_Color_2(const void *color4f, int color_space); // (const SkColor4f *color4f, sk_color_space_t color_space) -> sk_shader_t
int SkShaders_Blend(int mode, int dst, int src); // (SkBlendMode mode, sk_shader_t dst, sk_shader_t src) -> sk_shader_t
int SkShaders_Blend_2(int value, int dst, int src); // (sk_blender_t value, sk_shader_t dst, sk_shader_t src) -> sk_shader_t
int SkShaders_CoordClamp(int shader, const void *subset); // (sk_shader_t shader, const SkRect *subset) -> sk_shader_t

//sk_sp< SkShader > SkShaders_MakeFractalNoise(SkScalar baseFrequencyX, SkScalar baseFrequencyY, int numOctaves, SkScalar seed, const SkISize *tileSize);
//sk_sp< SkShader > SkShaders_MakeTurbulence(SkScalar baseFrequencyX, SkScalar baseFrequencyY, int numOctaves, SkScalar seed, const SkISize *tileSize);

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_SHADERS_H
