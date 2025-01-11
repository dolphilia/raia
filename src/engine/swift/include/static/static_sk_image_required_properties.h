//
// Created by dolphilia on 2024/04/03.
//

#ifndef RAIA_SKIA_STATIC_SK_IMAGE_REQUIRED_PROPERTIES_H
#define RAIA_SKIA_STATIC_SK_IMAGE_REQUIRED_PROPERTIES_H

#include <set>
#include <map>
#include "include/core/SkImage.h"
#include "export_api.h"

typedef int sk_image_required_properties_t;

extern "C" {
RAIA_API void static_sk_image_required_properties_delete(int key);
RAIA_API SkImage::RequiredProperties * static_sk_image_required_properties_get_ptr(int key);
}

int static_sk_image_required_properties_make(SkImage::RequiredProperties value);
SkImage::RequiredProperties static_sk_image_required_properties_get(int key);
void static_sk_image_required_properties_set(int key, SkImage::RequiredProperties value);

#endif //RAIA_SKIA_STATIC_SK_IMAGE_REQUIRED_PROPERTIES_H
