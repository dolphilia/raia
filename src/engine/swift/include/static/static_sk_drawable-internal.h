#ifndef STATIC_SK_DRAWABLE_INTERNAL_H
#define STATIC_SK_DRAWABLE_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkDrawable.h"
int static_sk_drawable_make(sk_sp<SkDrawable> value);
void static_sk_drawable_set(int key, sk_sp<SkDrawable> value);
sk_sp<SkDrawable> static_sk_drawable_get_entity(int key);
#endif // STATIC_SK_DRAWABLE_INTERNAL_H
