//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_CUBIC_MAP_H
#define RAIA_SKIA_SK_CUBIC_MAP_H

#ifdef __cplusplus
extern "C" {
#endif

void *SkCubicMap_new(int p1, int p2); // (sk_point_t p1, sk_point_t p2) -> SkCubicMap *
void SkCubicMap_delete(void * cubic_map); // (SkCubicMap * cubic_map)
float SkCubicMap_computeYFromX(void * cubic_map, float x); // (SkCubicMap * cubic_map, float x) -> float
int SkCubicMap_computeFromT(void * cubic_map, float t); // (SkCubicMap * cubic_map, float t) -> sk_point_t

// static

bool SkCubicMap_IsLinear(int p1, int p2); // (sk_point_t p1, sk_point_t p2) -> bool

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_CUBIC_MAP_H
