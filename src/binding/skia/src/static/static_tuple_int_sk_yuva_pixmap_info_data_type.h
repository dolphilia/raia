//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_TUPLE_INT_SK_YUVA_PIXMAP_INFO_DATA_TYPE_H
#define RAIA_SKIA_STATIC_TUPLE_INT_SK_YUVA_PIXMAP_INFO_DATA_TYPE_H

#include <string>
#include <map>
#include <tuple>
#include "include/core/SkYUVAPixmaps.h"

void static_tuple_int_sk_yuva_pixmap_info_data_type_delete(const char *key);
std::tuple<int, SkYUVAPixmapInfo::DataType> static_tuple_int_sk_yuva_pixmap_info_data_type_get(const char *key, int index);
void static_tuple_int_sk_yuva_pixmap_info_data_type_set(const char *key, std::tuple<int, SkYUVAPixmapInfo::DataType> value);

#endif //RAIA_SKIA_STATIC_TUPLE_INT_SK_YUVA_PIXMAP_INFO_DATA_TYPE_H
