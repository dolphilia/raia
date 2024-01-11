//
// Created by dolphilia on 2024/01/08.
//

#include "sk_cubic_map.h"

extern "C" {

SkCubicMap *SkCubicMap_new(SkPoint p1, SkPoint p2) {
    return new SkCubicMap(p1, p2);
}

float SkCubicMap_computeYFromX(SkCubicMap * cubic_map, float x) {
    return cubic_map->computeYFromX(x);
}

SkPoint SkCubicMap_computeFromT(SkCubicMap * cubic_map, float t) {
    return cubic_map->computeFromT(t);
}

// static

bool SkCubicMap_IsLinear(SkPoint p1, SkPoint p2) {
    return SkCubicMap::IsLinear(p1, p2);
}

}