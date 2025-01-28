//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_FILTERS_H
#define RAIA_SKIA_SK_COLOR_FILTERS_H

#ifdef __cplusplus
extern "C" {
#endif

void SkColorFilters_delete(void *colorFilters); // (SkColorFilters *colorFilters)

// static

int SkColorFilters_Blend(const void *c, int color_space, int mode); // (const SkColor4f *c, sk_color_space_t color_space, SkBlendMode mode) -> sk_color_filter_t
int SkColorFilters_Blend_2(unsigned int c, int mode); // (SkColor c, SkBlendMode mode) -> sk_color_filter_t
int SkColorFilters_Compose(int color_filter1, int color_filter2); // (sk_color_filter_t color_filter1, sk_color_filter_t color_filter2) -> sk_color_filter_t
int SkColorFilters_HSLAMatrix(const float rowMajor[20]); // (const float rowMajor[20]) -> sk_color_filter_t
int SkColorFilters_HSLAMatrix_2(const void *matrix); // (const SkColorMatrix *matrix) -> sk_color_filter_t
int SkColorFilters_Lerp(float t, int color_filter1, int color_filter2); // (float t, sk_color_filter_t color_filter1, sk_color_filter_t color_filter2) -> sk_color_filter_t
int SkColorFilters_Lighting(unsigned int mul, unsigned int add); // (SkColor mul, SkColor add) -> sk_color_filter_t
int SkColorFilters_LinearToSRGBGamma(); // () -> sk_color_filter_t
int SkColorFilters_Matrix(const float rowMajor[20]); // (const float rowMajor[20]) -> sk_color_filter_t
int SkColorFilters_Matrix_2(const void *matrix); // (const SkColorMatrix *matrix) -> sk_color_filter_t
int SkColorFilters_SRGBToLinearGamma(); // () -> sk_color_filter_t
int SkColorFilters_Table(const unsigned char table[256]); // (const uint8_t table[256]) -> sk_color_filter_t
int SkColorFilters_Table_2(int color_table); // (sk_color_table_t color_table) -> sk_color_filter_t
int SkColorFilters_TableARGB(const unsigned char tableA[256], const unsigned char tableR[256], const unsigned char tableG[256], const unsigned char tableB[256]); // (const uint8_t tableA[256], const uint8_t tableR[256], const uint8_t tableG[256], const uint8_t tableB[256]) -> sk_color_filter_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_COLOR_FILTERS_H
