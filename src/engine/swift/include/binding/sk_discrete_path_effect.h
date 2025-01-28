//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_DISCRETE_PATH_EFFECT_H
#define RAIA_SKIA_SK_DISCRETE_PATH_EFFECT_H

#ifdef __cplusplus
extern "C" {
#endif

void SkDiscretePathEffect_delete(void * discretePathEffect); // (SkDiscretePathEffect * discretePathEffect)

// static

int SkDiscretePathEffect_Make(float segLength, float dev, unsigned int seedAssist); // (SkScalar segLength, SkScalar dev, uint32_t seedAssist) -> sk_path_effect_t
void SkDiscretePathEffect_RegisterFlattenables(); // ()

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_DISCRETE_PATH_EFFECT_H
