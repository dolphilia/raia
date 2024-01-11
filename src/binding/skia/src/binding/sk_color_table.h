//
// Created by dolphilia on 2024/01/08.
//

#ifndef RAIA_SKIA_SK_COLOR_TABLE_H
#define RAIA_SKIA_SK_COLOR_TABLE_H

#include "include/core/SkColorTable.h"
#include "../static/static_sk_color_table.h"

extern "C" {
const uint8_t * SkColorTable_alphaTable(SkColorTable *color_table);
const uint8_t * SkColorTable_redTable(SkColorTable *color_table);
const uint8_t * SkColorTable_greenTable(SkColorTable *color_table);
const uint8_t * SkColorTable_blueTable(SkColorTable *color_table);
void SkColorTable_flatten(SkColorTable *color_table, SkWriteBuffer *buffer);
bool SkColorTable_unique(SkColorTable *color_table);
void SkColorTable_ref(SkColorTable *color_table);
void SkColorTable_unref(SkColorTable *color_table);
// static
void SkColorTable_Make(const char *sk_color_table_key_out, const uint8_t table[256]);
void SkColorTable_Make_2(const char *sk_color_table_key_out, const uint8_t tableA[256], const uint8_t tableR[256], const uint8_t tableG[256], const uint8_t tableB[256]);
void SkColorTable_Deserialize(const char *sk_color_table_key_out, SkReadBuffer *buffer);
}

#endif //RAIA_SKIA_SK_COLOR_TABLE_H