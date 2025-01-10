//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_DATA_H
#define RAIA_SKIA_STATIC_SK_DATA_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkData.h"

typedef int sk_data_t;
typedef int const_sk_data_t;

int static_sk_data_make(sk_sp<SkData> value);
extern "C" void static_sk_data_delete(int key);
extern "C" SkData *static_sk_data_get(int key);
void static_sk_data_set(int key, sk_sp<SkData> value);
sk_sp<SkData> static_sk_data_move(int key);
// const
int static_const_sk_data_make(sk_sp<const SkData> value);
extern "C" void static_const_sk_data_delete(int key);
extern "C" const SkData *static_const_sk_data_get(int key);
void static_const_sk_data_set(int key, sk_sp<const SkData> value);
sk_sp<const SkData> static_const_sk_data_move(int key);

#endif //RAIA_SKIA_STATIC_SK_DATA_H
