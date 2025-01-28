//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_LINE_2D_PATH_EFFECT_H
#define RAIA_SKIA_SK_LINE_2D_PATH_EFFECT_H

#ifdef __cplusplus
extern "C" {
#endif

void SkLine2DPathEffect_delete(void * line2DPathEffect); // (SkLine2DPathEffect * line2DPathEffect)

// static

int SkLine2DPathEffect_Make(float width, const void *matrix); // (SkScalar width, const SkMatrix *matrix) -> sk_path_effect_t
void SkLine2DPathEffect_RegisterFlattenables(); // ()

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_LINE_2D_PATH_EFFECT_H
