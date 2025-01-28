//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_TABLE_H
#define RAIA_SKIA_SK_COLOR_TABLE_H

#ifdef __cplusplus
extern "C" {
#endif

void SkColorTable_delete(void *color_table); // (SkColorTable *color_table)
const void * SkColorTable_alphaTable(void *color_table); // (SkColorTable *color_table) -> const uint8_t *
const void * SkColorTable_redTable(void *color_table); // (SkColorTable *color_table) -> const uint8_t *
const void * SkColorTable_greenTable(void *color_table); // (SkColorTable *color_table) -> const uint8_t *
const void * SkColorTable_blueTable(void *color_table); // (SkColorTable *color_table) -> const uint8_t *
void SkColorTable_flatten(void *color_table, void *buffer); // (SkColorTable *color_table, SkWriteBuffer *buffer)
bool SkColorTable_unique(void *color_table); // (SkColorTable *color_table) -> bool
void SkColorTable_ref(void *color_table); // (SkColorTable *color_table)
void SkColorTable_unref(void *color_table); // (SkColorTable *color_table)

// static

int SkColorTable_Make(const void * table); // (const uint8_t table[256]) -> sk_color_table_t
int SkColorTable_Make_2(const void * tableA, const void * tableR, const void * tableG, const void * tableB); // (const uint8_t tableA[256], const uint8_t tableR[256], const uint8_t tableG[256], const uint8_t tableB[256]) -> sk_color_table_t
int SkColorTable_Deserialize(void * buffer); // (SkReadBuffer *buffer) -> sk_color_table_t

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_COLOR_TABLE_H
