//
// Created by dolphilia on 2024/01/12.
//

#include "static_sk_b_box_hierarchy.h"

static std::map<std::string, sk_sp<SkBBoxHierarchy>> static_sk_b_box_hierarchy;

void static_sk_b_box_hierarchy_delete(const char *key) {
    static_sk_b_box_hierarchy[key].reset();
    static_sk_b_box_hierarchy.erase(key);
}

SkBBoxHierarchy *static_sk_b_box_hierarchy_get(const char *key) {
    return static_sk_b_box_hierarchy[key].get();
}

void static_sk_b_box_hierarchy_set(const char *key, sk_sp<SkBBoxHierarchy> value) {
    static_sk_b_box_hierarchy[key] = std::move(value);
}

sk_sp<SkBBoxHierarchy> static_sk_b_box_hierarchy_move(const char *key) {
    return std::move(static_sk_b_box_hierarchy[key]);
}