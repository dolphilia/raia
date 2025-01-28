//
// Created by dolphilia on 2024/01/12.
//

#include "static_sk_color.h"

#include <set>
#include <string>
#include <map>
#include "include/private/base/SkSpan_impl.h"
#include "include/core/SkColor.h"
#include "static_sk_color-internal.h"

// struct color_t {
//     int r;
//     int g;
//     int b;
//     int a;
// };
//
// static std::set<int> color_available_keys;
// static std::map<int, color_t> colors;
// static int color_index = 0;
//
// int static_sk_color_make(color_t value) {
//     int key;
//     if (!color_available_keys.empty()) {
//         auto it = color_available_keys.begin();
//         key = *it;
//         color_available_keys.erase(it);
//     } else {
//         key = color_index++;
//     }
//     colors[key] = value;
//     return key;
// }
//
// void static_sk_color_delete(int key) {
//     colors.erase(key);
//     color_available_keys.insert(key);
// }
//
// color_t static_sk_color_get(int key) {
//     return colors[key];
// }
//
// void static_sk_color_set(int key, color_t value) {
//     colors[key] = value;
// }
