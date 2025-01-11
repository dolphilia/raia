//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_SK_B_BOX_HIERARCHY_H
#define RAIA_SKIA_STATIC_SK_B_BOX_HIERARCHY_H

#include <set>
#include <string>
#include <map>
#include "include/core/SkBBHFactory.h"
#include "export_api.h"

typedef int sk_b_box_hierarchy_t;

extern "C" {
RAIA_API void static_sk_b_box_hierarchy_delete(int key);
RAIA_API SkBBoxHierarchy *static_sk_b_box_hierarchy_get(int key);
}

int static_sk_b_box_hierarchy_make(sk_sp<SkBBoxHierarchy> value);
void static_sk_b_box_hierarchy_set(int key, sk_sp<SkBBoxHierarchy> value);
sk_sp<SkBBoxHierarchy> static_sk_b_box_hierarchy_move(int key);

#endif //RAIA_SKIA_STATIC_SK_B_BOX_HIERARCHY_H
