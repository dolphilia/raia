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
// static
int SkColorFilters_Blend(int sk_color_space_key_in, const SkColor4f * c, SkBlendMode mode);
int SkColorFilters_Blend_2(SkColor c, SkBlendMode mode);
int SkColorFilters_Compose(int sk_color_filter_key_in_1, int sk_color_filter_key_in_2);
int SkColorFilters_HSLAMatrix(const float rowMajor[20]);
int SkColorFilters_HSLAMatrix_2(const SkColorMatrix *matrix);
int SkColorFilters_Lerp(int sk_color_filter_key_in_1, int sk_color_filter_key_in_2, float t);
int SkColorFilters_Lighting(SkColor mul, SkColor add);
int SkColorFilters_LinearToSRGBGamma();
int SkColorFilters_Matrix(const float rowMajor[20]);
int SkColorFilters_Matrix_2(const SkColorMatrix *matrix);
int SkColorFilters_SRGBToLinearGamma();
int SkColorFilters_Table(const uint8_t table[256]);
int SkColorFilters_Table_2(int sk_color_table_key_in);
int SkColorFilters_TableARGB(const uint8_t tableA[256], const uint8_t tableR[256], const uint8_t tableG[256], const uint8_t tableB[256]);
}
#endif //RAIA_SKIA_SK_COLOR_FILTERS_H
