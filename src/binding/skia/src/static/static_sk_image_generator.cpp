//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_image_generator.h"

static std::map<std::string, std::unique_ptr<SkImageGenerator>> static_sk_image_generator;

void static_sk_image_generator_delete(const char *key) {
    static_sk_image_generator[key].reset();
    static_sk_image_generator.erase(key);
}

SkImageGenerator *static_sk_image_generator_get(const char *key) {
    return static_sk_image_generator[key].get();
}

void static_sk_image_generator_set(const char *key, std::unique_ptr<SkImageGenerator> value) {
    static_sk_image_generator[key] = std::move(value);
}

std::unique_ptr<SkImageGenerator> static_sk_image_generator_move(const char *key) {
    return std::move(static_sk_image_generator[key]);
}