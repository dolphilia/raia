//
// Created by dolphilia on 2024/01/08.
//

#include "sk_color_filters.h"

extern "C" {

// static

void SkColorFilters_delete(SkColorFilters *colorFilters) {
    delete colorFilters;
}

int SkColorFilters_Blend(int sk_color_space_key_in, const SkColor4f * c, SkBlendMode mode) {
    return static_sk_color_filter_make(SkColorFilters::Blend(*c, static_sk_color_space_move(sk_color_space_key_in), mode));
}

int SkColorFilters_Blend_2(SkColor c, SkBlendMode mode) {
    return static_sk_color_filter_make(SkColorFilters::Blend(c, mode));
}

int SkColorFilters_Compose(int sk_color_filter_key_in_1, int sk_color_filter_key_in_2) {
    return static_sk_color_filter_make(SkColorFilters::Compose(static_sk_color_filter_move(sk_color_filter_key_in_1), static_sk_color_filter_move(sk_color_filter_key_in_2)));
}

int SkColorFilters_HSLAMatrix(const float rowMajor[20]) {
    return static_sk_color_filter_make(SkColorFilters::HSLAMatrix(rowMajor));
}

int SkColorFilters_HSLAMatrix_2(const SkColorMatrix *matrix) {
    return static_sk_color_filter_make(SkColorFilters::HSLAMatrix(*matrix));
}

int SkColorFilters_Lerp(int sk_color_filter_key_in_1, int sk_color_filter_key_in_2, float t) {
    return static_sk_color_filter_make(SkColorFilters::Lerp(t, static_sk_color_filter_move(sk_color_filter_key_in_1), static_sk_color_filter_move(sk_color_filter_key_in_2)));
}

int SkColorFilters_Lighting(SkColor mul, SkColor add) {
    return static_sk_color_filter_make(SkColorFilters::Lighting(mul, add));
}

int SkColorFilters_LinearToSRGBGamma() {
    return static_sk_color_filter_make(SkColorFilters::LinearToSRGBGamma());
}

int SkColorFilters_Matrix(const float rowMajor[20]) {
    return static_sk_color_filter_make(SkColorFilters::Matrix(rowMajor));
}

int SkColorFilters_Matrix_2(const SkColorMatrix *matrix) {
    return static_sk_color_filter_make(SkColorFilters::Matrix(*matrix));
}

int SkColorFilters_SRGBToLinearGamma() {
    return static_sk_color_filter_make(SkColorFilters::SRGBToLinearGamma());
}

int SkColorFilters_Table(const uint8_t table[256]) {
    return static_sk_color_filter_make(SkColorFilters::Table(table));
}

int SkColorFilters_Table_2(int sk_color_table_key_in) {
    return static_sk_color_filter_make(SkColorFilters::Table(static_sk_color_table_move(sk_color_table_key_in)));
}

int SkColorFilters_TableARGB(const uint8_t tableA[256], const uint8_t tableR[256], const uint8_t tableG[256], const uint8_t tableB[256]) {
    return static_sk_color_filter_make(SkColorFilters::TableARGB(tableA, tableR, tableG, tableB));
}

}