//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_HIGH_CONTRAST_CONFIG_H
#define RAIA_SKIA_SK_HIGH_CONTRAST_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

void *SkHighContrastConfig_new(); // () -> SkHighContrastConfig *
void *SkHighContrastConfig_new_2(bool grayscale, int invertStyle, float contrast); // (bool grayscale, SkHighContrastConfig::InvertStyle invertStyle, SkScalar contrast) -> SkHighContrastConfig *
void SkHighContrastConfig_delete(void * highContrastConfig); // (SkHighContrastConfig * highContrastConfig)
bool isValid(void *high_contrast_config); // (SkHighContrastConfig *high_contrast_config) -> bool

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_HIGH_CONTRAST_CONFIG_H
