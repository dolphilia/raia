//
// Created by dolphilia on 2024/01/08.
//

#include "sk_color_table.h"

extern "C" {

void SkColorTable_delete(SkColorTable *color_table) {
    delete color_table;
}

const uint8_t * SkColorTable_alphaTable(SkColorTable *color_table) {
    return color_table->alphaTable();
}

const uint8_t * SkColorTable_redTable(SkColorTable *color_table) {
    return color_table->redTable();
}

const uint8_t * SkColorTable_greenTable(SkColorTable *color_table) {
    return color_table->greenTable();
}

const uint8_t * SkColorTable_blueTable(SkColorTable *color_table) {
    return color_table->blueTable();
}

void SkColorTable_flatten(SkColorTable *color_table, SkWriteBuffer *buffer) {
    color_table->flatten(*buffer);
}

bool SkColorTable_unique(SkColorTable *color_table) {
    return color_table->unique();
}

void SkColorTable_ref(SkColorTable *color_table) {
    return color_table->ref();
}

void SkColorTable_unref(SkColorTable *color_table) {
    color_table->unref();
}

// static

sk_color_table_t SkColorTable_Make(const uint8_t table[256]) {
    return static_sk_color_table_make(SkColorTable::Make(table));
}

sk_color_table_t SkColorTable_Make_2(const uint8_t tableA[256], const uint8_t tableR[256], const uint8_t tableG[256], const uint8_t tableB[256]) {
    return static_sk_color_table_make(SkColorTable::Make(tableA, tableR, tableG, tableB));
}

sk_color_table_t SkColorTable_Deserialize(SkReadBuffer *buffer) {
    return static_sk_color_table_make(SkColorTable::Deserialize(*buffer));
}

}