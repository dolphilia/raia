//
// Created by dolphilia on 2024/01/06.
//

#ifndef RAIA_SKIA_SK_BLEND_MODE_H
#define RAIA_SKIA_SK_BLEND_MODE_H

#ifdef __cplusplus
extern "C" {
#endif

bool SkBlendMode_SkBlendMode_AsCoeff(int mode, void * src, void * dst); // (SkBlendMode mode, SkBlendModeCoeff *src, SkBlendModeCoeff *dst) -> bool
const char * SkBlendMode_SkBlendMode_Name(int blendMode); // (SkBlendMode blendMode) -> const char *

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_BLEND_MODE_H
