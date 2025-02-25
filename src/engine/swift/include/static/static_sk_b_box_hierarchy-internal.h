//
// Created by dolphilia on 25/01/11.
//
#ifndef STATIC_SK_B_BOX_HIERARCHY_INTERNAL_H
#define STATIC_SK_B_BOX_HIERARCHY_INTERNAL_H
#include "include/core/SkBBHFactory.h"
#include <set>
#include <map>
int static_sk_b_box_hierarchy_make(sk_sp<SkBBoxHierarchy> value);
void static_sk_b_box_hierarchy_set(int key, sk_sp<SkBBoxHierarchy> value);
sk_sp<SkBBoxHierarchy> static_sk_b_box_hierarchy_get_entity(int key);
#endif //STATIC_SK_B_BOX_HIERARCHY_INTERNAL_H
