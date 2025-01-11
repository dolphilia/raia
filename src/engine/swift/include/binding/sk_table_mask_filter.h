//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_TABLE_MASK_FILTER_H
#define RAIA_SKIA_SK_TABLE_MASK_FILTER_H

#include "include/effects/SkTableMaskFilter.h"
#include "export_api.h"

extern "C" {
RAIA_API void SkTableMaskFilter_delete(SkTableMaskFilter *tableMaskFilter);
// static
RAIA_API void SkTableMaskFilter_MakeGammaTable(uint8_t table[256], SkScalar gamma);
RAIA_API void SkTableMaskFilter_MakeClipTable(uint8_t table[256], uint8_t min, uint8_t max);
RAIA_API SkMaskFilter * SkTableMaskFilter_Create(const uint8_t table[256]);
RAIA_API SkMaskFilter * SkTableMaskFilter_CreateGamma(SkScalar gamma);
RAIA_API SkMaskFilter * SkTableMaskFilter_CreateClip(uint8_t min, uint8_t max);
}

#endif //RAIA_SKIA_SK_TABLE_MASK_FILTER_H
