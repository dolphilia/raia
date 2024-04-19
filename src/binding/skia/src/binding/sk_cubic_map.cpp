//
// Created by dolphilia on 2024/01/08.
//

#include "sk_cubic_map.h"

extern "C" {

SkCubicMap *SkCubicMap_new(sk_point_t p1, sk_point_t p2) {
    return new SkCubicMap(static_sk_point_get(p1), static_sk_point_get(p2));
}

void SkCubicMap_delete(SkCubicMap * cubic_map) {
    delete cubic_map;
}

float SkCubicMap_computeYFromX(SkCubicMap * cubic_map, float x) {
    return cubic_map->computeYFromX(x);
}

sk_point_t SkCubicMap_computeFromT(SkCubicMap * cubic_map, float t) {
    return static_sk_point_make(cubic_map->computeFromT(t));
}

// static

bool SkCubicMap_IsLinear(sk_point_t p1, sk_point_t p2) {
    return SkCubicMap::IsLinear(static_sk_point_get(p1), static_sk_point_get(p2));
}

}