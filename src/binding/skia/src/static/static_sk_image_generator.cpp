//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_image_generator.h"

static std::map<int , std::unique_ptr<SkImageGenerator>> static_sk_image_generator;
static int static_sk_image_generator_index = 0;

int static_sk_image_generator_make(std::unique_ptr<SkImageGenerator> value) {
    static_sk_image_generator[static_sk_image_generator_index] = std::move(value);
    static_sk_image_generator_index++;
    return static_sk_image_generator_index - 1;
}

void static_sk_image_generator_delete(int key) {
    static_sk_image_generator[key].reset();
    static_sk_image_generator.erase(key);
}

SkImageGenerator *static_sk_image_generator_get(int key) {
    return static_sk_image_generator[key].get();
}

void static_sk_image_generator_set(int key, std::unique_ptr<SkImageGenerator> value) {
    static_sk_image_generator[key] = std::move(value);
}

std::unique_ptr<SkImageGenerator> static_sk_image_generator_move(int key) {
    return std::move(static_sk_image_generator[key]);
}