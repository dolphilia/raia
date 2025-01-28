//
// Created by dolphilia on 2024/01/09.
//

#ifndef RAIA_SKIA_SK_LUMA_COLOR_FILTER_H
#define RAIA_SKIA_SK_LUMA_COLOR_FILTER_H

#ifdef __cplusplus
extern "C" {
#endif

void SkLumaColorFilter_delete(void * lumaColorFilter); // (SkLumaColorFilter * lumaColorFilter)

// static

int SkLumaColorFilter_Make(); // () -> sk_color_filter_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_LUMA_COLOR_FILTER_H
