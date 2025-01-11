//
// Created by dolphilia on 24/06/20.
//

#ifndef RESKIA_STATIC_SK_POINT_TWO_H
#define RESKIA_STATIC_SK_POINT_TWO_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkRect.h"
#include "export_api.h"

typedef int sk_point_two_t;

extern "C" {
int static_sk_point_two_make_float(float fx1, float fy1, float fx2, float fy2);
void static_sk_point_two_delete(int key);
SkPoint * static_sk_point_two_get_ptr(int key);
};

int static_sk_point_two_make(SkPoint value1, SkPoint value2);
void static_sk_point_two_set(int key, SkPoint value1, SkPoint value2);
//SkPoint static_sk_point_two_get(int key);

#endif //RESKIA_STATIC_SK_POINT_TWO_H
