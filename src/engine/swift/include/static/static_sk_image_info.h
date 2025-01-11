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
#include "export_api.h"

typedef int sk_image_info_t;

extern "C" {
RAIA_API void static_sk_image_info_delete(int key);
RAIA_API SkImageInfo * static_sk_image_info_get_ptr(int key);
}

int static_sk_image_info_make(SkImageInfo value);
SkImageInfo static_sk_image_info_get(int key);
void static_sk_image_info_set(int key, SkImageInfo value);

#endif //RAIA_SKIA_STATIC_SK_IMAGE_INFO_H
