//
// Created by dolphilia on 2024/02/03.
//

#include "static_sk_svg_node.h"

static std::set<int> static_sk_svg_node_available_keys;
static std::map<int , sk_sp<SkSVGNode>> static_sk_svg_node;
static int static_sk_svg_node_index = 0;

int static_sk_svg_node_make(sk_sp<SkSVGNode> value) {
    int key;
    if (!static_sk_svg_node_available_keys.empty()) {
        auto it = static_sk_svg_node_available_keys.begin();
        key = *it;
        static_sk_svg_node_available_keys.erase(it);
    } else {
        key = static_sk_svg_node_index++;
    }
    static_sk_svg_node[key] = std::move(value);
    return key;
}

void static_sk_svg_node_delete(int key) {
    static_sk_svg_node[key].reset();
    static_sk_svg_node.erase(key);
    static_sk_svg_node_available_keys.insert(key);
}

SkSVGNode *static_sk_svg_node_get(int key) {
    return static_sk_svg_node[key].get();
}

void static_sk_svg_node_set(int key, sk_sp<SkSVGNode> value) {
    static_sk_svg_node[key] = std::move(value);
}

sk_sp<SkSVGNode> static_sk_svg_node_move(int key) {
    return std::move(static_sk_svg_node[key]);
}