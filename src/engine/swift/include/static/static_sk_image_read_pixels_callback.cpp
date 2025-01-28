//
// Created by dolphilia on 2024/04/03.
//

#include "static_sk_image_read_pixels_callback.h"
#include "static_sk_image_read_pixels_callback-internal.h"

//#include <set>
//#include <string>
//#include <map>
//#include "include/core/SkFlattenable.h"
//#include "include/core/SkImage.h"
//
//typedef int sk_image_read_pixels_callback_t;
//
//static std::set<int> static_sk_image_read_pixels_callback_available_keys;
//static std::map<int , SkImage::ReadPixelsCallback> static_sk_image_read_pixels_callback;
//static int static_sk_image_read_pixels_callback_index = 0;
//
//int static_sk_image_read_pixels_callback_make(SkImage::ReadPixelsCallback value) {
//    int key;
//    if (!static_sk_image_read_pixels_callback_available_keys.empty()) {
//        auto it = static_sk_image_read_pixels_callback_available_keys.begin();
//        key = *it;
//        static_sk_image_read_pixels_callback_available_keys.erase(it);
//    } else {
//        key = static_sk_image_read_pixels_callback_index++;
//    }
//    static_sk_image_read_pixels_callback[key] = value;
//    return key;
//}
//
//void static_sk_flattenable_factory_delete(int key) {
//    static_sk_image_read_pixels_callback.erase(key);
//    static_sk_image_read_pixels_callback_available_keys.insert(key);
//}
//
//SkImage::ReadPixelsCallback static_sk_flattenable_factory_get(int key) {
//    return static_sk_image_read_pixels_callback.at(key);
//}
