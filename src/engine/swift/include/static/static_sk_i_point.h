//
// Created by dolphilia on 2024/03/30.
//

#ifndef RAIA_SKIA_STATIC_SK_I_POINT_H
#define RAIA_SKIA_STATIC_SK_I_POINT_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkRect.h"
#include "export_api.h"

typedef int sk_i_point_t;

extern "C" {
RAIA_API void static_sk_i_point_delete(int key);
RAIA_API SkIPoint * static_sk_i_point_get_ptr(int key);
}

int static_sk_i_point_make(SkIPoint value);
SkIPoint static_sk_i_point_get(int key);
void static_sk_i_point_set(int key, SkIPoint value);

#endif //RAIA_SKIA_STATIC_SK_I_POINT_H
