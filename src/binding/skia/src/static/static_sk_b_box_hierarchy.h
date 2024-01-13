//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_SK_B_BOX_HIERARCHY_H
#define RAIA_SKIA_STATIC_SK_B_BOX_HIERARCHY_H

#include <string>
#include <map>
#include "include/core/SkBBHFactory.h"

void static_sk_b_box_hierarchy_delete(const char *key);
SkBBoxHierarchy *static_sk_b_box_hierarchy_get(const char *key);
void static_sk_b_box_hierarchy_set(const char *key, sk_sp<SkBBoxHierarchy> value);
sk_sp<SkBBoxHierarchy> static_sk_b_box_hierarchy_move(const char *key);

#endif //RAIA_SKIA_STATIC_SK_B_BOX_HIERARCHY_H
