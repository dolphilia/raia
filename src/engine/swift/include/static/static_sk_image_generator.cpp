//
// Created by dolphilia on 2024/01/05.
//

#include "static_sk_image_generator.h"
#include "static_sk_image_generator-internal.h"

static std::set<int> static_sk_image_generator_available_keys;
static std::map<int , std::unique_ptr<SkImageGenerator>> static_sk_image_generator;
static int static_sk_image_generator_index = 0;

int static_sk_image_generator_make(std::unique_ptr<SkImageGenerator> value) {
    int key;
    if (!static_sk_image_generator_available_keys.empty()) {
        auto it = static_sk_image_generator_available_keys.begin();
        key = *it;
        static_sk_image_generator_available_keys.erase(it);
    } else {
        key = static_sk_image_generator_index++;
    }
    static_sk_image_generator[key] = std::move(value);
    return key;
}

void static_sk_image_generator_delete(int key) {
    static_sk_image_generator[key].reset();
    static_sk_image_generator.erase(key);
    static_sk_image_generator_available_keys.insert(key);
}

void *static_sk_image_generator_get(int key) { // -> SkImageGenerator *
    return static_sk_image_generator[key].get();
}

void static_sk_image_generator_set(int key, std::unique_ptr<SkImageGenerator> value) {
    static_sk_image_generator[key] = std::move(value);
}

std::unique_ptr<SkImageGenerator> static_sk_image_generator_move(int key) {
    return std::move(static_sk_image_generator[key]);
}
