//
// Created by dolphilia on 2024/02/03.
//

#ifndef RAIA_SKIA_STATIC_SK_SVG_NODE_H
#define RAIA_SKIA_STATIC_SK_SVG_NODE_H

#include <set>
#include <string>
#include <map>
#include "modules/svg/include/SkSVGNode.h"

typedef int sk_svg_node_t;

int static_sk_svg_node_make(sk_sp<SkSVGNode> value);
extern "C" void static_sk_svg_node_delete(int key);
extern "C" SkSVGNode *static_sk_svg_node_get(int key);
void static_sk_svg_node_set(int key, sk_sp<SkSVGNode> value);
sk_sp<SkSVGNode> static_sk_svg_node_move(int key);

#endif //RAIA_SKIA_STATIC_SK_SVG_NODE_H
