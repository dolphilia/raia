//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_IMAGE_GENERATOR_H
#define RAIA_SKIA_STATIC_SK_IMAGE_GENERATOR_H

#include <string>
#include <map>
#include "include/core/SkImageGenerator.h"

void static_sk_image_generator_delete(const char *key);
SkImageGenerator *static_sk_image_generator_get(const char *key);
void static_sk_image_generator_set(const char *key, std::unique_ptr<SkImageGenerator> value);
std::unique_ptr<SkImageGenerator> static_sk_image_generator_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_IMAGE_GENERATOR_H
