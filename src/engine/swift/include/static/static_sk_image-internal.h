#ifndef STATIC_SK_IMAGE_INTERNAL_H
#define STATIC_SK_IMAGE_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkImage.h"
int static_sk_image_make(sk_sp<SkImage> value);
void static_sk_image_set(int key, sk_sp<SkImage> value);
sk_sp<SkImage> static_sk_image_move(int key);
#endif // STATIC_SK_IMAGE_INTERNAL_H
