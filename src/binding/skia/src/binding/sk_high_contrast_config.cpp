//
// Created by dolphilia on 2024/01/08.
//

#include "sk_high_contrast_config.h"

extern "C" {

SkHighContrastConfig *SkHighContrastConfig_new() {
    return new SkHighContrastConfig();
}

SkHighContrastConfig *SkHighContrastConfig_new_2(bool grayscale, SkHighContrastConfig::InvertStyle invertStyle, SkScalar contrast) {
    return new SkHighContrastConfig(grayscale, invertStyle, contrast);
}

void SkHighContrastConfig_delete(SkHighContrastConfig * highContrastConfig) {
    delete highContrastConfig;
}

bool isValid(SkHighContrastConfig *high_contrast_config) {
    return high_contrast_config->isValid();
}

}