//
// Created by dolphilia on 2024/02/06.
//

#include "static_sk_svg_fe_flood.h"

static std::set<int> static_sk_svg_fe_flood_available_keys;
static std::map<int , sk_sp<SkSVGFeFlood>> static_sk_svg_fe_flood;
static int static_sk_svg_fe_flood_index = 0;

int static_sk_svg_fe_flood_make(sk_sp<SkSVGFeFlood> value) {
    int key;
    if (!static_sk_svg_fe_flood_available_keys.empty()) {
        auto it = static_sk_svg_fe_flood_available_keys.begin();
        key = *it;
        static_sk_svg_fe_flood_available_keys.erase(it);
    } else {
        key = static_sk_svg_fe_flood_index++;
    }
    static_sk_svg_fe_flood[key] = std::move(value);
    return key;
}

void static_sk_svg_fe_flood_delete(int key) {
    static_sk_svg_fe_flood[key].reset();
    static_sk_svg_fe_flood.erase(key);
    static_sk_svg_fe_flood_available_keys.insert(key);
}

SkSVGFeFlood *static_sk_svg_fe_flood_get(int key) {
    return static_sk_svg_fe_flood[key].get();
}

void static_sk_svg_fe_flood_set(int key, sk_sp<SkSVGFeFlood> value) {
    static_sk_svg_fe_flood[key] = std::move(value);
}

sk_sp<SkSVGFeFlood> static_sk_svg_fe_flood_move(int key) {
    return std::move(static_sk_svg_fe_flood[key]);
}