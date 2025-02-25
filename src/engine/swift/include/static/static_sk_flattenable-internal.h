#ifndef STATIC_SK_FLATTENABLE_INTERNAL_H
#define STATIC_SK_FLATTENABLE_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkFlattenable.h"
int static_sk_flattenable_make(sk_sp<SkFlattenable> value);
void static_sk_flattenable_set(int key, sk_sp<SkFlattenable> value);
sk_sp<SkFlattenable> static_sk_flattenable_get_entity(int key);
#endif // STATIC_SK_FLATTENABLE_INTERNAL_H
