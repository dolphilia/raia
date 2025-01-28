//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_HIGH_CONTRAST_FILTER_H
#define RAIA_SKIA_SK_HIGH_CONTRAST_FILTER_H

#ifdef __cplusplus
extern "C" {
#endif

void SkHighContrastFilter_delete(void * highContrastFilter); // (SkHighContrastFilter * highContrastFilter)

// static

int SkHighContrastFilter_Make(const void * config); // (const SkHighContrastConfig * config) -> sk_color_filter_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_HIGH_CONTRAST_FILTER_H
