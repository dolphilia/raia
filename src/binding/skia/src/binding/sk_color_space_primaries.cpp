//
// Created by dolphilia on 2024/01/08.
//

#include "sk_color_space_primaries.h"

extern "C" {

void SkColorSpacePrimaries_delete(SkColorSpacePrimaries *color_pace_primaries) {
    delete color_pace_primaries;
}

void SkColorSpacePrimaries_toXYZD50(SkColorSpacePrimaries *color_pace_primaries, skcms_Matrix3x3 *toXYZD50) {
    color_pace_primaries->toXYZD50(toXYZD50);
}

}