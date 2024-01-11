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
void SkColorFilters_Blend(const char *sk_color_filter_key_out, const char * sk_color_space_key_in, const SkColor4f * c, SkBlendMode mode);
void SkColorFilters_Blend_2(const char *sk_color_filter_key_out, SkColor c, SkBlendMode mode);
void SkColorFilters_Compose(const char *sk_color_filter_key_out, const char *sk_color_filter_key_in_1, const char *sk_color_filter_key_in_2);
void SkColorFilters_HSLAMatrix(const char *sk_color_filter_key_out, const float rowMajor[20]);
void SkColorFilters_HSLAMatrix_2(const char *sk_color_filter_key_out, const SkColorMatrix *matrix);
void SkColorFilters_Lerp(const char *sk_color_filter_key_out, const char *sk_color_filter_key_in_1, const char *sk_color_filter_key_in_2, float t);
void SkColorFilters_Lighting(const char *sk_color_filter_key_out, SkColor mul, SkColor add);
void SkColorFilters_LinearToSRGBGamma(const char *sk_color_filter_key_out);
void SkColorFilters_Matrix(const char *sk_color_filter_key_out, const float rowMajor[20]);
void SkColorFilters_Matrix_2(const char *sk_color_filter_key_out, const SkColorMatrix *matrix);
void SkColorFilters_SRGBToLinearGamma(const char *sk_color_filter_key_out);
void SkColorFilters_Table(const char *sk_color_filter_key_out, const uint8_t table[256]);
void SkColorFilters_Table_2(const char *sk_color_filter_key_out, const char *sk_color_table_key_in);
void SkColorFilters_TableARGB(const char *sk_color_filter_key_out, const uint8_t tableA[256], const uint8_t tableR[256], const uint8_t tableG[256], const uint8_t tableB[256]);
}
#endif //RAIA_SKIA_SK_COLOR_FILTERS_H
