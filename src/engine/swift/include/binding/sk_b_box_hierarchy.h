//
// Created by dolphilia on 2024/01/05.
//

#ifndef RAIA_SKIA_SK_B_BOX_HIERARCHY_H
#define RAIA_SKIA_SK_B_BOX_HIERARCHY_H

#ifdef __cplusplus
extern "C" {
#endif

void SkBBoxHierarchy_delete(void *b_box_hierarchy); // (SkBBoxHierarchy *b_box_hierarchy)
void SkBBoxHierarchy_insert(void *b_box_hierarchy, const void *rect, int N); // (SkBBoxHierarchy *b_box_hierarchy, const SkRect *rect, int N)
void SkBBoxHierarchy_insert_2(void *b_box_hierarchy, const void *rect, const void *metadata, int N); // (SkBBoxHierarchy *b_box_hierarchy, const SkRect *rect, const SkBBoxHierarchy::Metadata *metadata, int N)
void SkBBoxHierarchy_search(void *b_box_hierarchy, const void *query, int results); // (SkBBoxHierarchy *b_box_hierarchy, const SkRect *query, std::vector<int> *results)
unsigned long SkBBoxHierarchy_bytesUsed(void *b_box_hierarchy); // (SkBBoxHierarchy *b_box_hierarchy) -> size_t
bool SkBBoxHierarchy_unique(void *b_box_hierarchy); // (SkBBoxHierarchy *b_box_hierarchy) -> bool
void SkBBoxHierarchy_ref(void *b_box_hierarchy); // (SkBBoxHierarchy *b_box_hierarchy)
void SkBBoxHierarchy_unref(void *b_box_hierarchy); // (SkBBoxHierarchy *b_box_hierarchy)

#ifdef __cplusplus
}
#endif

#endif //RAIA_SKIA_SK_B_BOX_HIERARCHY_H
