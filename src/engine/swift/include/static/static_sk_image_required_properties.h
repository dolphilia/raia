//
// Created by dolphilia on 2024/04/03.
//

#ifndef RAIA_SKIA_STATIC_SK_IMAGE_REQUIRED_PROPERTIES_H
#define RAIA_SKIA_STATIC_SK_IMAGE_REQUIRED_PROPERTIES_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_image_required_properties_t;
void static_sk_image_required_properties_delete(int key);
void * static_sk_image_required_properties_get_ptr(int key); // -> SkImage::RequiredProperties *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_IMAGE_REQUIRED_PROPERTIES_H
