//
// Created by dolphilia on 2024/02/08.
//

#include "static_sk_svg_presentation_attributes.h"

static std::set<int> static_sk_svg_presentation_attributes_available_keys;
static std::map<int , SkSVGPresentationAttributes> static_sk_svg_presentation_attributes;
static int static_sk_svg_presentation_attributes_index = 0;

int static_sk_svg_presentation_attributes_make(SkSVGPresentationAttributes value) {
    int key;
    if (!static_sk_svg_presentation_attributes_available_keys.empty()) {
        auto it = static_sk_svg_presentation_attributes_available_keys.begin();
        key = *it;
        static_sk_svg_presentation_attributes_available_keys.erase(it);
    } else {
        key = static_sk_svg_presentation_attributes_index++;
    }
    static_sk_svg_presentation_attributes[key] = std::move(value);
    return key;
}

void static_sk_svg_presentation_attributes_delete(int key) {
    static_sk_svg_presentation_attributes.erase(key);
    static_sk_svg_presentation_attributes_available_keys.insert(key);
}

SkSVGPresentationAttributes static_sk_svg_presentation_attributes_get(int key) {
    return static_sk_svg_presentation_attributes[key];
}

void static_sk_svg_presentation_attributes_set(int key, SkSVGPresentationAttributes value) {
    static_sk_svg_presentation_attributes[key] = std::move(value);
}