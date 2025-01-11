//
// Created by dolphilia on 2024/01/11.
//

#ifndef RAIA_SKIA_STATIC_SK_YUVA_INFO_H
#define RAIA_SKIA_STATIC_SK_YUVA_INFO_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkYUVAInfo.h"
#include "export_api.h"

typedef int sk_yuva_info_t;

extern "C" {
RAIA_API void static_sk_yuva_info_delete(int key);
RAIA_API SkYUVAInfo * static_sk_yuva_info_get_ptr(int key);
}

int static_sk_yuva_info_make(SkYUVAInfo value);
SkYUVAInfo static_sk_yuva_info_get(int key);
void static_sk_yuva_info_set(int key, SkYUVAInfo value);

#endif //RAIA_SKIA_STATIC_SK_YUVA_INFO_H
