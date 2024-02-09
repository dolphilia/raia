//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_node.h"

extern "C" {

void SkSVGNode_delete(SkSVGNode *svgNode) {
    delete svgNode;
}

SkSVGTag SkSVGNode_tag(SkSVGNode *svgNode) {
    return svgNode->tag();
}

void SkSVGNode_appendChild(SkSVGNode *svgNode, sk_svg_node_t svg_node) {
    svgNode->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGNode_render(SkSVGNode *svgNode, const SkSVGRenderContext *svgRenderContext) {
    svgNode->render(*svgRenderContext);
}

bool SkSVGNode_asPaint(SkSVGNode *svgNode, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgNode->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGNode_asPath(SkSVGNode *svgNode, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgNode->asPath(*svgRenderContext));
}

sk_rect_t SkSVGNode_objectBoundingBox(SkSVGNode *svgNode, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgNode->objectBoundingBox(*svgRenderContext));
}

void SkSVGNode_setAttribute(SkSVGNode *svgNode, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgNode->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGNode_setAttribute(SkSVGNode *svgNode, const char *attributeName, const char *attributeValue) {
//     svgNode->
// }

bool SkSVGNode_parseAndSetAttribute(SkSVGNode *svgNode, const char *name, const char *value) {
    return svgNode->parseAndSetAttribute(name, value);
}

bool SkSVGNode_unique(SkSVGNode *svgNode) {
    return svgNode->unique();
}

void SkSVGNode_ref(SkSVGNode *svgNode) {
    svgNode->ref();
}

void SkSVGNode_unref(SkSVGNode *svgNode) {
    svgNode->unref();
}

}