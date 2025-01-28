//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_HIGH_CONTRAST_CONFIG_H
#define RAIA_SKIA_SK_HIGH_CONTRAST_CONFIG_H

#include "include/effects/SkHighContrastFilter.h"

extern "C" {
SkHighContrastConfig *SkHighContrastConfig_new();
SkHighContrastConfig *SkHighContrastConfig_new_2(bool grayscale, SkHighContrastConfig::InvertStyle invertStyle, SkScalar contrast);
void SkHighContrastConfig_delete(SkHighContrastConfig * highContrastConfig);
bool isValid(SkHighContrastConfig *high_contrast_config);
}

#endif //RAIA_SKIA_SK_HIGH_CONTRAST_CONFIG_H
