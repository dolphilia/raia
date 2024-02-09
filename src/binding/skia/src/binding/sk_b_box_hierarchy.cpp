//
// Created by dolphilia on 2024/01/05.
//

#include "sk_b_box_hierarchy.h"

extern "C" {

void SkBBoxHierarchy_delete(SkBBoxHierarchy *b_box_hierarchy) {
    delete b_box_hierarchy;
}

void SkBBoxHierarchy_insert(SkBBoxHierarchy *b_box_hierarchy, const SkRect rect[], int N) {
    b_box_hierarchy->insert(rect, N);
}

void SkBBoxHierarchy_insert_2(SkBBoxHierarchy *b_box_hierarchy, const SkRect rect[], const SkBBoxHierarchy::Metadata metadata[], int N) {
    b_box_hierarchy->insert(rect, metadata, N);
}

void SkBBoxHierarchy_search(SkBBoxHierarchy *b_box_hierarchy, const SkRect *query, std::vector<int> *results) { // @TODO
    b_box_hierarchy->search(*query, results);
}

size_t SkBBoxHierarchy_bytesUsed(SkBBoxHierarchy *b_box_hierarchy) {
    return b_box_hierarchy->bytesUsed();
}

bool SkBBoxHierarchy_unique(SkBBoxHierarchy *b_box_hierarchy) {
    return b_box_hierarchy->unique();
}

void SkBBoxHierarchy_ref(SkBBoxHierarchy *b_box_hierarchy) {
    b_box_hierarchy->ref();
}

void SkBBoxHierarchy_unref(SkBBoxHierarchy *b_box_hierarchy) {
    b_box_hierarchy->unref();
}

}