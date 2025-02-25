#ifndef STATIC_SK_TYPEFACE_INTERNAL_H
#define STATIC_SK_TYPEFACE_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkTypeface.h"
int static_sk_typeface_make(sk_sp<SkTypeface> value);
void static_sk_typeface_set(int key, sk_sp<SkTypeface> value);
sk_sp<SkTypeface> static_sk_typeface_get_entity(int key);
#endif // STATIC_SK_TYPEFACE_INTERNAL_H
