//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_IMAGE_INFO_H
#define RAIA_SKIA_STATIC_SK_IMAGE_INFO_H

#include <set>
#include <string>
#include <map>
#include <utility>
#include "include/core/SkImageInfo.h"

typedef int sk_image_info_t;

int static_sk_image_info_make(SkImageInfo value);
extern "C" void static_sk_image_info_delete(int key);
SkImageInfo static_sk_image_info_get(int key);
void static_sk_image_info_set(int key, SkImageInfo value);

#endif //RAIA_SKIA_STATIC_SK_IMAGE_INFO_H
