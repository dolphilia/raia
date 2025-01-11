//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_CUBIC_MAP_H
#define RAIA_SKIA_SK_CUBIC_MAP_H

#include "include/core/SkCubicMap.h"
#include "../static/static_sk_point.h"
#include "export_api.h"

extern "C" {
RAIA_API SkCubicMap *SkCubicMap_new(sk_point_t p1, sk_point_t p2);
RAIA_API void SkCubicMap_delete(SkCubicMap * cubic_map);
RAIA_API float SkCubicMap_computeYFromX(SkCubicMap * cubic_map, float x);
RAIA_API sk_point_t SkCubicMap_computeFromT(SkCubicMap * cubic_map, float t);
// static
RAIA_API bool SkCubicMap_IsLinear(sk_point_t p1, sk_point_t p2);
}

#endif //RAIA_SKIA_SK_CUBIC_MAP_H
