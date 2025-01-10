//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_STATIC_SK_IMAGE_GENERATOR_H
#define RAIA_SKIA_STATIC_SK_IMAGE_GENERATOR_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkImageGenerator.h"

typedef int sk_image_generator_t;

int static_sk_image_generator_make(std::unique_ptr<SkImageGenerator> value);
extern "C" void static_sk_image_generator_delete(int key);
extern "C" SkImageGenerator *static_sk_image_generator_get(int key);
void static_sk_image_generator_set(int key, std::unique_ptr<SkImageGenerator> value);
std::unique_ptr<SkImageGenerator> static_sk_image_generator_move(int key);

#endif //RAIA_SKIA_STATIC_SK_IMAGE_GENERATOR_H
