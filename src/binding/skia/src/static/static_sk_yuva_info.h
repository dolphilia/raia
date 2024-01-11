//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_YUVA_INFO_H
#define RAIA_SKIA_STATIC_SK_YUVA_INFO_H

#include <string>
#include <map>
#include "include/core/SkYUVAInfo.h"

void static_sk_yuva_info_delete(const char *key);
SkYUVAInfo static_sk_yuva_info_get(const char *key);
void static_sk_yuva_info_set(const char *key, SkYUVAInfo value);

#endif //RAIA_SKIA_STATIC_SK_YUVA_INFO_H
