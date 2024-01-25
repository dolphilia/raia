//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_YUVA_INFO_H
#define RAIA_SKIA_STATIC_SK_YUVA_INFO_H

#include <string>
#include <map>
#include "include/core/SkYUVAInfo.h"

void static_sk_yuva_info_delete(int key);
SkYUVAInfo static_sk_yuva_info_get(int key);
void static_sk_yuva_info_set(int key, SkYUVAInfo value);

#endif //RAIA_SKIA_STATIC_SK_YUVA_INFO_H
