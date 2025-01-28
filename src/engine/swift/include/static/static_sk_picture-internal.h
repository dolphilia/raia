#ifndef STATIC_SK_PICTURE_INTERNAL_H
#define STATIC_SK_PICTURE_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkPicture.h"
int static_sk_picture_make(sk_sp<SkPicture> value);
void static_sk_picture_set(int key, sk_sp<SkPicture> value);
sk_sp<SkPicture> static_sk_picture_move(int key);
#endif // STATIC_SK_PICTURE_INTERNAL_H
