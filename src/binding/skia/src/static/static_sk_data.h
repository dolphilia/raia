//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_DATA_H
#define RAIA_SKIA_STATIC_SK_DATA_H

#include <string>
#include <map>
#include "include/core/SkData.h"

void static_sk_data_delete(const char *key);
SkData *static_sk_data_get(const char *key);
void static_sk_data_set(const char *key, sk_sp<SkData> value);
sk_sp<SkData> static_sk_data_move(const char *key);
// const

void static_const_sk_data_delete(const char *key);
const SkData *static_const_sk_data_get(const char *key);
void static_const_sk_data_set(const char *key, sk_sp<const SkData> value);
sk_sp<const SkData> static_const_sk_data_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_DATA_H
