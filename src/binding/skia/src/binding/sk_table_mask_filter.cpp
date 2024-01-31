//
// Created by dolphilia on 2024/01/11.
//

#include "sk_table_mask_filter.h"

extern "C" {

void SkTableMaskFilter_delete(SkTableMaskFilter *tableMaskFilter) {
    delete tableMaskFilter;
}

// static

void SkTableMaskFilter_MakeGammaTable(uint8_t table[256], SkScalar gamma) {
    SkTableMaskFilter::MakeGammaTable(table, gamma);
}

void SkTableMaskFilter_MakeClipTable(uint8_t table[256], uint8_t min, uint8_t max) {
    SkTableMaskFilter::MakeClipTable(table, min, max);
}

SkMaskFilter * SkTableMaskFilter_Create(const uint8_t table[256]) {
    return SkTableMaskFilter::Create(table);
}

SkMaskFilter * SkTableMaskFilter_CreateGamma(SkScalar gamma) {
    return SkTableMaskFilter::CreateGamma(gamma);
}

SkMaskFilter * SkTableMaskFilter_CreateClip(uint8_t min, uint8_t max) {
    return SkTableMaskFilter::CreateClip(min, max);
}

}