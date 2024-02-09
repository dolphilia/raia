//
// Created by dolphilia on 2024/02/05.
//

#ifndef RAIA_SKIA_STATIC_STD_VECTOR_SK_SVG_LENGTH_H
#define RAIA_SKIA_STATIC_STD_VECTOR_SK_SVG_LENGTH_H

#include "modules/svg/include/SkSVGTypes.h"
#include <set>
#include <map>
#include <vector>

typedef int vector_sk_svg_length_t;

extern "C" {
void static_vector_sk_svg_length_delete(int key);
void static_vector_sk_svg_length_pop_back(int key);
void static_vector_sk_svg_length_erase(int key, int index);
}

int static_vector_sk_svg_length_make(std::vector<SkSVGLength> value);
SkSVGLength static_vector_sk_svg_length_get(int key, int index);
void static_vector_sk_svg_length_set(int key, std::vector<SkSVGLength> value);
void static_vector_sk_svg_length_push_back(int key, SkSVGLength value);
void static_vector_sk_svg_length_insert(int key, int index, SkSVGLength value);

#endif //RAIA_SKIA_STATIC_STD_VECTOR_SK_SVG_LENGTH_H
