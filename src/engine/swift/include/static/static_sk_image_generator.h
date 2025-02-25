//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_IMAGE_GENERATOR_H
#define RAIA_SKIA_STATIC_SK_IMAGE_GENERATOR_H

#ifdef __cplusplus
extern "C" {
#endif
typedef int sk_image_generator_t;
void static_sk_image_generator_delete(int key);
void *static_sk_image_generator_get_ptr(int key); // -> SkImageGenerator *
#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_IMAGE_GENERATOR_H
