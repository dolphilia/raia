//
// Created by dolphilia on 2024/02/06.
//

#ifndef RAIA_SKIA_SK_SVG_TRANSFORMABLE_NODE_H
#define RAIA_SKIA_SK_SVG_TRANSFORMABLE_NODE_H

#include "modules/svg/include/SkSVGTransformableNode.h"
#include "../static/static_sk_svg_node.h"
#include "../static/static_sk_path.h"
#include "../static/static_sk_rect.h"

extern "C" {
void SkSVGTransformableNode_delete(SkSVGTransformableNode *svgTransformableNode);
void SkSVGTransformableNode_setTransform(SkSVGTransformableNode *svgTransformableNode, const SkSVGTransformType *t);
SkSVGTag SkSVGTransformableNode_tag(SkSVGTransformableNode *svgTransformableNode);
void SkSVGTransformableNode_appendChild(SkSVGTransformableNode *svgTransformableNode, sk_svg_node_t svg_node);
void SkSVGTransformableNode_render(SkSVGTransformableNode *svgTransformableNode, const SkSVGRenderContext *svgRenderContext);
bool SkSVGTransformableNode_asPaint(SkSVGTransformableNode *svgTransformableNode, const SkSVGRenderContext *svgRenderContext, SkPaint *paint);
sk_path_t SkSVGTransformableNode_asPath(SkSVGTransformableNode *svgTransformableNode, const SkSVGRenderContext *svgRenderContext);
sk_rect_t SkSVGTransformableNode_objectBoundingBox(SkSVGTransformableNode *svgTransformableNode, const SkSVGRenderContext *svgRenderContext);
void SkSVGTransformableNode_setAttribute(SkSVGTransformableNode *svgTransformableNode, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue);
// bool SkSVGTransformableNode_setAttribute(SkSVGTransformableNode *svgTransformableNode, const char *attributeName, const char *attributeValue);
bool SkSVGTransformableNode_parseAndSetAttribute(SkSVGTransformableNode *svgTransformableNode, const char *name, const char *value);
bool SkSVGTransformableNode_unique(SkSVGTransformableNode *svgTransformableNode);
void SkSVGTransformableNode_ref(SkSVGTransformableNode *svgTransformableNode);
void SkSVGTransformableNode_unref(SkSVGTransformableNode *svgTransformableNode);
}

#endif //RAIA_SKIA_SK_SVG_TRANSFORMABLE_NODE_H
