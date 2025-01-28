//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_DATA_TABLE_H
#define RAIA_SKIA_STATIC_SK_DATA_TABLE_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_data_table_t;
void static_sk_data_table_delete(int key);
void *static_sk_data_table_get(int key); // -> SkDataTable *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_DATA_TABLE_H
