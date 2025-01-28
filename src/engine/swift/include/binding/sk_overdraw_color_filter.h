//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_OVERDRAW_COLOR_FILTER_H
#define RAIA_SKIA_SK_OVERDRAW_COLOR_FILTER_H

#ifdef __cplusplus
extern "C" {
#endif

void SkOverdrawColorFilter_delete(void * overdrawColorFilter); // (SkOverdrawColorFilter *overdrawColorFilter)

// static

int SkOverdrawColorFilter_MakeWithSkColors(const void * color); // (const SkColor color[SkOverdrawColorFilter::kNumColors]) -> sk_color_filter_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_OVERDRAW_COLOR_FILTER_H
