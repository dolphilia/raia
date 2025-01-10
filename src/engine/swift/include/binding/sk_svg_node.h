//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_NODE_H
#define RAIA_SKIA_SK_SVG_NODE_H

#include "modules/svg/include/SkSVGNode.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"

extern "C" {
void SkSVGNode_delete(SkSVGNode *svgNode);
SkSVGTag SkSVGNode_tag(SkSVGNode *svgNode);
void SkSVGNode_appendChild(SkSVGNode *svgNode, sk_svg_node_t svg_node);
void SkSVGNode_render(SkSVGNode *svgNode, const SkSVGRenderContext *svgRenderContext);
bool SkSVGNode_asPaint(SkSVGNode *svgNode, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGNode_asPath(SkSVGNode *svgNode, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGNode_objectBoundingBox(SkSVGNode *svgNode, const SkSVGRenderContext *svgRenderContext);
void SkSVGNode_setAttribute(SkSVGNode *svgNode, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGNode_setAttribute(SkSVGNode *svgNode, const char *attributeName, const char *attributeValue);
bool SkSVGNode_parseAndSetAttribute(SkSVGNode *svgNode, const char *name, const char *value);
bool SkSVGNode_unique(SkSVGNode *svgNode);
void SkSVGNode_ref(SkSVGNode *svgNode);
void SkSVGNode_unref(SkSVGNode *svgNode);
}

#endif //RAIA_SKIA_SK_SVG_NODE_H
