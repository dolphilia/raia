//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_SK_B_BOX_HIERARCHY_H
#define RAIA_SKIA_STATIC_SK_B_BOX_HIERARCHY_H

#include <string>
#include <map>
#include "include/core/SkBBHFactory.h"

int static_sk_b_box_hierarchy_make(sk_sp<SkBBoxHierarchy> value);
void static_sk_b_box_hierarchy_delete(int key);
SkBBoxHierarchy *static_sk_b_box_hierarchy_get(int key);
void static_sk_b_box_hierarchy_set(int key, sk_sp<SkBBoxHierarchy> value);
sk_sp<SkBBoxHierarchy> static_sk_b_box_hierarchy_move(int key);

#endif //RAIA_SKIA_STATIC_SK_B_BOX_HIERARCHY_H
