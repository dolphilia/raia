//
// Created by dolphilia on 2024/01/12.
//

#ifndef RAIA_SKIA_STATIC_SK_B_BOX_HIERARCHY_H
#define RAIA_SKIA_STATIC_SK_B_BOX_HIERARCHY_H

#ifdef __cplusplus
extern "C" {
#endif

typedef int sk_b_box_hierarchy_t;

void static_sk_b_box_hierarchy_delete(int key);
void *static_sk_b_box_hierarchy_get(int key); // -> SkBBoxHierarchy

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_STATIC_SK_B_BOX_HIERARCHY_H
