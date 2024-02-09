//
// Created by dolphilia on 2024/02/06.
//

#include "sk_svg_transformable_node.h"

extern "C" {

void SkSVGTransformableNode_delete(SkSVGTransformableNode *svgTransformableNode) {
    delete svgTransformableNode;
}

void SkSVGTransformableNode_setTransform(SkSVGTransformableNode *svgTransformableNode, const SkSVGTransformType *t) {
    svgTransformableNode->setTransform(*t);
}

SkSVGTag SkSVGTransformableNode_tag(SkSVGTransformableNode *svgTransformableNode) {
    return svgTransformableNode->tag();
}

void SkSVGTransformableNode_appendChild(SkSVGTransformableNode *svgTransformableNode, sk_svg_node_t svg_node) {
    svgTransformableNode->appendChild(static_sk_svg_node_move(svg_node));
}

void SkSVGTransformableNode_render(SkSVGTransformableNode *svgTransformableNode, const SkSVGRenderContext *svgRenderContext) {
    svgTransformableNode->render(*svgRenderContext);
}

bool SkSVGTransformableNode_asPaint(SkSVGTransformableNode *svgTransformableNode, const SkSVGRenderContext *svgRenderContext, SkPaint *paint) {
    return svgTransformableNode->asPaint(*svgRenderContext, paint);
}

sk_path_t SkSVGTransformableNode_asPath(SkSVGTransformableNode *svgTransformableNode, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_path_make(svgTransformableNode->asPath(*svgRenderContext));
}

sk_rect_t SkSVGTransformableNode_objectBoundingBox(SkSVGTransformableNode *svgTransformableNode, const SkSVGRenderContext *svgRenderContext) {
    return static_sk_rect_make(svgTransformableNode->objectBoundingBox(*svgRenderContext));
}

void SkSVGTransformableNode_setAttribute(SkSVGTransformableNode *svgTransformableNode, SkSVGAttribute svgAttribute, const SkSVGValue *svgValue) {
    svgTransformableNode->setAttribute(svgAttribute, *svgValue);
}

// bool SkSVGTransformableNode_setAttribute(SkSVGTransformableNode *svgTransformableNode, const char *attributeName, const char *attributeValue) {
//     svgTransformableNode->
// }

bool SkSVGTransformableNode_parseAndSetAttribute(SkSVGTransformableNode *svgTransformableNode, const char *name, const char *value) {
    return svgTransformableNode->parseAndSetAttribute(name, value);
}

bool SkSVGTransformableNode_unique(SkSVGTransformableNode *svgTransformableNode) {
    return svgTransformableNode->unique();
}

void SkSVGTransformableNode_ref(SkSVGTransformableNode *svgTransformableNode) {
    svgTransformableNode->ref();
}

void SkSVGTransformableNode_unref(SkSVGTransformableNode *svgTransformableNode) {
    svgTransformableNode->unref();
}

}