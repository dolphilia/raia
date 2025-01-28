//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_PATH_1D_PATH_EFFECT_H
#define RAIA_SKIA_SK_PATH_1D_PATH_EFFECT_H

#ifdef __cplusplus
extern "C" {
#endif

void SkPath1DPathEffect_delete(void *path1DPathEffect); // (SkPath1DPathEffect *path1DPathEffect)

// static

int SkPath1DPathEffect_Make(const void *path, float advance, float phase, int style); // (const SkPath *path, SkScalar advance, SkScalar phase, SkPath1DPathEffect::Style style) -> sk_path_effect_t
void SkPath1DPathEffect_RegisterFlattenables(); // ()

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_PATH_1D_PATH_EFFECT_H
