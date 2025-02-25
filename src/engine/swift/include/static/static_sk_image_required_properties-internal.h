#ifndef STATIC_SK_IMAGE_REQUIRED_PROPERTIES_INTERNAL_H
#define STATIC_SK_IMAGE_REQUIRED_PROPERTIES_INTERNAL_H
#include <set>
#include <map>
#include "include/core/SkImage.h"
int static_sk_image_required_properties_make(SkImage::RequiredProperties value);
SkImage::RequiredProperties static_sk_image_required_properties_get_entity(int key);
void static_sk_image_required_properties_set(int key, SkImage::RequiredProperties value);
#endif // STATIC_SK_IMAGE_REQUIRED_PROPERTIES_INTERNAL_H
