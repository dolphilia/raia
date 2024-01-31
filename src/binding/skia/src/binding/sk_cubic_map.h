//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_CUBIC_MAP_H
#define RAIA_SKIA_SK_CUBIC_MAP_H

#include "include/core/SkCubicMap.h"

extern "C" {
void SkCubicMap_delete(SkCubicMap * cubic_map);
SkCubicMap *SkCubicMap_new(SkPoint p1, SkPoint p2);
float SkCubicMap_computeYFromX(SkCubicMap * cubic_map, float x);
SkPoint SkCubicMap_computeFromT(SkCubicMap * cubic_map, float t);
// static
bool SkCubicMap_IsLinear(SkPoint p1, SkPoint p2);
}

#endif //RAIA_SKIA_SK_CUBIC_MAP_H
