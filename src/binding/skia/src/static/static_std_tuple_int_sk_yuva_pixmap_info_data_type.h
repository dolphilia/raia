//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_STD_TUPLE_INT_SK_YUVA_PIXMAP_INFO_DATA_TYPE_H
#define RAIA_SKIA_STATIC_STD_TUPLE_INT_SK_YUVA_PIXMAP_INFO_DATA_TYPE_H

#include <set>
#include <string>
#include <map>
#include <tuple>
#include "include/core/SkYUVAPixmaps.h"

typedef int tuple_int_sk_yuva_pixmap_info_data_type_t;

int static_tuple_int_sk_yuva_pixmap_info_data_type_make(std::tuple<int, SkYUVAPixmapInfo::DataType> value);
extern "C" void static_tuple_int_sk_yuva_pixmap_info_data_type_delete(int key);
std::tuple<int, SkYUVAPixmapInfo::DataType> static_tuple_int_sk_yuva_pixmap_info_data_type_get(int key, int index);
void static_tuple_int_sk_yuva_pixmap_info_data_type_set(int key, std::tuple<int, SkYUVAPixmapInfo::DataType> value);

#endif //RAIA_SKIA_STATIC_STD_TUPLE_INT_SK_YUVA_PIXMAP_INFO_DATA_TYPE_H
