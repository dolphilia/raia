//
// Created by dolphilia on 2024/01/11.
//

#include "static_std_tuple_int_sk_yuva_pixmap_info_data_type.h"

static std::map<std::string, std::tuple<int, SkYUVAPixmapInfo::DataType>> static_tuple_int_sk_yuva_pixmap_info_data_type;

void static_tuple_int_sk_yuva_pixmap_info_data_type_delete(const char *key) {
    static_tuple_int_sk_yuva_pixmap_info_data_type.erase(key);
}

std::tuple<int, SkYUVAPixmapInfo::DataType> static_tuple_int_sk_yuva_pixmap_info_data_type_get(const char *key, int index) {
    return static_tuple_int_sk_yuva_pixmap_info_data_type[key];
}

void static_tuple_int_sk_yuva_pixmap_info_data_type_set(const char *key, std::tuple<int, SkYUVAPixmapInfo::DataType> value) {
    static_tuple_int_sk_yuva_pixmap_info_data_type[key] = std::move(value);
}
