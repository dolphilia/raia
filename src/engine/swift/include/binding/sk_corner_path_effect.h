//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_CORNER_PATH_EFFECT_H
#define RAIA_SKIA_SK_CORNER_PATH_EFFECT_H

#ifdef __cplusplus
extern "C" {
#endif

void SkCornerPathEffect_delete(void * cornerPathEffect); // (SkCornerPathEffect * cornerPathEffect)

// static

int SkCornerPathEffect_Make(float radius); // (SkScalar radius) -> sk_path_effect_t
void SkCornerPathEffect_RegisterFlattenables(); // ()

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_CORNER_PATH_EFFECT_H
