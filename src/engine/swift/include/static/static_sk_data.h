//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_DATA_H
#define RAIA_SKIA_STATIC_SK_DATA_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkData.h"
#include "export_api.h"

typedef int sk_data_t;
typedef int const_sk_data_t;

extern "C" {
RAIA_API void static_sk_data_delete(int key);
RAIA_API SkData *static_sk_data_get(int key);
// const
RAIA_API void static_const_sk_data_delete(int key);
RAIA_API const SkData *static_const_sk_data_get(int key);
}

int static_sk_data_make(sk_sp<SkData> value);
void static_sk_data_set(int key, sk_sp<SkData> value);
sk_sp<SkData> static_sk_data_move(int key);
// const
int static_const_sk_data_make(sk_sp<const SkData> value);
void static_const_sk_data_set(int key, sk_sp<const SkData> value);
sk_sp<const SkData> static_const_sk_data_move(int key);

#endif //RAIA_SKIA_STATIC_SK_DATA_H
