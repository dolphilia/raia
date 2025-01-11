//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_HIGH_CONTRAST_CONFIG_H
#define RAIA_SKIA_SK_HIGH_CONTRAST_CONFIG_H

#include "include/effects/SkHighContrastFilter.h"
#include "export_api.h"

extern "C" {
RAIA_API SkHighContrastConfig *SkHighContrastConfig_new();
RAIA_API SkHighContrastConfig *SkHighContrastConfig_new_2(bool grayscale, SkHighContrastConfig::InvertStyle invertStyle, SkScalar contrast);
RAIA_API void SkHighContrastConfig_delete(SkHighContrastConfig * highContrastConfig);
RAIA_API bool isValid(SkHighContrastConfig *high_contrast_config);
}

#endif //RAIA_SKIA_SK_HIGH_CONTRAST_CONFIG_H
