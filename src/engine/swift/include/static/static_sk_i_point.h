//
// Created by dolphilia on 2024/03/30.
//

#ifndef RAIA_SKIA_STATIC_SK_I_POINT_H
#define RAIA_SKIA_STATIC_SK_I_POINT_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkRect.h"

typedef int sk_i_point_t;

int static_sk_i_point_make(SkIPoint value);
extern "C" void static_sk_i_point_delete(int key);
SkIPoint static_sk_i_point_get(int key);
void static_sk_i_point_set(int key, SkIPoint value);

#endif //RAIA_SKIA_STATIC_SK_I_POINT_H
