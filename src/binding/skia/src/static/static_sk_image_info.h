//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_IMAGE_INFO_H
#define RAIA_SKIA_STATIC_SK_IMAGE_INFO_H

#include <string>
#include <map>
#include <utility>
#include "include/core/SkImageInfo.h"

void static_sk_image_info_delete(const char *key);
SkImageInfo static_sk_image_info_get(const char *key);
void static_sk_image_info_set(const char *key, SkImageInfo value);

#endif //RAIA_SKIA_STATIC_SK_IMAGE_INFO_H
