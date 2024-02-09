//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_image.h"
//#include "modules/svg/include/SkSVGImage.h"
#include <set>
#include <map>

/*
static std::set<int> static_sk_svg_@_available_keys;
static std::map<int , sk_sp<SkSVG$>> static_sk_svg_@;
static int static_sk_svg_@_index = 0;

int static_sk_svg_@_make(sk_sp<SkSVG$> value) {
int key;
if (!static_sk_svg_@_available_keys.empty()) {
auto it = static_sk_svg_@_available_keys.begin();
key = *it;
static_sk_svg_@_available_keys.erase(it);
} else {
key = static_sk_svg_@_index++;
}
static_sk_svg_@[key] = std::move(value);
return key;
}

void static_sk_svg_@_delete(int key) {
    static_sk_svg_@[key].reset();
    static_sk_svg_@.erase(key);
    static_sk_svg_@_available_keys.insert(key);
}

SkSVG$ *static_sk_svg_@_get(int key) {
    return static_sk_svg_@[key].get();
}

void static_sk_svg_@_set(int key, sk_sp<SkSVG$> value) {
    static_sk_svg_@[key] = std::move(value);
}

sk_sp<SkSVG$> static_sk_svg_@_move(int key) {
    return std::move(static_sk_svg_@[key]);
}
*/