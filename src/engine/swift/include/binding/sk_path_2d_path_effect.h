//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_PATH_2D_PATH_EFFECT_H
#define RAIA_SKIA_SK_PATH_2D_PATH_EFFECT_H

#ifdef __cplusplus
extern "C" {
#endif

void SkPath2DPathEffect_delete(void *path2DPathEffect); // (SkPath2DPathEffect *path2DPathEffect)

// static

int SkPath2DPathEffect_Make(const void *matrix, const void *path); // (const SkMatrix *matrix, const SkPath *path) -> sk_path_effect_t
void SkPath2DPathEffect_RegisterFlattenables(); // ()

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_PATH_2D_PATH_EFFECT_H
