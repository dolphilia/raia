//
// Created by dolphilia on 2024/01/08.
//

#include "sk_color_filters.h"

extern "C" {

// static

void SkColorFilters_delete(SkColorFilters *colorFilters) {
    delete colorFilters;
}

sk_color_filter_t SkColorFilters_Blend(const SkColor4f *c, sk_color_space_t color_space, SkBlendMode mode) {
    return static_sk_color_filter_make(SkColorFilters::Blend(*c, static_sk_color_space_move(color_space), mode));
}

sk_color_filter_t SkColorFilters_Blend_2(SkColor c, SkBlendMode mode) {
    return static_sk_color_filter_make(SkColorFilters::Blend(c, mode));
}

sk_color_filter_t SkColorFilters_Compose(sk_color_filter_t color_filter1, sk_color_filter_t color_filter2) {
    return static_sk_color_filter_make(SkColorFilters::Compose(static_sk_color_filter_move(color_filter1), static_sk_color_filter_move(color_filter2)));
}

sk_color_filter_t SkColorFilters_HSLAMatrix(const float rowMajor[20]) {
    return static_sk_color_filter_make(SkColorFilters::HSLAMatrix(rowMajor));
}

sk_color_filter_t SkColorFilters_HSLAMatrix_2(const SkColorMatrix *matrix) {
    return static_sk_color_filter_make(SkColorFilters::HSLAMatrix(*matrix));
}

sk_color_filter_t SkColorFilters_Lerp(float t, sk_color_filter_t color_filter1, sk_color_filter_t color_filter2) {
    return static_sk_color_filter_make(SkColorFilters::Lerp(t, static_sk_color_filter_move(color_filter1), static_sk_color_filter_move(color_filter2)));
}

sk_color_filter_t SkColorFilters_Lighting(SkColor mul, SkColor add) {
    return static_sk_color_filter_make(SkColorFilters::Lighting(mul, add));
}

sk_color_filter_t SkColorFilters_LinearToSRGBGamma() {
    return static_sk_color_filter_make(SkColorFilters::LinearToSRGBGamma());
}

sk_color_filter_t SkColorFilters_Matrix(const float rowMajor[20]) {
    return static_sk_color_filter_make(SkColorFilters::Matrix(rowMajor));
}

sk_color_filter_t SkColorFilters_Matrix_2(const SkColorMatrix *matrix) {
    return static_sk_color_filter_make(SkColorFilters::Matrix(*matrix));
}

sk_color_filter_t SkColorFilters_SRGBToLinearGamma() {
    return static_sk_color_filter_make(SkColorFilters::SRGBToLinearGamma());
}

sk_color_filter_t SkColorFilters_Table(const uint8_t table[256]) {
    return static_sk_color_filter_make(SkColorFilters::Table(table));
}

sk_color_filter_t SkColorFilters_Table_2(sk_color_table_t color_table) {
    return static_sk_color_filter_make(SkColorFilters::Table(static_sk_color_table_move(color_table)));
}

sk_color_filter_t SkColorFilters_TableARGB(const uint8_t tableA[256], const uint8_t tableR[256], const uint8_t tableG[256], const uint8_t tableB[256]) {
    return static_sk_color_filter_make(SkColorFilters::TableARGB(tableA, tableR, tableG, tableB));
}

}