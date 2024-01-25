//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_DATA_H
#define RAIA_SKIA_STATIC_SK_DATA_H

#include <string>
#include <map>
#include "include/core/SkData.h"

void static_sk_data_delete(int key);
SkData *static_sk_data_get(int key);
void static_sk_data_set(int key, sk_sp<SkData> value);
sk_sp<SkData> static_sk_data_move(int key);
// const

void static_const_sk_data_delete(int key);
const SkData *static_const_sk_data_get(int key);
void static_const_sk_data_set(int key, sk_sp<const SkData> value);
sk_sp<const SkData> static_const_sk_data_move(int key);

#endif //RAIA_SKIA_STATIC_SK_DATA_H
