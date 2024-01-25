//
// Created by dolphilia on 2024/01/08.
//

#include "sk_color_filters.h"

extern "C" {

// static

void SkColorFilters_Blend(int sk_color_filter_key_out, int sk_color_space_key_in, const SkColor4f * c, SkBlendMode mode) {
    static_sk_color_filter_set(sk_color_filter_key_out, SkColorFilters::Blend(*c, static_sk_color_space_move(sk_color_space_key_in), mode));
}

void SkColorFilters_Blend_2(int sk_color_filter_key_out, SkColor c, SkBlendMode mode) {
    static_sk_color_filter_set(sk_color_filter_key_out, SkColorFilters::Blend(c, mode));
}

void SkColorFilters_Compose(int sk_color_filter_key_out, int sk_color_filter_key_in_1, int sk_color_filter_key_in_2) {
    static_sk_color_filter_set(sk_color_filter_key_out, SkColorFilters::Compose(static_sk_color_filter_move(sk_color_filter_key_in_1), static_sk_color_filter_move(sk_color_filter_key_in_2)));
}

void SkColorFilters_HSLAMatrix(int sk_color_filter_key_out, const float rowMajor[20]) {
    static_sk_color_filter_set(sk_color_filter_key_out, SkColorFilters::HSLAMatrix(rowMajor));
}

void SkColorFilters_HSLAMatrix_2(int sk_color_filter_key_out, const SkColorMatrix *matrix) {
    static_sk_color_filter_set(sk_color_filter_key_out, SkColorFilters::HSLAMatrix(*matrix));
}

void SkColorFilters_Lerp(int sk_color_filter_key_out, int sk_color_filter_key_in_1, int sk_color_filter_key_in_2, float t) {
    static_sk_color_filter_set(sk_color_filter_key_out, SkColorFilters::Lerp(t, static_sk_color_filter_move(sk_color_filter_key_in_1), static_sk_color_filter_move(sk_color_filter_key_in_2)));
}

void SkColorFilters_Lighting(int sk_color_filter_key_out, SkColor mul, SkColor add) {
    static_sk_color_filter_set(sk_color_filter_key_out, SkColorFilters::Lighting(mul, add));
}

void SkColorFilters_LinearToSRGBGamma(int sk_color_filter_key_out) {
    static_sk_color_filter_set(sk_color_filter_key_out, SkColorFilters::LinearToSRGBGamma());
}

void SkColorFilters_Matrix(int sk_color_filter_key_out, const float rowMajor[20]) {
    static_sk_color_filter_set(sk_color_filter_key_out, SkColorFilters::Matrix(rowMajor));
}

void SkColorFilters_Matrix_2(int sk_color_filter_key_out, const SkColorMatrix *matrix) {
    static_sk_color_filter_set(sk_color_filter_key_out, SkColorFilters::Matrix(*matrix));
}

void SkColorFilters_SRGBToLinearGamma(int sk_color_filter_key_out) {
    static_sk_color_filter_set(sk_color_filter_key_out, SkColorFilters::SRGBToLinearGamma());
}

void SkColorFilters_Table(int sk_color_filter_key_out, const uint8_t table[256]) {
    static_sk_color_filter_set(sk_color_filter_key_out, SkColorFilters::Table(table));
}

void SkColorFilters_Table_2(int sk_color_filter_key_out, int sk_color_table_key_in) {
    static_sk_color_filter_set(sk_color_filter_key_out, SkColorFilters::Table(static_sk_color_table_move(sk_color_table_key_in)));
}

void SkColorFilters_TableARGB(int sk_color_filter_key_out, const uint8_t tableA[256], const uint8_t tableR[256], const uint8_t tableG[256], const uint8_t tableB[256]) {
    static_sk_color_filter_set(sk_color_filter_key_out, SkColorFilters::TableARGB(tableA, tableR, tableG, tableB));
}

}