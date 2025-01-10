//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_FILTERS_H
#define RAIA_SKIA_SK_COLOR_FILTERS_H

#include "include/core/SkColorFilter.h"
#include "../static/static_sk_color_filter.h"
#include "../static/static_sk_color_space.h"
#include "../static/static_sk_color_table.h"

extern "C" {
void SkColorFilters_delete(SkColorFilters *colorFilters);
// static
sk_color_filter_t SkColorFilters_Blend(const SkColor4f *c, sk_color_space_t color_space, SkBlendMode mode);
sk_color_filter_t SkColorFilters_Blend_2(SkColor c, SkBlendMode mode);
sk_color_filter_t SkColorFilters_Compose(sk_color_filter_t color_filter1, sk_color_filter_t color_filter2);
sk_color_filter_t SkColorFilters_HSLAMatrix(const float rowMajor[20]);
sk_color_filter_t SkColorFilters_HSLAMatrix_2(const SkColorMatrix *matrix);
sk_color_filter_t SkColorFilters_Lerp(float t, sk_color_filter_t color_filter1, sk_color_filter_t color_filter2);
sk_color_filter_t SkColorFilters_Lighting(SkColor mul, SkColor add);
sk_color_filter_t SkColorFilters_LinearToSRGBGamma();
sk_color_filter_t SkColorFilters_Matrix(const float rowMajor[20]);
sk_color_filter_t SkColorFilters_Matrix_2(const SkColorMatrix *matrix);
sk_color_filter_t SkColorFilters_SRGBToLinearGamma();
sk_color_filter_t SkColorFilters_Table(const uint8_t table[256]);
sk_color_filter_t SkColorFilters_Table_2(sk_color_table_t color_table);
sk_color_filter_t SkColorFilters_TableARGB(const uint8_t tableA[256], const uint8_t tableR[256], const uint8_t tableG[256], const uint8_t tableB[256]);
}
#endif //RAIA_SKIA_SK_COLOR_FILTERS_H
