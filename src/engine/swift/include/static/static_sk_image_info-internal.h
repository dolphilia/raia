#ifndef STATIC_SK_IMAGE_INFO_INTERNAL_H
#define STATIC_SK_IMAGE_INFO_INTERNAL_H
#include <set>
#include <map>
#include <utility>
#include "include/core/SkImageInfo.h"
int static_sk_image_info_make(SkImageInfo value);
SkImageInfo static_sk_image_info_get_entity(int key);
void static_sk_image_info_set(int key, SkImageInfo value);
#endif // STATIC_SK_IMAGE_INFO_INTERNAL_H
