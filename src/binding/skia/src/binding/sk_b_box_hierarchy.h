//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_SK_B_BOX_HIERARCHY_H
#define RAIA_SKIA_SK_B_BOX_HIERARCHY_H

#include "include/core/SkBBHFactory.h"

extern "C" {
void SkBBoxHierarchy_delete(SkBBoxHierarchy *b_box_hierarchy);
void SkBBoxHierarchy_insert(SkBBoxHierarchy *b_box_hierarchy, const SkRect rect[], int N);
void SkBBoxHierarchy_insert_2(SkBBoxHierarchy *b_box_hierarchy, const SkRect rect[], const SkBBoxHierarchy::Metadata metadata[], int N);
void SkBBoxHierarchy_search(SkBBoxHierarchy *b_box_hierarchy, const SkRect *query, std::vector<int> *results);
size_t SkBBoxHierarchy_bytesUsed(SkBBoxHierarchy *b_box_hierarchy);
bool SkBBoxHierarchy_unique(SkBBoxHierarchy *b_box_hierarchy);
void SkBBoxHierarchy_ref(SkBBoxHierarchy *b_box_hierarchy);
void SkBBoxHierarchy_unref(SkBBoxHierarchy *b_box_hierarchy);
}

#endif //RAIA_SKIA_SK_B_BOX_HIERARCHY_H
