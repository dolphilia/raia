#ifndef STATIC_SK_DATA_INTERNAL_H
#define STATIC_SK_DATA_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkData.h"
int static_sk_data_make(sk_sp<SkData> value);
void static_sk_data_set(int key, sk_sp<SkData> value);
sk_sp<SkData> static_sk_data_get_entity(int key);
// const
int static_const_sk_data_make(sk_sp<const SkData> value);
void static_const_sk_data_set(int key, sk_sp<const SkData> value);
sk_sp<const SkData> static_const_sk_data_get_entity(int key);
#endif // STATIC_SK_DATA_INTERNAL_H
