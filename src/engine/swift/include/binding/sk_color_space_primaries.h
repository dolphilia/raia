//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_SPACE_PRIMARIES_H
#define RAIA_SKIA_SK_COLOR_SPACE_PRIMARIES_H

#ifdef __cplusplus
extern "C" {
#endif

void SkColorSpacePrimaries_delete(void *color_pace_primaries); // (SkColorSpacePrimaries *color_pace_primaries)
void SkColorSpacePrimaries_toXYZD50(void *color_pace_primaries, void *toXYZD50); // (SkColorSpacePrimaries *color_pace_primaries, skcms_Matrix3x3 *toXYZD50)

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_COLOR_SPACE_PRIMARIES_H
