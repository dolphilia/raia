//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_SK_TABLE_MASK_FILTER_H
#define RAIA_SKIA_SK_TABLE_MASK_FILTER_H

#ifdef __cplusplus
extern "C" {
#endif

void SkTableMaskFilter_delete(void *tableMaskFilter); // (SkTableMaskFilter *tableMaskFilter)

// static

void SkTableMaskFilter_MakeGammaTable(void * table, float gamma); // (uint8_t table[256], SkScalar gamma)
void SkTableMaskFilter_MakeClipTable(void * table, unsigned char min, unsigned char max); // (uint8_t table[256], uint8_t min, uint8_t max)
void * SkTableMaskFilter_Create(const void * table); // (const uint8_t table[256]) -> SkMaskFilter *
void * SkTableMaskFilter_CreateGamma(float gamma); // (SkScalar gamma) -> SkMaskFilter *
void * SkTableMaskFilter_CreateClip(unsigned char min, unsigned char max); // (uint8_t min, uint8_t max) -> SkMaskFilter *

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_TABLE_MASK_FILTER_H
