//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_fe_morphology.h"

static std::set<int> static_sk_svg_fe_morphology_available_keys;
static std::map<int , sk_sp<SkSVGFeMorphology>> static_sk_svg_fe_morphology;
static int static_sk_svg_fe_morphology_index = 0;

int static_sk_svg_fe_morphology_make(sk_sp<SkSVGFeMorphology> value) {
    int key;
    if (!static_sk_svg_fe_morphology_available_keys.empty()) {
        auto it = static_sk_svg_fe_morphology_available_keys.begin();
        key = *it;
        static_sk_svg_fe_morphology_available_keys.erase(it);
    } else {
        key = static_sk_svg_fe_morphology_index++;
    }
    static_sk_svg_fe_morphology[key] = std::move(value);
    return key;
}

void static_sk_svg_fe_morphology_delete(int key) {
    static_sk_svg_fe_morphology[key].reset();
    static_sk_svg_fe_morphology.erase(key);
    static_sk_svg_fe_morphology_available_keys.insert(key);
}

SkSVGFeMorphology *static_sk_svg_fe_morphology_get(int key) {
    return static_sk_svg_fe_morphology[key].get();
}

void static_sk_svg_fe_morphology_set(int key, sk_sp<SkSVGFeMorphology> value) {
    static_sk_svg_fe_morphology[key] = std::move(value);
}

sk_sp<SkSVGFeMorphology> static_sk_svg_fe_morphology_move(int key) {
    return std::move(static_sk_svg_fe_morphology[key]);
}
