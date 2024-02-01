//
// Created by dolphilia on 2024/01/11.
//

#include "static_std_tuple_int_sk_yuva_pixmap_info_data_type.h"

static std::set<int> static_tuple_int_sk_yuva_pixmap_info_data_type_available_keys;
static std::map<int , std::tuple<int, SkYUVAPixmapInfo::DataType>> static_tuple_int_sk_yuva_pixmap_info_data_type;
static int static_tuple_int_sk_yuva_pixmap_info_data_type_index = 0;

int static_tuple_int_sk_yuva_pixmap_info_data_type_make(std::tuple<int, SkYUVAPixmapInfo::DataType> value) {
    int key;
    if (!static_tuple_int_sk_yuva_pixmap_info_data_type_available_keys.empty()) {
        auto it = static_tuple_int_sk_yuva_pixmap_info_data_type_available_keys.begin();
        key = *it;
        static_tuple_int_sk_yuva_pixmap_info_data_type_available_keys.erase(it);
    } else {
        key = static_tuple_int_sk_yuva_pixmap_info_data_type_index++;
    }
    static_tuple_int_sk_yuva_pixmap_info_data_type[key] = value;
    return key;
}

void static_tuple_int_sk_yuva_pixmap_info_data_type_delete(int key) {
    static_tuple_int_sk_yuva_pixmap_info_data_type.erase(key);
    static_tuple_int_sk_yuva_pixmap_info_data_type_available_keys.insert(key);
}

std::tuple<int, SkYUVAPixmapInfo::DataType> static_tuple_int_sk_yuva_pixmap_info_data_type_get(int key, int index) {
    return static_tuple_int_sk_yuva_pixmap_info_data_type[key];
}

void static_tuple_int_sk_yuva_pixmap_info_data_type_set(int key, std::tuple<int, SkYUVAPixmapInfo::DataType> value) {
    static_tuple_int_sk_yuva_pixmap_info_data_type[key] = std::move(value);
}
